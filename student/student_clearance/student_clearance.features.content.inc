<?php

/**
 * Implementation of hook_content_default_fields().
 */
function student_clearance_content_default_fields() {
  $fields = array();

  // Exported field: field_agreement_agree
  $fields['clearance_agreement-field_agreement_agree'] = array(
    'field_name' => 'field_agreement_agree',
    'type_name' => 'clearance_agreement',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'cck_blocks' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '|
0|I Agree',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'I agree',
      'weight' => '-2',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_student
  $fields['clearance_agreement-field_student'] = array(
    'field_name' => 'field_student',
    'type_name' => 'clearance_agreement',
    'display_settings' => array(
      'weight' => '31',
      'parent' => '',
      'cck_blocks' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'userreference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'userreference',
    'active' => '1',
    'referenceable_roles' => array(
      '29' => 29,
      '2' => 0,
      '8' => 0,
      '30' => 0,
      '27' => 0,
      '26' => 0,
      '28' => 0,
      '25' => 0,
    ),
    'referenceable_status' => '',
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'reverse_link' => 0,
      'default_value' => array(
        '0' => array(
          'uid' => NULL,
          '_error_element' => 'default_value_widget][field_student][0][uid][uid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Student',
      'weight' => '8',
      'description' => '',
      'type' => 'userreference_autocomplete',
      'module' => 'userreference',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('I agree');
  t('Student');

  return $fields;
}
