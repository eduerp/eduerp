<?php
/**
 * @file views-view-table--student-clearance--page-1.tpl.php
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $class: A class or classes to apply to the table, based on settings.
 * - $rows: An array of row items. Each row is an array of content.
 */
?>
<table class="<?php print $class; ?>">
  <?php if (!empty($title)) : ?>
    <caption><?php print $title; ?></caption>
  <?php endif; ?>
  <tbody>
    <?php
      $new_rows = array();
      foreach ($rows[0] as $field=>$content) {
        if ($content != "")
          $new_rows[$field] = $content;
      }
      $count = 0;
      // Only taking the first record in $rows
      foreach ($new_rows as $field => $content):
        // skip fields that have blank content
        if ($content == "") continue;
        $row_class = ($count % 2) ? "even " : "odd ";
        $row_class .= ($count == 0) ? "views-row-first " : "";
        $row_class = trim($row_class);
    ?>
      <tr class="<?php echo $row_class; ?>">
        <th class="views-field views-field-<?php print $fields[$field]; ?>"><?php print $header[$field]; ?></th>
        <td class="views-field views-field-<?php print $fields[$field]; ?>"><?php print $content; ?></td>
      </tr>
    <?php
        $count++;
      endforeach;
    ?>
    <?php
      $row_class = ($count % 2) ? "even" : "odd";
    ?>
<form action="<?php echo url('student/clearance/post'); ?>" method="post">
      <tr class="<?php echo $row_class; ?>">
        <th style="text-align:right">
          <input type="checkbox" name="verify" value="1" VERIFY_OPTIONS />
        </th>
        <td>Verified</td>
      </tr>
    <?php
      $row_class = ($row_class == "even") ? "odd" : "even";
    ?>
      <tr class="<?php echo $row_class; ?>">
        <th style="text-align:right">
          <input type="checkbox" name="clearance" id="edit-field-clearance-cleared" value="1" CLEARANCE_OPTIONS />
        </th>
        <td>Cleared</td>
      </tr>
			<?php
      $row_class = ($row_class == "even") ? "odd" : "even";
    ?>
      <tr class="<?php echo $row_class; ?>">
        <th style="text-align:right">
          <!--<input type="checkbox" name="field-clearance-uncleared" id="edit-field-clearance-uncleared" value="0" class="form-checkbox" />-->
        </th>
        <!--<td>Not Cleared</td>-->
				<td><?php print theme('student_field_uncleared');?></td>
				<td><?php print theme('student_field_uncleared_reasons');?></td>
      </tr>
			<?php
      $row_class = ($row_class == "even") ? "odd" : "even";
      if (FALSE) { // Disable for Sokoto
      ?>
      <tr class="<?php echo $row_class; ?>">
        <th style="text-align:right">
          <!--<input type="checkbox" name="field-clearance-deferred" id="edit-field-clearance-deferred" value="0" class="form-checkbox" />-->
        </th>
        <td><?php print theme('student_field_deferred');?></td>
      </tr>
      <?php
      $row_class = ($row_class == "even") ? "odd" : "even";
      }
      ?>
      <tr class="<?php echo $row_class; ?> view-row-last">
        <th style="text-align:right">
          &nbsp;
        </th>
        <td>
          <input type="hidden" name="student_uid" value="STUDENTID" />
          <input type="submit" value="Submit" SUBMIT_OPTIONS />
        </td>
      </tr>
</form>
  </tbody>
</table>

