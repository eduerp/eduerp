<?php
/**
*
* This function should be moved to an install profile for eduerp.
 * At the moment, it is placed here,
*/
function eduerp_run_task($task) {
    switch($task) {
        case 'institution':
            // run the institution db script gotten from edupay
            $institution_query = eduerp_institution_read_sql();
            $result = db_result(db_query($institution_query));
            return $result;
        break;
    }
}

/**
 * Reads institution specific script from a file
 * @return string
 */
function eduerp_institution_read_sql() {
    $path = drupal_get_path('module', 'eduerp') . '/database/webapp_institution.sql';
    $query_content = '';
    $query_content = file_get_contents($path);
    return $query_content;
}
/**
* Called everytime more institutions are added into edupay
*
*/
function eduerp_institution_update() {


}
