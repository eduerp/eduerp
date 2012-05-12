<?php
/**
 * Footer for student View 20111004
 */

global $user;

// Find data for this student (copied & simplified from staff.module Student Progress)
$sql = "SELECT
      sp.field_student_ref_sp_uid AS uid,
      u.name AS mat,
      sp.field_cgpaforstudent_sp_value,
      sp.field_credit_load_completed_sp_value,
      p.field_min_credit_load_program_value,
      SUBSTRING(spro.field_profile_reg_session_value, 1, 4) - spro.field_profile_yearofentry_value + 1 AS elapsed_years,
      p.field_duration_value,
      p.field_max_duration_value,
      CONCAT(pro.field_profile_last_name_value, ', ', pro.field_profile_first_name_value, ' ', IFNULL(pro.field_profile_middle_name_value, '')) AS student_name, pro.nid student_key,
      spro.field_profile_mode_of_entry_value
    FROM {content_type_student_program} sp
    INNER JOIN {node} npro ON sp.field_student_ref_sp_uid=npro.uid AND npro.type='profile'
    INNER JOIN {content_type_profile} pro ON npro.vid=pro.vid
    INNER JOIN {node} nspro ON npro.uid=nspro.uid AND nspro.type='student_profile'
    INNER JOIN {content_type_student_profile} spro ON nspro.vid=spro.vid
    INNER JOIN {content_type_program} p
    INNER JOIN {users} u ON sp.field_student_ref_sp_uid=u.uid
    WHERE
      sp.field_student_ref_sp_uid=%d AND
      sp.field_program_ref_sp_nid=spro.field_profile_first_choice_nid AND
      sp.field_program_ref_sp_nid=p.nid";
$result = db_query($sql, $user->uid);
$cgpa = db_fetch_object($result);

// Find any failed (and not since passed) courses for this student (copied & simplified from staff.module Student Progress)
$sql = "SELECT
    failedcourses.uid,
    failedcourses.failedlist,
    CONCAT(pro.field_profile_last_name_value, ', ', pro.field_profile_first_name_value, ' ', IFNULL(pro.field_profile_middle_name_value, '')) AS student_name, pro.nid student_key
  FROM
    (
      SELECT
        exams.field_mat_no_uid AS uid,
        GROUP_CONCAT(exams.field_code_value SEPARATOR ', ') AS failedlist
      FROM (
        SELECT DISTINCT
          IF(sg.field_gradepoint_value='-', 0, sg.field_gradepoint_value) AS gradepoint,
          sg.field_mat_no_uid,
          CONCAT(ci.field_sess_name_value, ci.field_semester_name_value, sg.nid) AS sess_sem,
          c.field_code_value
        FROM
          {content_type_student_grades} sg,
          {content_type_course_instance} ci,
          {content_type_course} c,
          {program_course} pc,
          {node} nspro,
          {content_type_student_profile} spro
        WHERE
          sg.field_mat_no_uid=%d AND
          sg.field_course_instance_nid=ci.nid AND
          sg.field_examscorelocked_value>4 AND
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
          sg0.field_mat_no_uid=%d AND
          sg0.field_course_instance_nid=ci0.nid AND
          sg0.field_examscorelocked_value>4 AND
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
        exams.field_mat_no_uid=most_recent_exam.field_mat_no_uid AND
        exams.gradepoint=0
      GROUP BY exams.field_mat_no_uid
      ORDER BY exams.field_code_value
    ) AS failedcourses
  INNER JOIN {node} npro ON failedcourses.uid=npro.uid AND npro.type='profile'
  INNER JOIN {content_type_profile} pro ON npro.vid=pro.vid";
$result = db_query($sql, $user->uid, $user->uid);
$failed = db_fetch_object($result);

echo '<table class="body-table"><tbody>';
echo '<tr><td valign="top" class="table-label">cGPA                     </td><td valign="top">' . $cgpa->field_cgpaforstudent_sp_value        . '</td></tr>';
echo '<tr><td valign="top" class="table-label">Total Credit Units Taken </td><td valign="top">' . $cgpa->field_credit_load_completed_sp_value . '</td></tr>';
echo '<tr><td valign="top" class="table-label">Total Units Required     </td><td valign="top">' . $cgpa->field_min_credit_load_program_value  . '</td></tr>';
echo '<tr><td valign="top" class="table-label">Failed Course(s)         </td><td valign="top">' . $failed->failedlist                         . '</td></tr>';
echo '<tr><td valign="top" class="table-label">Years since Student Start</td><td valign="top">' . $cgpa->elapsed_years                        . '</td></tr>';
echo '<tr><td valign="top" class="table-label">Programme Duration       </td><td valign="top">' . $cgpa->field_duration_value                 . '</td></tr>';
echo '<tr><td valign="top" class="table-label">Maximum Semesters allowed</td><td valign="top">' . $cgpa->field_max_duration_value             . '</td></tr>';
echo '</tbody></table>';
?>