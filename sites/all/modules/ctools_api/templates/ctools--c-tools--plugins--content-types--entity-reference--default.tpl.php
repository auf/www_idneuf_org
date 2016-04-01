<?php
/**
 * @file
 * Default theme variant for Entity Reference content type plugin.
 *
 * @see CTools\Plugins\ContentTypes\EntityReference
 *
 * @var array $content
 */
?>
<?php foreach ($content['references'] as $item): ?>
  <p><?php print $item['reference']['entity_label']; ?></p>
<?php endforeach; ?>
