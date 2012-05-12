<?php
/**
 * Implementation of hook_views_default_views(), walk through the files in the views directory including the files and creating the views.
 */
function grading_views_default_views() {
	$path = dirname(__FILE__) . "/views/";
	$views = array();

	$dir = dir($path);
	while ($filename = $dir->read()) {
		$full_path = $path . $filename;
		if (is_file($full_path) && strpos($full_path, '.php')) {
			include($full_path);
			$views[$view->name] = $view;
		}
	}

  return $views;
}
