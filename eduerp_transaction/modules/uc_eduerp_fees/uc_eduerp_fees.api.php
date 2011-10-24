<?php 

/**
 * @file
 * 
 * Documentation of all hooks in uc_eduerp_fees module
 */ 

 /**
 * Declare fees.
 *
 * This hook is invoked from uc_eduerp_fees_add_to_cart() to get the list fee items to be
 * added to cart. 
 *
 * @param $fees
 *   The fees object which is a node object.
 *
 * @ingroup node_api_hooks
 * @ingroup hooks
 */
function hook_eduerp_fees($fees) {
  $fees = array();
  $fees['fees_name'] = array(
    'item' => 'The fees item',
    'description' => t('Fees description'),
    'options' => 'Any other options array to pass along'
  );
  return $fees;
}
/**
 * Alter fees.
 *
 * This hook is invoked from uc_eduerp_fees_pay_fees() to alter the 
 * elements in the fees structure
 *
 * @param $items
 *   The item in the fees to alter. You can also use it to inject
 *   your own fees elements
 *
 * @ingroup uc_eduerp_fees_api_hooks
 * @ingroup hooks
 */
function hook_eduerp_fees_alter(&$items) {
  // Items is passed by reference. So you can modify it
  $value = array();
  return $value;
}