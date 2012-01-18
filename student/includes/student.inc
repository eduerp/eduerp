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
  protected $faculty;
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
  
  public function get_programme_object($nid) {
    $program_obj = db_fetch_object(db_query("SELECT * FROM 
    {content_type_program} p
    WHERE p.nid = %d", $nid));
    
    return $program_obj;
  }
  
  public function get_department_nid($prog_nid) {
    $programme = $this->get_programme_object($prog_nid);
    $dept_nid = $programme->field_department_id_nid;
    
    return $dept_nid;
  }
  
  public function get_college_nid($dept_nid) {
    $college_id = db_result(db_query("SELECT field_college_id_nid
        FROM {content_type_department} d
        WHERE d.nid = %d", $dept_nid));
        
    return $college_id;
  }
  
  public function get_faculty($college_id) {
    $faculty = db_result(db_query("SELECT field_college_name_value
        FROM {content_type_college} c
        WHERE c.nid = %d", $college_id));
    $this->faculty = $faculty;
    return $this->faculty;
  }
  
  // get all content profile fields
  // go through drupal_get_schema
  public function get_all_fields() {
    
  }
  
}