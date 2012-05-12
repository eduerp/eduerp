<?php
/**
 * Copy of "Footer for course_grades View 20100228" (course_grades_footer.inc) for PHPDoc purposes only
 * Removed code outside functions to allow PHPDoc (APIGen) to work!
 *
 * @global stdClass $eduerpapprovalform is set to contain values needed for various approval forms.
 */

/**
 * Form to allow to allow Lecturer to approve grades (relevant locked fields will then become 1).
 *
 * @uses approve_grades_lecturer_form_validate()
 * @uses approve_grades_lecturer_form_submit()
 * @global stdClass $eduerpapprovalform already contains values needed for the form.
 */
function approve_grades_lecturer_form($form_state) {
  global $eduerpapprovalform;

  $form['comment'] = array(
    '#type' => 'textarea',
    '#title' => 'Enter a comment on the grades for the HOD.',
    '#cols' => 80,
    '#rows' => 5,
    '#required' => TRUE
  );

  $form['course_url']     = array('#type' => 'value', '#value' => $eduerpapprovalform->course_url);
  $form['lecturer_uid']   = array('#type' => 'value', '#value' => $eduerpapprovalform->lecturer_uid);
  $form['lecturer_alternate_uid'] = array('#type' => 'value', '#value' => $eduerpapprovalform->lecturer_alternate_uid);
  $form['hod_uid']        = array('#type' => 'value', '#value' => $eduerpapprovalform->hod_uid);
  $form['coursecode']     = array('#type' => 'value', '#value' => $eduerpapprovalform->coursecode);
  $form['session']        = array('#type' => 'value', '#value' => $eduerpapprovalform->session);
  $form['semester']       = array('#type' => 'value', '#value' => $eduerpapprovalform->semester);
  $form['location']       = array('#type' => 'value', '#value' => $eduerpapprovalform->location);
  $form['number_of_ca']   = array('#type' => 'value', '#value' => $eduerpapprovalform->number_of_ca);
  $form['ca_approved_onebyone'] = array('#type' => 'value', '#value' => $eduerpapprovalform->ca_approved_onebyone);
  $form['fieldtoapprove'] = array('#type' => 'value', '#value' => $eduerpapprovalform->fieldtoapprove);
  $form['gradestext']     = array('#type' => 'value', '#value' => $eduerpapprovalform->gradestext);

  $form['submit'] = array('#type' => 'submit', '#value' => 'Approve ' . $eduerpapprovalform->gradestext . '.');

  return $form;
}


/**
 * validate hook for {@link approve_grades_lecturer_form()}
 */
function approve_grades_lecturer_form_validate($form, &$form_state) {
  if (empty($form_state['values']['comment'])) {
    form_set_error('comment', 'You must enter a comment for the Head of Department!');
  }
}


/**
 * submit hook for {@link approve_grades_lecturer_form()}
 *
 * <p>Relevant CA & Exam locked fields become 1.</p>
 * <p>Calculate GPA, cGPA and other data if exam scores are being entered.</p>
 * <p>Create an Approval Record.</p>
 * <p>Send e-mails to those that need to be notified.</p>
 * @uses findcourseparameters()
 */
function approve_grades_lecturer_form_submit($form, &$form_state) {
  global $user;
  global $base_url;

  $fieldtoapprove = $form_state['values']['fieldtoapprove'];
  $comment        = $form_state['values']['comment'];
  $course_url     = $form_state['values']['course_url'];
  $lecturer_uid   = $form_state['values']['lecturer_uid'];
  $lecturer_alternate_uid = $form_state['values']['lecturer_alternate_uid'];
  $hod_uid        = $form_state['values']['hod_uid'];
  $coursecode     = $form_state['values']['coursecode'];
  $session        = $form_state['values']['session'];
  $semester       = $form_state['values']['semester'];
  $location       = $form_state['values']['location'];
  $number_of_ca   = $form_state['values']['number_of_ca'];
  $ca_approved_onebyone = $form_state['values']['ca_approved_onebyone'];
  $gradestext     = $form_state['values']['gradestext'];

  if ($semester === 'All') {
    $semesterwhere    = '';
    $semesterwherea   = '';
    $semesterwhereb   = '';
    $semesterwheregpa = '';
  }
  else {
    $semesterwhere    = 'AND ci.field_semester_name_value=' . (int)$semester;
    $semesterwherea   = 'AND cia.field_semester_name_value=' . (int)$semester;
    $semesterwhereb   = 'AND cib.field_semester_name_value=' . (int)$semester;
    $semesterwheregpa = 'AND gpa.field_semester_name_gpa_value=' . (int)$semester;
  }

  if ($location === 'All') {
    $locationwhere  = '';
    $locationwherea = '';
    $locationwhereb = '';
  }
  else {
    $locationwhere  = 'AND ci.field_location_value=' . (int)$location;
    $locationwherea = 'AND cia.field_location_value=' . (int)$location;
    $locationwhereb = 'AND cib.field_location_value=' . (int)$location;
  }

  // Don't allow an exam score approved by the VC to be changed
  if ($fieldtoapprove === 'field_examscorelocked_value') $protectVC = 'AND sg.field_examscorelocked_value < 5';
  else $protectVC = '';

  if ($ca_approved_onebyone) {
    $setstatement = "SET sg.`{$fieldtoapprove}`='1'";
  }
  else { // Approve CAs along with exam
    $setstatement = "SET
      sg.`field_ca1locked_value`='1',
      sg.`field_ca2locked_value`='1',
      sg.`field_ca3locked_value`='1',
      sg.`field_ca4locked_value`='1',
      sg.`field_examscorelocked_value`='1'";
  }

  $sql = "UPDATE {content_type_student_grades} sg, {content_type_course_instance} ci, {content_type_course} c
    $setstatement
    WHERE
      sg.field_course_instance_nid=ci.nid AND
      sg.field_dropped_value=0 AND
      ci.field_course_id_nid=c.nid AND
      ci.field_sess_name_value='%s' $semesterwhere $locationwhere AND
      c.field_code_value='%s'
      $protectVC";
  db_query($sql, $session, $coursecode);
  cache_clear_all('content:', content_cache_tablename(), TRUE);

  if ($fieldtoapprove === 'field_examscorelocked_value') {
    // Set the GPA for all students in this view
    $sql = "UPDATE
      {content_type_student_gpa} gpa,
      (
        SELECT
          exams.field_mat_no_uid AS uid,
          MAX(exams.field_calc_type_value) AS calc_type,
          SUM(exams.gradepoint*exams.credit_load) AS gradepoints,
          MIN(exams.gradepoint) AS allpassed,
          SUM(exams.credit_load) AS totalload
        FROM (
          SELECT
            IF(sg.field_gradepoint_value='-', 0, sg.field_gradepoint_value) AS gradepoint,
            sg.field_mat_no_uid,
            sg.field_calc_type_value,
            sg.field_credit_load_sg_value AS credit_load,
            c.field_creditload_value AS old_credit_load
          FROM
            {content_type_student_grades} sg,
            {content_type_course_instance} ci,
            {content_type_course} c
          WHERE
            sg.field_mat_no_uid IN (
              SELECT sga.field_mat_no_uid
              FROM
                {content_type_student_grades} sga,
                {content_type_course_instance} cia,
                {content_type_course} ca
              WHERE
                sga.field_course_instance_nid=cia.nid AND
                cia.field_course_id_nid=ca.nid AND
                cia.field_sess_name_value='%s' $semesterwherea $locationwherea AND
                ca.field_code_value='%s'
            ) AND
            sg.field_course_instance_nid=ci.nid AND
            sg.field_examscorelocked_value>0 AND
            sg.field_dropped_value=0 AND
            ci.field_course_id_nid=c.nid AND
            ci.field_sess_name_value='%s' $semesterwhere AND
            ci.field_repeat_value=0
          ) AS exams
        GROUP BY exams.field_mat_no_uid
      ) AS gpatoset
    SET
      gpa.field_gptotal_value=gpatoset.gradepoints,
      gpa.field_credit_load_completed_value=gpatoset.totalload,
      gpa.field_gpa_value=IF(gpatoset.calc_type=3,
        IF(gpatoset.allpassed=0, '-', 'Pass'),
        FORMAT(IF(gpatoset.totalload=0, 0, gpatoset.gradepoints/gpatoset.totalload), 2)
      )
    WHERE
      gpa.field_student_ref_gpa_uid=gpatoset.uid AND
      gpa.field_sess_name_gpa_value='%s' $semesterwheregpa";
    db_query($sql, $session, $coursecode, $session, $session);

    // Set the cGPA for all students in this view
    // ... Finds the grade for the most recent sitting of each course
    // ... Sums them and saves result in the student_program found from the students's profile
    $sql = "UPDATE
      {content_type_student_program} sp,
      {node} nspro1,
      {content_type_student_profile} spro1,
      (
        SELECT
          exams.field_mat_no_uid AS uid,
          MAX(exams.field_calc_type_value) AS calc_type,
          SUM(exams.gradepoint*exams.credit_load) AS gradepoints,
          MIN(exams.gradepoint) AS allpassed,
          SUM(exams.credit_load) AS totalload
        FROM (
          SELECT DISTINCT
            IF(sg.field_gradepoint_value='-', 0, sg.field_gradepoint_value) AS gradepoint,
            sg.field_mat_no_uid,
            sg.field_calc_type_value,
            CONCAT(ci.field_sess_name_value, ci.field_semester_name_value, sg.nid) AS sess_sem,
            c.field_code_value,
            sg.field_credit_load_sg_value AS credit_load,
            c.field_creditload_value AS old_credit_load
          FROM
            {content_type_student_grades} sg,
            {content_type_course_instance} ci,
            {content_type_course} c,
            {program_course} pc,
            {node} nspro,
            {content_type_student_profile} spro
          WHERE
            sg.field_mat_no_uid IN (
              SELECT sga.field_mat_no_uid
              FROM
                {content_type_student_grades} sga,
                {content_type_course_instance} cia,
                {content_type_course} ca
              WHERE
                sga.field_course_instance_nid=cia.nid AND
                cia.field_course_id_nid=ca.nid AND
                cia.field_sess_name_value='%s' $semesterwherea $locationwherea AND
                ca.field_code_value='%s'
            ) AND
            sg.field_course_instance_nid=ci.nid AND
            sg.field_examscorelocked_value>0 AND
            sg.field_dropped_value=0 AND
            ci.field_course_id_nid=c.nid AND
            ci.field_course_id_nid=pc.course_id AND
            pc.programme_id=spro.field_profile_first_choice_nid AND
            nspro.uid=sg.field_mat_no_uid AND
            nspro.type='student_profile' AND
            nspro.vid=spro.vid
          ) AS exams
        JOIN (
          SELECT
            sg0.field_mat_no_uid,
            MAX(CONCAT(ci0.field_sess_name_value, ci0.field_semester_name_value, sg0.nid)) AS sess_sem0,
            c0.field_code_value
          FROM
            {content_type_student_grades} sg0,
            {content_type_course_instance} ci0,
            {content_type_course} c0,
            {program_course} pc0,
            {node} nspro0,
            {content_type_student_profile} spro0
          WHERE
            sg0.field_mat_no_uid IN (
              SELECT sgb.field_mat_no_uid
              FROM
                {content_type_student_grades} sgb,
                {content_type_course_instance} cib,
                {content_type_course} cb
              WHERE
                sgb.field_course_instance_nid=cib.nid AND
                cib.field_course_id_nid=cb.nid AND
                cib.field_sess_name_value='%s' $semesterwhereb $locationwhereb AND
                cb.field_code_value='%s'
            ) AND
            sg0.field_course_instance_nid=ci0.nid AND
            sg0.field_examscorelocked_value>0 AND
            sg0.field_dropped_value=0 AND
            ci0.field_course_id_nid=c0.nid AND
            ci0.field_course_id_nid=pc0.course_id AND
            pc0.programme_id=spro0.field_profile_first_choice_nid AND
            nspro0.uid=sg0.field_mat_no_uid AND
            nspro0.type='student_profile' AND
            nspro0.vid=spro0.vid
          GROUP BY c0.field_code_value, sg0.field_mat_no_uid
          ) AS most_recent_exam
        ON
          exams.field_code_value=most_recent_exam.field_code_value AND
          exams.sess_sem=most_recent_exam.sess_sem0 AND
          exams.field_mat_no_uid=most_recent_exam.field_mat_no_uid
        GROUP BY exams.field_mat_no_uid
      ) AS cgpatoset
    SET
      sp.field_gptotal_sp_value=cgpatoset.gradepoints,
      sp.field_credit_load_completed_sp_value=cgpatoset.totalload,
      sp.field_cgpa_sp_value=IF(cgpatoset.calc_type=3,
        IF(cgpatoset.allpassed=0, '-', 'Pass'),
        FORMAT(IF(cgpatoset.totalload=0, 0, cgpatoset.gradepoints/cgpatoset.totalload), 2)
      )
    WHERE
      sp.field_student_ref_sp_uid=cgpatoset.uid AND
      sp.field_program_ref_sp_nid=spro1.field_profile_first_choice_nid AND
      nspro1.uid=cgpatoset.uid AND
      nspro1.type='student_profile' AND
      nspro1.vid=spro1.vid";
    db_query($sql, $session, $coursecode, $session, $coursecode);
    cache_clear_all('content:', content_cache_tablename(), TRUE);
  }

  list($level, $sem, $loc, $department, $college) = findcourseparameters($coursecode, $session, $semesterwhere, $locationwhere);

  $user_profile = new UserProfile($user->uid);

  $name = '';
  if (!empty($user_profile->profile_first_name) && !empty($user_profile->profile_last_name)) {
    $middle = '';
    if (!empty($user_profile->profile_middle_name)) $middle = $user_profile->profile_middle_name . ' ';
    $name = "$user_profile->profile_first_name {$middle}$user_profile->profile_last_name";
  }

  $firsttime = TRUE;

  // Determine who gets notified when Lecturer (or equiv) submits grades
  $inroles = "'Head of Department', 'Department Grade Editor', 'Department Examination Officer', 'Dean of Faculty', 'Faculty Grade Editor', 'Faculty Examination Officer', 'University Grade Editor'";

  $sql = "SELECT
      d.field_college_id_nid AS college_id,
      c.field_department_nid_nid AS department_id
    FROM {content_type_department} d, {content_type_course} c
    WHERE
      d.nid=c.field_department_nid_nid AND
      c.field_code_value='%s'";
  $staffresult = db_query($sql, $coursecode);
  $staff = db_fetch_object($staffresult);

  $sql = "SELECT DISTINCT uid AS hod_uid
    FROM {eduerp_roles}
    WHERE (department_id=%d OR college_id=%d OR (department_id=0 AND college_id=0)) AND role IN ($inroles)";
  $hodresult = db_query($sql, $staff->department_id, $staff->college_id);
  while ($hod = db_fetch_object($hodresult)) {

    if (!empty($hod->hod_uid)) {
      $destination_user = user_load($hod->hod_uid);
      $user_profile = new UserProfile($hod->hod_uid);
    }
    else {
      $destination_user = NULL;
      $user_profile = NULL;
    }

    $subject = "$gradestext for $coursecode Approved by $name";

    $body = '';
    if (!empty($user_profile->profile_first_name) && !empty($user_profile->profile_last_name)) {
      $middle = '';
      if (!empty($user_profile->profile_middle_name)) $middle = $user_profile->profile_middle_name . ' ';
      $body .= "Dear $user_profile->profile_first_name {$middle}$user_profile->profile_last_name,\n\n";
    }

    $body .= "I have approved $gradestext for $coursecode\n\n";
    $body .= "URL: $course_url\n";
    $body .= "Department: $department\n";
    $body .= "Faculty: $college\n";
    $body .= "Level: $level\n";
    $body .= "Session: $session\n";
    $body .= "Semester: $sem\n";
    $body .= "Location: $loc\n\n";
    $body .= "Lecturer's comment...\n";
    $body .= str_replace('<br />', "\n", $comment);
    $body .= "\n\n{$name}\n\n";

    if ($firsttime) {
      $node = new stdClass();
      $node->type                            = 'approval';
      $node->uid                             = 1;
      $node->status                          = 0;
      $node->promote                         = 0;
      $node->sticky                          = 0;
      $node->comment                         = 0;
      $node->title                           = $subject;
      $node->body                            = $comment;
      $node->field_url[0]['value']           = $course_url;
      $node->field_approver[0]['uid']        = $user->uid;
      $node->field_destination[0]['value']   = $hod_uid;
      $node->field_coursecode[0]['value']    = $coursecode;
      $node->field_programme[0]['value']     = '';
      $node->field_department1[0]['value']   = $department;
      $node->field_college1[0]['value']      = $college;
      $node->field_level1[0]['value']        = $level;
      $node->field_session1[0]['value']      = $session;
      $node->field_semester1[0]['value']     = $sem;
      $node->field_location1[0]['value']     = $loc;
      $node->field_what_approved[0]['value'] = $gradestext;
      $node->field_action[0]['value']        = 'Approved by Lecturer';
      node_save($node);

      $firsttime = FALSE;
    }

    if (!empty($destination_user)) {
      $message = drupal_mail('grading', 'approval', $destination_user->mail, language_default(), array(), $user->mail, FALSE);
      $message['subject'] = $subject;
      $message['body'] = $body;
      drupal_mail_send($message);
    }
  }

  drupal_set_message('Approval successfull');
}


/**
 * Form to allow to allow HOD to unlock grades (relevant locked fields will then become 0).
 *
 * @uses unlock_grades_hod_form_validate()
 * @uses unlock_grades_hod_form_submit()
 * @global stdClass $eduerpapprovalform already contains values needed for the form.
 */
function unlock_grades_hod_form($form_state) {
  global $eduerpapprovalform;

  $form['comment'] = array(
    '#type' => 'textarea',
    '#title' => 'Enter a comment on the grades for the Lecturer.',
    '#cols' => 80,
    '#rows' => 5,
    '#required' => TRUE
  );

  $form['course_url']   = array('#type' => 'value', '#value' => $eduerpapprovalform->course_url);
  $form['lecturer_uid'] = array('#type' => 'value', '#value' => $eduerpapprovalform->lecturer_uid);
  $form['lecturer_alternate_uid'] = array('#type' => 'value', '#value' => $eduerpapprovalform->lecturer_alternate_uid);
  $form['hod_uid']      = array('#type' => 'value', '#value' => $eduerpapprovalform->hod_uid);
  $form['coursecode']   = array('#type' => 'value', '#value' => $eduerpapprovalform->coursecode);
  $form['session']      = array('#type' => 'value', '#value' => $eduerpapprovalform->session);
  $form['semester']     = array('#type' => 'value', '#value' => $eduerpapprovalform->semester);
  $form['location']     = array('#type' => 'value', '#value' => $eduerpapprovalform->location);
  $form['number_of_ca'] = array('#type' => 'value', '#value' => $eduerpapprovalform->number_of_ca);
  $form['ca_approved_onebyone'] = array('#type' => 'value', '#value' => $eduerpapprovalform->ca_approved_onebyone);
  $form['fieldtoapprovehod'] = array('#type' => 'value', '#value' => $eduerpapprovalform->fieldtoapprovehod);
  $form['gradestexthod'] = array('#type' => 'value', '#value' => $eduerpapprovalform->gradestexthod);

  $form['submit'] = array('#type' => 'submit', '#value' => 'Unlock the ' . $eduerpapprovalform->gradestexthod . ' for the lecturer to re-edit.');

  return $form;
}


/**
 * validate hook for {@link unlock_grades_hod_form()}
 */
function unlock_grades_hod_form_validate($form, &$form_state) {
  if (empty($form_state['values']['comment'])) {
    form_set_error('comment', 'You must enter a comment for the Lecturer!');
  }
}


/**
 * submit hook for {@link unlock_grades_hod_form()}
 *
 * <p>Relevant CA & Exam locked fields become 0.</p>
 * <p>Create an Approval Record.</p>
 * <p>Send notification e-mail to Lecturer.</p>
 * @uses findcourseparameters()
 */
function unlock_grades_hod_form_submit($form, &$form_state) {
  global $user;

  $fieldtoapprovehod = $form_state['values']['fieldtoapprovehod'];
  $comment           = $form_state['values']['comment'];
  $course_url        = $form_state['values']['course_url'];
  $lecturer_uid      = $form_state['values']['lecturer_uid'];
  $lecturer_alternate_uid = $form_state['values']['lecturer_alternate_uid'];
  $hod_uid           = $form_state['values']['hod_uid'];
  $coursecode        = $form_state['values']['coursecode'];
  $session           = $form_state['values']['session'];
  $semester          = $form_state['values']['semester'];
  $location          = $form_state['values']['location'];
  $number_of_ca      = $form_state['values']['number_of_ca'];
  $ca_approved_onebyone = $form_state['values']['ca_approved_onebyone'];
  $gradestexthod        = $form_state['values']['gradestexthod'];

  if ($semester === 'All') $semesterwhere = '';
  else $semesterwhere = 'AND ci.field_semester_name_value=' . (int)$semester;

  if ($location === 'All') $locationwhere = '';
  else $locationwhere = 'AND ci.field_location_value=' . (int)$location;

  // Don't allow an exam score approved by the VC to be changed
  if ($fieldtoapprovehod === 'field_examscorelocked_value') $protectVC = 'AND sg.field_examscorelocked_value < 5';
  else $protectVC = '';

  if ($ca_approved_onebyone) {
    $setstatement = "SET sg.`{$fieldtoapprovehod}`='0'";
  }
  else {
    $setstatement = "SET
      sg.`field_ca1locked_value`='0',
      sg.`field_ca2locked_value`='0',
      sg.`field_ca3locked_value`='0',
      sg.`field_ca4locked_value`='0',
      sg.`field_examscorelocked_value`='0'";
  }

  $sql = "UPDATE {content_type_student_grades} sg, {content_type_course_instance} ci, {content_type_course} c
    $setstatement
    WHERE
      sg.field_course_instance_nid=ci.nid AND
      sg.field_dropped_value=0 AND
      ci.field_course_id_nid=c.nid AND
      ci.field_sess_name_value='%s' $semesterwhere $locationwhere AND
      c.field_code_value='%s'
      $protectVC";
  db_query($sql, $session, $coursecode);
  cache_clear_all('content:', content_cache_tablename(), TRUE);

  list($level, $sem, $loc, $department, $college) = findcourseparameters($coursecode, $session, $semesterwhere, $locationwhere);

  $user_profile = new UserProfile($user->uid);

  $name = '';
  if (!empty($user_profile->profile_first_name) && !empty($user_profile->profile_last_name)) {
    $middle = '';
    if (!empty($user_profile->profile_middle_name)) $middle = $user_profile->profile_middle_name . ' ';
    $name = "$user_profile->profile_first_name {$middle}$user_profile->profile_last_name";
  }

  if (!empty($lecturer_uid)) {
    $destination_user = user_load($lecturer_uid);
    $user_profile = new UserProfile($lecturer_uid);
  }
  else {
    $destination_user = NULL;
    $user_profile = NULL;
  }

  $subject = "$gradestexthod for $coursecode Unlocked by $name";

  $body = '';
  if (!empty($user_profile->profile_first_name) && !empty($user_profile->profile_last_name)) {
    $middle = '';
    if (!empty($user_profile->profile_middle_name)) $middle = $user_profile->profile_middle_name . ' ';
    $body .= "Dear $user_profile->profile_first_name {$middle}$user_profile->profile_last_name,\n\n";
  }

  $body .= "I have unlocked $gradestexthod for $coursecode\n\n";
  $body .= "URL: $course_url\n";
  $body .= "Department: $department\n";
  $body .= "Faculty: $college\n";
  $body .= "Level: $level\n";
  $body .= "Session: $session\n";
  $body .= "Semester: $sem\n";
  $body .= "Location: $loc\n\n";
  $body .= "Head of Department's comment...\n";
  $body .= str_replace('<br />', "\n", $comment);
  $body .= "\n\n{$name}\n";

  $node = new stdClass();
  $node->type                            = 'approval';
  $node->uid                             = 1;
  $node->status                          = 0;
  $node->promote                         = 0;
  $node->sticky                          = 0;
  $node->comment                         = 0;
  $node->title                           = $subject;
  $node->body                            = $comment;
  $node->field_url[0]['value']           = $course_url;
  $node->field_approver[0]['uid']        = $user->uid;
  $node->field_destination[0]['value']   = $lecturer_uid;
  $node->field_coursecode[0]['value']    = $coursecode;
  $node->field_programme[0]['value']     = '';
  $node->field_department1[0]['value']   = $department;
  $node->field_college1[0]['value']      = $college;
  $node->field_level1[0]['value']        = $level;
  $node->field_session1[0]['value']      = $session;
  $node->field_semester1[0]['value']     = $sem;
  $node->field_location1[0]['value']     = $loc;
  $node->field_what_approved[0]['value'] = $gradestexthod;
  $node->field_action[0]['value']        = 'Unlocked by HOD';
  node_save($node);

  if (!empty($destination_user)) {
    $message = drupal_mail('grading', 'approval', $destination_user->mail, language_default(), array(), $user->mail, FALSE);
    $message['subject'] = $subject;
    $message['body'] = $body;
    drupal_mail_send($message);
  }

  if (!empty($lecturer_alternate_uid)) {
    $destination_user = user_load($lecturer_alternate_uid);
    $user_profile = new UserProfile($lecturer_alternate_uid);
  }
  else {
    $destination_user = NULL;
    $user_profile = NULL;
  }

  $subject = "$gradestexthod for $coursecode Unlocked by $name";

  $body = '';
  if (!empty($user_profile->profile_first_name) && !empty($user_profile->profile_last_name)) {
    $middle = '';
    if (!empty($user_profile->profile_middle_name)) $middle = $user_profile->profile_middle_name . ' ';
    $body .= "Dear $user_profile->profile_first_name {$middle}$user_profile->profile_last_name,\n\n";
  }

  $body .= "I have unlocked $gradestexthod for $coursecode\n\n";
  $body .= "URL: $course_url\n";
  $body .= "Department: $department\n";
  $body .= "Faculty: $college\n";
  $body .= "Level: $level\n";
  $body .= "Session: $session\n";
  $body .= "Semester: $sem\n";
  $body .= "Location: $loc\n\n";
  $body .= "Head of Department's comment...\n";
  $body .= str_replace('<br />', "\n", $comment);
  $body .= "\n\n{$name}\n";

  if (!empty($destination_user)) {
    $message = drupal_mail('grading', 'approval', $destination_user->mail, language_default(), array(), $user->mail, FALSE);
    $message['subject'] = $subject;
    $message['body'] = $body;
    drupal_mail_send($message);
  }

  drupal_set_message('Unlocking successfull');
}


/**
 * Form to allow to allow HOD to approve grades (relevant locked fields will then become 2).
 *
 * @uses approve_grades_hod_form_validate()
 * @uses approve_grades_hod_form_submit()
 * @global stdClass $eduerpapprovalform already contains values needed for the form.
 */
function approve_grades_hod_form($form_state) {
  global $eduerpapprovalform;

  $form['comment'] = array(
    '#type' => 'textarea',
    '#title' => 'Enter a comment on the grades for the Dean.',
    '#cols' => 80,
    '#rows' => 5,
    '#required' => TRUE
  );

  $form['course_url']     = array('#type' => 'value', '#value' => $eduerpapprovalform->course_url);
  $form['hod_uid']        = array('#type' => 'value', '#value' => $eduerpapprovalform->hod_uid);
  $form['dean_uid']       = array('#type' => 'value', '#value' => $eduerpapprovalform->dean_uid);
  $form['coursecode']     = array('#type' => 'value', '#value' => $eduerpapprovalform->coursecode);
  $form['session']        = array('#type' => 'value', '#value' => $eduerpapprovalform->session);
  $form['semester']       = array('#type' => 'value', '#value' => $eduerpapprovalform->semester);
  $form['location']       = array('#type' => 'value', '#value' => $eduerpapprovalform->location);
  $form['number_of_ca']   = array('#type' => 'value', '#value' => $eduerpapprovalform->number_of_ca);
  $form['ca_approved_onebyone'] = array('#type' => 'value', '#value' => $eduerpapprovalform->ca_approved_onebyone);
  $form['fieldtoapprovehoda']   = array('#type' => 'value', '#value' => $eduerpapprovalform->fieldtoapprovehoda);
  $form['gradestexthoda']       = array('#type' => 'value', '#value' => $eduerpapprovalform->gradestexthoda);
  $form['srcfield']             = array('#type' => 'value', '#value' => $eduerpapprovalform->srcfield);
  $form['destfield']            = array('#type' => 'value', '#value' => $eduerpapprovalform->destfield);

  $form['submit'] = array('#type' => 'submit', '#value' => 'Approve ' . $eduerpapprovalform->gradestexthoda . '.');

  return $form;
}


/**
 * validate hook for {@link approve_grades_hod_form()}
 */
function approve_grades_hod_form_validate($form, &$form_state) {
  if (empty($form_state['values']['comment'])) {
    form_set_error('comment', 'You must enter a comment for the Dean!');
  }
}


/**
 * submit hook for {@link approve_grades_hod_form()}
 *
 * <p>Relevant CA & Exam locked fields become 2.</p>
 * <p>If this is a CA approval, set the student visible CA scores to the values set by the lecturer.</p>
 * <p>Create an Approval Record.</p>
 * <p>Send e-mails to those that need to be notified.</p>
 * <p>Send e-mails to Students for CA only.</p>
 * @uses findcourseparameters()
 */
function approve_grades_hod_form_submit($form, &$form_state) {
  global $user;
  global $base_url;

  $fieldtoapprovehoda = $form_state['values']['fieldtoapprovehoda'];
  $comment        = $form_state['values']['comment'];
  $course_url     = $form_state['values']['course_url'];
  $hod_uid        = $form_state['values']['hod_uid'];
  $dean_uid       = $form_state['values']['dean_uid'];
  $coursecode     = $form_state['values']['coursecode'];
  $session        = $form_state['values']['session'];
  $semester       = $form_state['values']['semester'];
  $location       = $form_state['values']['location'];
  $number_of_ca   = $form_state['values']['number_of_ca'];
  $ca_approved_onebyone = $form_state['values']['ca_approved_onebyone'];
  $gradestexthoda = $form_state['values']['gradestexthoda'];
  $srcfield       = $form_state['values']['srcfield'];
  $destfield      = $form_state['values']['destfield'];

  if ($semester === 'All') $semesterwhere = '';
  else $semesterwhere = 'AND ci.field_semester_name_value=' . (int)$semester;

  if ($location === 'All') $locationwhere = '';
  else $locationwhere = 'AND ci.field_location_value=' . (int)$location;

  // Don't allow an exam score approved by the VC to be changed
  if ($fieldtoapprovehoda === 'field_examscorelocked_value') $protectVC = 'AND sg.field_examscorelocked_value < 5';
  else $protectVC = '';

  if ($ca_approved_onebyone) {
    $setstatement = "SET sg.`{$fieldtoapprovehoda}`='2'";
  }
  else { // Approve CAs along with exam
    $setstatement = "SET
      sg.`field_ca1locked_value`='2',
      sg.`field_ca2locked_value`='2',
      sg.`field_ca3locked_value`='2',
      sg.`field_ca4locked_value`='2',
      sg.`field_examscorelocked_value`='2'";
  }

  $sql = "UPDATE {content_type_student_grades} sg, {content_type_course_instance} ci, {content_type_course} c
    $setstatement
    WHERE
      sg.field_course_instance_nid=ci.nid AND
      sg.field_dropped_value=0 AND
      ci.field_course_id_nid=c.nid AND
      ci.field_sess_name_value='%s' $semesterwhere $locationwhere AND
      c.field_code_value='%s'
      $protectVC";
  db_query($sql, $session, $coursecode);
  cache_clear_all('content:', content_cache_tablename(), TRUE);

  if ($srcfield != 'NONE') {
    // Make the CAs visible to students
    $setstatement = "SET sg.`{$destfield}`=sg.`{$srcfield}`";
    $sql = "UPDATE {content_type_student_grades} sg, {content_type_course_instance} ci, {content_type_course} c
      $setstatement
      WHERE
        sg.field_course_instance_nid=ci.nid AND
        sg.field_dropped_value=0 AND
        ci.field_course_id_nid=c.nid AND
        ci.field_sess_name_value='%s' $semesterwhere $locationwhere AND
        c.field_code_value='%s'";
    db_query($sql, $session, $coursecode);
    cache_clear_all('content:', content_cache_tablename(), TRUE);
  }

  list($level, $sem, $loc, $department, $college) = findcourseparameters($coursecode, $session, $semesterwhere, $locationwhere);

  $user_profile = new UserProfile($user->uid);

  $name = '';
  if (!empty($user_profile->profile_first_name) && !empty($user_profile->profile_last_name)) {
    $middle = '';
    if (!empty($user_profile->profile_middle_name)) $middle = $user_profile->profile_middle_name . ' ';
    $name = "$user_profile->profile_first_name {$middle}$user_profile->profile_last_name";
  }

  $firsttime = TRUE;

  // Determine who gets notified when HOD (or equiv) submits Grade approval form
  $inroles = "'Dean of Faculty', 'Faculty Grade Editor', 'Faculty Examination Officer', 'University Grade Editor'";

  $sql = "SELECT
      d.field_college_id_nid AS college_id,
      c.field_department_nid_nid AS department_id
    FROM {content_type_department} d, {content_type_course} c
    WHERE
      d.nid=c.field_department_nid_nid AND
      c.field_code_value='%s'";
  $staffresult = db_query($sql, $coursecode);
  $staff = db_fetch_object($staffresult);

  $sql = "SELECT DISTINCT uid AS dean_uid
    FROM {eduerp_roles}
    WHERE (department_id=%d OR college_id=%d OR (department_id=0 AND college_id=0)) AND role IN ($inroles)";
  $hodresult = db_query($sql, $staff->department_id, $staff->college_id);
  while ($hod = db_fetch_object($hodresult)) {

    if (!empty($hod->dean_uid)) {
      $destination_user = user_load($hod->dean_uid);
      $user_profile = new UserProfile($hod->dean_uid);
    }
    else {
      $destination_user = NULL;
      $user_profile = NULL;
    }

    $subject = "$gradestexthoda for $coursecode Approved by $name";

    $body = '';
    if (!empty($user_profile->profile_first_name) && !empty($user_profile->profile_last_name)) {
      $middle = '';
      if (!empty($user_profile->profile_middle_name)) $middle = $user_profile->profile_middle_name . ' ';
      $body .= "Dear $user_profile->profile_first_name {$middle}$user_profile->profile_last_name,\n\n";
    }

    $body .= "I have approved $gradestexthoda for $coursecode\n\n";
    $body .= "URL: $course_url\n";
    $body .= "Department: $department\n";
    $body .= "Faculty: $college\n";
    $body .= "Level: $level\n";
    $body .= "Session: $session\n";
    $body .= "Semester: $sem\n";
    $body .= "Location: $loc\n\n";
    $body .= "HOD's comment...\n";
    $body .= str_replace('<br />', "\n", $comment);
    $body .= "\n\n{$name}\n\n";

    if ($firsttime) {
      $node = new stdClass();
      $node->type                            = 'approval';
      $node->uid                             = 1;
      $node->status                          = 0;
      $node->promote                         = 0;
      $node->sticky                          = 0;
      $node->comment                         = 0;
      $node->title                           = $subject;
      $node->body                            = $comment;
      $node->field_url[0]['value']           = $course_url;
      $node->field_approver[0]['uid']        = $user->uid;
      $node->field_destination[0]['value']   = $dean_uid;
      $node->field_coursecode[0]['value']    = $coursecode;
      $node->field_programme[0]['value']     = '';
      $node->field_department1[0]['value']   = $department;
      $node->field_college1[0]['value']      = $college;
      $node->field_level1[0]['value']        = $level;
      $node->field_session1[0]['value']      = $session;
      $node->field_semester1[0]['value']     = $sem;
      $node->field_location1[0]['value']     = $loc;
      $node->field_what_approved[0]['value'] = $gradestexthoda;
      $node->field_action[0]['value']        = 'Approved by HOD';
      node_save($node);

      $firsttime = FALSE;
    }

    if (!empty($destination_user)) {
      $message = drupal_mail('grading', 'approval', $destination_user->mail, language_default(), array(), $user->mail, FALSE);
      $message['subject'] = $subject;
      $message['body'] = $body;
      drupal_mail_send($message);
    }
  }

  // Send e-mails to Students for CA only
  if ($srcfield != 'NONE') {
    $sql = "SELECT sg.field_mat_no_uid FROM {content_type_student_grades} sg, {content_type_course_instance} ci, {content_type_course} c
      WHERE
        sg.field_course_instance_nid=ci.nid AND
        sg.field_dropped_value=0 AND
        ci.field_course_id_nid=c.nid AND
        ci.field_sess_name_value='%s' $semesterwhere $locationwhere AND
        c.field_code_value='%s'";
    $studentresult = db_query($sql, $session, $coursecode);

    while ($student = db_fetch_object($studentresult)) {
      $student_uid = $student->field_mat_no_uid;

      $destination_user = user_load($student_uid);
      $user_profile = new UserProfile($student_uid);

      $subject = "$gradestexthoda for $coursecode Approved by $name";

      $body = '';
      if (!empty($user_profile->profile_first_name) && !empty($user_profile->profile_last_name)) {
        $middle = '';
        if (!empty($user_profile->profile_middle_name)) $middle = $user_profile->profile_middle_name . ' ';
        $body .= "Dear $user_profile->profile_first_name {$middle}$user_profile->profile_last_name,\n\n";
      }
      $body .= "I have approved $gradestexthoda for $coursecode\n\n";
      $body .= "To view your grades go to $base_url/student\n";
      $body .= "You will have to login first.\n\n";
      $body .= "{$name}\n";

      $message = drupal_mail('grading', 'notifystudent', $destination_user->mail, language_default(), array(), $user->mail, FALSE);
      $message['subject'] = $subject;
      $message['body'] = $body;
      drupal_mail_send($message);

      db_query("INSERT INTO cron_notification (approver_uid, student_uid, gradestext, programme, instruction) VALUES (%d, %d, '%s', '%s', %d)",
        $user->uid, $student_uid, $gradestexthoda, $coursecode, 1);
    }
  }

  drupal_set_message('Approval successfull');
}


/**
 * Form to allow to allow Dean to approve grades (relevant locked fields will then become 3).
 *
 * @uses approve_grades_dean_form_validate()
 * @uses approve_grades_dean_form_submit()
 * @global stdClass $eduerpapprovalform already contains values needed for the form.
 */
function approve_grades_dean_form($form_state) {
  global $eduerpapprovalform;

  $form['comment'] = array(
    '#type' => 'textarea',
    '#title' => 'Enter a comment on the grades for the Record.',
    '#cols' => 80,
    '#rows' => 5,
    '#required' => TRUE
  );

  $form['course_url']     = array('#type' => 'value', '#value' => $eduerpapprovalform->course_url);
  $form['dean_uid']       = array('#type' => 'value', '#value' => $eduerpapprovalform->dean_uid);
  $form['coursecode']     = array('#type' => 'value', '#value' => $eduerpapprovalform->coursecode);
  $form['session']        = array('#type' => 'value', '#value' => $eduerpapprovalform->session);
  $form['semester']       = array('#type' => 'value', '#value' => $eduerpapprovalform->semester);
  $form['location']       = array('#type' => 'value', '#value' => $eduerpapprovalform->location);
  $form['number_of_ca']   = array('#type' => 'value', '#value' => $eduerpapprovalform->number_of_ca);
  $form['ca_approved_onebyone'] = array('#type' => 'value', '#value' => $eduerpapprovalform->ca_approved_onebyone);
  $form['fieldtoapprovedean']   = array('#type' => 'value', '#value' => $eduerpapprovalform->fieldtoapprovedean);
  $form['gradestextdean']       = array('#type' => 'value', '#value' => $eduerpapprovalform->gradestextdean);
  $form['srcfield']             = array('#type' => 'value', '#value' => $eduerpapprovalform->srcfield);

  $form['submit'] = array('#type' => 'submit', '#value' => 'Approve ' . $eduerpapprovalform->gradestextdean . '.');

  return $form;
}


/**
 * validate hook for {@link approve_grades_dean_form()}
 */
function approve_grades_dean_form_validate($form, &$form_state) {
  if (empty($form_state['values']['comment'])) {
    form_set_error('comment', 'You must enter a comment for the Record!');
  }
}


/**
 * submit hook for {@link approve_grades_dean_form()}
 *
 * <p>Relevant CA & Exam locked fields become 3 (or 5 if this is for a CA only... Fully Approved).</p>
 * <p>Create an Approval Record.</p>
 * @uses findcourseparameters()
 */
function approve_grades_dean_form_submit($form, &$form_state) {
  global $user;
  global $base_url;

  $fieldtoapprovedean = $form_state['values']['fieldtoapprovedean'];
  $comment            = $form_state['values']['comment'];
  $course_url         = $form_state['values']['course_url'];
  $dean_uid           = $form_state['values']['dean_uid'];
  $coursecode         = $form_state['values']['coursecode'];
  $session            = $form_state['values']['session'];
  $semester           = $form_state['values']['semester'];
  $location           = $form_state['values']['location'];
  $number_of_ca       = $form_state['values']['number_of_ca'];
  $ca_approved_onebyone = $form_state['values']['ca_approved_onebyone'];
  $gradestextdean     = $form_state['values']['gradestextdean'];
  $srcfield           = $form_state['values']['srcfield'];

  if ($semester === 'All') $semesterwhere = '';
  else $semesterwhere = 'AND ci.field_semester_name_value=' . (int)$semester;

  if ($location === 'All') $locationwhere = '';
  else $locationwhere = 'AND ci.field_location_value=' . (int)$location;

  // Don't allow an exam score approved by the VC to be changed
  if ($fieldtoapprovedean === 'field_examscorelocked_value') $protectVC = 'AND sg.field_examscorelocked_value < 5';
  else $protectVC = '';

  if ($ca_approved_onebyone) {
    if ($srcfield != 'NONE') {
      $setstatement = "SET sg.`{$fieldtoapprovedean}`='5'"; // This is a CA so make it fully approved
    }
    else {
      $setstatement = "SET sg.`{$fieldtoapprovedean}`='3'";
    }
  }
  else { // Approve CAs along with exam
    $setstatement = "SET
      sg.`field_ca1locked_value`='3',
      sg.`field_ca2locked_value`='3',
      sg.`field_ca3locked_value`='3',
      sg.`field_ca4locked_value`='3',
      sg.`field_examscorelocked_value`='3'";
  }

  $sql = "UPDATE {content_type_student_grades} sg, {content_type_course_instance} ci, {content_type_course} c
    $setstatement
    WHERE
      sg.field_course_instance_nid=ci.nid AND
      sg.field_dropped_value=0 AND
      ci.field_course_id_nid=c.nid AND
      ci.field_sess_name_value='%s' $semesterwhere $locationwhere AND
      c.field_code_value='%s'
      $protectVC";
  db_query($sql, $session, $coursecode);
  cache_clear_all('content:', content_cache_tablename(), TRUE);

  list($level, $sem, $loc, $department, $college) = findcourseparameters($coursecode, $session, $semesterwhere, $locationwhere);

  $user_profile = new UserProfile($user->uid);

  $name = '';
  if (!empty($user_profile->profile_first_name) && !empty($user_profile->profile_last_name)) {
    $middle = '';
    if (!empty($user_profile->profile_middle_name)) $middle = $user_profile->profile_middle_name . ' ';
    $name = "$user_profile->profile_first_name {$middle}$user_profile->profile_last_name";
  }

  $subject = "$gradestextdean for $coursecode Approved by $name";

  $node = new stdClass();
  $node->type                            = 'approval';
  $node->uid                             = 1;
  $node->status                          = 0;
  $node->promote                         = 0;
  $node->sticky                          = 0;
  $node->comment                         = 0;
  $node->title                           = $subject;
  $node->body                            = $comment;
  $node->field_url[0]['value']           = $course_url;
  $node->field_approver[0]['uid']        = $user->uid;
  $node->field_coursecode[0]['value']    = $coursecode;
  $node->field_programme[0]['value']     = '';
  $node->field_department1[0]['value']   = $department;
  $node->field_college1[0]['value']      = $college;
  $node->field_level1[0]['value']        = $level;
  $node->field_session1[0]['value']      = $session;
  $node->field_semester1[0]['value']     = $sem;
  $node->field_location1[0]['value']     = $loc;
  $node->field_what_approved[0]['value'] = $gradestextdean;
  $node->field_action[0]['value']        = 'Approved by Dean';
  node_save($node);

  drupal_set_message('Approval successfull');
}


/**
 * Find parameters for Course selected in the View
 *
 * @return array of parameters
 */
function findcourseparameters($coursecode, $session, $semesterwhere, $locationwhere) {
  $sql = "SELECT
      c.field_level_value AS level,
      ci.field_semester_name_value AS sem,
      ci.field_location_value AS loc,
      d.field_department_name_value AS department,
      co.field_college_name_value AS college
    FROM {content_type_course_instance} ci, {content_type_course} c, {content_type_department} d, {content_type_college} co
    WHERE
      c.field_code_value='%s' AND
      c.nid=ci.field_course_id_nid AND
      ci.field_sess_name_value='%s'
      $semesterwhere $locationwhere AND
      c.field_department_nid_nid=d.nid AND
      d.field_college_id_nid=co.nid
    LIMIT 1";
  $collegeresult = db_query($sql, $coursecode, $session);
  if ($collegerow = db_fetch_object($collegeresult)) {
    return array($collegerow->level, $collegerow->sem, $collegerow->loc, $collegerow->department, $collegerow->college);
  }
  else {
    return array('', '', '', '', '');
  }
}


/**
 * Print all locations for Course selected in the View
 */
function listlocations($coursecode, $session, $semesterwhere, $locationwhere) {
  $sql = "SELECT DISTINCT
      ci.field_location_value AS location,
      ci.field_lecturer_uid AS lecturer_uid
    FROM {content_type_course} c, {content_type_course_instance} ci
    WHERE
      c.field_code_value='%s' AND
      c.nid=ci.field_course_id_nid AND
      ci.field_sess_name_value='%s'
      $semesterwhere $locationwhere";
  $locationresult = db_query($sql, $coursecode, $session);
  while ($locationdetail = db_fetch_object($locationresult)) {
    $user_profile = new UserProfile($locationdetail->lecturer_uid);

    echo "Location: $locationdetail->location (Lecturer: $user_profile->profile_first_name ";
    if (!empty($user_profile->profile_middle_name)) echo $user_profile->profile_middle_name . ' ';
    echo "$user_profile->profile_last_name)<br />";
  }
}
?>