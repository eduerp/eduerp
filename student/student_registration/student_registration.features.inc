<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function student_registration_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function student_registration_node_info() {
  $items = array(
    'student_profile' => array(
      'name' => t('Student Profile'),
      'module' => 'features',
      'description' => t('A student profile built as content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
