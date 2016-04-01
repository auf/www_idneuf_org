<?php
/**
 * @file
 * Default theme variant for Customizable Region style plugin.
 *
 * @see CTools\Plugins\Styles\CustomizableRegion
 *
 * @var array $settings
 * @var string[] $panes
 */
?>
<?php if (!empty($settings['tag'])): ?>
  <<?php print $settings['tag']; ?><?php print drupal_attributes($settings['attributes']); ?>>
<?php endif; ?>

  <?php foreach ($panes as $pid => $content): ?>
    <?php print $content; ?>
  <?php endforeach; ?>

<?php if (!empty($settings['tag'])): ?>
  </<?php print $settings['tag']; ?>>
<?php endif; ?>
