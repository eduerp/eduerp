<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function student_registration_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_exam1
  $groups['student_profile-group_exam1'] = array(
    'group_type' => 'standard',
    'type_name' => 'student_profile',
    'group_name' => 'group_exam1',
    'label' => 'Please enter your O-level (or equivalent) Examination Results (First Sitting)',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '19',
    'fields' => array(
      '0' => 'field_profile_olevel_qual_1',
      '1' => 'field_profile_olevel_insti1',
      '2' => 'field_profile_exam_number_1',
      '3' => 'field_profile_year_exam_taken_1',
      '4' => 'field_profile_olevel_exams_1',
    ),
  );

  // Exported group: group_exam2
  $groups['student_profile-group_exam2'] = array(
    'group_type' => 'standard',
    'type_name' => 'student_profile',
    'group_name' => 'group_exam2',
    'label' => 'Please enter your O-level (sitting 2) Results. Direct Entry Students please enter your A-level (or equivalent) Results',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '20',
    'fields' => array(
      '0' => 'field_profile_olevel_qual_2',
      '1' => 'field_profile_olevel_insti2',
      '2' => 'field_profile_exam_number_2',
      '3' => 'field_profile_year_exam_taken_2',
      '4' => 'field_profile_olevel_exams_2',
    ),
  );

  // Exported group: group_health_information
  $groups['student_profile-group_health_information'] = array(
    'group_type' => 'standard',
    'type_name' => 'student_profile',
    'group_name' => 'group_health_information',
    'label' => 'Health Information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsible',
        'description' => '',
      ),
      'display' => array(
        'weight' => '12',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '18',
    'fields' => array(
      '0' => 'field_profile_health_status',
      '1' => 'field_profile_health_disability',
    ),
  );

  // Exported group: group_next_of_kin_information
  $groups['student_profile-group_next_of_kin_information'] = array(
    'group_type' => 'standard',
    'type_name' => 'student_profile',
    'group_name' => 'group_next_of_kin_information',
    'label' => 'Next of Kin Information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '11',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '17',
    'fields' => array(
      '0' => 'field_profile_kin_title',
      '1' => 'field_profile_kin_name',
      '2' => 'field_profile_kin_relationship',
      '3' => 'field_profile_kin_telephone',
      '4' => 'field_profile_kin_mobile',
      '5' => 'field_profile_kin_address',
      '6' => 'field_profile_kin_city',
    ),
  );

  // Exported group: group_olevels_second
  $groups['student_profile-group_olevels_second'] = array(
    'group_type' => 'standard',
    'type_name' => 'student_profile',
    'group_name' => 'group_olevels_second',
    'label' => 'Examination Results (Second Sitting)',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '14',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '0',
    'fields' => array(),
  );

  // Exported group: group_sponsor_information
  $groups['student_profile-group_sponsor_information'] = array(
    'group_type' => 'standard',
    'type_name' => 'student_profile',
    'group_name' => 'group_sponsor_information',
    'label' => 'Sponsor\'s Information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsible',
        'description' => '',
      ),
      'display' => array(
        'weight' => '10',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '55',
    'fields' => array(),
  );

  // Exported group: group_sponsor_informationx
  $groups['student_profile-group_sponsor_informationx'] = array(
    'group_type' => 'standard',
    'type_name' => 'student_profile',
    'group_name' => 'group_sponsor_informationx',
    'label' => 'Sponsor\'s Information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '54',
    'fields' => array(),
  );

  // Exported group: group_xxx
  $groups['student_profile-group_xxx'] = array(
    'group_type' => 'standard',
    'type_name' => 'student_profile',
    'group_name' => 'group_xxx',
    'label' => 'Sponsor\'s Information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsible',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '16',
    'fields' => array(
      '0' => 'field_profile_state_sponsor',
      '1' => 'field_profile_sponsor_name',
      '2' => 'field_profile_sponsor_address',
      '3' => 'field_profile_sponsor_city',
      '4' => 'field_profile_sponsor_state',
      '5' => 'field_profile_sponsor_phone',
      '6' => 'field_profile_sponsor_mobile',
      '7' => 'field_profile_sponsor_email',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Examination Results (Second Sitting)');
  t('Health Information');
  t('Next of Kin Information');
  t('Please enter your O-level (or equivalent) Examination Results (First Sitting)');
  t('Please enter your O-level (sitting 2) Results. Direct Entry Students please enter your A-level (or equivalent) Results');
  t('Sponsor\'s Information');

  return $groups;
}
