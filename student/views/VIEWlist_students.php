<?php
$view = new view;
$view->name = 'list_students';
$view->description = 'List Students';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'users';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('relationships', array(
  'content_profile_rel' => array(
    'label' => 'Content Profile',
    'required' => 0,
    'type' => 'profile',
    'id' => 'content_profile_rel',
    'table' => 'users',
    'field' => 'content_profile_rel',
    'relationship' => 'none',
  ),
  'content_profile_rel_1' => array(
    'label' => 'Content Student Profile',
    'required' => 0,
    'type' => 'student_profile',
    'id' => 'content_profile_rel_1',
    'table' => 'users',
    'field' => 'content_profile_rel',
    'relationship' => 'none',
  ),
  'field_profile_first_choice_nid' => array(
    'label' => 'Programme',
    'required' => 0,
    'delta' => -1,
    'id' => 'field_profile_first_choice_nid',
    'table' => 'node_data_field_profile_first_choice',
    'field' => 'field_profile_first_choice_nid',
    'relationship' => 'content_profile_rel_1',
  ),
  'field_department_id_nid' => array(
    'label' => 'Department nid',
    'required' => 0,
    'delta' => -1,
    'id' => 'field_department_id_nid',
    'table' => 'node_data_field_department_id',
    'field' => 'field_department_id_nid',
    'relationship' => 'field_profile_first_choice_nid',
  ),
  'field_college_id_nid' => array(
    'label' => 'College nid',
    'required' => 0,
    'delta' => -1,
    'id' => 'field_college_id_nid',
    'table' => 'node_data_field_college_id',
    'field' => 'field_college_id_nid',
    'relationship' => 'field_department_id_nid',
  ),
));
$handler->override_option('fields', array(
  'name' => array(
    'label' => 'Mat No.',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_user' => 1,
    'overwrite_anonymous' => 0,
    'anonymous_text' => '',
    'exclude' => 0,
    'id' => 'name',
    'table' => 'users',
    'field' => 'name',
    'relationship' => 'none',
  ),
  'field_profile_last_name_value' => array(
    'label' => 'Last Name',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 1,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_profile_last_name_value',
    'table' => 'node_data_field_profile_last_name',
    'field' => 'field_profile_last_name_value',
    'relationship' => 'content_profile_rel',
  ),
  'field_profile_first_name_value' => array(
    'label' => 'First Name',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 1,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_profile_first_name_value',
    'table' => 'node_data_field_profile_first_name',
    'field' => 'field_profile_first_name_value',
    'relationship' => 'content_profile_rel',
  ),
  'field_profile_middle_name_value' => array(
    'label' => 'Middle Name',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_profile_middle_name_value',
    'table' => 'node_data_field_profile_middle_name',
    'field' => 'field_profile_middle_name_value',
    'relationship' => 'content_profile_rel',
  ),
  'field_profile_yearofentry_value' => array(
    'label' => 'Year of Entry',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'repeat' => array(
      'show_repeat_rule' => '',
    ),
    'fromto' => array(
      'fromto' => 'both',
    ),
    'id' => 'field_profile_yearofentry_value',
    'table' => 'node_data_field_profile_yearofentry',
    'field' => 'field_profile_yearofentry_value',
    'relationship' => 'content_profile_rel_1',
  ),
  'field_profile_level_name_value' => array(
    'label' => 'Level',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_profile_level_name_value',
    'table' => 'node_data_field_profile_level_name',
    'field' => 'field_profile_level_name_value',
    'relationship' => 'content_profile_rel_1',
  ),
  'field_profile_gender_value' => array(
    'label' => 'Gender',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_profile_gender_value',
    'table' => 'node_data_field_profile_gender',
    'field' => 'field_profile_gender_value',
    'relationship' => 'content_profile_rel',
  ),
  'field_profile_state_name_origin_value' => array(
    'label' => 'State of Origin',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_profile_state_name_origin_value',
    'table' => 'node_data_field_profile_state_name_origin',
    'field' => 'field_profile_state_name_origin_value',
    'relationship' => 'content_profile_rel',
  ),
  'field_programme_name_value' => array(
    'label' => 'Program',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_programme_name_value',
    'table' => 'node_data_field_programme_name',
    'field' => 'field_programme_name_value',
    'relationship' => 'field_profile_first_choice_nid',
  ),
));
$handler->override_option('filters', array(
  'rid' => array(
    'operator' => 'or',
    'value' => array(
      '30' => '30',
      '29' => '29',
    ),
    'group' => '0',
    'exposed' => TRUE,
    'expose' => array(
      'use_operator' => 0,
      'operator' => 'rid_op',
      'identifier' => 'rid',
      'label' => 'Student Status',
      'optional' => 0,
      'single' => 1,
      'remember' => 1,
      'reduce' => 1,
    ),
    'id' => 'rid',
    'table' => 'users_roles',
    'field' => 'rid',
    'relationship' => 'none',
    'reduce_duplicates' => 0,
    'override' => array(
      'button' => 'Override',
    ),
  ),
  'field_profile_yearofentry_value' => array(
    'operator' => '=',
    'value' => '',
    'group' => '0',
    'exposed' => TRUE,
    'expose' => array(
      'use_operator' => 0,
      'operator' => 'field_profile_yearofentry_value_op',
      'identifier' => 'field_profile_yearofentry_value',
      'label' => 'Year of Entry',
      'optional' => 1,
      'remember' => 1,
    ),
    'case' => 1,
    'id' => 'field_profile_yearofentry_value',
    'table' => 'node_data_field_profile_yearofentry',
    'field' => 'field_profile_yearofentry_value',
    'relationship' => 'content_profile_rel_1',
  ),
  'field_profile_level_name_value_many_to_one' => array(
    'operator' => 'or',
    'value' => array(),
    'group' => '0',
    'exposed' => TRUE,
    'expose' => array(
      'use_operator' => 0,
      'operator' => 'field_profile_level_name_value_many_to_one_op',
      'identifier' => 'level',
      'label' => 'Level',
      'optional' => 1,
      'single' => 1,
      'remember' => 1,
      'reduce' => 0,
    ),
    'id' => 'field_profile_level_name_value_many_to_one',
    'table' => 'node_data_field_profile_level_name',
    'field' => 'field_profile_level_name_value_many_to_one',
    'relationship' => 'content_profile_rel_1',
    'reduce_duplicates' => 0,
  ),
  'field_profile_gender_value_many_to_one' => array(
    'operator' => 'or',
    'value' => array(),
    'group' => '0',
    'exposed' => TRUE,
    'expose' => array(
      'use_operator' => 0,
      'operator' => 'field_profile_gender_value_many_to_one_op',
      'identifier' => 'gender',
      'label' => 'Gender',
      'optional' => 1,
      'single' => 1,
      'remember' => 1,
      'reduce' => 0,
    ),
    'id' => 'field_profile_gender_value_many_to_one',
    'table' => 'node_data_field_profile_gender',
    'field' => 'field_profile_gender_value_many_to_one',
    'relationship' => 'content_profile_rel',
    'reduce_duplicates' => 0,
  ),
  'field_programme_name_value_many_to_one' => array(
    'operator' => 'or',
    'value' => array(),
    'group' => '0',
    'exposed' => TRUE,
    'expose' => array(
      'use_operator' => 0,
      'operator' => 'field_programme_name_value_many_to_one_op',
      'identifier' => 'programme',
      'label' => 'Programme',
      'optional' => 1,
      'single' => 1,
      'remember' => 1,
      'reduce' => 0,
    ),
    'id' => 'field_programme_name_value_many_to_one',
    'table' => 'node_data_field_programme_name',
    'field' => 'field_programme_name_value_many_to_one',
    'relationship' => 'field_profile_first_choice_nid',
    'reduce_duplicates' => 0,
  ),
  'field_department_name_value_many_to_one' => array(
    'operator' => 'or',
    'value' => array(),
    'group' => '0',
    'exposed' => TRUE,
    'expose' => array(
      'use_operator' => 0,
      'operator' => 'field_department_name_value_many_to_one_op',
      'identifier' => 'department',
      'label' => 'Department',
      'optional' => 1,
      'single' => 1,
      'remember' => 1,
      'reduce' => 0,
    ),
    'id' => 'field_department_name_value_many_to_one',
    'table' => 'node_data_field_department_name',
    'field' => 'field_department_name_value_many_to_one',
    'relationship' => 'field_department_id_nid',
    'reduce_duplicates' => 0,
  ),
  'field_college_name_value_many_to_one' => array(
    'operator' => 'or',
    'value' => array(),
    'group' => '0',
    'exposed' => TRUE,
    'expose' => array(
      'use_operator' => 0,
      'operator' => 'field_college_name_value_many_to_one_op',
      'identifier' => 'college',
      'label' => 'Faculty',
      'optional' => 1,
      'single' => 1,
      'remember' => 1,
      'reduce' => 0,
    ),
    'id' => 'field_college_name_value_many_to_one',
    'table' => 'node_data_field_college_name',
    'field' => 'field_college_name_value_many_to_one',
    'relationship' => 'field_college_id_nid',
    'reduce_duplicates' => 0,
  ),
));
$handler->override_option('access', array(
  'type' => 'perm',
  'perm' => 'student data',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('footer', '<?php
if (!empty($_SESSION[\'views\'][\'list_students\'][\'default\'][\'rid\'])) {

  $rid = $_SESSION[\'views\'][\'list_students\'][\'default\'][\'rid\'];
  $where = "WHERE users_roles.rid={$rid}";

  if (!empty($_SESSION[\'views\'][\'list_students\'][\'default\'][\'yearofentry\'])) {
    $yearofentry = $_SESSION[\'views\'][\'list_students\'][\'default\'][\'yearofentry\'];
    $yearofentry = addslashes($yearofentry);
    if ($yearofentry !== \'All\') $where .= " AND node_users_1_node_data_field_profile_yearofentry.field_profile_yearofentry_value=\'{$yearofentry}\'";
  }

  if (!empty($_SESSION[\'views\'][\'list_students\'][\'default\'][\'level\'])) {
    $level = $_SESSION[\'views\'][\'list_students\'][\'default\'][\'level\'];
    $level = addslashes($level);
    if ($level !== \'All\') $where .= " AND node_users_1_node_data_field_profile_level_name.field_profile_level_name_value=\'{$level}\'";
  }

  if (!empty($_SESSION[\'views\'][\'list_students\'][\'default\'][\'gender\'])) {
    $gender = $_SESSION[\'views\'][\'list_students\'][\'default\'][\'gender\'];
    $gender = addslashes($gender);
    if ($gender !== \'All\') $where .= " AND node_users_node_data_field_profile_gender.field_profile_gender_value=\'{$gender}\'";
  }

  if (!empty($_SESSION[\'views\'][\'list_students\'][\'default\'][\'programme\'])) {
    $programme = $_SESSION[\'views\'][\'list_students\'][\'default\'][\'programme\'];
    $programme = addslashes($programme);
    if ($programme !== \'All\') $where .= " AND node_node_data_field_profile_first_choice_node_data_field_programme_name.field_programme_name_value=\'{$programme}\'";
  }

  if (!empty($_SESSION[\'views\'][\'list_students\'][\'default\'][\'department\'])) {
    $department = $_SESSION[\'views\'][\'list_students\'][\'default\'][\'department\'];
    $department = addslashes($department);
    if ($department !== \'All\') $where .= " AND node_node_data_field_department_id_node_data_field_department_name.field_department_name_value=\'{$department}\'";
  }

  if (!empty($_SESSION[\'views\'][\'list_students\'][\'default\'][\'college\'])) {
    $college = $_SESSION[\'views\'][\'list_students\'][\'default\'][\'college\'];
    $college = addslashes($college);
    if ($college !== \'All\') $where .= " AND node_node_data_field_college_id_node_data_field_college_name.field_college_name_value=\'{$college}\'";
  }

  $sql = "SELECT COUNT(users.uid) AS count
    FROM users users 
    LEFT JOIN node node_users ON users.uid = node_users.uid AND node_users.type = \'profile\'
    LEFT JOIN node node_users_1 ON users.uid = node_users_1.uid AND node_users_1.type = \'student_profile\'
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
?>');
$handler->override_option('footer_format', '3');
$handler->override_option('footer_empty', 0);
$handler->override_option('items_per_page', 100);
$handler->override_option('use_pager', '1');
$handler->override_option('style_plugin', 'table');
$handler->override_option('style_options', array(
  'grouping' => '',
  'override' => 1,
  'sticky' => 0,
  'order' => 'asc',
  'columns' => array(
    'name' => 'name',
    'value' => 'value',
    'value_1' => 'value_1',
    'value_2' => 'value_2',
    'value_3' => 'value_3',
    'value_4' => 'value_4',
    'value_5' => 'value_5',
    'value_6' => 'value_6',
    'value_7' => 'value_7',
    'field_profile_last_name_value' => 'field_profile_last_name_value',
    'field_profile_first_name_value' => 'field_profile_first_name_value',
    'field_profile_middle_name_value' => 'field_profile_middle_name_value',
    'field_profile_yearofentry_value' => 'field_profile_yearofentry_value',
    'field_profile_level_name_value' => 'field_profile_level_name_value',
    'field_profile_gender_value' => 'field_profile_gender_value',
    'field_profile_state_name_origin_value' => 'field_profile_state_name_origin_value',
    'field_programme_name_value' => 'field_programme_name_value',
  ),
  'info' => array(
    'name' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'value' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'value_1' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'value_2' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'value_3' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'value_4' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'value_5' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'value_6' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'value_7' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'field_profile_last_name_value' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'field_profile_first_name_value' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'field_profile_middle_name_value' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'field_profile_yearofentry_value' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'field_profile_level_name_value' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'field_profile_gender_value' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'field_profile_state_name_origin_value' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'field_programme_name_value' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  ),
  'default' => 'name',
));
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->override_option('path', 'liststudents');
$handler->override_option('menu', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
