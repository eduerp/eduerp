<?php

/**
 * Implementation of hook_strongarm().
 */
function student_registration_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_student_profile';
  $strongarm->value = 0;
  $export['comment_anonymous_student_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_student_profile';
  $strongarm->value = '3';
  $export['comment_controls_student_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_student_profile';
  $strongarm->value = '4';
  $export['comment_default_mode_student_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_student_profile';
  $strongarm->value = '1';
  $export['comment_default_order_student_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_student_profile';
  $strongarm->value = '50';
  $export['comment_default_per_page_student_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_student_profile';
  $strongarm->value = '0';
  $export['comment_form_location_student_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_student_profile';
  $strongarm->value = '1';
  $export['comment_preview_student_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_student_profile';
  $strongarm->value = '0';
  $export['comment_student_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_student_profile';
  $strongarm->value = '1';
  $export['comment_subject_field_student_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_student_profile';
  $strongarm->value = array(
    'title' => '1',
    'revision_information' => '3',
    'author' => '23',
    'options' => '24',
    'comment_settings' => '30',
    'menu' => '2',
    'path' => '4',
    'print' => '25',
  );
  $export['content_extra_weights_student_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_student_profile';
  $strongarm->value = array(
    'weight' => '1',
    'user_display' => 'full',
    'edit_link' => 0,
    'edit_tab' => 'sub',
    'add_link' => 1,
    'registration_use' => 1,
    'admin_user_create_use' => 0,
    'registration_hide' => array(),
  );
  $export['content_profile_student_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_student_profile';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_student_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_student_profile';
  $strongarm->value = '0';
  $export['upload_student_profile'] = $strongarm;

  return $export;
}
