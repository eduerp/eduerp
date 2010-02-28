<?php
// Footer for course_grades View 20100228

global $user;
global $base_url;

if (!empty($_SESSION['views']['course_grades']['default']['coursecode']) && !empty($_SESSION['views']['course_grades']['default']['session'])) {
  $coursecode = $_SESSION['views']['course_grades']['default']['coursecode'];
  $session = $_SESSION['views']['course_grades']['default']['session'];

  if (empty($_SESSION['views']['course_grades']['default']['semester'])) $semester = 'All';
  else $semester = $_SESSION['views']['course_grades']['default']['semester'];
  if ($semester === 'All') $semesterwhere = '';
  else $semesterwhere = 'AND ci.field_semester_name_value=' . (int)$semester;

  if (empty($_SESSION['views']['course_grades']['default']['location'])) $location = 'All';
  else $location = $_SESSION['views']['course_grades']['default']['location'];
  if ($location === 'All') $locationwhere = '';
  else $locationwhere = 'AND ci.field_location_value=' . (int)$location;

  // Determine how CA should be treated
  $sql = "SELECT cgw.number_of_ca, cgw.ca_approved_onebyone
    FROM {course_grade_weightings} cgw, {content_type_course} c
    WHERE
      (cgw.course_id=c.nid AND c.field_code_value='%s') OR
      cgw.course_id=0
    ORDER BY cgw.course_id DESC";  // Select the course specific one (if any) first followed by the default one
  $weightings = db_query($sql, $coursecode);
  $row = db_fetch_object($weightings);
  $number_of_ca = $row->number_of_ca;
  $ca_approved_onebyone = $row->ca_approved_onebyone;

  // Number of grades of each level (A-F)
  $sql = "SELECT field_grade_value, COUNT(*) AS count FROM {content_type_student_grades} sg, {content_type_course_instance} ci, {content_type_course} c
    WHERE
      sg.field_course_instance_nid=ci.nid AND
      c.field_code_value='%s' AND
      ci.field_sess_name_value='%s'
      $semesterwhere $locationwhere AND
      ci.field_course_id_nid=c.nid
    GROUP BY field_grade_value
    ORDER BY field_grade_value";
  $countgrades = db_query($sql, $coursecode, $session);

  echo '<table class="body-table"><tbody>';
  echo '<tr><th valign="top" class="table-label" colspan="2">RESULTS SUMMARY</th></tr>';

  $total = 0;
  $missing = 0;
  while ($row = db_fetch_object($countgrades)) {
    if ($row->field_grade_value === '-') {
      $missing = $row->count;
    }
    else {
      echo '<tr>';
      echo '<td valign="top" class="table-label">Number of ' . $row->field_grade_value . ' Grades </td>';
      echo '<td valign="top">' . $row->count . '</td>';
      echo '</tr>';
    }
    $total += $row->count;
  }
  echo '<tr>';
  echo '<td valign="top" class="table-label">Number of Missing Grades</td>';
  echo '<td valign="top">' . $missing . '</td>';
  echo '</tr>';

  echo '<tr>';
  echo '<td valign="top" class="table-label">Total Number of Students</td>';
  echo '<td valign="top">' . $total . '</td>';
  echo '</tr>';

  echo '<tr><td colspan="2"></td></tr>';

  // Approval Status
  $sql = "SELECT
      MIN(field_ca1locked_value) AS alllocked1,
      MIN(field_ca2locked_value) AS alllocked2,
      MIN(field_ca3locked_value) AS alllocked3,
      MIN(field_ca4locked_value) AS alllocked4,
      MIN(field_examscorelocked_value) AS alllockede,
      MAX(field_ca1locked_value) AS anylocked1,
      MAX(field_ca2locked_value) AS anylocked2,
      MAX(field_ca3locked_value) AS anylocked3,
      MAX(field_ca4locked_value) AS anylocked4,
      MAX(field_examscorelocked_value) AS anylockede
    FROM {content_type_student_grades} sg, {content_type_course_instance} ci, {content_type_course} c
    WHERE
      sg.field_course_instance_nid=ci.nid AND
      c.field_code_value='%s' AND
      ci.field_sess_name_value='%s'
      $semesterwhere $locationwhere AND
      ci.field_course_id_nid=c.nid";
  $locksresult = db_query($sql, $coursecode, $session);
  $locks = db_fetch_object($locksresult);

  $sql = "SELECT DISTINCT
      d.field_college_id_nid AS college_id,
      c.field_department_nid_nid AS department_id,
      ci.field_lecturer_uid AS lecturer_uid,
      ci.field_lecturer_alternate_uid AS lecturer_alternate_uid,
      ci.field_repeat_value AS repeat
    FROM {content_type_department} d, {content_type_course} c, {content_type_course_instance} ci
    WHERE
      d.nid=c.field_department_nid_nid AND
      c.field_code_value='%s' AND
      c.nid=ci.field_course_id_nid AND
      ci.field_sess_name_value='%s'
      $semesterwhere $locationwhere";
  $staffresult = db_query($sql, $coursecode, $session);
  $staff = db_fetch_object($staffresult);

  $singlelecturer = TRUE;
  if (db_fetch_object($staffresult)) $singlelecturer = FALSE; // Found more records, so there are a number of course_instance(s) with different lecturers

  if (empty($staff->lecturer_uid)) $staff->lecturer_uid = 0;
  if (empty($staff->lecturer_alternate_uid)) $staff->lecturer_alternate_uid = 0;

  if ($staff->repeat) $number_of_ca = 0;

  if ($ca_approved_onebyone && $number_of_ca >= 1) {
    echo '<tr>';
    echo '<td valign="top" class="table-label">Continuous Assessment 1</td>';
    echo '<td valign="top">';
    if     ($locks->alllocked1 == 0) echo 'Not Submitted by Lecturer';
    elseif ($locks->alllocked1 == 1) echo 'All Submitted to HOD';
    elseif ($locks->alllocked1 >= 2) echo 'All Approved by HOD';
    echo '</td>';
    echo '</tr>';
  }

  if ($ca_approved_onebyone && $number_of_ca >= 2) {
    echo '<tr>';
    echo '<td valign="top" class="table-label">Continuous Assessment 2</td>';
    echo '<td valign="top">';
    if     ($locks->alllocked2 == 0) echo 'Not Submitted by Lecturer';
    elseif ($locks->alllocked2 == 1) echo 'All Submitted to HOD';
    elseif ($locks->alllocked2 >= 2) echo 'All Approved by HOD';
    echo '</td>';
    echo '</tr>';
  }

  if ($ca_approved_onebyone && $number_of_ca >= 3) {
    echo '<tr>';
    echo '<td valign="top" class="table-label">Continuous Assessment 3</td>';
    echo '<td valign="top">';
    if     ($locks->alllocked3 == 0) echo 'Not Submitted by Lecturer';
    elseif ($locks->alllocked3 == 1) echo 'All Submitted to HOD';
    elseif ($locks->alllocked3 >= 2) echo 'All Approved by HOD';
    echo '</td>';
    echo '</tr>';
  }

  if ($ca_approved_onebyone && $number_of_ca >= 4) {
    echo '<tr>';
    echo '<td valign="top" class="table-label">Continuous Assessment 4</td>';
    echo '<td valign="top">';
    if     ($locks->alllocked4 == 0) echo 'Not Submitted by Lecturer';
    elseif ($locks->alllocked4 == 1) echo 'All Submitted to HOD';
    elseif ($locks->alllocked4 >= 2) echo 'All Approved by HOD';
    echo '</td>';
    echo '</tr>';
  }
  echo '<tr>';
  echo '<td valign="top" class="table-label">Exam Score</td>';
  echo '<td valign="top">';
  if     ($locks->alllockede == 0) echo 'Not Submitted by Lecturer';
  elseif ($locks->alllockede == 1) echo 'All Submitted to HOD';
  elseif ($locks->alllockede == 2) echo 'All Submitted to Dean';
  elseif ($locks->alllockede == 3) echo 'All Submitted to Registrar';
  elseif ($locks->alllockede == 4) echo 'All Submitted to Vice Chancellor';
  elseif ($locks->alllockede == 5) echo 'All Approved by Vice Chancellor';
  echo '</td>';
  echo '</tr>';

  echo '</tbody></table>';

  $inroles = "'Head of Department', 'Department Examination Officer', 'Faculty Examination Officer', 'University Examination Officer'";

  $sql = "SELECT uid AS hod_uid
    FROM {eduerp_roles}
    WHERE (department_id=%d OR college_id=%d OR (department_id=0 AND college_id=0)) AND role IN ($inroles)";
  $hodresult = db_query($sql, $staff->department_id, $staff->college_id);
  $hod_uid = '';
  while ($hod = db_fetch_object($hodresult)) {
    if ($hod_uid === '') $hod_uid = $hod->hod_uid;
    else $hod_uid = $hod_uid . ',' . $hod->hod_uid;
  }
  if (empty($hod_uid)) $hod_uid = 0;

  global $eduerpapprovalform;
  $coursecodeenc = rawurlencode($coursecode);
  $sessionenc    = rawurlencode($session);
  $eduerpapprovalform->course_url = $base_url . "/course?coursecode={$coursecodeenc}&session={$sessionenc}&semester={$semester}&location={$location}";
  $eduerpapprovalform->lecturer_uid = $staff->lecturer_uid;
  $eduerpapprovalform->lecturer_alternate_uid = $staff->lecturer_alternate_uid;
  $eduerpapprovalform->hod_uid = $hod_uid;
  $eduerpapprovalform->coursecode = $coursecode;
  $eduerpapprovalform->session = $session;
  $eduerpapprovalform->semester = $semester;
  $eduerpapprovalform->location = $location;
  $eduerpapprovalform->number_of_ca = $number_of_ca;
  $eduerpapprovalform->ca_approved_onebyone = $ca_approved_onebyone;

  $inroles = "'Department Examination Officer', 'Faculty Examination Officer', 'University Examination Officer'";

  $sql = "SELECT uid AS lecturerequiv_uid
    FROM {eduerp_roles}
    WHERE (department_id=%d OR college_id=%d OR (department_id=0 AND college_id=0)) AND role IN ($inroles)";
  $lecturerequivresult = db_query($sql, $staff->department_id, $staff->college_id);

  $lecturerequiv_uid_array = array();
  while ($lecturerequiv = db_fetch_object($lecturerequivresult)) {
    $lecturerequiv_uid_array[] = $lecturerequiv->lecturerequiv_uid;
  }

  if (empty($hod_uid)) {
    echo 'THERE IS NO HEAD OF DEPARTMENT ASSIGNED FOR THIS DEPARTMENT, ONE MUST BE ASSIGNED';
  }
  elseif ($user->uid == $staff->lecturer_uid || $user->uid == $staff->lecturer_alternate_uid || in_array($user->uid, $lecturerequiv_uid_array)) {
    $showform = FALSE;
    if     ($ca_approved_onebyone && $number_of_ca >= 1 && $locks->alllocked1 == 0) {
      $eduerpapprovalform->fieldtoapprove = 'field_ca1locked_value';
      $eduerpapprovalform->gradestext = 'First set of Continuous Assessment Grades';
      $showform = TRUE;
    }
    elseif ($ca_approved_onebyone && $number_of_ca >= 2 && $locks->alllocked2 == 0) {
      $eduerpapprovalform->fieldtoapprove = 'field_ca2locked_value';
      $eduerpapprovalform->gradestext = 'Second set of Continuous Assessment Grades';
      $showform = TRUE;
    }
    elseif ($ca_approved_onebyone && $number_of_ca >= 3 && $locks->alllocked3 == 0) {
      $eduerpapprovalform->fieldtoapprove = 'field_ca3locked_value';
      $eduerpapprovalform->gradestext = 'Third set of Continuous Assessment Grades';
      $showform = TRUE;
    }
    elseif ($ca_approved_onebyone && $number_of_ca >= 4 && $locks->alllocked4 == 0) {
      $eduerpapprovalform->fieldtoapprove = 'field_ca4locked_value';
      $eduerpapprovalform->gradestext = 'Fourth set of Continuous Assessment Grades';
      $showform = TRUE;
    }
    elseif ($locks->alllockede == 0) {
      $eduerpapprovalform->fieldtoapprove = 'field_examscorelocked_value';
      $eduerpapprovalform->gradestext = 'Final Exam Grades';
      $showform = TRUE;
    }

    if ($showform) {
      if ($singlelecturer) {
        echo drupal_get_form('approve_grades_lecturer_form');
      }
      else {
        echo "YOU MUST CHOOSE A SPECIFIC LOCATION ABOVE IF YOU WANT TO APPROVE GRADES. CHOICES ARE...<br />";

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
          $lecturer_user = user_load($locationdetail->lecturer_uid);

          echo "Location: $locationdetail->location (Lecturer: $lecturer_user->profile_first_name ";
          if (!empty($lecturer_user->profile_middle_name)) echo $lecturer_user->profile_middle_name . ' ';
          echo "$lecturer_user->profile_last_name)<br />";
        }
      }
    }
  }

  $hod_uid_array = explode(',', $hod_uid);
  if (in_array($user->uid, $hod_uid_array)) {
    $showform = FALSE;
    if ($locks->anylockede && $locks->alllockede < 5) {
      $eduerpapprovalform->fieldtoapprovehod = 'field_examscorelocked_value';
      $eduerpapprovalform->gradestexthod = 'Final Exam Grades';
      $showform = TRUE;
    }
    elseif ($ca_approved_onebyone && $number_of_ca >= 4 && $locks->anylocked4 && $locks->alllocked4 < 5) {
      $eduerpapprovalform->fieldtoapprovehod = 'field_ca4locked_value';
      $eduerpapprovalform->gradestexthod = 'Fourth set of Continuous Assessment Grades';
      $showform = TRUE;
    }
    elseif ($ca_approved_onebyone && $number_of_ca >= 3 && $locks->anylocked3 && $locks->alllocked3 < 5) {
      $eduerpapprovalform->fieldtoapprovehod = 'field_ca3locked_value';
      $eduerpapprovalform->gradestexthod = 'Third set of Continuous Assessment Grades';
      $showform = TRUE;
    }
    elseif ($ca_approved_onebyone && $number_of_ca >= 2 && $locks->anylocked2 && $locks->alllocked2 < 5) {
      $eduerpapprovalform->fieldtoapprovehod = 'field_ca2locked_value';
      $eduerpapprovalform->gradestexthod = 'Second set of Continuous Assessment Grades';
      $showform = TRUE;
    }
    elseif ($ca_approved_onebyone && $number_of_ca >= 1 && $locks->anylocked1 && $locks->alllocked1 < 5) {
      $eduerpapprovalform->fieldtoapprovehod = 'field_ca1locked_value';
      $eduerpapprovalform->gradestexthod = 'First set of Continuous Assessment Grades';
      $showform = TRUE;
    }

    if ($showform) {
      if ($singlelecturer) {
        echo drupal_get_form('unlock_grades_hod_form');
      }
      else {
        echo "YOU MUST CHOOSE A SPECIFIC LOCATION ABOVE IF YOU WANT TO UNLOCK GRADES. CHOICES ARE...<br />";

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
          $lecturer_user = user_load($locationdetail->lecturer_uid);

          echo "Location: $locationdetail->location (Lecturer: $lecturer_user->profile_first_name ";
          if (!empty($lecturer_user->profile_middle_name)) echo $lecturer_user->profile_middle_name . ' ';
          echo "$lecturer_user->profile_last_name)<br />";
        }
      }
    }
  }
}


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


function approve_grades_lecturer_form_validate($form, &$form_state) {
  if (empty($form_state['values']['comment'])) {
    form_set_error('comment', 'You must enter a comment for the Head of Department!');
  }
}


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

  if ($semester === 'All') $semesterwhere = '';
  else $semesterwhere = 'AND ci.field_semester_name_value=' . (int)$semester;

  if ($location === 'All') $locationwhere = '';
  else $locationwhere = 'AND ci.field_location_value=' . (int)$location;

  // Don't allow an exam score approved by the VC to be changed
  if ($fieldtoapprove === 'field_examscorelocked_value') $protectVC = 'AND sg.field_examscorelocked_value < 5';
  else $protectVC = '';

  if ($ca_approved_onebyone) {
    $setstatement = "SET sg.`{$fieldtoapprove}`='1'";
  }
  else { // Approve CAs along with exam
    $setstatement = "
      SET sg.`field_ca1locked_value`='1',
      SET sg.`field_ca2locked_value`='1',
      SET sg.`field_ca3locked_value`='1',
      SET sg.`field_ca4locked_value`='1',
      SET sg.`field_examscorelocked_value`='1'";
  }

  $sql = "UPDATE {content_type_student_grades} sg, {content_type_course_instance} ci, {content_type_course} c
    $setstatement
    WHERE
      sg.field_course_instance_nid=ci.nid AND
      ci.field_course_id_nid=c.nid AND
      ci.field_sess_name_value='%s' $semesterwhere $locationwhere AND
      c.field_code_value='%s'
      $protectVC";
  db_query($sql, $session, $coursecode);

  $sql = "SELECT
      c.field_level_value AS level,
      ci.field_semester_name_value AS sem,
      ci.field_location_value AS loc,
      d.field_department_name_value AS department,
      co.field_college_name_value AS college
    FROM {content_type_course_instance} ci, {content_type_course} c, {content_department_course} d, {content_type_college} co
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
    $level = $collegerow->level;
    $sem = $collegerow->sem;
    $loc =  $collegerow->loc;
    $department = $collegerow->department;
    $college = $collegerow->college;
  }
  else {
    $level = '';
    $sem = '';
    $loc = '';
    $department = '';
    $college = '';
  }

  profile_load_profile($user);

  $name = '';
  if (!empty($user->profile_first_name) && !empty($user->profile_last_name)) {
    $middle = '';
    if (!empty($user->profile_middle_name)) $middle = $user->profile_middle_name . ' ';
    $name = "$user->profile_first_name {$middle}$user->profile_last_name";
  }

  $firsttime = TRUE;
  $hod_uid_array = explode(',', $hod_uid);
  foreach ($hod_uid_array as $hod_uid_i) {

    if (!empty($hod_uid_i)) $destination_user = user_load($hod_uid_i);
    else $destination_user = NULL;

    $subject = "$gradestext for $coursecode Approved by $name";

    $body = '';
    if (!empty($destination_user->profile_first_name) && !empty($destination_user->profile_last_name)) {
      $middle = '';
      if (!empty($destination_user->profile_middle_name)) $middle = $destination_user->profile_middle_name . ' ';
      $body .= "Dear $destination_user->profile_first_name {$middle}$destination_user->profile_last_name,\n\n";
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
      $node->status                          = 1;
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


function unlock_grades_hod_form_validate($form, &$form_state) {
  if (empty($form_state['values']['comment'])) {
    form_set_error('comment', 'You must enter a comment for the Lecturer!');
  }
}


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
  $gradestext        = $form_state['values']['gradestexthod'];

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
    $setstatement = "
      SET sg.`field_ca1locked_value`='0',
      SET sg.`field_ca2locked_value`='0',
      SET sg.`field_ca3locked_value`='0',
      SET sg.`field_ca4locked_value`='0',
      SET sg.`field_examscorelocked_value`='0'";
  }

  $sql = "UPDATE {content_type_student_grades} sg, {content_type_course_instance} ci, {content_type_course} c
    $setstatement
    WHERE
      sg.field_course_instance_nid=ci.nid AND
      ci.field_course_id_nid=c.nid AND
      ci.field_sess_name_value='%s' $semesterwhere $locationwhere AND
      c.field_code_value='%s'
      $protectVC";
  db_query($sql, $session, $coursecode);

  $sql = "SELECT
      c.field_level_value AS level,
      ci.field_semester_name_value AS sem,
      ci.field_location_value AS loc,
      d.field_department_name_value AS department,
      co.field_college_name_value AS college
    FROM {content_type_course_instance} ci, {content_type_course} c, {content_department_course} d, {content_type_college} co
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
    $level = $collegerow->level;
    $sem = $collegerow->sem;
    $loc = $collegerow->loc;
    $department = $collegerow->department;
    $college = $collegerow->college;
  }
  else {
    $level = '';
    $sem = '';
    $loc = '';
    $department = '';
    $college = '';
  }

  profile_load_profile($user);

  $name = '';
  if (!empty($user->profile_first_name) && !empty($user->profile_last_name)) {
    $middle = '';
    if (!empty($user->profile_middle_name)) $middle = $user->profile_middle_name . ' ';
    $name = "$user->profile_first_name {$middle}$user->profile_last_name";
  }

  if (!empty($lecturer_uid)) $destination_user = user_load($lecturer_uid);

  $subject = "$gradestext for $coursecode Unlocked by $name";

  $body = '';
  if (!empty($destination_user->profile_first_name) && !empty($destination_user->profile_last_name)) {
    $middle = '';
    if (!empty($destination_user->profile_middle_name)) $middle = $destination_user->profile_middle_name . ' ';
    $body .= "Dear $destination_user->profile_first_name {$middle}$destination_user->profile_last_name,\n\n";
  }

  $body .= "I have unlocked $gradestext for $coursecode\n\n";
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
  $node->status                          = 1;
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
  $node->field_what_approved[0]['value'] = $gradestext;
  $node->field_action[0]['value']        = 'Unlocked by Head of Department';
  node_save($node);

  if (!empty($destination_user)) {
    $message = drupal_mail('grading', 'approval', $destination_user->mail, language_default(), array(), $user->mail, FALSE);
    $message['subject'] = $subject;
    $message['body'] = $body;
    drupal_mail_send($message);
  }

  if (!empty($lecturer_alternate_uid)) $destination_user = user_load($lecturer_alternate_uid);
  else $destination_user = NULL;

  $subject = "$gradestext for $coursecode Unlocked by $name";

  $body = '';
  if (!empty($destination_user->profile_first_name) && !empty($destination_user->profile_last_name)) {
    $middle = '';
    if (!empty($destination_user->profile_middle_name)) $middle = $destination_user->profile_middle_name . ' ';
    $body .= "Dear $destination_user->profile_first_name {$middle}$destination_user->profile_last_name,\n\n";
  }

  $body .= "I have unlocked $gradestext for $coursecode\n\n";
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
?>