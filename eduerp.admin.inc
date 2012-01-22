<?php
// $Id$
/**
 * @file
 * All admin related tasks
 */


/**
 * Retrieves institution by required fields
 * @param <type> $op
 * @return string
 * @author Kayode Odeyemi (dreyemi@gmail.com)
 */
function eduerp_get_institution($op = 'institution') {
	static $institution_names;

	if(!isset($institution_names)) {
		$institution_names = _eduerp_institution_names();
	}

	$func = 'eduerp_institutions';
	if (function_exists($func) && !isset($institutions)) {
		$institutions = $func();
	}

	switch($op) {
		case 'name':
			return eduerp_get_institution_name();
		case 'names':
			return $institution_names;
		default:
			return $institutions;
	}
	//return $institutions;
}

function eduerp_get_institution_name() {
	$result = db_fetch_object(db_query("SELECT * FROM {webapp_institution} WHERE id = %d", variable_get('eduerp_institution', '')));
	return $result;
}

function _eduerp_institution_names() {
	$names = array();
	$sql = 'SELECT name FROM {webapp_institution}';
		$result = db_query($sql);
		while($rows = db_fetch_object($result)) {
			$names[] = $rows->name;
		}
	return $names;
}
/**
 * Get all institutions
 *
 * @author Kayode Odeyemi (dreyemi@gmail.com)
 * @return array
 */
function eduerp_institutions() {
	$institutions = array();
	$sql = 'SELECT name, code, secret FROM {webapp_institution}';
	$result = db_query($sql);
	while($rows = db_fetch_object($result)) {
		$institutions[] = array($rows);
	}
	return $institutions;
}