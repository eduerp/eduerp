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

/**
 * class definition for User profiles
 * @var int $uid stores the userid that is being used to retrieve the profile nodes
 * @var array $field_map field map is used to store the node/field mapping
 * @var array $profile_nodes stores the node objects used as content profiles for the user
 */
class UserProfile {
  var $uid;
  var $field_map = array();
  var $profile_nodes = array();

  /**
   * class constructor - instantiates the object
   * and loads necessary nodes.
   * @var int $uid User id for the user
   * @return object
   */
  function __construct($uid) {
    $this->uid = $uid;

    // obtain all content profile types and use that to map
    // the fields to the object.
    $content_profiles = content_profile_get_types('names');

    // after obtainining the content profile types, we'll retrieve 
    // those that have been defined for this user.
    foreach ($content_profiles as $content_profile => $content_profile_name) {
      if ($node = eduerp_load_profile($this->uid, $content_profile)) {
        $this->profile_nodes[$content_profile] = $node;
      }
    }

    $this->_hydrate_fields();
  }

  /**
   * _hydrate_fields - loads fields from the content profile nodes
   * @return void
   */
  private function _hydrate_fields() {
    foreach ($this->profile_nodes as $node) {
      // obtain visible properties for nodes and set them
      // it sets $this->profile_first_name = $node->field_profile_first_name
      // for instance
      foreach ($node as $key => $value) {
        if (preg_match('/^field\_(.*)/', $key, $matches)) {
          $node_value = $node->$key;
          $this->$matches[1] = $node_value[0]['value'];
          $this->field_map[$matches[1]] = $node->type;
        }
      }
    }
  }

  /**
   * this method saves all the attached content profile nodes
   * @return void
   */
  public function save() {
    // iterate through all the profile fields and store
    // their values in the respective nodes
    foreach ($this as $key => $value) {
      if (isset($this->field_map[$key])) {
        $node_field_name = 'field_' . $key;
        // must be returned as a reference if not
        // it will not be saved.
        $node_field =& $this->profile_nodes[$this->field_map[$key]]->$node_field_name;
        $node_field[0]['value'] = $value;
      }
    }
    foreach ($this->profile_nodes as $node) {
      node_save($node);
    }
  }
}
