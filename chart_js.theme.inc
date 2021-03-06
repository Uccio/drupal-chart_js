<?php

/**
 * @file
 * Theme functions for chart types.
 */

/**
 * Chart JS theme.
 */
function theme_chart_js(&$vars) {
  static $chart_no = 0;
  $chart_no++;
  $chart_id = 'chart_js-' . $chart_no;

  if (empty($vars['data'])) {
    return t('No data provided.');
  }

  $g = (object) $vars;
  // Sanitize data if html is not set to TRUE.


  $d_labels= json_encode($vars['labels']);
  $d_dataset = '';
  foreach ($vars['data']['datasets'] as $k => $v){
    $d_dataset .= json_encode($v) .',';
  }

  drupal_add_library('chart_js', 'chart_js');
  drupal_add_js("new Chart(document.getElementById(\"$chart_id\"), {
    type: '$g->chart_type',
    data: {
      labels: $d_labels,
      datasets: [
        $d_dataset
      ]
    },
    options: {
      legend: { display: false },
      title: {
        display: true,
        text: '$g->title'
      }
    }
});"

, array('type' => 'inline', 'scope' => JS_DEFAULT));



  $html = "<canvas id=\"$chart_id\" width=\"800\" height=\"450\"></canvas>";

  return $html;

}
