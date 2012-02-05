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
  $strongarm->name = 'comment_anonymous_student_clearance';
  $strongarm->value = 0;
  $export['comment_anonymous_student_clearance'] = $strongarm;

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
  $strongarm->name = 'comment_controls_student_clearance';
  $strongarm->value = '3';
  $export['comment_controls_student_clearance'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_clearance_agreement';
  $strongarm->value = '4';
  $export['comment_default_mode_clearance_agreement'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_student_clearance';
  $strongarm->value = '4';
  $export['comment_default_mode_student_clearance'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_clearance_agreement';
  $strongarm->value = '1';
  $export['comment_default_order_clearance_agreement'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_student_clearance';
  $strongarm->value = '1';
  $export['comment_default_order_student_clearance'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_clearance_agreement';
  $strongarm->value = '50';
  $export['comment_default_per_page_clearance_agreement'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_student_clearance';
  $strongarm->value = '50';
  $export['comment_default_per_page_student_clearance'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_clearance_agreement';
  $strongarm->value = '0';
  $export['comment_form_location_clearance_agreement'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_student_clearance';
  $strongarm->value = '0';
  $export['comment_form_location_student_clearance'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_clearance_agreement';
  $strongarm->value = '1';
  $export['comment_preview_clearance_agreement'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_student_clearance';
  $strongarm->value = '1';
  $export['comment_preview_student_clearance'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_student_clearance';
  $strongarm->value = '0';
  $export['comment_student_clearance'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_clearance_agreement';
  $strongarm->value = '1';
  $export['comment_subject_field_clearance_agreement'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_student_clearance';
  $strongarm->value = '0';
  $export['comment_subject_field_student_clearance'] = $strongarm;

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
  $strongarm->name = 'content_extra_weights_student_clearance';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '20',
    'author' => '20',
    'options' => '25',
    'menu' => '-2',
    'path' => '30',
    'print' => '30',
  );
  $export['content_extra_weights_student_clearance'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_clearance_agreement';
  $strongarm->value = 0;
  $export['content_profile_use_clearance_agreement'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eduerp_agreement';
  $strongarm->value = '
<p>USMANU DANFODIYO UNIVERSITY</p>
<p>P.M.B. 2346, SOKOTO, NIGERIA</p>
<p>OFFICE OF THE REGISTRAR</p>
<p>Date: [site-date-timestamp-raw]</p>
<p>Name of Candidate: [field_profile_first_name-raw] [field_profile_middle_name-raw] [field_profile_last_name-raw]</p>
<p>2011/2012 SESSION CONFIRMATION OF ADMISSION</p>
<p>This is to confirm that the above named has been offered Provisional admission into the Usmanu Danfodiyo University, Sokoto in 2011/2012 Academic Session.</p>
<p>The Candidate has been admitted to read: [programme] [level] level in the Faculty/College of [faculty]. His/her admission number is [matric_number]. Faculties and Departments are requested to note and register the Candidate accordingly subject to the candidate&#39;s acceptance of the undertaking below.</p>
<p>Thank you</p>
<p>&nbsp;</p>
<p>For: Registrar</p>
<p>UNDERTAKING</p>
<p>I [field_profile_first_name-raw] [field_profile_middle_name-raw] [field_profile_last_name-raw] the undersigned, hereby accept the provisional admission pending the verification of my entry qualifications by the University within the duration of the study. I further accept that this offer may be withdrawn by the University within the duration of the study if it is discovered that I have not satisfied the entry requirements or that my entry qualification is otherwise than as presented at the time of registration.</p>
<p>To this end, I undertake to bring certified proof(s) of my qualification (e.g. SSCE, IJMB, NCE, etc.) from awarding examination bodies within one year.</p>
<p>Dated this [site-date-dd]-[site-date-mm]-[site-date-yyyy]</p>
<p>[field_profile_signature-filefield-view]</p>
<p>Signature of Student.</p>
';
  $export['eduerp_agreement'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'form_build_id_clearance_agreement';
  $strongarm->value = 'form-e5f9748421785c9f70d7b24b11f9d74a';
  $export['form_build_id_clearance_agreement'] = $strongarm;

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
  $strongarm->name = 'node_options_student_clearance';
  $strongarm->value = array();
  $export['node_options_student_clearance'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_clearance_agreement';
  $strongarm->value = '1';
  $export['upload_clearance_agreement'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_student_clearance';
  $strongarm->value = '0';
  $export['upload_student_clearance'] = $strongarm;

  return $export;
}
