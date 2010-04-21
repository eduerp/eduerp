<?php
// staff_eduerp_profile.inc Alan Barrett 20091112
// Save profile data from veritas_staff into eduerp category of user profile


function save_staff_eduerp_profile($uid) {
  $sql = "SELECT
    a.user_id,
    CONCAT(UCASE(LEFT(a.staff_last_name, 1)), LCASE(SUBSTRING(a.staff_last_name, 2))) AS last_name,
    CONCAT(UCASE(LEFT(a.staff_first_name, 1)), LCASE(SUBSTRING(a.staff_first_name, 2))) AS first_name,
    CONCAT(UCASE(LEFT(a.staff_middle_name, 1)), LCASE(SUBSTRING(a.staff_middle_name, 2))) AS middle_name,
    a.dob,
    t.title_name,
    IF(a.gender='F', 'female', 'male') AS gender,
    c.country_name,
    l.lga_name,
    s0.state_name AS state_name_origin,
    a.permanent_home_address AS permanent_address1,
    a.permanent_city_address AS permanent_address_city,
    a.gsm AS mobile_number,
    a.marital_status,
    d.field_department_name_value AS department_name,
    co.field_college_name_value AS college_name
  FROM
    {veritas_staff} a
    LEFT JOIN {title} t ON a.staff_title=t.title_id
    LEFT JOIN {country} c ON a.nationality=c.country_id
    LEFT JOIN {lga} l ON a.lga=l.lga_id
    LEFT JOIN {state} s0 ON a.state=s0.state_id
    LEFT JOIN {content_type_department} d ON a.department_id=d.nid
    LEFT JOIN {content_type_college} co ON d.field_college_id_nid=co.nid
  WHERE a.user_id=%d";
  $admitteds = db_query($sql, $uid);
  $admitted = db_fetch_array($admitteds);

  $addprofile = array();
  foreach ($admitted as $key => $value) {
    $profile_key = 'profile_' . $key;

    if ($key === 'dob') {
      $addprofile[$profile_key] = serialize(array(
          'year'  => (int)substr($value, 0, 4),
          'month' => (int)substr($value, 5, 2),
          'day'   => (int)substr($value, 8, 2)
        ));
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

  $addprofile['profile_permanent_address_state'] = '';
  $addprofile['profile_religion'] = '';
  $addprofile['profile_jambno'] = '';
  $addprofile['profile_mode_of_entry'] = '';
  $addprofile['profile_mode_of_study'] = '';
  $addprofile['profile_yearofentry'] = '';
  $addprofile['profile_level_id'] = '';
  $addprofile['profile_level_name'] = '';
  $addprofile['profile_first_choice'] = '';
  $addprofile['profile_programme_name'] = '';

  foreach ($addprofile as $profile_key => $value) {
    db_query("DELETE FROM {profile_values}
      USING {profile_values}, {profile_fields} pf
      WHERE {profile_values}.uid=%d AND {profile_values}.fid=pf.fid AND pf.name='%s'", $uid, $profile_key);
    db_query("INSERT INTO {profile_values} SELECT pf.fid, %d AS uid, '%s' AS value FROM {profile_fields} pf WHERE pf.name='%s'", $uid, $value, $profile_key);
  }

  // Do Staff specific profile values
  $sql = "SELECT
    a.user_id,
    a.staff_no,
    ve.name AS employment_type,
    st.staff_type_name AS staff_type,
    a.department_id
  FROM
    {veritas_staff} a
    LEFT JOIN {veritas_employment_type} ve ON a.employment_type_id=ve.id
    LEFT JOIN {veritas_staff_type} st ON a.staff_type_id=st.staff_type_id
  WHERE a.user_id=%d";
  $admitteds = db_query($sql, $uid);
  $admitted = db_fetch_array($admitteds);

  foreach ($admitted as $key => $value) {
    $profile_key = 'profile_' . $key;
    if (is_null($value)) $value = '';

    db_query("DELETE FROM {profile_values}
      USING {profile_values}, {profile_fields} pf
      WHERE {profile_values}.uid=%d AND {profile_values}.fid=pf.fid AND pf.name='%s'", $uid, $profile_key);
    db_query("INSERT INTO {profile_values} SELECT pf.fid, %d AS uid, '%s' AS value FROM {profile_fields} pf WHERE pf.name='%s'", $uid, $value, $profile_key);
  }
}
?>
