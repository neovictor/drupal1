<?php
/**
 * @file
 *  Expose current user role as a context condition.
 */
class masquerade_is_masquerading_context_condition extends context_condition {
  /** 
   * For whatever reason, custom plugins' settings get ignored when the context
   * editor saves values. 
   */
  function condition_values() {
    return array(1 => t('Evaluate this context when the current user is posing as someone else.'));
  }

  /**
   *  hook_context_reaction() is required of your module and will have to call $plugin->execute()
   *  or this plugin won't do anything.
   */
  function execute() {
    if (isset($_SESSION['masquerading']) && is_numeric($_SESSION['masquerading'])) {
      foreach ($this->get_contexts() as $context) {
        $this->condition_met($context, 'is_masquerading');
      }
    }
  }
}
