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
