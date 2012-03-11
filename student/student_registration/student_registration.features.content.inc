<?php

/**
 * Implementation of hook_content_default_fields().
 */
function student_registration_content_default_fields() {
  $fields = array();

  // Exported field: field_personal_email
  $fields['student_profile-field_personal_email'] = array(
    'field_name' => 'field_personal_email',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '16',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
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
      '5' => array(
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
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Personal Email Address',
      'weight' => '22',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_exam_number_1
  $fields['student_profile-field_profile_exam_number_1'] = array(
    'field_name' => 'field_profile_exam_number_1',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '32',
      'parent' => 'group_olevels_first',
      'label' => array(
        'format' => 'inline',
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
      '5' => array(
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
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '60',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profile_exam_number_1][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Examination Number',
      'weight' => '32',
      'description' => 'For Postgraduate Applications please enter the qualification achieved (e.g. Diploma in Computer Studies). There is no need to enter examination Records.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_exam_number_2
  $fields['student_profile-field_profile_exam_number_2'] = array(
    'field_name' => 'field_profile_exam_number_2',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '38',
      'parent' => 'group_olevels_second',
      'label' => array(
        'format' => 'inline',
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
      '5' => array(
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
    'max_length' => '60',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profile_exam_number_2][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Examination Number',
      'weight' => '38',
      'description' => 'For Postgraduate Applications please enter the qualification achieved (e.g. Bachelor in Computer Studies). There is no need to enter examination Records.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_first_choice
  $fields['student_profile-field_profile_first_choice'] = array(
    'field_name' => 'field_profile_first_choice',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '8',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'program' => 'program',
      'allocation_rules' => 0,
      'allocation_rules_description' => 0,
      'allocation_settings' => 0,
      'approval' => 0,
      'blocks' => 0,
      'clearance_agreement' => 0,
      'college' => 0,
      'course' => 0,
      'course_instance' => 0,
      'department' => 0,
      'hostels' => 0,
      'page' => 0,
      'product' => 0,
      'product_kit' => 0,
      'profile' => 0,
      'room_allocations' => 0,
      'room_reservations' => 0,
      'rooms' => 0,
      'school_fee_approved_instalments' => 0,
      'school_fee_approved_scholarships' => 0,
      'school_fee_item_setup' => 0,
      'school_fee_item_setup_details' => 0,
      'school_fee_items' => 0,
      'school_fee_level_types' => 0,
      'school_fee_nationality_types' => 0,
      'school_fee_settings' => 0,
      'school_fee_structure_classes' => 0,
      'staff_profile' => 0,
      'story' => 0,
      'student_clearance' => 0,
      'student_gpa' => 0,
      'student_profile' => 0,
      'student_program' => 0,
      'student_record' => 0,
      'student_grades' => 0,
    ),
    'advanced_view' => 'registration_allowed_programmes',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Programme offerred',
      'weight' => '14',
      'description' => '',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_profile_health_disability
  $fields['student_profile-field_profile_health_disability'] = array(
    'field_name' => 'field_profile_health_disability',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '11',
      'parent' => 'group_health_information',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '50',
    'allowed_values' => 'asthma|Asthma
blind|Blind
deaf|Deaf
diabetes|Diabetes
dumb|Dumb
dysmenorrhoea|Dysmenorrhoea
epilepsy|Epilepsy
hypertension|Hypertension
myopia|Myopia/Hypermyopia
physically-challenged|Physically Challenged
std|STD/HIV/AIDS
sickle|Sickle Cell
tuberculosis|Tuberculosis',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Disabilities',
      'weight' => '11',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_profile_health_status
  $fields['student_profile-field_profile_health_status'] = array(
    'field_name' => 'field_profile_health_status',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '10',
      'parent' => 'group_health_information',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '30',
    'allowed_values' => 'normal|Normal
physically-challenged|Physically Challenged
sickness|Sickness',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Health Status',
      'weight' => '10',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_profile_hobbies
  $fields['student_profile-field_profile_hobbies'] = array(
    'field_name' => 'field_profile_hobbies',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '9',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '3',
      'size' => 60,
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Hobbies',
      'weight' => '15',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_jambno
  $fields['student_profile-field_profile_jambno'] = array(
    'field_name' => 'field_profile_jambno',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => 0,
      'parent' => '',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '30',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '15',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profile_jambno][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'JAMB No.',
      'weight' => '6',
      'description' => 'If this is a Postgraduate Application please use your application form number given to you by the University.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_kin_address
  $fields['student_profile-field_profile_kin_address'] = array(
    'field_name' => 'field_profile_kin_address',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '25',
      'parent' => 'group_next_of_kin_information',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '3',
      'size' => 60,
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Next of Kin\'s Address',
      'weight' => '25',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_kin_city
  $fields['student_profile-field_profile_kin_city'] = array(
    'field_name' => 'field_profile_kin_city',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '26',
      'parent' => 'group_next_of_kin_information',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Next of Kin\'s City',
      'weight' => '26',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_kin_mobile
  $fields['student_profile-field_profile_kin_mobile'] = array(
    'field_name' => 'field_profile_kin_mobile',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '24',
      'parent' => 'group_next_of_kin_information',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '15',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profile_kin_mobile][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Next of Kin\'s Mobile',
      'weight' => '24',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_kin_name
  $fields['student_profile-field_profile_kin_name'] = array(
    'field_name' => 'field_profile_kin_name',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '21',
      'parent' => 'group_next_of_kin_information',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Next of Kin\'s Name',
      'weight' => '21',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_kin_relationship
  $fields['student_profile-field_profile_kin_relationship'] = array(
    'field_name' => 'field_profile_kin_relationship',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '22',
      'parent' => 'group_next_of_kin_information',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'Father
Mother
Uncle
Aunt
Husband
Wife
Brother
Sister
Other',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Next of Kin\'s Relationship',
      'weight' => '22',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_profile_kin_telephone
  $fields['student_profile-field_profile_kin_telephone'] = array(
    'field_name' => 'field_profile_kin_telephone',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '23',
      'parent' => 'group_next_of_kin_information',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Next of Kin\'s Telephone',
      'weight' => '23',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_kin_title
  $fields['student_profile-field_profile_kin_title'] = array(
    'field_name' => 'field_profile_kin_title',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '20',
      'parent' => 'group_next_of_kin_information',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Next of Kin\'s Title',
      'weight' => '20',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_level_name
  $fields['student_profile-field_profile_level_name'] = array(
    'field_name' => 'field_profile_level_name',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '7',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '30',
    'allowed_values' => '',
    'allowed_values_php' => '$sql = "SELECT DISTINCT level AS value FROM {program_level_semester} ORDER BY level";
$res = db_query($sql);
$rows = array();
while ($row = db_fetch_array($res)) {
  $rows[$row[\'value\']] = $row[\'value\'];
}
return $rows;',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Level',
      'weight' => '13',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_profile_matno
  $fields['student_profile-field_profile_matno'] = array(
    'field_name' => 'field_profile_matno',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '2',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '30',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profile_matno][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Matriculation No.',
      'weight' => '8',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_mode_of_entry
  $fields['student_profile-field_profile_mode_of_entry'] = array(
    'field_name' => 'field_profile_mode_of_entry',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '-1',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '30',
    'allowed_values' => 'UTME
DE
MATRIC
CIS
Postgraduate',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Mode of Entry',
      'weight' => '5',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_profile_mode_of_study
  $fields['student_profile-field_profile_mode_of_study'] = array(
    'field_name' => 'field_profile_mode_of_study',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '3',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'Full_Time
Part_Time',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Mode of Study',
      'weight' => '9',
      'description' => 'Please specify your mode of study',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_profile_olevel_exams_1
  $fields['student_profile-field_profile_olevel_exams_1'] = array(
    'field_name' => 'field_profile_olevel_exams_1',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '34',
      'parent' => 'group_olevels_first',
      'label' => array(
        'format' => 'inline',
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
    ),
    'widget_active' => '1',
    'type' => 'exam_record',
    'required' => '0',
    'multiple' => '9',
    'module' => 'student',
    'active' => '1',
    'subjects_allowed_values' => '|
Agricultural Science
Animal Husbandry
Applied Electricity
Arabic
Auto Mechanics
Biology
Building Construction
Business Management
Carpentry and Joinery
Catering Craft Practice
Chemistry
Christian Religious Studies
Clerical Office Duties
Clothing and textiles
Commerce
Cosmetology
Cover
Draughtmanship Craft Practice
Economics
Electronics
Engineering Science
English Language
English Language Balance
Financial Accounting
Fisheries
Food and Nutrition
French
Further Maths
Geography
Government
Hausa Language
Health Science
History
Home Management
ICT - Information Communication Technology
Introduction to Building Construction
Islamic Religious Studies
Ladies Garment Making
Literature in English
Management Living
Mathematics
Mens Garment Making
Metalwork
Music
Nigerian Languages
Painting and Decorating
Physical Education
Physics
Plumbing and Pipefitting
Principles of Cost Accounting
Science (core)
Shorthand
Sierra Leone Languages
Sierra Leone studies
Technical Drawing
Typewriting
Visual Art
Woodwork',
    'grades_allowed_values' => '|
A1
B2
B3
C4
C5
C6
D7
E8
F9
A
B
C
D
E
F',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'subject' => '',
          'grade' => '',
          '_error_element' => 'exam_subject',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Examination Records',
      'weight' => '34',
      'description' => '',
      'type' => 'exam_record_exam_record',
      'module' => 'student',
    ),
  );

  // Exported field: field_profile_olevel_exams_2
  $fields['student_profile-field_profile_olevel_exams_2'] = array(
    'field_name' => 'field_profile_olevel_exams_2',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '40',
      'parent' => 'group_olevels_second',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'exam_record',
    'required' => '0',
    'multiple' => '9',
    'module' => 'student',
    'active' => '1',
    'subjects_allowed_values' => '|
Agricultural Science
Animal Husbandry
Applied Electricity
Arabic
Auto Mechanics
Biology
Building Construction
Business Management
Carpentry and Joinery
Catering Craft Practice
Chemistry
Christian Religious Studies
Clerical Office Duties
Clothing and textiles
Commerce
Cosmetology
Cover
Draughtmanship Craft Practice
Economics
Electronics
Engineering Science
English Language
English Language Balance
Financial Accounting
Fisheries
Food and Nutrition
French
Further Maths
Geography
Government
Hausa Language
Health Science
History
Home Management
ICT - Information Communication Technology
Introduction to Building Construction
Islamic Religious Studies
Ladies Garment Making
Literature in English
Management Living
Mathematics
Mens Garment Making
Metalwork
Music
Nigerian Languages
Painting and Decorating
Physical Education
Physics
Plumbing and Pipefitting
Principles of Cost Accounting
Science (core)
Shorthand
Sierra Leone Languages
Sierra Leone studies
Technical Drawing
Typewriting
Visual Art
Woodwork',
    'grades_allowed_values' => '|
A1
B2
B3
C4
C5
C6
D7
E8
F9
Distinction
Credit
Pass
Fail
A
B
C
D
E
F',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'subject' => '',
          'grade' => '',
          '_error_element' => 'exam_subject',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Examination Records',
      'weight' => '40',
      'description' => '',
      'type' => 'exam_record_exam_record',
      'module' => 'student',
    ),
  );

  // Exported field: field_profile_olevel_insti1
  $fields['student_profile-field_profile_olevel_insti1'] = array(
    'field_name' => 'field_profile_olevel_insti1',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '31',
      'parent' => 'group_olevels_first',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Institution',
      'weight' => '31',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_olevel_insti2
  $fields['student_profile-field_profile_olevel_insti2'] = array(
    'field_name' => 'field_profile_olevel_insti2',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '37',
      'parent' => 'group_olevels_second',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Institution',
      'weight' => '37',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_olevel_qual_1
  $fields['student_profile-field_profile_olevel_qual_1'] = array(
    'field_name' => 'field_profile_olevel_qual_1',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '30',
      'parent' => 'group_olevels_first',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '30',
    'allowed_values' => 'GCE-O-Level
NABTEB
NECO
WAEC
Diploma
NCE
IJMB
First-Degree',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Qualification',
      'weight' => '30',
      'description' => 'For Postgraduate Applications please enter your second highest qualification (Diploma, NCE, IJMB or First Degree)',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_profile_olevel_qual_2
  $fields['student_profile-field_profile_olevel_qual_2'] = array(
    'field_name' => 'field_profile_olevel_qual_2',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '36',
      'parent' => 'group_olevels_second',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '30',
    'allowed_values' => 'GCE-O-Level
GCE-A-Level
IJMB
NABTEB
NCE
NECO
OND
WAEC
First-Degree
Postgraduate-Diploma',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Qualification',
      'weight' => '36',
      'description' => 'For Postgraduate Applications please enter your highest qualification (First Degree or Postgraduate Diploma)',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_profile_reg_semester
  $fields['student_profile-field_profile_reg_semester'] = array(
    'field_name' => 'field_profile_reg_semester',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '6',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
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
      '5' => array(
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
    'max_length' => '30',
    'allowed_values' => '',
    'allowed_values_php' => '$sql = "SELECT DISTINCT field_profile_reg_semester_value AS value FROM {content_type_student_profile} ORDER BY field_profile_reg_semester_value";
$res = db_query($sql);
$rows = array();
while ($row = db_fetch_array($res)) {
  $rows[$row[\'value\']] = $row[\'value\'];
}
return $rows;',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Registered Semester',
      'weight' => '12',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_profile_reg_session
  $fields['student_profile-field_profile_reg_session'] = array(
    'field_name' => 'field_profile_reg_session',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '5',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '30',
    'allowed_values' => '',
    'allowed_values_php' => '$sql = "SELECT DISTINCT field_profile_reg_session_value AS value FROM {content_type_student_profile} ORDER BY field_profile_reg_session_value";
$res = db_query($sql);
$rows = array();
while ($row = db_fetch_array($res)) {
  $rows[$row[\'value\']] = $row[\'value\'];
}
return $rows;',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Registered Session',
      'weight' => '11',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_profile_score_details
  $fields['student_profile-field_profile_score_details'] = array(
    'field_name' => 'field_profile_score_details',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '52',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
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
      '5' => array(
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
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '255',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profile_score_details][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Score Details',
      'weight' => '7',
      'description' => 'Please put in JAMB Score for UTME or Highest Qualification for DE or Postgraduate',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_sponsor_address
  $fields['student_profile-field_profile_sponsor_address'] = array(
    'field_name' => 'field_profile_sponsor_address',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '46',
      'parent' => 'group_sponsor_information',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '255',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '3',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profile_sponsor_address][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sponsor\'s Address',
      'weight' => '46',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_sponsor_city
  $fields['student_profile-field_profile_sponsor_city'] = array(
    'field_name' => 'field_profile_sponsor_city',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '47',
      'parent' => 'group_sponsor_information',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '60',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profile_sponsor_city][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sponsor\'s Address City',
      'weight' => '47',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_sponsor_email
  $fields['student_profile-field_profile_sponsor_email'] = array(
    'field_name' => 'field_profile_sponsor_email',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '51',
      'parent' => 'group_sponsor_information',
      'label' => array(
        'format' => 'inline',
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
      '5' => array(
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
    'max_length' => '60',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Sponsor\'s e-mail',
      'weight' => '51',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_sponsor_mobile
  $fields['student_profile-field_profile_sponsor_mobile'] = array(
    'field_name' => 'field_profile_sponsor_mobile',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '50',
      'parent' => 'group_sponsor_information',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '60',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profile_sponsor_mobile][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sponsor\'s Mobile No.',
      'weight' => '50',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_sponsor_name
  $fields['student_profile-field_profile_sponsor_name'] = array(
    'field_name' => 'field_profile_sponsor_name',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '45',
      'parent' => 'group_sponsor_information',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '60',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profile_sponsor_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sponsor\'s Name (Sponsor data must be entered if there is no State Sponsor!)',
      'weight' => '45',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_sponsor_phone
  $fields['student_profile-field_profile_sponsor_phone'] = array(
    'field_name' => 'field_profile_sponsor_phone',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '49',
      'parent' => 'group_sponsor_information',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '60',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profile_sponsor_phone][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sponsor\'s Telephone No.',
      'weight' => '49',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_sponsor_state
  $fields['student_profile-field_profile_sponsor_state'] = array(
    'field_name' => 'field_profile_sponsor_state',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '48',
      'parent' => 'group_sponsor_information',
      'label' => array(
        'format' => 'inline',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '60',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profile_sponsor_state][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sponsor\'s Address State',
      'weight' => '48',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_state_sponsor
  $fields['student_profile-field_profile_state_sponsor'] = array(
    'field_name' => 'field_profile_state_sponsor',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '44',
      'parent' => 'group_sponsor_information',
      'label' => array(
        'format' => 'inline',
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
      '5' => array(
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
    'max_length' => '50',
    'allowed_values' => '',
    'allowed_values_php' => '$list = array();
$rs = db_query(\'SELECT * FROM {eduerp_states} ORDER BY state_name\');
while ($row = db_fetch_object($rs)) $list[$row->state_name] = $row->state_name;
return $list;',
    'widget' => array(
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'State Sponsor (if any)',
      'weight' => '44',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_profile_year_exam_taken_1
  $fields['student_profile-field_profile_year_exam_taken_1'] = array(
    'field_name' => 'field_profile_year_exam_taken_1',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '33',
      'parent' => 'group_olevels_first',
      'label' => array(
        'format' => 'inline',
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
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-50:+0',
      'label_position' => 'within',
      'label' => 'Year & Month Exam Taken',
      'weight' => '33',
      'description' => '',
      'type' => 'date_select',
      'module' => 'date',
    ),
  );

  // Exported field: field_profile_year_exam_taken_2
  $fields['student_profile-field_profile_year_exam_taken_2'] = array(
    'field_name' => 'field_profile_year_exam_taken_2',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '39',
      'parent' => 'group_olevels_second',
      'label' => array(
        'format' => 'inline',
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
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-50:+0',
      'label_position' => 'within',
      'label' => 'Year & Month Exam Taken',
      'weight' => '39',
      'description' => '',
      'type' => 'date_select',
      'module' => 'date',
    ),
  );

  // Exported field: field_profile_yearofentry
  $fields['student_profile-field_profile_yearofentry'] = array(
    'field_name' => 'field_profile_yearofentry',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '4',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
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
      '5' => array(
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
    'max_length' => '4',
    'allowed_values' => '',
    'allowed_values_php' => '$sql = "SELECT DISTINCT field_profile_yearofentry_value AS value FROM {content_type_student_profile} ORDER BY field_profile_yearofentry_value";
$res = db_query($sql);
$rows = array();
while ($row = db_fetch_array($res)) {
  $rows[$row[\'value\']] = $row[\'value\'];
}
return $rows;',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Year of Entry',
      'weight' => '10',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_university_email
  $fields['student_profile-field_university_email'] = array(
    'field_name' => 'field_university_email',
    'type_name' => 'student_profile',
    'display_settings' => array(
      'weight' => '15',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
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
      '5' => array(
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
    'text_processing' => '',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => 60,
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Internal University Email Address',
      'weight' => '21',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Disabilities');
  t('Examination Number');
  t('Examination Records');
  t('Health Status');
  t('Hobbies');
  t('Institution');
  t('Internal University Email Address');
  t('JAMB No.');
  t('Level');
  t('Matriculation No.');
  t('Mode of Entry');
  t('Mode of Study');
  t('Next of Kin\'s Address');
  t('Next of Kin\'s City');
  t('Next of Kin\'s Mobile');
  t('Next of Kin\'s Name');
  t('Next of Kin\'s Relationship');
  t('Next of Kin\'s Telephone');
  t('Next of Kin\'s Title');
  t('Personal Email Address');
  t('Programme offerred');
  t('Qualification');
  t('Registered Semester');
  t('Registered Session');
  t('Score Details');
  t('Sponsor\'s Address');
  t('Sponsor\'s Address City');
  t('Sponsor\'s Address State');
  t('Sponsor\'s Mobile No.');
  t('Sponsor\'s Name (Sponsor data must be entered if there is no State Sponsor!)');
  t('Sponsor\'s Telephone No.');
  t('Sponsor\'s e-mail');
  t('State Sponsor (if any)');
  t('Year & Month Exam Taken');
  t('Year of Entry');

  return $fields;
}
