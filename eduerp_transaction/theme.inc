<?php
/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

 /**
  * 
	* @deprecated
	*/ 
function theme_eduerp_transaction_display_reservation_info() {
    $output = t('eduerp_transaction_display_reservation_info is called');
    return $output;
}

/**
 * The overview page render of Eduerp Transaction
 * 
 */ 
function theme_eduerp_transaction_overview() {
	$output = '<p><div>';
	$output .= t('"Eduerp transaction" contains modules to help with integration into a payment system to perform transactions such as collection and processing of fees.');
	$output .= '<p>' . t('It contains the ability to process the transaction concurrently taking into consideration expiration date, transaction status, the user making the transaction and other parameters to make the transaction successful') . '</p>';
	$items = array(
		l('Eduerp Fees', ''),
		l('Edupay', '')
	);
	$output .= '<p>' . theme('item_list', $items) . '</p>';
	$output .= '</div></p>';
	return $output;
}
