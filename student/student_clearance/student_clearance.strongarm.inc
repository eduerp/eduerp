<?php

/**
 * Implementation of hook_strongarm().
 */
function student_clearance_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_clearance_agreement';
  $strongarm->value = 0;

  $export['comment_anonymous_clearance_agreement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_clearance_agreement';
  $strongarm->value = '0';

  $export['comment_clearance_agreement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_clearance_agreement';
  $strongarm->value = '3';

  $export['comment_controls_clearance_agreement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_clearance_agreement';
  $strongarm->value = '4';

  $export['comment_default_mode_clearance_agreement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_clearance_agreement';
  $strongarm->value = '1';

  $export['comment_default_order_clearance_agreement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_clearance_agreement';
  $strongarm->value = '50';

  $export['comment_default_per_page_clearance_agreement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_clearance_agreement';
  $strongarm->value = '0';

  $export['comment_form_location_clearance_agreement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_clearance_agreement';
  $strongarm->value = '1';

  $export['comment_preview_clearance_agreement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_clearance_agreement';
  $strongarm->value = '1';

  $export['comment_subject_field_clearance_agreement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_clearance_agreement';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-3',
    'revision_information' => '-1',
    'author' => '0',
    'options' => '1',
    'comment_settings' => '4',
    'menu' => '-4',
    'path' => '3',
    'attachments' => '2',
  );

  $export['content_extra_weights_clearance_agreement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_clearance_agreement';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_clearance_agreement'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_clearance_agreement';
  $strongarm->value = '1';

  $export['upload_clearance_agreement'] = $strongarm;
  return $export;
}
