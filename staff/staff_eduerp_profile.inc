<?php
// staff_eduerp_profile.inc Alan Barrett 20091112
// Save profile data from admitted_student into eduerp category of user profile


function save_staff_eduerp_profile($uid) {
  $sql = "SELECT
    a.user_id,
    CONCAT(UCASE(LEFT(a.staff_last_name, 1)), LCASE(SUBSTRING(a.staff_last_name, 2))) AS last_name,
    CONCAT(UCASE(LEFT(a.staff_first_name, 1)), LCASE(SUBSTRING(a.staff_first_name, 2))) AS first_name,
    CONCAT(UCASE(LEFT(a.staff_middle_name, 1)), LCASE(SUBSTRING(a.staff_middle_name, 2))) AS middle_name,
    a.dob
  FROM
    veritas_staff a
  WHERE a.user_id=%d";
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
    }
    else {
      if (is_null($value)) {
        $addprofile[$profile_key] = '';
      }
      else {
        $addprofile[$profile_key] = $value;
      }
    }
  }

  $addprofile['profile_title_name'] = '';
  $addprofile['profile_gender'] = '';
  $addprofile['profile_country_name'] = '';
  $addprofile['profile_lga_name'] = '';
  $addprofile['profile_state_name_origin'] = '';
  $addprofile['profile_permanent_address1'] = '';
  $addprofile['profile_permanent_address_city'] = '';
  $addprofile['profile_permanent_address_state'] = '';
  $addprofile['profile_mobile_number'] = '';
  $addprofile['profile_marital_status'] = '';
  $addprofile['profile_religion'] = '';
  $addprofile['profile_jambno'] = '';
  $addprofile['profile_mode_of_entry'] = '';
  $addprofile['profile_mode_of_study'] = '';
  $addprofile['profile_yearofentry'] = '';
  $addprofile['profile_level_id'] = '';
  $addprofile['profile_level_name'] = '';
  $addprofile['profile_first_choice'] = '';
  $addprofile['profile_programme_name'] = '';
  $addprofile['profile_department_name'] = '';
  $addprofile['profile_college_name'] = '';

  $userforprofile = new stdClass;
  $userforprofile->uid = $uid;
  profile_save_profile($addprofile, $userforprofile, 'eduerp');
}
?>
