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

  return $permissions;
}
