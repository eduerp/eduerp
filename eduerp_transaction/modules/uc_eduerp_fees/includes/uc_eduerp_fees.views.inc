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
  
  $data['fees_order']['table']['join']['uc_orders'] = array(
    'left_field' => 'order_id',
    'field' => 'order_id',
  );
  
  // This table references the {content_type_program} table.
  // This creates an 'implicit' relationship to the content_type_program table, so that when 'Node'
  // is the base table, the fields are automatically available.
  $data['fees_order']['table']['join']['content_type_program'] = array(
    'left_field' => 'vid', # 'left_field' is the primary key in the referenced table.
    'field' => 'vid', # 'field' is the foreign key in this table.
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
  
  // nid field.
  $data['fees_order']['nid'] = array(
    'title' => t('Fees structure nid'), 
    'help' => $order_products['fields']['nid']['description'],
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
  
  // type field.
  $data['fees_order']['type'] = array(
    'title' => t('Fees type'), 
    'help' => $order_products['fields']['type']['description'],
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
     'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  // cart_item_id field.
  $data['fees_order']['cart_item_id'] = array(
    'title' => t('Cart Item Id'), 
    'help' => $order_products['fields']['cart_item_id']['description'],
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
  
  // title field.
  $data['fees_order']['title'] = array(
    'title' => t('Fees title'), 
    'help' => $order_products['fields']['title']['description'],
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
  // price field
  $data['fees_order']['price'] = array(
    'title' => t('Fee Cost'),
    'help' => $order_products['fields']['price']['description'],
    'field' => array(
      'handler' => 'uc_views_handler_field_money_amount',
      'click sortable' => TRUE,
      'float' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_float',
    ),
  );
  
  // nationality field.
  $data['fees_order']['nationality'] = array(
    'title' => t('Nationality'), 
    'help' => $order_products['fields']['nationality']['description'],
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
  
  // programme field.
  $data['fees_order']['programme'] = array(
    'title' => t('Student Programme'), 
    'help' => $order_products['fields']['nationality']['description'],
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    /*'relationship' => array(
      'base' => 'content_type_program',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Program'),
    ),*/
    'relationship' => array(
      'base' => 'content_type_student_profile',
      'field' => 'field_profile_first_choice_nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Program'),
    ),
  );  
  
  // level_nane field.
  $data['fees_order']['level_name'] = array(
    'title' => t('Student Level'), 
    'help' => $order_products['fields']['nationality']['description'],
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
  
  // session field.
  $data['fees_order']['session'] = array(
    'title' => t('Academic Session'), 
    'help' => $order_products['fields']['nationality']['description'],
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
  
  // uid field.
  $data['fees_order']['uid'] = array(
    'title' => t('User id'), 
    'help' => $order_products['fields']['uid']['description'],
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      'name field' => 'name', // the field to display in the summary.
      'numeric' => TRUE,
      'validate type' => 'uid',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_name',
      'title' => t('Name'),
    ),
    /*'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),*/
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('Order user'),
    ),
    
  );
  
  // jambno field.
  $data['fees_order']['jambno'] = array(
    'title' => t('Jamb Number'), 
    'help' => $order_products['fields']['jambno']['description'],
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
     'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  // fullnames field.
  $data['fees_order']['fullnames'] = array(
    'title' => t('Student Full names'), 
    'help' => $order_products['fields']['fullnames']['description'],
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
  
  // institution field.
  $data['fees_order']['institution'] = array(
    'title' => t('Current Institution'), 
    'help' => $order_products['fields']['institution']['description'],
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
  
  // status field.
  $data['fees_order']['status'] = array(
    'title' => t('Fees Order Status'), 
    'help' => $order_products['fields']['status']['description'],
    'field' => array(
      //'handler' => 'uc_eduerp_fees_handler_field_status',
      'handler' => 'uc_views_handler_field_order_status',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_order_status',
    ),
  );
  
  // email field.
  $data['fees_order']['email'] = array(
    'title' => t('Student Order email'), 
    'help' => $order_products['fields']['fullnames']['description'],
    'field' => array(
      'handler' => 'views_handler_field_user_mail',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
  
  // order_id field.
  // @todo Make this a foreign key to uc_orders table both in the schema
  // and db
  $data['fees_order']['order_id'] = array(
    'title' => t('Order Id'), 
    'help' => $order_products['fields']['order_id']['description'],
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
  
  // scholarship field.
  $data['fees_order']['scholarship'] = array(
    'title' => t('Scholarship'), 
    'help' => $order_products['fields']['scholarship']['description'],
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
  
  // late_registration_date field.
  $data['fees_order']['late_registration_date'] = array(
    'title' => t('Late registration date'), 
    'help' => $order_products['fields']['late_registration_date']['description'],
    'field' => array(
      'handler' => 'views_handler_field_date', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  
  // allow_instalment field
  $data['fees_order']['allow_instalment'] = array(
    'title' => t('Allow Instalment'), 
    'help' => $order_products['fields']['allow_instalment']['description'],
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Allow Instalment'),
      'type' => 'yes-no',
    ),
  );
  
  // hostel_nid
  $data['fees_order']['hostel_nid'] = array(
    'title' => t('Hostel nid'), 
    'help' => $order_products['fields']['hostel_nid']['description'],
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
  
  // hostel_type
  $data['fees_order']['hostel_type'] = array(
    'title' => t('Hostel type'), 
    'help' => $order_products['fields']['hostel_type']['description'],
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
  
  // expiry_date
  $data['fees_order']['expiry_date'] = array(
    'title' => t('Hostel expiry date'), 
    'help' => $order_products['fields']['expiry_date']['description'],
    'field' => array(
      'handler' => 'views_handler_field_date', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  
  // attributes field
  $data['fees_order']['attributes'] = array(
    'title' => t('Fees Attributes'), 
    'help' => $order_products['fields']['attributes']['description'],
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
  
  // module
  $data['fees_order']['module'] = array(
    'title' => t('Fees Order module'), 
    'help' => $order_products['fields']['module']['description'],
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
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
      'uc_eduerp_fees_handler_field_fees_order_id' => array(
        'parent' => 'views_handler_field',
      ),
      'uc_eduerp_fees_handler_field_product_nid' => array(
        'parent' => 'views_handler_field',
      ),
      'uc_eduerp_fees_handler_field_nid' => array(
        'parent' => 'views_handler_field',
      ),
      'uc_eduerp_fees_handler_field_type' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_cart_item_id' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_title' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_price' => array(
        'parent' => 'uc_views_handler_field_money_amount',
      ),
     'uc_eduerp_fees_handler_field_nationality' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_programme' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_level_name' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_session' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_late_registration_date' => array(
        'parent' => 'views_handler_field_date',
      ),
     'uc_eduerp_fees_handler_field_late_registration_amount' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_late_registration_nid' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_late_registration_description' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_uid' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_jambno' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_fullnames' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_institution' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_status' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_email' => array(
        'parent' => 'views_handler_field_user_email',
      ),
     'uc_eduerp_fees_handler_field_order_id' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_scholarship' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_allow_instalment' => array(
        'parent' => 'views_handler_field_boolean',
      ),
     'uc_eduerp_fees_handler_field_hostel_nid' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_hostel_type' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_expiry_date' => array(
        'parent' => 'views_handler_field_date',
      ),
     'uc_eduerp_fees_handler_field_attributes' => array(
        'parent' => 'views_handler_field',
      ),
     'uc_eduerp_fees_handler_field_module' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}