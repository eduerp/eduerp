<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function student_registration_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_health_information
  $groups['student_profile-group_health_information'] = array(
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
    'weight' => '12',
    'group_type' => 'standard',
    'fields' => array(
      '0' => 'field_profile_health_status',
      '1' => 'field_profile_health_disability',
    ),
  );

  // Exported group: group_next_of_kin_information
  $groups['student_profile-group_next_of_kin_information'] = array(
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
    'weight' => '11',
    'group_type' => 'standard',
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

  // Exported group: group_olevels_first
  $groups['student_profile-group_olevels_first'] = array(
    'type_name' => 'student_profile',
    'group_name' => 'group_olevels_first',
    'label' => 'O Level Results (First Sitting)',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '15',
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
    'weight' => '15',
    'group_type' => 'standard',
    'fields' => array(
      '0' => 'field_profile_olevel_qual_1',
      '1' => 'field_profile_olevel_insti1',
      '2' => 'field_profile_olevel_exams_1',
    ),
  );

  // Exported group: group_olevels_second
  $groups['student_profile-group_olevels_second'] = array(
    'type_name' => 'student_profile',
    'group_name' => 'group_olevels_second',
    'label' => 'O Level Results (Second Sitting)',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '16',
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
    'weight' => '16',
    'group_type' => 'standard',
    'fields' => array(
      '0' => 'field_profile_olevel_qual_2',
      '1' => 'field_profile_olevel_insti2',
      '2' => 'field_profile_olevel_exams_2',
    ),
  );

  // Exported group: group_sponsor_information
  $groups['student_profile-group_sponsor_information'] = array(
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
    'weight' => '10',
    'group_type' => 'standard',
    'fields' => array(
      '0' => 'field_profile_sponsor_name',
      '1' => 'field_profile_sponsor_address',
      '2' => 'field_profile_sponsor_city',
      '3' => 'field_profile_sponsor_state',
      '4' => 'field_profile_sponsor_phone',
      '5' => 'field_profile_sponsor_mobile',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Health Information');
  t('Next of Kin Information');
  t('O Level Results (First Sitting)');
  t('O Level Results (Second Sitting)');
  t('Sponsor\'s Information');

  return $groups;
}
