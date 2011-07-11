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

  // Exported permission: view field_agreement_agree
  $permissions['view field_agreement_agree'] = array(
    'name' => 'view field_agreement_agree',
    'roles' => array(
      '0' => 'Administrator',
    ),
  );

  return $permissions;
}
