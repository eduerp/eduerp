<?php

/**
 * Implementation of hook_views_default_views().
 */
function student_clearance_views_default_views() {
  $views = array();

  // Exported view: clearance_agreement
  $view = new view;
  $view->name = 'clearance_agreement';
  $view->description = 'Clearance agreement view between student and clearance officer';
  $view->tag = 'eduerp';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'field_student_uid' => array(
      'label' => 'Student',
      'required' => 1,
      'delta' => -1,
      'id' => 'field_student_uid',
      'table' => 'node_data_field_student',
      'field' => 'field_student_uid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type_1' => array(
      'operator' => 'in',
      'value' => array(
        'clearance_agreement' => 'clearance_agreement',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type_1',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('empty', 'Agreement doesn\'t exist. Please contact your admission officer');
  $handler->override_option('empty_format', '1');
  $handler->override_option('row_plugin', 'node');
  $handler->override_option('row_options', array(
    'relationship' => 'none',
    'build_mode' => 'full',
    'links' => 1,
    'comments' => 0,
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('arguments', array(
    'uid' => array(
      'default_action' => 'empty',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => 'Student agreement',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'user',
      'validate_fail' => 'empty',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'uid',
      'table' => 'users',
      'field' => 'uid',
      'validate_user_argument_type' => 'either',
      'validate_user_roles' => array(
        '29' => 29,
        '2' => 0,
        '8' => 0,
        '30' => 0,
        '27' => 0,
        '26' => 0,
        '28' => 0,
        '25' => 0,
      ),
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_fixed' => '',
      'default_argument_user' => 0,
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'product' => 0,
        'uc_school_product' => 0,
        'hostels' => 0,
        'product_kit' => 0,
        'allocation_rules' => 0,
        'allocation_rules_description' => 0,
        'allocation_settings' => 0,
        'approval' => 0,
        'blocks' => 0,
        'book' => 0,
        'clearance_agreement' => 0,
        'college' => 0,
        'course' => 0,
        'course_instance' => 0,
        'department' => 0,
        'page' => 0,
        'profile' => 0,
        'program' => 0,
        'rooms' => 0,
        'room_allocations' => 0,
        'room_reservations' => 0,
        'staff_profile' => 0,
        'story' => 0,
        'student_clearance' => 0,
        'student_gpa' => 0,
        'student_grades' => 0,
        'student_profile' => 0,
        'student_program' => 0,
        'student_record' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '2' => 0,
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 1,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('path', 'user/%/clearance');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'Clearance Agreement',
    'description' => 'Clearance Agreement',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->override_option('fields', array(
    'field_agreement_agree_value' => array(
      'label' => 'I agree',
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
      'format' => 'editable_html',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_agreement_agree_value',
      'table' => 'node_data_field_agreement_agree',
      'field' => 'field_agreement_agree_value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('row_plugin', 'fields');
  $handler->override_option('row_options', array(
    'inline' => array(),
    'separator' => '',
    'hide_empty' => 0,
  ));
  $handler->override_option('attachment_position', 'after');
  $handler->override_option('inherit_arguments', TRUE);
  $handler->override_option('inherit_exposed_filters', FALSE);
  $handler->override_option('inherit_pager', FALSE);
  $handler->override_option('render_pager', TRUE);
  $handler->override_option('displays', array(
    'page_1' => 'page_1',
    'default' => 0,
  ));

  $views[$view->name] = $view;

  return $views;
}
