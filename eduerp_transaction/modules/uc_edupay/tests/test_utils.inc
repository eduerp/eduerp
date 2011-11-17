<?php 

/**
 * @file 
 * Utility functions for simpletest
 */ 

/**
 * Create fees_order table if it doesn't exist
 */ 
function uc_edupay_create_table() {
  $ret = array();
  if(!db_table_exists('fees_order')) {
    $table = drupal_get_schema('fees_order');
    return db_create_table($ret, 'fees_order', $table);
  }
}