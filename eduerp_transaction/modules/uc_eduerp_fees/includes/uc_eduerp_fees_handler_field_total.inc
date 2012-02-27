<?php 

class uc_eduerp_fees_handler_field_total extends views_handler_field {
  
  // Add a field to the query
  function query() {
    //dsm($this);
    $this->field_alias = 'fees_order_field_total_'. $this->position;
  }
  
  function option_definition() {
    $options = parent::option_definition();
    $options['value'] = array('default' => '');
    return $options;
  }
  
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['view_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter a view name that contains the field to calculate the total'),
      '#default_value' => $this->options['view_name'],
    );
    $form['view_display'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter the name of the view display you want to use'),
      '#default_value' => $this->options['view_display'],
    );
    $form['price_field_key'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter the name of the field that holds the total values'),
      '#default_value' => $this->options['price_field_key'],
    );
    
    $view_name = $this->options['view_name'];
    $view_display = $this->options['view_display'];
    $price_field_key = $this->options['price_field_key'];
    $view = views_get_view_result($view_name, $view_display);
    
    foreach($view as $key => $value) {
      $prices[] = $value->$price_field_key;
    }
    
    $this->options['price'] = array_sum($prices);

  }
  
  function render($values) {
    views_flush_caches();
    return $this->options['price'];
  }
}