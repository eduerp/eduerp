<?php 

class views_handler_filter_sponsor extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Sponsor');
      $sponsor = uc_edupay_fees_order_get_item('sponsor');
      foreach ($sponsor as $key => $value) {
        $options[$value['sponsor']] = $value['sponsor'];
      }
      $this->value_options = $options;
    }
  }
}