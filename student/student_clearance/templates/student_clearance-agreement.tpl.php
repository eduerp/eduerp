<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language ?>" xml:lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<style type="text/css">
@media print {
  #hideforprinted {display: none;}
}
</style>
<script type="text/javascript"><?php /* Needed to avoid Flash of Unstyled Content in IE */ ?> </script>
</head>
<body>
<?php

echo $site_logo;

echo $content;

echo '<div id="hideforprinted" align="right" style="margin-top: 1em; margin-right: 1em;"><input type="button" value="'. t('Print') .'" onclick="window.print();" /> '
     . '<input type="button" value="'. t('Close window') .'" onclick="window.close();" /></div>';
?>
</body>
</html>
