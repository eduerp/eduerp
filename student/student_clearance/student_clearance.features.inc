<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function student_clearance_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function student_clearance_node_info() {
  $items = array(
    'clearance_agreement' => array(
      'name' => t('Clearance Agreement'),
      'module' => 'features',
      'description' => t('An agreement between a student and clearance officer (Registry role)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_rules_defaults().
 */
function student_clearance_rules_defaults() {
  return array(
    'rules' => array(
      'rules_student_cleared' => array(
        '#type' => 'rule',
        '#set' => 'event_student_cleared',
        '#label' => 'Student cleared',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'student',
          'student_clearance' => 'student_clearance',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(
          '0' => array(
            '#info' => array(
              'label' => 'Create a clearance agreement node',
              'arguments' => array(
                'author' => array(
                  'type' => 'user',
                  'label' => 'User, who is set as author',
                ),
                'title' => array(
                  'type' => 'string',
                  'label' => 'Title',
                  'description' => 'The title of the newly created content.',
                ),
                'student_id' => array(
                  'type' => 'value',
                  'label' => 'The student id.',
                ),
              ),
              'module' => 'Student',
            ),
            '#name' => 'student_action_create_agreement',
            '#settings' => array(
              'title' => 'A new clearance agreement for $student_id',
              'type' => 'clearance_agreement',
              '#argument map' => array(
                'author' => 'author',
                'clearance_node' => 'node',
              ),
            ),
            '#type' => 'action',
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}

/**
 * Implementation of hook_views_api().
 */
function student_clearance_views_api() {
  return array(
    'api' => '2',
  );
}
