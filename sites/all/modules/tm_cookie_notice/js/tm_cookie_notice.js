(function ($) {
	Drupal.behaviors.tm_cookie_notice_popup = {
		attach: function(context, settings) {
			$('body').not('.sliding-popup-processed').addClass('sliding-popup-processed').each(function() {
				if (Drupal.tm_cookie_notice.cookiesEnabled()) {
					var status = Drupal.tm_cookie_notice.getCurrentStatus();

					if (status == 0) {
						$('.agree-button').click(function() {
							Drupal.tm_cookie_notice.setStatus(1);
							Drupal.tm_cookie_notice.changeStatus(1);
						});
	
						Drupal.tm_cookie_notice.createPopup(Drupal.settings.tm_cookie_notice.popup_html_info);
					} else {
						return;
					}
				} else {
					return;
				}
			});
		}
	}

	Drupal.tm_cookie_notice = {};

	Drupal.tm_cookie_notice.createPopup = function(html) {
		var popup = $(html).attr({"id": "sliding-popup"}).hide();
		popup.appendTo("body");
		popup.show()
			.attr({"class": "sliding-popup-bottom"})
			.css({"bottom": "-100%"})
			.animate({bottom: 0}, 1000)
		Drupal.tm_cookie_notice.attachEvents();
	}

	Drupal.tm_cookie_notice.attachEvents = function() {

		$('.agree-button').click(function() {
			Drupal.tm_cookie_notice.setStatus(0);
			Drupal.tm_cookie_notice.changeStatus(1);
		});
	}

	Drupal.tm_cookie_notice.getCurrentStatus = function() {
		name = 'cookie-agreed';
		value = Drupal.tm_cookie_notice.getCookie(name);
		return value;
	}

	Drupal.tm_cookie_notice.changeStatus = function(value) {
		var status = Drupal.tm_cookie_notice.getCurrentStatus();
		if (status == value) {
			return;
		}
	
		$(".sliding-popup-bottom").animate({bottom: $("#sliding-popup").height() * -1}, 1000, function () {
			if (status == 0) {
				$("#sliding-popup").html(Drupal.settings.tm_cookie_notice.popup_html_agreed).animate({bottom: 0}, 1000)
				Drupal.tm_cookie_notice.attachEvents();
			}
			if (status == 1) {
				$("#sliding-popup").remove();
			}
		})
		Drupal.tm_cookie_notice.setStatus(value);
	}

	Drupal.tm_cookie_notice.setStatus = function(status) {
		var date = new Date();
		date.setDate(date.getDate() + 100);
		var cookie = "cookie-agreed=" + status + ";expires=" + date.toUTCString() + ";path=" + Drupal.settings.basePath;
		document.cookie = cookie;
	}

	/**
	 * Verbatim copy of Drupal.comment.getCookie().
	 */
	Drupal.tm_cookie_notice.getCookie = function(name) {
		var search = name + '=',
			returnValue = '';

		if (document.cookie.length > 0) {
			offset = document.cookie.indexOf(search);
			if (offset != -1) {
				offset += search.length;
				var end = document.cookie.indexOf(';', offset);
				if (end == -1) {
					end = document.cookie.length;
				}
				returnValue = decodeURIComponent(document.cookie.substring(offset, end).replace(/\+/g, '%20'));
			}
		}
		
		return returnValue;
	};
	
	Drupal.tm_cookie_notice.cookiesEnabled = function() {
		var cookieEnabled = (navigator.cookieEnabled) ? true : false;
		if (typeof navigator.cookieEnabled == "undefined" && !cookieEnabled) { 
			document.cookie = "testcookie";
			cookieEnabled = (document.cookie.indexOf("testcookie") != -1) ? true : false;
		}
		
		return (cookieEnabled);
	}
})(jQuery);