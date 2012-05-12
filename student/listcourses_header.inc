<?php
/**
 * Header for listcourses View 20100228
 */

global $user;

$user_profile = new UserProfile($user->uid);

$studentname = '';
if (!empty($user_profile->profile_first_name) && !empty($user_profile->profile_last_name)) {
  $middle = '';
  if (!empty($user_profile->profile_middle_name)) $middle = ' ' . $user_profile->profile_middle_name;
  $studentname = "{$user_profile->profile_last_name}, {$user_profile->profile_first_name}{$middle}";
}

$result = db_query("SELECT field_programme_name_value FROM {content_type_program} WHERE nid=%d", $user_profile->profile_first_choice);
$row = db_fetch_object($result);

$session = variable_get('eduerp_current_session', '');

echo "<b>Name: $studentname<br />
Admission Number: $user->name<br />
Program Name: $row->field_programme_name_value<br />
Current Session: $session<br /><br /></b>";
?>
