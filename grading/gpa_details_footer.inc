<?php
// Footer for gpa_details View 20100304

global $base_url;

if (!empty($_SESSION['views']['gpa_details']['default']['programme']) &&
    !empty($_SESSION['views']['gpa_details']['default']['level']) &&
    !empty($_SESSION['views']['gpa_details']['default']['session']) &&
    !empty($_SESSION['views']['gpa_details']['default']['semester'])) {
  $programme  = $_SESSION['views']['gpa_details']['default']['programme'];
  $level      = $_SESSION['views']['gpa_details']['default']['level'];
  $session    = $_SESSION['views']['gpa_details']['default']['session'];
  $semester   = $_SESSION['views']['gpa_details']['default']['semester'];

  $sql = "SELECT DISTINCT c.field_code_value AS coursecode, ci.field_sess_name_value AS session, ci.field_semester_name_value AS semester
    FROM {content_type_course_instance} ci, {content_type_course} c, {content_type_student_grades} sg, {content_type_student_gpa} gpa, {content_type_program} p
    WHERE
      ci.nid=sg.field_course_instance_nid AND
      ci.field_course_id_nid=c.nid AND
      sg.field_student_gpa_nid=gpa.nid AND
      gpa.field_level_name_gpa_value='%s' AND
      gpa.field_sess_name_gpa_value='%s' AND
      gpa.field_semester_name_gpa_value='%s' AND
      gpa.field_program_ref_gpa_nid=p.nid AND
      p.field_programme_name_value='%s'
    ORDER BY coursecode ASC";

  $courserows = db_query($sql, $level, $session, $semester, $programme);

  $first = true;
  while ($courserow = db_fetch_object($courserows)) {
    if ($first) {
      echo '<table class="body-table"><tbody>';
      echo '<tr><th valign="top" class="table-label">Click on a course below to see details</th></tr>';
      $first = false;
    }

    $coursecodeenc = rawurlencode($courserow->coursecode);
    $sessionenc    = rawurlencode($courserow->session);
    echo '<tr><td><a href="' . $base_url . "/course?coursecode={$coursecodeenc}&session={$sessionenc}&semester={$courserow->semester}&location=All" . '">' . $courserow->coursecode . '</a></td></tr>';
  }

  if (!$first) echo '</tbody></table>';
}
?>