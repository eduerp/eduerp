<?php 

/**
 * Get a value from an array. 
 * Works on both singular and multi-dimensional array
 */ 
function array_value($items, $value) {
  return in_array($value, $items) ? $value : NULL;
}

/**
 * Checks if an array value exists in an array
 * @returns
 *  - boolean
 */ 
function array_in_array($arr, $haystack) {
  $exists = TRUE;
  if(is_array($arr)) {
    foreach($arr as $value) {
      $exists = (in_array($value, $haystack));
    }
    if($exists) {
      return TRUE;
    }
    return FALSE;
    }
  }