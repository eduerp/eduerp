<?php
// computed.inc Alan Barrett 20090724
// Grade calculations


function calctotal($exam, $ca1, $ca2, $ca3, $ca4, $course_instance_nid) {
  static $repeatbycinid = array(); // Cache

  if (!isset($repeatbycinid[$course_instance_nid])) {

    $sql = "SELECT field_repeat_value FROM {content_type_course_instance} WHERE nid={$course_instance_nid} LIMIT 1";
    $repeats = db_query($sql);
    $repeat = db_fetch_object($repeats);

    $repeatbycinid[$course_instance_nid] = $repeat->field_repeat_value;
  }

  if ($repeatbycinid[$course_instance_nid]) { // This is a repeat exam with no CA
    $total = (int)$exam;
  }
  else {
    //$total = ($exam*60 + $ca1*10 + $ca2*10 + $ca3*10 + $ca4*10)/100.0;
    $total = $exam + $ca1 + $ca2 + $ca3 + $ca4;
    $total = (int)$total;
  }

  return $total;
}


function grade_total($exam, $ca1, $ca2, $ca3, $ca4, $uid, $course_instance_nid, $examscorelocked, $field_name = NULL) {

  if ((!isset($field_name) || !($field_name === 'field_exam_score')) &&  ($exam == 0)) return '-';

  return (string)calctotal($exam, $ca1, $ca2, $ca3, $ca4, $course_instance_nid);
}


function grade_gradepoint($exam, $ca1, $ca2, $ca3, $ca4, $uid, $course_instance_nid, $examscorelocked, $field_name = NULL) {

  if ((!isset($field_name) || !($field_name === 'field_exam_score')) &&  ($exam == 0)) return '-';

  $total = calctotal($exam, $ca1, $ca2, $ca3, $ca4, $course_instance_nid);

  if ($total >= 70) $gp = 5;
  elseif ($total >= 60) $gp = 4;
  elseif ($total >= 50) $gp = 3;
  elseif ($total >= 45) $gp = 2;
  elseif ($total >= 40) $gp = 1;
  else $gp = 0;

  updatestudentgpa($gp, $uid, $course_instance_nid, $examscorelocked, $field_name);

  return (string)$gp;
}


function grade_grade($exam, $ca1, $ca2, $ca3, $ca4, $uid, $course_instance_nid, $examscorelocked, $field_name = NULL) {

  if ((!isset($field_name) || !($field_name === 'field_exam_score')) &&  ($exam == 0)) return '-';

  $total = (int)grade_gradepoint($exam, $ca1, $ca2, $ca3, $ca4, $uid, $course_instance_nid, $field_name);
  if ($total === 5) return 'A';
  if ($total === 4) return 'B';
  if ($total === 3) return 'C';
  if ($total === 2) return 'D';
  if ($total === 1) return 'E';
  return 'F';
}


function updatestudentgpa($gp, $uid, $course_instance_nid, $examscorelocked, $field_name = NULL) {
  global $user;
  global $base_url;

  if (!empty($uid) && !empty($course_instance_nid)) {

    if     ($gp === 5) $grade = 'A';
    elseif ($gp === 4) $grade = 'B';
    elseif ($gp === 3) $grade = 'C';
    elseif ($gp === 2) $grade = 'D';
    elseif ($gp === 1) $grade = 'E';
    else               $grade = 'F';

    $sql = "UPDATE {content_type_student_grades} sg SET sg.field_grade_value='{$grade}', sg.field_gradepoint_value='{$gp}'
      WHERE sg.field_mat_no_uid={$uid} AND sg.field_course_instance_nid={$course_instance_nid}";
    db_query($sql);

    if ($examscorelocked > 0 && !empty($field_name)) { // This means that GPA/cGPA has already been calculated, so need to redo (only an examination officer could have submitted this change)

      // Set the GPA for this student (code below here is based on code in course_grades_footer, but is simplified to deal with a single student and a specific course_instance)
      $sql = "UPDATE
        {content_type_student_gpa} gpa,
        (
          SELECT
            exams.field_mat_no_uid AS uid,
            SUM(exams.gradepoint) AS gradepoints,
            SUM(exams.field_creditload_value) AS totalload,
            exams.field_sess_name_value AS session,
            exams.field_semester_name_value AS semester
          FROM (
            SELECT
              IF(sg.field_gradepoint_value='-', 0, sg.field_gradepoint_value) AS gradepoint,
              sg.field_mat_no_uid,
              c.field_creditload_value,
              ci0.field_sess_name_value,
              ci0.field_semester_name_value
            FROM
              {content_type_student_grades} sg,
              {content_type_course_instance} ci,
              {content_type_course} c,
              {content_type_course_instance} ci0
            WHERE
              sg.field_mat_no_uid={$uid}
              sg.field_course_instance_nid=ci.nid AND
              sg.field_examscorelocked_value>0 AND
              sg.field_dropped_value=0 AND
              ci.field_course_id_nid=c.nid AND
              ci.field_sess_name_value=ci0.field_sess_name_value AND
              ci.field_semester_name_value=ci0.field_semester_name_value AND
              ci.field_repeat_value=0 AND
              ci0.nid={$course_instance_nid}
            ) AS exams
          GROUP BY exams.field_mat_no_uid
        ) AS gpatoset
      SET
        gpa.field_gptotal_value=gpatoset.gradepoints,
        gpa.field_credit_load_completed_value=gpatoset.totalload,
        gpa.field_gpa_value=FORMAT(IF(gpatoset.totalload=0, 0, gpatoset.gradepoints/gpatoset.totalload), 2)
      WHERE
        gpa.field_student_ref_gpa_uid=gpatoset.uid AND
        gpa.field_sess_name_gpa_value=gpatoset.session AND
        gpa.field_semester_name_gpa_value=gpatoset.semester";
      db_query($sql);

      // Set the cGPA for this student
      // ... Finds the grade for the most recent sitting of each course
      // ... Sums them and saves result in the student_program found from the students's profile
      $sql = "UPDATE
        {content_type_student_program} sp,
        {profile_fields} pf1,
        {profile_values} pv1,
        (
          SELECT
            exams.field_mat_no_uid AS uid,
            SUM(exams.gradepoint) AS gradepoints,
            SUM(exams.field_creditload_value) AS totalload
          FROM (
            SELECT
              IF(sg.field_gradepoint_value='-', 0, sg.field_gradepoint_value) AS gradepoint,
              sg.field_mat_no_uid,
              CONCAT(ci.field_sess_name_value, ci.field_semester_name_value, sg.nid) AS sess_sem,
              c.field_code_value,
              c.field_creditload_value
            FROM
              {content_type_student_grades} sg,
              {content_type_course_instance} ci,
              {content_type_course} c,
              {program_course} pc,
              {profile_fields} pf,
              {profile_values} pv
            WHERE
              sg.field_mat_no_uid={$uid}
              sg.field_course_instance_nid=ci.nid AND
              sg.field_examscorelocked_value>0 AND
              sg.field_dropped_value=0 AND
              ci.field_course_id_nid=c.nid AND
              ci.field_course_id_nid=pc.course_id AND
              pc.programme_id=pv.value AND
              pf.name='profile_first_choice' AND
              pf.fid=pv.fid AND
              pv.uid=sg.field_mat_no_uid
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
              {profile_fields} pf0,
              {profile_values} pv0
            WHERE
              sg0.field_mat_no_uid={$uid}
              sg0.field_course_instance_nid=ci0.nid AND
              sg0.field_examscorelocked_value>0 AND
              sg0.field_dropped_value=0 AND
              ci0.field_course_id_nid=c0.nid AND
              ci0.field_course_id_nid=pc0.course_id AND
              pc0.programme_id=pv0.value AND
              pf0.name='profile_first_choice' AND
              pf0.fid=pv0.fid AND
              pv0.uid=sg0.field_mat_no_uid
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
        sp.field_cgpa_sp_value=FORMAT(IF(cgpatoset.totalload=0, 0, cgpatoset.gradepoints/cgpatoset.totalload), 2)
      WHERE
        sp.field_student_ref_sp_uid=cgpatoset.uid AND
        sp.field_program_ref_sp_nid=pv.value AND
        pf1.name='profile_first_choice' AND
        pf1.fid=pv.fid AND
        pv1.uid=cgpatoset.uid";
      db_query($sql);

      // Find the fields for the approval record
      $sql = "SELECT
          ci.field_sess_name_value AS session,
          ci.field_semester_name_value AS sem,
          ci.field_location_value AS loc,
          c.field_code_value AS coursecode,
          c.field_level_value AS level,
          d.field_department_name_value AS department,
          co.field_college_name_value AS college
        FROM {content_type_course_instance} ci, {content_type_course} c, {content_type_department} d, {content_type_college} co
        WHERE
          ci.nid=%d AND
          ci.field_course_id_nid=c.nid AND
          c.field_department_nid_nid=d.nid AND
          d.field_college_id_nid=co.nid
        LIMIT 1";
      $approvalresult = db_query($sql, $course_instance_nid);
      $approvalrow = db_fetch_object($approvalresult);
      $session = $approvalrow->session;
      $sem = $approvalrow->sem;
      $loc = $approvalrow->loc;
      $coursecode = $approvalrow->coursecode;
      $level = $approvalrow->level;
      $department = $approvalrow->department;
      $college = $approvalrow->college;

      profile_load_profile($user);
      $name = '';
      if (!empty($user->profile_first_name) && !empty($user->profile_last_name)) {
        $middle = '';
        if (!empty($user->profile_middle_name)) $middle = $user->profile_middle_name . ' ';
        $name = "$user->profile_first_name {$middle}$user->profile_last_name";
      }

      $student_user = user_load($uid);
      $studentname = '';
      if (!empty($student_user->profile_first_name) && !empty($student_user->profile_last_name)) {
        $middle = '';
        if (!empty($student_user->profile_middle_name)) $middle = $student_user->profile_middle_name . ' ';
        $studentname = "$student_user->profile_first_name {$middle}$student_user->profile_last_name";
      }

      $gradestexts = array(
        'field_ca1' => 'First Continuous Assessment Grade',
        'field_ca2' => 'Second Continuous Assessment Grade',
        'field_ca3' => 'Third Continuous Assessment Grade',
        'field_ca4' => 'Fourth Continuous Assessment Grade',
        'field_exam_score' => 'Final Exam Grade');
      $gradestext = $gradestexts[$field_name];
      $subject = "$gradestext for $coursecode for student '$studentname' Changed by $name";

      $coursecodeenc = rawurlencode($coursecode);
      $sessionenc    = rawurlencode($session);
      $course_url = $base_url . "/course?coursecode={$coursecodeenc}&session={$sessionenc}&semester={$sem}&location={$loc}";

      $node = new stdClass();
      $node->type                            = 'approval';
      $node->uid                             = 1;
      $node->status                          = 1;
      $node->promote                         = 0;
      $node->sticky                          = 0;
      $node->comment                         = 0;
      $node->title                           = $subject;
      $node->body                            = '';
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
      $node->field_what_approved[0]['value'] = $gradestext;
      $node->field_action[0]['value']        = 'Changed by Examination Officer';
      node_save($node);
    }
  }
}
?>
