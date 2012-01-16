<?php
/**
* Implementation of hook_rules_event_info().
* @ingroup rules
*/
function student_rules_event_info() {
  return array(
    'student_cleared' => array(
      'label' => t('A student was cleared.'),
      'module' => 'Student',
      'arguments' => array(
        'author' => array(
          'type' => 'user',
          'label' => t('Author of the node'),
          'handler' => 'rules_events_argument_node_author',
        ),
        'student_id' => array('type' => 'user', 'label' => t('The student being cleared.')),
        'node' => array('type' => 'node', 'label' => t('The clearance node information that was created.')),
        //'node' => array('type' => 'node', 'label' => t('The clearance node information that was created.')),
      ),
    ),
  );
}


/**
 * implementation of hook_rules_condition_info()
 * @return <type>
 */
function student_rules_condition_info() {
    return array(
      'student_clearance_performed' => array(
        'label' => t('A student clearance was done'),
        'arguments' => array(
          'student_id' => array('type' => 'value', 'label' => t('The student id.')),
        ),
        'module' => 'Student'
      ),
    );
}

function student_clearance_performed($student_id) {
  global $user;
  $student_id = isset($student_id) ? $student_id : student_views_get_current_student();

  $user_profile = new UserProfile($student_id);

  if((!empty($user_profile->profile_matno) &&
    eduerp_has_role($user, 'Student') && !empty($user_profile->profile_first_name)
      && !empty($user_profile->profile_last_name))) {

      return TRUE;
  }
  else {
      return FALSE;
  }
}

/**
 *
 * Implementation of hook_rules_action_info().
 *
 * @see student_action_create_agreement
 *
 * @author Kayode Odeyemi (dreyemi@gmail.com)
 */
function student_rules_action_info() {
    return array(
      'student_action_create_agreement' => array(
        'label' => t('Create a clearance agreement node'),
        'arguments' => array(
          'author' => array('type' => 'user', 'label' => t('User, who is set as author')),
          'title' => array(
            'type' => 'string',
            'label' => t('Title'),
            'description' => t('The title of the newly created content.'),
          ),
          'student_id' => array('type' => 'value', 'label' => t('The student id.')),
          'clearance_node' => array('type' => 'node', 'label' => t('Content')),
        ),
        'new variables' => array(
          'clearance_agreement_node_added' => array(
            'type' => 'node',
            'label' => t('New content'),
            'save' => TRUE,
            'label callback' => 'rules_action_add_node_variable_label',
            ),
          ),
        'module' => 'Student', // only used for grouping of the condition in the admin dropdown list
      ),
      // Update student clearance after it has been loaded
      'student_action_update_student_clearance' => array(
        'label' => t('Update student clearance'),
        'arguments' => array(
          'author' => array('type' => 'user', 'label' => t('User, who is set as author')),
          'student_id' => array('type' => 'value', 'label' => t('The student id.')),
          'student_clearance_node_loaded' => array('type' => 'node', 'label' => t('Student clearance node')),
        ),
        'new variables' => array(
          'student_clearance_updated_node' => array(
            'type' => 'node',
            'label' => t('Updated content'),
            'save' => TRUE,
            'label callback' => 'rules_action_update_student_clearance_variable_label',
          ),
        ),
        'module' => 'Student', // only used for grouping of the condition in the admin dropdown list
      ),
      // Load the just added clearance agreement using
      // clearance_agreement_node_added variable
      /*'student_action_load_clearance_agreement' => array(
        'label' => t('Load the immediate new clearance agreement'),
        'arguments' => array(
          'agreement_node' => array('type' => 'node', 'label' => t('Agreement node')),
        ),
        'module' => 'Student', // only used for grouping of the condition in the admin dropdown list
      ),*/
    );
}

function rules_action_update_student_clearance_variable_label($settings) {
  return t('Updated node is @nid', array('@nid' => $settings['nid']));
}

/**
 * do
 * create a new clearance agreement node
 *
 * $author: Node author
 * $settings: Every other variables declared are stored in here
 *
 * @param <type> $author
 * @param <type> $student_id
 * @param array $settings.
 * @return <type>
 *
 * @author Kayode Odeyemi (dreyemi@gmail.com)
 */
function student_action_create_agreement($author, $title, $student_id, $node, $settings) {
	if (node_access('create', $settings['type'], $author)) {
    module_load_include('inc', 'node', 'node.pages');
    $student_id = isset($student_id) ? $student_id : student_views_get_current_student();

    $node = (object)array('type' => $settings['type']);
    node_object_prepare($node);

    $node->is_new = 1;
    $node->author = $author->name;
    $node->author = $author->uid;
    $node->title = $title;
    $node->field_student[0][uid] = $student_id;
    $node->body = variable_get('eduerp_agreement', '');

    return array('clearance_agreement_node_added' , node_save($node));
	}
}

function student_action_create_agreement_form($settings, &$form) {
  module_load_include('inc', 'node', 'node.pages');

  $form['settings']['type'] = array(
    '#type' => 'select',
    '#title' => t('Content type to be used'),
    '#options' => node_get_types('names'),
    '#default_value' => isset($settings['type']) ? $settings['type'] : '',
    '#description' => t('Select a content type that will be created when this action is invoked.'),
    '#required' => TRUE,
  );
}

function student_action_update_student_clearance($author, $student_id, $node, $settings) {
  module_load_include('inc', 'node', 'node.pages');
  $node->field_clearance_agreement[0]['nid'] = $settings['nid'];
  return array('student_clearance_updated_node', node_save($node));
}

function student_action_update_student_clearance_form($settings, &$form) {
  module_load_include('inc', 'node', 'node.pages');
  
  $form['settings']['nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Node nid'),
    '#default_value' => isset($settings['nid']) ? $settings['nid'] : '', 
    '#description' => t('Enter the nid of the node to update.'),
    '#required' => TRUE,
  );
}

/*function student_action_load_clearance_agreement($node, $settings) {
  //return array('node_loaded' => node_load($nid, $vid ? $vid : NULL));
}

function student_action_load_clearance_agreement_form($settings, &$form) {
  module_load_include('inc', 'node', 'node.pages');
  
  // put the node variable to use in $settings
  
  // put here a drop down select form of loaded rules variables
  // set the variable on save into $settings
}*/