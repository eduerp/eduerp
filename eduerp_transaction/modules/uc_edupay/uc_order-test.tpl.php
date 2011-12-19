<?php 

/**
 * @file
 * test Invoice template for eduerp
 */ 

?>
    <div id="container" style="margin:0 auto;width:80%;font-family:Arial;font-size:12px; border:solid 1px #EDF0F9">
      <div class="inner" style="padding:8px">
        
        <!-- invoice header -->
        <div id="invoice-header" style="top:5px;border:solid 1px #000; height:100px">
          <div class="header-left" style="float:left;width:25%;height:100%;border:solid 1px #EDF0F9">
            <?php echo $site_logo; ?>
          </div>
          <div class="header-right" style="float:right;width:73%;height:100%">
            <div style="float:left;border:solid 1px #EDF0F9; width:70%;text-align:center;height:100%">
              <div style="text-transform:uppercase; color:#305E37"><h3><?php echo $institution_name ?></h1></div>
              <div style="text-transform:uppercase; color:#08941E"><h4><?php echo $institution_address ?></h4></div>
            </div>
            <div style="float:right; width:25%;border:solid 1px #EDF0F9;height:100%">
              <div style="color:#D73627"><b><?php echo $invoice_number ?></b></div>
              <div style="text-transform:uppercase; text-align:center"><h3><?php echo $invoice_title ?></h3></div>
            </div>
          </div>
        </div>
        
        <!-- invoice body -->
        <div id="invoice-body" style="margin-top:5px;border:solid 1px #D0D0D0;background:#E3E9FF;">
          <div class="body-left" style="float:left; width:25%; border:solid 1px #D0D0D0; margin-right:5px">
            <div class="inner" style="padding:5px">
              <div><b><?php echo $user_label ?></b></div>
              <div style="width:100%">Name: <?php echo $fullnames ?></div>
              <div style="width:100%">Admission Number: </div>
              <div style="width:100%">Programme: <?php echo $programme ?></div>
            </div>
          </div>
          <div class="body-center" style="float:right; width:72%; border:solid 1px #D0D0D0;">
            <table border="0" bordercolor="#FFCC00" style="font-size:11px" width="100%" cellpadding="0" cellspacing="0">
              <tr>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td><?php echo $fees_order_date ?></td>
              </tr>
              <tr>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
              </tr>
              <tr>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
              </tr>
              <tr>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
              </tr>
              <tr style="text-transform:uppercase">
                <th></th>
                <th>Fee Items</th>
                <th></th>
                <th>Price</th>
              </tr>
              <tr>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
              </tr>
              <?php 
                if (is_array($order->products)) {
                  $context = array(
                    'revision' => 'formatted',
                    'type' => 'order_product',
                    'subject' => array(
                      'order' => $order,
                    ),
                  );
                  foreach ($order->products as $product) {
                    $price_info = array(
                      'price' => $product->price,
                      'qty' => $product->qty,
                    );
                    $context['subject']['order_product'] = $product;
                    $context['subject']['node'] = node_load($product->nid);
              ?>
              <tr>
                <td>&nbsp;</td>
                <td valign="middle"><b><?php echo $product->title ?></b></td>
                <td>&nbsp;</td>
                <td valign="middle"><b><?php echo uc_price($price_info, $context); ?></b></td>
              </tr>
              <?php } ?>
              <?php } ?>
              <tr>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
              </tr>
              <tr>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>Total: <b><?php echo $order_total; ?></b></td>
              </tr>
              <tr>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
                <td>&nbsp;</td>
              </tr>
            </table>
          </div>
          
        </div>
        <div style="clear:both"/>
        
        <!-- invoice footer -->
        <div id="invoice-footer" style="margin-top:5px;border:solid 1px #000;">
          <div class="inner" style="padding:5px">
            <b><?php echo $invoice_note; ?>
          </div>
          <div style="margin-top:5px; text-align:center; border:dotted 1px #333; padding:8px;font-style:italic">
            <ul style="">
              <li style="display:inline"><?php echo $bank_account1 ?></li>
              <li style="display:inline"><?php echo $bank_account2 ?></li>
              <li style="display:inline">Account Name: <b><?php echo $institution_name ?></b></li>
            </ul>
          </div>
          
        </div>
        
      </div>
    </div>
  </body>
</html>
