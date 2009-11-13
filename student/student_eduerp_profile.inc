<?php
// student_eduerp_profile.inc Alan Barrett 20091111
// Save profile data from admitted_student into eduerp category of user profile


function save_student_eduerp_profile($uid) {
  $sql = "SELECT
    a.student_id,
    CONCAT(UCASE(LEFT(a.last_name, 1)), LCASE(SUBSTRING(a.last_name, 2))) AS last_name,
    CONCAT(UCASE(LEFT(a.first_name, 1)), LCASE(SUBSTRING(a.first_name, 2))) AS first_name,
    CONCAT(UCASE(LEFT(a.middle_name, 1)), LCASE(SUBSTRING(a.middle_name, 2))) AS middle_name,
    t.title_name,
    a.gender,
    a.dob,
    c.country_name,
    l.lga_name,
    s0.state_name AS state_name_origin,
    a.permanent_address1,
    a.permanent_address_city,
    s.state_name AS permanent_address_state,
    a.mobile_number,
    a.marital_status,
    a.religion,
    a.jambno,
    a.mode_of_entry,
    a.mode_of_study,
    a.yearofentry,
    a.level_id,
    lev.level_name,
    a.first_choice,
    p.programme_name,
    d.department_name,
    co.college_name
  FROM
    admitted_student a
    LEFT JOIN title t ON a.title=t.title_id
    LEFT JOIN country c ON a.nationality=c.country_id
    LEFT JOIN lga l ON a.lkup_lga_origin=l.lga_id
    LEFT JOIN state s ON a.permanent_address_state=s.state_id
    LEFT JOIN state s0 ON a.state_origin=s0.state_id
    LEFT JOIN programme p ON a.first_choice=p.programme_id
    LEFT JOIN level lev ON a.level_id=lev.level_id
    LEFT JOIN department d ON p.department_id=d.department_id
    LEFT JOIN college co ON d.college_id=co.college_id
  WHERE a.student_id=%d";
  $admitteds = db_query($sql, $uid);
  $admitted = db_fetch_array($admitteds);

  $addprofile = array();
  foreach ($admitted as $key => $value) {
    $profile_key = 'profile_' . $key;

    if ($key === 'dob') {
      $addprofile[$profile_key] = array(
          'year'  => (int)substr($value, 0, 4),
          'month' => (int)substr($value, 5, 2),
          'day'   => (int)substr($value, 8, 2)
        );
      //echo $key . ': ' . $value . '<br />';
    }
    else {
      if (is_null($value)) {
        $addprofile[$profile_key] = '';
      }
      else {
        $addprofile[$profile_key] = $value;
      }
      //echo $key . ': ' . $addprofile[$profile_key] . '<br />';
    }
  }

  $userforprofile = new stdClass;
  $userforprofile->uid = $admitted['student_id'];
  profile_save_profile($addprofile, $userforprofile, 'eduerp');
}
?>
