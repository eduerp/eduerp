<?php
/**
 * Global eduerp utility functions
 */

/**
 * Checks if a particular account has a certain role
 * @param object $account - The user account to check
 * @param mixed $role - role is either int (role id) or string (role name)
 * @return bool
 */
function eduerp_has_role($account, $role_param) {
  $roles_list = $account->roles;
  if (is_int($role)) {
    if (array_key_exists($role_param, $roles_list)) return true;
    return false;
  }
  else {
    if (array_search($role_param, $roles_list)) return true;
    return false;
  }
}

/**
 * Fetches the role id for a particular role
 * @param string $role - the role
 * @return int - 0 for not found or the id for the role
 */
function _eduerp_get_role_id ($role) {
  $query = "select * from {role} where name='%s'";
  $rs = db_query($query, $role);
  if ($rs) {
    $result = db_fetch_object($rs);
    return $result->rid;
  } else {
    return 0;
  }
}

/**
 * Fetches the role name for a particular role id
 * @param string $rid - the role id
 * @return mixed - false if not found or the role name if found
 */
function _eduerp_get_role ($rid) {
  $query = "select * from {role} where rid=%d";
  $rs = db_query($query, $role);
  if ($rs) {
    $result = db_fetch_object($rs);
    return $result->name;
  } else {
    return false;
  }
}

/**
 * Deletes a particular role from a user's account - USE WITH CARE!
 * @param object $account - the user object
 * @param string $role - The role to delete
 * @return bool - true on success, else false
 */
function eduerp_delete_role($account, $role) {
  $roles = &$account->roles;
  $rid = _eduerp_get_role_id($role);
  if ($rid) {
    unset($roles[$rid]);
    user_save($account, array('roles' => $roles));
    return true;
  }
  return false;
}

/**
 * Adds a particular role to a user's account
 * @param object $account - the user object
 * @param string $role - the role to add
 * @return bool - true on success, else false
 */
function eduerp_add_role($account, $role) {
  $roles = &$account->roles;
  $rid = _eduerp_get_role_id($role);
  if ($rid) {
    if (!array_key_exists($rid, $roles)) {
      $roles = $roles + array($rid => _eduerp_get_role($rid));
      user_save($account, array('roles' => $roles));
      return true;
    }
  }
  return false;
}

/**
 * Sets a particular role to a user's account
 * @param object $account - the user object
 * @param string $role - the role to set
 * @return bool - true on success, else false
 */
function eduerp_set_role($account, $role) {
  $rid = _eduerp_get_role_id($role);
  if ($rid) {
    $set_role = array($rid => _eduerp_get_role($rid));
    user_save($account, array('roles' => $set_role));
    return true;
  }
  return false;
}

