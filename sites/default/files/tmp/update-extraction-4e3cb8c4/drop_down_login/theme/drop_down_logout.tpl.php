<?php
/**
 * @file
 * Template for logout button.
 *
 * Available variables
 * - $logout_url: url for logout button/link
 * - $logout_link_text: logout button/link text.
 */
?>
<div class="drop-down-login-container" id="drop-down-login-wrapper">
  <a href="<?php print $logout_url; ?>" class="logout button">
    <span><?php print $logout_link_text; ?></span>
  </a>
</div>
