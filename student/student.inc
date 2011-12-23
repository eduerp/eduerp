<?php 

class student {
  
  protected $uid;
  protected $db_table = 'student_profile';
  protected $profile;
  protected $programme;
  protected $level;
  protected $signature;
  protected $age;
  protected $gender;
  protected $firstname;
  protected $middlename;
  protected $lastname;
  protected $fullnames;
  protected $matric_number;
  protected $picture;
  protected $department;
  protected $state;
  protected $lga;
  protected $religion;
  protected $permanent_address;
  protected $permanent_city;
  protected $permanent_state;
  protected $marital_status;
  protected $country_name;
  protected $dob;
  protected $mobile_number;
  protected $title;
  
  public function __construct($uid) {
    $this->uid = $uid;
    $this->profile = content_profile_load($db_table, $this->uid);
  }
  public function get_programme($nid) {
    $prog_field = 'field_programme_name_value';
    $query = db_query("SELECT " . $prog_field . "
    FROM {content_type_program} p
    WHERE p.nid = %d", $nid);
    
    $this->programme = db_result($query);
    return $this->programme;
  }
}