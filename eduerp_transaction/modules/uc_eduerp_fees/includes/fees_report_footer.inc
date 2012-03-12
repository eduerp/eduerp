<?php
// fees_report_footer.inc 20120307

// NOTE: if Filters in the view are changed in any way or are added to, this code needs to be updated!!!
// Even changing a filter to "Remember" a setting will cause issues (because $_SESSION['views']['fees_summary']['default'] will need to be used).

$admission = $_REQUEST['admission'];
if (empty($admission)) $admission = '';

$session = $_REQUEST['session'];
if (empty($session)) $session = '';

$course = $_REQUEST['course'];
if (empty($course)) $course = '';

$college = $_REQUEST['college'];
if (empty($college)) $college = '';
if ($college == 'All') $college = '';

$sponsor = $_REQUEST['sponsor'];
if (empty($sponsor)) $sponsor = '';
if ($sponsor == 'All') $sponsor = '';

$status = $_SESSION['views']['fees_summary']['default']['status'];

$level_name = $_REQUEST['level_name'];
if (empty($level_name)) $level_name = '';

$type = $_REQUEST['type'];
if (empty($type)) $type = '';
if ($type == 'All') $type = '';

$scholarship_type = $_REQUEST['scholarship_type'];
if (empty($scholarship_type)) $scholarship_type = '';
if ($scholarship_type == 'All') $scholarship_type = '';

$date = $_SESSION['views']['fees_summary']['default']['date'];
$date_min = $date['min'];
$date_max = $date['max'];
if (empty($date_min) || empty ($date_max)) {
  $date_min = '';
  $date_max = '';
}
else {
  $date_min = intval(strtotime($date_min, 0));
  $date_max = intval(strtotime($date_max, 0));
}

$bank = $_SESSION['views']['fees_summary']['default']['bank'];
if (empty($bank)) $bank = '';

$sql = "
SELECT SUM(original_amount) AS paid_incl_scholarships, SUM(price) AS paid_directly
FROM node node
LEFT JOIN fees_order fees_order ON node.nid = fees_order.nid
LEFT JOIN content_type_school_fee_item_setup node_data_field_fee_structure_name ON node.vid = node_data_field_fee_structure_name.vid
WHERE
  ((fees_order.jambno) LIKE ('%%%s%%')) AND
  ((fees_order.session) LIKE ('%%%s%%')) AND
  ((fees_order.course) LIKE ('%%%s%%')) AND ";
  if ($college != '') $sql .= "(fees_order.college = '%s') AND "; else $sql .= '%s';
  if ($sponsor != '') $sql .= "(fees_order.sponsor IN ('%s')) AND "; else $sql .= '%s';
  if (!empty($status)) $sql .= "(fees_order.status in ('" . implode("','", $status) . "')) AND ";
  $sql .= "
  ((fees_order.level_name) LIKE ('%%%s%%')) AND ";
  if ($type != '') $sql .= "(fees_order.type IN ('%s')) AND "; else $sql .= '%s';
  if ($scholarship_type != '') $sql .= "(fees_order.scholarship_type IN ('%s')) AND "; else $sql .= '%s';
  if ($date_min != '') $sql .= "(fees_order.expiry_date >= %s) AND (fees_order.expiry_date <= %s) AND "; else  $sql .= '%s %s';
  $sql .= "
  ((fees_order.email) LIKE ('%%%s%%'))";

//dsm(array(
//'SESSION' => $_SESSION,
//'sql' => $sql,
//'admission' => $admission,
//'session' => $session,
//'course' => $course,
//'college' => $college,
//'sponsor' => $sponsor,
//'status' => $status,
//'level_name' => $level_name,
//'type' => $type,
//'scholarship_type' => $scholarship_type,
//'date' => $date,
//'bank' => $bank,
//));//ab


$rs = db_query($sql, $admission, $session, $course, $college, $sponsor, $level_name, $type, $scholarship_type, $date_min, $date_max, $bank);
$row = db_fetch_object($rs);

$output  = "<p>Total Fees Paid by Students plus Scholarships: <b>" . number_format($row->paid_incl_scholarships) . "</b></p>";
$output .= "<p>Total Fees Paid by Students Directly: <b>" . number_format($row->paid_directly) . "</b></p>";
print $output;
?>