<?php
// Footer for gpa View 20100304

global $user;
global $base_url;

if (!empty($_SESSION['views']['gpa']['default']['programme']) &&
    !empty($_SESSION['views']['gpa']['default']['level']) &&
    !empty($_SESSION['views']['gpa']['default']['session']) &&
    !empty($_SESSION['views']['gpa']['default']['semester'])) {
  $programme  = $_SESSION['views']['gpa']['default']['programme'];
  $level      = $_SESSION['views']['gpa']['default']['level'];
  $session    = $_SESSION['views']['gpa']['default']['session'];
  $semester   = $_SESSION['views']['gpa']['default']['semester'];

  // Display statistics on exams completed
  $sql = "SELECT
    COUNT(*) AS number_students,
    SUM(fully) AS sumfully,
    SUM(part) AS sumpart,
    SUM(none) AS sumnone,
    MIN(ca1l) AS ca1locked,
    MIN(ca2l) AS ca2locked,
    MIN(ca3l) AS ca3locked,
    MIN(ca4l) AS ca4locked,
    MIN(examl) AS examlocked
  FROM
    (
      SELECT
        BIT_AND(sg.field_exam_score_value > 0) AS fully,
        BIT_OR(sg.field_exam_score_value > 0) AS part,
        BIT_AND(sg.field_exam_score_value = 0) AS none,
        MIN(sg.field_ca1locked_value) AS ca1l,
        MIN(sg.field_ca2locked_value) AS ca2l,
        MIN(sg.field_ca3locked_value) AS ca3l,
        MIN(sg.field_ca4locked_value) AS ca4l,
        MIN(sg.field_examscorelocked_value) AS examl
      FROM {content_type_student_grades} sg, {content_type_student_gpa} gpa, {content_type_program} p
      WHERE
        sg.field_student_gpa_nid=gpa.nid AND
        sg.field_dropped_value=0 AND
        gpa.field_level_name_gpa_value='%s' AND
        gpa.field_sess_name_gpa_value='%s' AND
        gpa.field_semester_name_gpa_value='%s' AND
        gpa.field_program_ref_gpa_nid=p.nid AND
        p.field_programme_name_value='%s'
      GROUP BY sg.field_mat_no_uid
    ) AS eachstudent";

  $summaryrows = db_query($sql, $level, $session, $semester, $programme);
  $summaryrow = db_fetch_object($summaryrows);

  echo '<table class="body-table"><tbody>';
  echo '<tr><th valign="top" class="table-label" colspan="2">RESULTS SUMMARY</th></tr>';

  echo '<tr>';
  echo '<td valign="top" class="table-label">Total No. of Registered Students</td>';
  echo '<td valign="top">' . $summaryrow->number_students . '</td>';
  echo '</tr>';

  echo '<tr>';
  echo '<td valign="top" class="table-label">No. of Students that Completed Exams</td>';
  echo '<td valign="top">' . $summaryrow->sumfully . '</td>';
  echo '</tr>';

  echo '<tr>';
  echo '<td valign="top" class="table-label">No. of Students that Partially Completed Exams</td>';
  echo '<td valign="top">' . ($summaryrow->sumpart - $summaryrow->sumfully) . '</td>';
  echo '</tr>';

  echo '<tr>';
  echo '<td valign="top" class="table-label">Number of Absent Students</td>';
  echo '<td valign="top">' . $summaryrow->sumnone . '</td>';
  echo '</tr>';

  $programmeenc = rawurlencode($programme);
  $sessionenc = rawurlencode($session);
  echo '<tr><td colspan="2"><a href="' . $base_url . "/gpa_details?programme={$programmeenc}&level={$level}&session={$sessionenc}&semester={$semester}" . '">SHOW DETAILS</a></td></tr>';

  echo '<tr><td colspan="2"></td></tr>';

  if     ($summaryrow->examlocked == 0) echo '<tr><td colspan="2">Waiting on some Lecturer Submissions for Semester Exam</td></tr>';
  elseif ($summaryrow->examlocked == 1) echo '<tr><td colspan="2">All Lecturers have Submitted Semester Exam Results</td></tr>';
  elseif ($summaryrow->examlocked == 2) echo '<tr><td colspan="2">All Departments have Approved Semester Exam Results</td></tr>';
  elseif ($summaryrow->examlocked == 3) echo '<tr><td colspan="2">All Faculties have Approved Semester Exam Results</td></tr>';
  elseif ($summaryrow->examlocked == 4) echo '<tr><td colspan="2">Registrar has Approved Semester Exam Results</td></tr>';
  elseif ($summaryrow->examlocked == 5) echo '<tr><td colspan="2">Semester Exam Results Fully Approved</td></tr>';

  echo '</tbody></table>';
}
?>
