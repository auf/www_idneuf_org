<?php
/**
 * @file
 * Default theme variant for Customizable Pane style plugin.
 *
 * @see CTools\Plugins\Styles\CustomizablePane
 *
 * @var \stdClass $content
 * @var array $settings
 */
?>
<?php if (!empty($content->tag)): ?>
  <<?php print $content->tag; ?><?php print drupal_attributes($content->attributes); ?>>
<?php endif; ?>

  <?php foreach ($settings['info'] as $name => $info): ?>
    <?php if (!empty($content->$name)): ?>

      <?php if (!empty($info['tag'])): ?>
        <<?php print $info['tag']; ?><?php print drupal_attributes($info['attributes']); ?>>
      <?php endif; ?>

        <?php print render($content->$name); ?>

      <?php if (!empty($info['tag'])): ?>
        </<?php print $info['tag']; ?>>
      <?php endif; ?>

    <?php endif; ?>
  <?php endforeach; ?>

<?php if (!empty($content->tag)): ?>
  </<?php print $content->tag; ?>>
<?php endif; ?>
