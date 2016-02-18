<?php

/**
 * @file
 * Contains the administration pages for Animate CSS.
 *
 */
function animate_css_settings($form_state) {

  $form['animate_css_visibility'] = array(
    '#type' => 'radios',
    '#title' => t('Show animations on specific pages'),
    '#options' => array(0 => t('All pages except those listed'), 1 => t('Only the listed pages')),
    '#default_value' => config_get('animate_css.settings', 'animate_css_visibility'),
  );
  $form['animate_css_pages'] = array(
    '#type' => 'textarea',
    '#title' => '<span class="element-invisible">' . t('Pages') . '</span>',
    '#default_value' => config_get('animate_css.settings', 'animate_css_pages'),
    '#description' => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')),
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  return $form;
}

/**
 * Submit handler for module_settings_form().
 */
function animate_css_settings_submit($form, &$form_state) {
    $config = config('animate_css.settings');
    foreach ($form_state['values'] as $key => $value)
    {
      $config->set($key, $value);
    }

    $config->save();
    backdrop_set_message(t('The configuration options have been saved.'));
}
?>
