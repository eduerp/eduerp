<?php
/**
 * Footer for list_students View 20120326
 */

if (!empty($_SESSION['views']['list_students']['default']['rid']) && empty($_SESSION['views']['list_students']['default']['uid'])) {

  $rid = $_SESSION['views']['list_students']['default']['rid'];
  $where = "WHERE users_roles.rid={$rid}";

  if (!empty($_SESSION['views']['list_students']['default']['yearofentry'])) {
    $yearofentry = $_SESSION['views']['list_students']['default']['yearofentry'];
    $yearofentry = addslashes($yearofentry);
    if ($yearofentry !== 'All') $where .= " AND node_users_1_node_data_field_profile_yearofentry.field_profile_yearofentry_value='{$yearofentry}'";
  }

  if (!empty($_SESSION['views']['list_students']['default']['level'])) {
    $level = $_SESSION['views']['list_students']['default']['level'];
    $level = addslashes($level);
    if ($level !== 'All') $where .= " AND node_users_1_node_data_field_profile_level_name.field_profile_level_name_value='{$level}'";
  }

  if (!empty($_SESSION['views']['list_students']['default']['gender'])) {
    $gender = $_SESSION['views']['list_students']['default']['gender'];
    $gender = addslashes($gender);
    if ($gender !== 'All') $where .= " AND node_users_node_data_field_profile_gender.field_profile_gender_value='{$gender}'";
  }

  if (!empty($_SESSION['views']['list_students']['default']['programme'])) {
    $programme = $_SESSION['views']['list_students']['default']['programme'];
    $programme = addslashes($programme);
    if ($programme !== 'All') $where .= " AND node_node_data_field_profile_first_choice_node_data_field_programme_name.field_programme_name_value='{$programme}'";
  }

  if (!empty($_SESSION['views']['list_students']['default']['department'])) {
    $department = $_SESSION['views']['list_students']['default']['department'];
    $department = addslashes($department);
    if ($department !== 'All') $where .= " AND node_node_data_field_department_id_node_data_field_department_name.field_department_name_value='{$department}'";
  }

  if (!empty($_SESSION['views']['list_students']['default']['college'])) {
    $college = $_SESSION['views']['list_students']['default']['college'];
    $college = addslashes($college);
    if ($college !== 'All') $where .= " AND node_node_data_field_college_id_node_data_field_college_name.field_college_name_value='{$college}'";
  }

  $sql = "SELECT COUNT(users.uid) AS count
    FROM users users
    LEFT JOIN node node_users ON users.uid = node_users.uid AND node_users.type = 'profile'
    LEFT JOIN node node_users_1 ON users.uid = node_users_1.uid AND node_users_1.type = 'student_profile'
    LEFT JOIN content_type_student_profile node_users_1_node_data_field_profile_first_choice ON node_users_1.vid = node_users_1_node_data_field_profile_first_choice.vid
    LEFT JOIN node node_node_data_field_profile_first_choice ON node_users_1_node_data_field_profile_first_choice.field_profile_first_choice_nid = node_node_data_field_profile_first_choice.nid
    LEFT JOIN content_type_program node_node_data_field_profile_first_choice_node_data_field_department_id ON node_node_data_field_profile_first_choice.vid = node_node_data_field_profile_first_choice_node_data_field_department_id.vid
    LEFT JOIN node node_node_data_field_department_id ON node_node_data_field_profile_first_choice_node_data_field_department_id.field_department_id_nid = node_node_data_field_department_id.nid
    LEFT JOIN content_type_department node_node_data_field_department_id_node_data_field_college_id ON node_node_data_field_department_id.vid = node_node_data_field_department_id_node_data_field_college_id.vid
    LEFT JOIN node node_node_data_field_college_id ON node_node_data_field_department_id_node_data_field_college_id.field_college_id_nid = node_node_data_field_college_id.nid
    INNER JOIN users_roles users_roles ON users.uid = users_roles.uid
    INNER JOIN content_type_student_profile node_users_1_node_data_field_profile_level_name ON node_users_1.vid = node_users_1_node_data_field_profile_level_name.vid
    INNER JOIN content_type_profile node_users_node_data_field_profile_gender ON node_users.vid = node_users_node_data_field_profile_gender.vid
    INNER JOIN content_type_program node_node_data_field_profile_first_choice_node_data_field_programme_name ON node_node_data_field_profile_first_choice.vid = node_node_data_field_profile_first_choice_node_data_field_programme_name.vid
    INNER JOIN content_type_department node_node_data_field_department_id_node_data_field_department_name ON node_node_data_field_department_id.vid = node_node_data_field_department_id_node_data_field_department_name.vid
    INNER JOIN content_type_college node_node_data_field_college_id_node_data_field_college_name ON node_node_data_field_college_id.vid = node_node_data_field_college_id_node_data_field_college_name.vid
    LEFT JOIN content_type_profile node_users_node_data_field_profile_last_name ON node_users.vid = node_users_node_data_field_profile_last_name.vid
    LEFT JOIN content_type_student_profile node_users_1_node_data_field_profile_yearofentry ON node_users_1.vid = node_users_1_node_data_field_profile_yearofentry.vid
    {$where}";
  $countresults = db_query($sql);
  if ($row = db_fetch_object($countresults)) {
    echo "<br /><b>Total number of results: {$row->count}</b>";
  }
}
?>