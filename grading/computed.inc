<?php
// computed.inc Alan Barrett 20090724
// Grade calculations


function calctotal($exam, $ca1, $ca2, $ca3, $ca4) {
  $total = ($exam*60 + $ca1*10 + $ca2*10 + $ca3*10 + $ca4*10)/100.0;
  $total = (int)$total;
  return $total;
}


function grade_total($exam, $ca1, $ca2, $ca3, $ca4, $uid, $course_instance_nid, $field_name = NULL) {

  if ((!isset($field_name) || !($field_name === 'field_exam_score')) &&  ($exam === '-')) return '-';

  return (string)calctotal($exam, $ca1, $ca2, $ca3, $ca4);
}


function grade_gradepoint($exam, $ca1, $ca2, $ca3, $ca4, $uid, $course_instance_nid, $field_name = NULL) {

  if ((!isset($field_name) || !($field_name === 'field_exam_score')) &&  ($exam === '-')) return '-';

  $total = calctotal($exam, $ca1, $ca2, $ca3, $ca4);
  if ($total >= 70) $gp = 5;
  elseif ($total >= 60) $gp = 4;
  elseif ($total >= 50) $gp = 3;
  elseif ($total >= 45) $gp = 2;
  elseif ($total >= 40) $gp = 1;
  else $gp = 0;

  updatestudentgpa($gp, $uid, $course_instance_nid);

  return (string)$gp;
}


function grade_grade($exam, $ca1, $ca2, $ca3, $ca4, $uid, $course_instance_nid, $field_name = NULL) {

  if ((!isset($field_name) || !($field_name === 'field_exam_score')) &&  ($exam === '-')) return '-';

  $total = (int)grade_gradepoint($exam, $ca1, $ca2, $ca3, $ca4, $uid, $course_instance_nid, $field_name);
  if ($total === 5) return 'A';
  if ($total === 4) return 'B';
  if ($total === 3) return 'C';
  if ($total === 2) return 'D';
  if ($total === 1) return 'E';
  return 'F';
}


function updatestudentgpa($gp, $uid, $course_instance_nid) {
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


    $sql = "SELECT sg.field_gradepoint_value, ci.field_credit_load_value
      FROM {content_type_student_grades} sg, {content_type_course_instance} ci, {content_type_course_instance} ci0
      WHERE sg.field_mat_no_uid={$uid} AND
        sg.field_course_instance_nid=ci.nid AND
        ci.field_session_id_value=ci0.field_session_id_value AND
        ci.field_semester_id_value=ci0.field_semester_id_value AND
        ci0.nid={$course_instance_nid}";

    $studentgrades = db_query($sql);
    $missinggrades = 0;
    $gpa = 0.0;
    $load = 0;
    while ($studentgrade = db_fetch_object($studentgrades)) {
      if ($studentgrade->field_gradepoint_value === '-') {
        $missinggrades++;
      }
      else {
        $gpa += $studentgrade->field_gradepoint_value * $studentgrade->field_credit_load_value;
        $load += $studentgrade->field_credit_load_value;
      }
    }

    $sql = "UPDATE {student_gpa} gpa, {content_type_course_instance} ci SET gpa.field_credit_load_completed_value={$load}
      WHERE field_student_ref_gpa_uid={$uid} AND
        gpa.field_session_id_gpa_value=ci.field_session_id_value AND
        gpa.field_semester_id_gpa_value=ci.field_semester_id_value AND
        ci.nid={$course_instance_nid}";
    db_query($sql);

    if (!$missinggrades && $load > 0.0) {
      $gpa = $gpa / $load;
      $gpa = number_format($gpa, 2);

      $sql = "UPDATE {student_gpa} gpa, {content_type_course_instance} ci SET gpa.field_gpa_value={$gpa}
        WHERE gpa.field_student_ref_gpa_uid={$uid} AND
          gpa.field_session_id_gpa_value=ci.field_session_id_value AND
          gpa.field_semester_id_gpa_value=ci.field_semester_id_value AND
          ci.nid={$course_instance_nid}";
      db_query($sql);

      $sql = "SELECT gpa.field_gpa_value FROM {student_gpa} gpa
        WHERE gpa.field_student_ref_gpa_uid={$uid}";
      $semestergpas = db_query($sql);
      $cgpa = 0.0;
      $countsemesters = 0;
      while ($semestergpa = db_fetch_object($semestergpas)) {
        if ($semestergpa->field_gpa_value != '-') {
          $cgpa += (float)$semestergpa->field_gpa_value;
          $countsemesters++;
        }
      }

      if ($countsemesters) {
        $cgpa = $cgpa / $countsemesters;
        $cgpa = number_format($cgpa, 2);
        $sql = "UPDATE {student_gpa} gpa, {content_type_course_instance} ci SET gpa.field_cgpa_value={$cgpa}
          WHERE gpa.field_student_ref_gpa_uid={$uid} AND
            gpa.field_session_id_gpa_value=ci.field_session_id_value AND
            gpa.field_semester_id_gpa_value=ci.field_semester_id_value AND
            ci.nid={$course_instance_nid}";
        db_query($sql);
      }
    }
  }
}
?>
