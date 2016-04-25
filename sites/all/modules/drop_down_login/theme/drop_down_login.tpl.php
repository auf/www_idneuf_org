<?php
/**
 * @file
 * Template for login dropd down.
 *
 * Available variables
 * - $login_form (array): renderable login form array
 * - $login_url: url for login button/link
 * - $login_link_text: logout button/link text.
 */
?>
<div class="drop-down-login-container" id="drop-down-login-wrapper">
  <a href="<?php print $login_url; ?>" class="login button">
    <span><span><?php print $login_link_text; ?></span></span>
  </a>
  <div class="dropdown" style="display: none;">
    <?php if(!empty($login_form)):?>
      <?php print render($login_form); ?>
    <?php endif; ?>
  </div>
</div>
