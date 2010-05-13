<?php
# Defines a set of library functions and helpers for use
# within EduERP

/**
 * loads a user's profile for reading and modification
 * @param int $uid specifies the user id of the profile to load
 * @param string $profile_type (optional) specifies the actual 
 *  profile type to load
 * @return object returns the profile node or false if there's none
 */
function eduerp_load_profile($uid, $profile_type = 'profile') {
  if ($node = node_load(array('type' => $profile_type, 'uid' => $uid))) {
    return $node;
  } else {
    return false;
  }
}

/**
 * saves a user profile node - nothing fanciful just a wrapper
 *
 * @param object $node
 * @return void since the node_save api function doesn't return 
 *  any status, we cannot return one.
 */
function eduerp_save_profile($node) {
  node_save($node);
}
