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
    p.field_programme_name_value AS programme_name,
    d.field_department_name_value AS department_name,
    co.field_college_name_value AS college_name
  FROM
    {admitted_student} a
    LEFT JOIN {title} t ON a.title=t.title_id
    LEFT JOIN {country} c ON a.nationality=c.country_id
    LEFT JOIN {lga} l ON a.lkup_lga_origin=l.lga_id
    LEFT JOIN {state} s ON a.permanent_address_state=s.state_id
    LEFT JOIN {state} s0 ON a.state_origin=s0.state_id
    LEFT JOIN {content_type_program} p ON a.first_choice=p.nid
    LEFT JOIN {level} lev ON a.level_id=lev.level_id
    LEFT JOIN {content_type_department} d ON p.field_department_id_nid=d.nid
    LEFT JOIN {content_type_college} co ON d.field_college_id_nid=co.nid
  WHERE a.student_id=%d";
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

  foreach ($addprofile as $profile_key => $value) {
    db_query("DELETE FROM {profile_values}
      USING {profile_values}, {profile_fields} pf
      WHERE {profile_values}.uid=%d AND {profile_values}.fid=pf.fid AND pf.name='%s'", $uid, $profile_key);
    db_query("INSERT INTO {profile_values} SELECT pf.fid, %d AS uid, '%s' AS value FROM {profile_fields} pf WHERE pf.name='%s'", $uid, $value, $profile_key);
  }
}
?>
