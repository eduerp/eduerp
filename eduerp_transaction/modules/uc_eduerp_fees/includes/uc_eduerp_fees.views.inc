<?php 

/**
 * Implementation of hook_views_data().
 */
function uc_eduerp_fees_views_data() {
  // uc_order_products table
  $order_products = drupal_get_schema('fees_order');
  $data['fees_order']['table']['group'] = t('Eduerp fees order');
  $data['fees_order']['table']['base'] = array(
    'field' => 'fees_order_id',
    'title' => t('Eduerp fees order'),
    'help' => t("Fees that have been ordered."),
  );
  $data['fees_order']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'nid',
  );
  
  // product_nid field.
  $data['fees_order']['product_nid'] = array(
    'title' => t('Product nid'), 
    'help' => $order_products['fields']['product_nid']['description'],
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );
  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function uc_eduerp_fees_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'uc_eduerp_fees') . '/includes',
    ),
    'handlers' => array(
       'uc_eduerp_fees_handler_field_order_id' => array( 'parent' => 'views_handler_field',),
    ),
  );
}