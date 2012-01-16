<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function student_clearance_user_default_permissions() {
  $permissions = array();

  // Exported permission: create clearance_agreement content
  $permissions['create clearance_agreement content'] = array(
    'name' => 'create clearance_agreement content',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Registry',
      '2' => 'Staff',
      '3' => 'Student',
    ),
  );

  // Exported permission: edit field_agreement_agree
  $permissions['edit field_agreement_agree'] = array(
    'name' => 'edit field_agreement_agree',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Student',
    ),
  );

  // Exported permission: edit field_clearance_date
  $permissions['edit field_clearance_date'] = array(
    'name' => 'edit field_clearance_date',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Registry',
    ),
  );

  // Exported permission: edit field_clearance_uncleared
  $permissions['edit field_clearance_uncleared'] = array(
    'name' => 'edit field_clearance_uncleared',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Registry',
      '2' => 'Staff',
    ),
  );

  // Exported permission: edit field_deferred
  $permissions['edit field_deferred'] = array(
    'name' => 'edit field_deferred',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Registry',
    ),
  );

  // Exported permission: edit field_staff_clearance
  $permissions['edit field_staff_clearance'] = array(
    'name' => 'edit field_staff_clearance',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Registry',
    ),
  );

  // Exported permission: edit field_staff_verification
  $permissions['edit field_staff_verification'] = array(
    'name' => 'edit field_staff_verification',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Registry',
    ),
  );

  // Exported permission: edit field_student
  $permissions['edit field_student'] = array(
    'name' => 'edit field_student',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Registry',
    ),
  );

  // Exported permission: edit field_uncleared_reasons
  $permissions['edit field_uncleared_reasons'] = array(
    'name' => 'edit field_uncleared_reasons',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Registry',
    ),
  );

  // Exported permission: edit field_verification_date
  $permissions['edit field_verification_date'] = array(
    'name' => 'edit field_verification_date',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Registry',
    ),
  );

  // Exported permission: view field_agreement_agree
  $permissions['view field_agreement_agree'] = array(
    'name' => 'view field_agreement_agree',
    'roles' => array(
      '0' => 'Administrator',
    ),
  );

  // Exported permission: view field_clearance_date
  $permissions['view field_clearance_date'] = array(
    'name' => 'view field_clearance_date',
    'roles' => array(
      '0' => 'Registry',
    ),
  );

  // Exported permission: view field_clearance_uncleared
  $permissions['view field_clearance_uncleared'] = array(
    'name' => 'view field_clearance_uncleared',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Registry',
      '2' => 'Staff',
    ),
  );

  // Exported permission: view field_deferred
  $permissions['view field_deferred'] = array(
    'name' => 'view field_deferred',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Registry',
    ),
  );

  // Exported permission: view field_staff_clearance
  $permissions['view field_staff_clearance'] = array(
    'name' => 'view field_staff_clearance',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Registry',
    ),
  );

  // Exported permission: view field_staff_verification
  $permissions['view field_staff_verification'] = array(
    'name' => 'view field_staff_verification',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Registry',
    ),
  );

  // Exported permission: view field_student
  $permissions['view field_student'] = array(
    'name' => 'view field_student',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Registry',
    ),
  );

  // Exported permission: view field_uncleared_reasons
  $permissions['view field_uncleared_reasons'] = array(
    'name' => 'view field_uncleared_reasons',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Registry',
    ),
  );

  // Exported permission: view field_verification_date
  $permissions['view field_verification_date'] = array(
    'name' => 'view field_verification_date',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Registry',
    ),
  );

  return $permissions;
}
