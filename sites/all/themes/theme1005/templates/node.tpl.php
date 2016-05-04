<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *	 or print a subset such as render($content['field_example']). Use
 *	 hide($content['field_example']) to temporarily suppress the printing of a
 *	 given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *	 calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $display_submitted: whether submission information should be displayed.
 * - $classes: String of classes that can be used to style contextually through
 *	 CSS. It can be manipulated through the variable $classes_array from
 *	 preprocess functions. The default values can be one or more of the
 *	 following:
 *	 - node: The current template type, i.e., "theming hook".
 *	 - node-[type]: The current node type. For example, if the node is a
 *		 "Blog entry" it would result in "node-blog". Note that the machine
 *		 name will often be in a short form of the human readable label.
 *	 - node-teaser: Nodes in teaser form.
 *	 - node-preview: Nodes in preview mode.
 *	 The following are controlled through the node publishing options.
 *	 - node-promoted: Nodes promoted to the front page.
 *	 - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *		 listings.
 *	 - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *	 modules, intended to be displayed in front of the main title tag that
 *	 appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *	 modules, intended to be displayed after the main title tag that appears in
 *	 the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *	 into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *	 teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *	 main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix node-<?php print $node->nid; ?>" role="article"<?php print $attributes; ?>>
	<?php $hitcount = statistics_get( $node->nid );
	unset($content['links']['statistics']);
	
	if ( $title || $user_picture || $display_submitted ) : ?>
		<header class="node-header clearfix">
			<!-- Node title -->
			<?php if ( $title && !$page ) :
				print render( $title_prefix ); ?>
					<h4 class="title node-title"<?php print $title_attributes; ?>>
						<a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a>
					</h4>
				<?php print render( $title_suffix );
			endif; ?>

			<!-- Node meta -->
	
		</header>
	<?php endif; ?>

	<div class="content node-content"<?php print $content_attributes; ?>>
		<?php // We hide the comments, tags and links now so that we can render them later.
		hide( $content['comments'] );
		hide( $content['links'] );
		hide( $content['field_tags'] ); ?>

		<!-- Node content -->
		<?php print render( $content ); ?>
	</div>
		<?php if ( $display_submitted ) : ?>
				<div class="submitted node-submitted" role="contentinfo">
					<ul class="submitted-list clearfix">
           	<?php   if ( $submitted_pubdate ) : // publish date ?>
							<li class="node-time" >
								<time datetime="<?php print $submitted_pubdate; ?>">
									<span class="fa fa-fw fa-calendar"></span> <?php print $submitted_date; ?>
								</time>
							</li>
						<?php endif; ?>
	
						<?php if ( $user_picture ) : // author icon ?>
							<li class="node-userpic"><?php print $user_picture; ?></li>
						<?php endif; ?>
	
						<?php if ( $submitted ) : // node author ?>
							<li class="node-author"><span class="fa fa-fw fa-user"></span> <?php print $submitted; ?></li>
						<?php endif; ?>
	
						
					<!-- 	<li class="node-views">
							<span class="fa fa-fw fa-eye"></span>
							<?php print $hitcount['totalcount'] ? $hitcount['totalcount'] : "0"; // node views
							print " view(s)"; ?>
						</li>-->
	
				 
							<li class="node-comments">
								<span class="fa fa-fw fa-comment"></span>
								<a href="<?php echo $node_url;?>#comments"><?php print $comment_count . t( " comment(s)" ); ?> </a>
							</li>
			
					</ul>
				</div>
			<?php endif; ?>
      <div class="Partager col-md-12">
      <div class="labelpartage col-md-2">Partager !</div>
      <!-- AddThis Button BEGIN -->
<div class="col-md-9 addthis_toolbox addthis_default_style addthis_32x32_style">
<a class="addthis_button_facebook" title="Facebook"></a>
<a class="addthis_button_twitter" title="Twitter"></a>
<a class="addthis_button_pinterest_share" title="pinterest"></a>
<a class="addthis_button_email" title="e-mail"></a>
<a class="addthis_button_google" title="google"></a>
<a class="addthis_button_linkedin" title="linkedin"></a>
</div>
<script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js#pubid=xa-4dedda0c245832a7"></script>
<!-- AddThis Button END -->
  </div>    
	<?php if ( !empty( $content['field_tags'] ) || !empty( $content['links'] ) ) : ?>
		<footer class="footer node-footer" role="contentinfo">
			<!-- Node tags -->
			<?php print render( $content['field_tags'] ); ?>
			
			<!-- Node links -->
			<!--	<?php if ( $links = render( $content['links'] ) ): ?>
				<div class="node-links clearfix">
					<?php print $links; ?>
				</div>
			<?php endif; ?>-->
		</footer>
	<?php endif;

	print render( $content['comments'] ); ?>
</div>