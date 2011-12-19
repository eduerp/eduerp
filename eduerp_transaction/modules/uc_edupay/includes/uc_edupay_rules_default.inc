<?php 

/**
 * @file 
 * Rules exports for uc_edupay
 * 
 * @author Kayode Odeyemi
 */ 

/**
 * Implementation of hook_rules_defaults().
 */
function uc_edupay_rules_defaults() {
  return array (
  'rules' => 
  array (
    'rules_generate_a_pdf_invoice' => 
    array (
      '#type' => 'rule',
      '#set' => 'event_uc_rules_order_checkout_complete',
      '#label' => 'Generate a PDF invoice',
      '#active' => 1,
      '#weight' => '0',
      '#categories' => 
      array (
        0 => 'uc_edupay',
      ),
      '#status' => 'custom',
      '#conditions' => 
      array (
        0 => 
        array (
          '#weight' => 0,
          '#info' => 
          array (
            'label' => 'Filter order by status',
            'arguments' => 
            array (
              'uc_order' => 
              array (
                'type' => 'uc_order',
                'label' => 'Ubercart Order',
              ),
            ),
            'module' => 'Ubercart Rules',
            'eval input' => 
            array (
              0 => 'status',
            ),
          ),
          '#name' => 'uc_rules_order_has_status',
          '#settings' => 
          array (
            'status' => 
            array (
              'pending' => 'pending',
              'payment_received' => 'payment_received',
              'completed' => 'completed',
            ),
          ),
          '#type' => 'condition',
        ),
      ),
      '#actions' => 
      array (
        0 => 
        array (
          '#weight' => 0,
          '#type' => 'action',
          '#settings' => 
          array (
            'views_pdf' => 'pdf_invoice',
            'arguments' => '[uc_order:uc_order_id]',
            'path' => 'sites/default/files/pdf_[uc_order:uc_order_id].pdf',
            'display' => 'pdf_1',
            '#eval input' => 
            array (
              'token_rules_input_evaluator' => 
              array (
                'path' => 
                array (
                  0 => 'uc_order',
                ),
                'arguments' => 
                array (
                  0 => 'uc_order',
                ),
              ),
            ),
          ),
          '#name' => 'views_pdf_rules_action_save',
          '#info' => 
          array (
            'label' => 'Save PDF as file on server',
            'module' => 'Views PDF',
            'eval input' => 
            array (
              0 => 'views_pdf',
              1 => 'path',
              2 => 'arguments',
            ),
          ),
        ),
      ),
      '#version' => 6003,
    ),
  ),
  );
}