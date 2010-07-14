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
      $count = 0;
      // Only taking the first record in $rows
      foreach ($rows[0] as $field => $content): 
        // skip fields that have blank content
        if ($content == "") continue;
        $row_class = ($count % 2) ? "even " : "odd ";
        $row_class .= ($count == 0) ? "views-row-first " : "";
        $row_class .= ($count == count($rows[0]) - 1) ? "views-row-last " : "";
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
  </tbody>
</table>

