<?php

/**
 * load_fixtures loads fixtures stored in files into the table defined in the 
 * function call.  It's important that the order of the fields match with the 
 * order in which the fixtures were saved as this function does not do such 
 * checks and validation
 * @param string $table - the table to be imported into
 * @param string $fixtures_file - the filename of the file to be imported from
 * @param bool $flush_table - if the table should be flushed first before importing
 * @return bool - true on success, false on failure
 */
function load_fixtures($table, $fixtures_file, $flush_table = false) {
  // confirm file existence
  if (!file_exists($fixtures_file)) return false;

  $fh = fopen($fixtures_file, "r");

  if ($flush_table) {
    // Sorry this only works for MySQL at the moment
    $sql = sprintf("TRUNCATE {%s}", $table);
    db_query($sql);
  }
  while ($row = fgetcsv($fh)) {
    $values = "";
    foreach ($row as $item) {
      $values .= sprintf("\"%s\",", $item);
    }
    $values = rtrim($values, ",");
    if ($values) $sql = sprintf("INSERT INTO {%s} VALUES (%s)", $table, $values);
    db_query($sql);
  }
}

?>
