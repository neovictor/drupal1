<?php
/**
 * @file
 *  Ctools access plugin which checks whether or not a user is currently masquerading.
 */
$plugin = array(
  'title' => t('User: Is Masquerading'),
  'description' => t('Checks whether or not a user is masquerading as another.'),
  'callback' => 'masquerade_ctools_is_masquerading_access_check',
  'default' => array(),
  'summary' => 'masquerade_ctools_is_masquerading_access_summary',
  'required context' => array(),
);

/**
 * Checks if the user is currently masquerading as another.
 * If no context is provided, this will automatically return FALSE.
 * @return
 *  TRUE if the current user is masquerading, FALSE otherwise.
 */
function masquerade_ctools_is_masquerading_access_check($conf, $context) {
  if (isset($_SESSION['masquerading']) && is_numeric($_SESSION['masquerading'])) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/**
 * Provides a simple access summary to administrators for this plugin.
 * @return
 *  A string which states whether or not the current user is masquerading.
 */
function masquerade_ctools_is_masquerading_access_summary($conf, $context) {
  return t('Current User: is masquerading as someone else.');
}
