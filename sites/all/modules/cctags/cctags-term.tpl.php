<?php
/**
 * $term object
 * $mode = block or page
 * example $term  object
 * stdClass Object
 *(
 *    [tid] => 26
 *    [vid] => 3
 *    [name] => Drupal 6.*
 *    [description] =>
 *    [weight] => 1.38629436112
 *    [depth] => 0
 *    [parents] => Array
 *        (
 *            [0] => 0
 *        )
 *
 *    [count] => 3
 *    [path] => taxonomy/term/26
 *    [level] => 5
 *    [link] => Drupal 7.*
 *)
 *   $term -- href link to taxonomy term
     */
?>
<?php print render($term) . '&nbsp; '; ?>