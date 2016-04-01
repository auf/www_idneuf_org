(function($, moduleName) {
  'use strict';

  Drupal.behaviors[moduleName] = {
    attach: function(context) {
      var $context = $(context);

      // Process all [type=checkbox] and [type=radio] fields.
      $context.find('.form-type-checkbox, .form-type-radio').once(moduleName, function() {
        var $checkbox = $(this).children('input');
        var input = $checkbox[0];

        $checkbox.after('<label class="pseudo-box ' + input.type + '" for="' + input.id + '"></label>');
      });

      // Process all [type=file] fields.
      $context.find('.form-type-managed-file').once(moduleName, function() {
        var $container = $(this);

        $container.find('[type=file]').css({position: 'fixed', top: '-100px'}).each(function() {
          var $filed = $(this).bind('change', function() {
            $wrapper.text(this.value.replace(/.*\\(.*)$/g, '$1')).toggleClass('focus');
          });

          var $wrapper = $('<div class="pseudo-file" />').width($filed.width()).bind('click', function() {
            $filed.click();
            $(this).toggleClass('focus');
          });

          $wrapper.prependTo(this.parentNode);
        });

        $container.find('a').attr('target', '_blank');
      });

      // Handler for "horizontal_tabs" type.
      $context.find('.horizontal-tabs').once(moduleName, function() {
        var $tabs = $('<ul class="clearfix" />');
        var $fieldsets = $(this).children('fieldset');
        var hash = location.hash.substr(1).split(':');
        var $firstTab = [];

        $fieldsets.each(function() {
          var $fieldset = $(this);
          var containerId = this.parentNode.id;

          $tabs.append($('<li class="' + this.id + '">' + $fieldset.children('legend').text() + '</li>').bind('click', function() {
            var $tab = $(this);

            $fieldsets.add($tab.siblings()).removeClass('active');
            $fieldset.add($tab).addClass('active');

            // Store active tab to location hash.
            location.replace('#horizontal-tab:' + containerId + ':' + $tab.index());
          }));
        });

        $tabs.prependTo(this);

        // Read active tabs from location hash.
        if (3 === hash.length && 'horizontal-tab' === hash[0]) {
          $firstTab = $('#' + hash[1]).find('li').eq(hash[2]);
        }

        if (!$firstTab.length) {
          $firstTab = $tabs.children().first();
        }

        // Open the first tab. The "addClass()" method cannot be
        // used, because on click we operate with a location hash.
        $firstTab.click();
      });
    }
  };
})(jQuery, 'ctools_api');
