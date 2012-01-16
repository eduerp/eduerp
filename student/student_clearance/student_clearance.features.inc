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
    'student_clearance' => array(
      'name' => t('Student Clearance'),
      'module' => 'features',
      'description' => t('Student clearance stores clearance data for students. This includes the date the clearance was made, who was cleared and who did the clearance. Also it stores student results verification data as well.'),
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

/**
 * Implementation of hook_rules_defaults().
 */
function student_clearance_rules_defaults() {
  return array(
    'rules' => array(
      'rules_student_clearance_agreement' => array(
        '#type' => 'rule',
        '#set' => 'event_init',
        '#label' => 'Student clearance agreement',
        '#active' => 0,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'student',
          'student_clearance' => 'student_clearance',
        ),
        '#status' => 'default',
        '#actions' => NULL,
        '#conditions' => NULL,
        '#version' => 6003,
      ),
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
            '#weight' => -9,
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
                'clearance_node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'new variables' => array(
                'clearance_agreement_node_added' => array(
                  'label' => 'new clearance agreement node',
                  'label callback' => FALSE,
                  'type' => 'node',
                  'save' => TRUE,
                ),
              ),
              'module' => 'Student',
            ),
            '#name' => 'student_action_create_agreement',
            '#settings' => array(
              'title' => 'Clearance Agreement by $author for $student_id',
              'type' => 'clearance_agreement',
              '#argument map' => array(
                'author' => 'author',
                'clearance_node' => 'node',
                'clearance_agreement_node_added' => 'clearance_agreement_node_added',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'rules_user_logs_in_for_the_first_time' => array(
        '#type' => 'rule',
        '#set' => 'event_user_login',
        '#label' => 'User logs in for the first time',
        '#active' => 0,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'student',
          'student_clearance' => 'student_clearance',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(),
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
