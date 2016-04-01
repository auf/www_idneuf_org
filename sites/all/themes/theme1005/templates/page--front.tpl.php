
<!DOCTYPE html>
<!--[if IE 8 ]><html lang="en" dir="ltr"  class="no-js ie ie8 lt-ie9"><![endif]-->
<!--[if IE 9 ]><html lang="en" dir="ltr"  class="no-js ie ie9"><![endif]-->
<!--[if (gt IE 9)|!(IE)]><!--><html lang="en" dir="ltr" class="no-js"><!--<![endif]--><head>
<meta charset="utf-8"/><script type="text/javascript">
//<![CDATA[
try{if (!window.CloudFlare) {var CloudFlare=[{verbose:0,p:0,byc:0,owlid:"cf",bag2:1,mirage2:0,oracle:0,paths:{cloudflare:"/cdn-cgi/nexp/dok3v=1613a3a185/"},atok:"f3c18daf825a91e52a630b0bec4f16c7",petok:"b2ae243ae39a98be69141715172fb90b51022c35-1459498052-86400",zone:"template-help.com",rocket:"0",apps:{"abetterbrowser":{"ie":"7"},"ga_key":{"ua":"UA-7078796-5","ga_bs":"2"}},sha2test:0}];!function(a,b){a=document.createElement("script"),b=document.getElementsByTagName("script")[0],a.async=!0,a.src="//ajax.cloudflare.com/cdn-cgi/nexp/dok3v=e982913d31/cloudflare.min.js",b.parentNode.insertBefore(a,b)}()}}catch(e){};
//]]>
</script>
<script type="text/javascript">window.NREUM||(NREUM={}),__nr_require=function(e,t,n){function r(n){if(!t[n]){var o=t[n]={exports:{}};e[n][0].call(o.exports,function(t){var o=e[n][1][t];return r(o||t)},o,o.exports)}return t[n].exports}if("function"==typeof __nr_require)return __nr_require;for(var o=0;o<n.length;o++)r(n[o]);return r}({QJf3ax:[function(e,t){function n(){}function r(e){function t(e){return e&&e instanceof n?e:e?a(e,i,o):o()}function s(n,r,o){e&&e(n,r,o);for(var i=t(o),a=l(n),u=a.length,f=0;u>f;f++)a[f].apply(i,r);var s=c[w[n]];return s&&s.push([h,n,r,i]),i}function p(e,t){g[e]=l(e).concat(t)}function l(e){return g[e]||[]}function d(e){return f[e]=f[e]||r(s)}function v(e,t){u(e,function(e,n){t=t||"feature",w[n]=t,t in c||(c[t]=[])})}var g={},w={},h={on:p,emit:s,get:d,listeners:l,context:t,buffer:v};return h}function o(){return new n}var i="nr@context",a=e("gos"),u=e(1),c={},f={},s=t.exports=r();s.backlog=c},{1:12,gos:"7eSDFh"}],ee:[function(e,t){t.exports=e("QJf3ax")},{}],3:[function(e,t){function n(e,t){return function(){r(e,[(new Date).getTime()].concat(i(arguments)),null,t)}}var r=e("handle"),o=e(1),i=e(2);"undefined"==typeof window.newrelic&&(newrelic=NREUM);var a=["setPageViewName","addPageAction","setCustomAttribute","finished","addToTrace","inlineHit"],u=["addPageAction"],c="api-";o(a,function(e,t){newrelic[t]=n(c+t,"api")}),o(u,function(e,t){newrelic[t]=n(c+t)}),t.exports=newrelic,newrelic.noticeError=function(e){"string"==typeof e&&(e=new Error(e)),r("err",[e,(new Date).getTime()])}},{1:12,2:13,handle:"D5DuLP"}],gos:[function(e,t){t.exports=e("7eSDFh")},{}],"7eSDFh":[function(e,t){function n(e,t,n){if(r.call(e,t))return e[t];var o=n();if(Object.defineProperty&&Object.keys)try{return Object.defineProperty(e,t,{value:o,writable:!0,enumerable:!1}),o}catch(i){}return e[t]=o,o}var r=Object.prototype.hasOwnProperty;t.exports=n},{}],handle:[function(e,t){t.exports=e("D5DuLP")},{}],D5DuLP:[function(e,t){function n(e,t,n,o){r.buffer([e],o),r.emit(e,t,n)}var r=e("ee").get("handle");t.exports=n,n.ee=r},{ee:"QJf3ax"}],XL7HBI:[function(e,t){function n(e){var t=typeof e;return!e||"object"!==t&&"function"!==t?-1:e===window?0:i(e,o,function(){return r++})}var r=1,o="nr@id",i=e("gos");t.exports=n},{gos:"7eSDFh"}],id:[function(e,t){t.exports=e("XL7HBI")},{}],G9z0Bl:[function(e,t){function n(){if(!v++){var e=d.info=NREUM.info,t=f.getElementsByTagName("script")[0];if(e&&e.licenseKey&&e.applicationID&&t){u(p,function(t,n){e[t]||(e[t]=n)});var n="https"===s.split(":")[0]||e.sslForHttp;d.proto=n?"https://":"http://",a("mark",["onload",i()],null,"api");var r=f.createElement("script");r.src=d.proto+e.agent,t.parentNode.insertBefore(r,t)}}}function r(){"complete"===f.readyState&&o()}function o(){a("mark",["domContent",i()],null,"api")}function i(){return(new Date).getTime()}var a=e("handle"),u=e(1),c=window,f=c.document;NREUM.o={ST:setTimeout,XHR:c.XMLHttpRequest,REQ:c.Request,EV:c.Event,PR:c.Promise,MO:c.MutationObserver},e(2);var s=(""+location).split("?")[0],p={beacon:"bam.nr-data.net",errorBeacon:"bam.nr-data.net",agent:"js-agent.newrelic.com/nr-885.min.js"},l=window.XMLHttpRequest&&XMLHttpRequest.prototype&&XMLHttpRequest.prototype.addEventListener&&!/CriOS/.test(navigator.userAgent),d=t.exports={offset:i(),origin:s,features:{},xhrWrappable:l};f.addEventListener?(f.addEventListener("DOMContentLoaded",o,!1),c.addEventListener("load",n,!1)):(f.attachEvent("onreadystatechange",r),c.attachEvent("onload",n)),a("mark",["firstbyte",i()],null,"api");var v=0},{1:12,2:3,handle:"D5DuLP"}],loader:[function(e,t){t.exports=e("G9z0Bl")},{}],12:[function(e,t){function n(e,t){var n=[],o="",i=0;for(o in e)r.call(e,o)&&(n[i]=t(o,e[o]),i+=1);return n}var r=Object.prototype.hasOwnProperty;t.exports=n},{}],13:[function(e,t){function n(e,t,n){t||(t=0),"undefined"==typeof n&&(n=e?e.length:0);for(var r=-1,o=n-t||0,i=Array(0>o?0:o);++r<o;)i[r]=e[t+r];return i}t.exports=n},{}]},{},["G9z0Bl"]);</script>
<link rel="shortcut icon" href="http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/favicon.ico" type="image/vnd.microsoft.icon"/>
<meta name="Generator" content="Drupal 7 (http://drupal.org)"/>
<script src="https://maps.googleapis.com/maps/api/js?v=3.exp&amp;sensor=false"></script>
<!--[if lte IE 8]>
		<div style=' text-align:center; clear: both; padding:0 0 0 15px; position: relative;'>
			<a href="//windows.microsoft.com/en-US/internet-explorer/products/ie/home?ocid=ie6_countdown_bannercode">
				<img src="//storage.ie6countdown.com/assets/100/images/banners/warning_bar_0000_us.jpg" border="0" height="42" width="820" alt="You are using an outdated browser. For a faster, safer browsing experience, upgrade for free today.">
			</a>
		</div>
	<![endif]-->
<title>Welcome to Dentic | Dentic</title>
<style type="text/css" media="all">@import url("http://livedemo00.template-help.com/drupal_54829/modules/system/system.base.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/modules/system/system.menus.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/modules/system/system.messages.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/modules/system/system.theme.css?o3m4mb");</style>
<style type="text/css" media="screen">@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tipsy/stylesheets/tipsy.css?o3m4mb");</style>
<style type="text/css" media="all">@import url("http://livedemo00.template-help.com/drupal_54829/modules/comment/comment.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/modules/date/date_api/date.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/modules/field/theme/field.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/modules/node/node.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/modules/poll/poll.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/modules/search/search.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tm_shortcodes/css/shortcodes.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/modules/user/user.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/modules/forum/forum.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/modules/views/css/views.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tm_lazyload/css/tm_lazyload.css?o3m4mb");</style>
<style type="text/css" media="all">@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/modules/cctags/cctags.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/libraries/colorbox/example1/colorbox.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/modules/ctools/css/ctools.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/modules/panels/css/panels.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tm_animate/css/animate.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tm_font_awesome/css/font-awesome.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/modules/flexslider/assets/css/flexslider_img.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/libraries/flexslider/flexslider.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/modules/dismiss/css/dismiss.base.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tm_follow/css/tm_follow.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/libraries/superfish/css/superfish.css?o3m4mb");</style>
<style type="text/css" media="screen">@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/css/boilerplate.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/css/style.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/css/maintenance-page.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/css/skeleton.css?o3m4mb");@import url("http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/css/custom.css?o3m4mb");</style>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/jquery_update/replace/jquery/1.8/jquery.min.js?v=1.8.3"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/misc/jquery.once.js?v=1.2"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/misc/drupal.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tipsy/javascripts/jquery.tipsy.js?v=0.1.7"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tipsy/javascripts/tipsy.js?v=0.1.7"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tm_shortcodes/js/jquery.easypiechart.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tm_shortcodes/js/jquery.appear.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tm_shortcodes/js/shortcodes.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tm_lazyload/js/jquery.lazyloader.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/libraries/colorbox/jquery.colorbox-min.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/colorbox/js/colorbox.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tm_animate/js/wow.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/libraries/flexslider/jquery.flexslider-min.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/olark/olark.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tm_block_bg/js/tm_block_bg_parallax.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tm_block_bg/js/jquery.stellar.min.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tm_block_bg/js/jquery.mb.YTPlayer.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/tm_block_bg/js/tm_block_bg_video.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/libraries/superfish/jquery.hoverIntent.minified.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/libraries/superfish/sftouchscreen.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/libraries/superfish/superfish.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/libraries/easing/jquery.easing.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/libraries/superfish/supersubs.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/superfish/superfish.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/js/theme1005.core.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/js/jquery.loader.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/js/jquery.mobilemenu.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/js/jquery.debouncedresize.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/js/jquery.easing.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/js/jquery.ui.totop.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/js/jquery.cookie.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/js/tm-stick-up.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/js/tformer.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/js/device.min.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/js/jquery.mousewheel.min.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/js/jquery.simplr.smoothscroll.min.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/js/migrate.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/js/tm-parallax.js?o3m4mb"></script>
<script type="text/javascript">
<!--//--><![CDATA[//><!--
jQuery.extend(Drupal.settings, {"basePath":"\/drupal_54829\/","pathPrefix":"","ajaxPageState":{"theme":"theme1005","theme_token":"Dy_sOs8bMOdqFlf9nsBINYwIFih7i-QbRowdHFx1wYU","js":{"0":1,"sites\/all\/modules\/flexslider\/assets\/js\/flexslider.load.js":1,"sites\/all\/modules\/addthis\/addthis.js":1,"sites\/all\/modules\/jquery_update\/replace\/jquery\/1.8\/jquery.min.js":1,"misc\/jquery.once.js":1,"misc\/drupal.js":1,"sites\/all\/modules\/tipsy\/javascripts\/jquery.tipsy.js":1,"sites\/all\/modules\/tipsy\/javascripts\/tipsy.js":1,"sites\/all\/modules\/tm_shortcodes\/js\/jquery.easypiechart.js":1,"sites\/all\/modules\/tm_shortcodes\/js\/jquery.appear.js":1,"sites\/all\/modules\/tm_shortcodes\/js\/shortcodes.js":1,"sites\/all\/modules\/tm_lazyload\/js\/jquery.lazyloader.js":1,"sites\/all\/libraries\/colorbox\/jquery.colorbox-min.js":1,"sites\/all\/modules\/colorbox\/js\/colorbox.js":1,"sites\/all\/modules\/tm_animate\/js\/wow.js":1,"sites\/all\/libraries\/flexslider\/jquery.flexslider-min.js":1,"sites\/all\/modules\/olark\/olark.js":1,"sites\/all\/modules\/tm_block_bg\/js\/tm_block_bg_parallax.js":1,"sites\/all\/modules\/tm_block_bg\/js\/jquery.stellar.min.js":1,"sites\/all\/modules\/tm_block_bg\/js\/jquery.mb.YTPlayer.js":1,"sites\/all\/modules\/tm_block_bg\/js\/tm_block_bg_video.js":1,"sites\/all\/libraries\/superfish\/jquery.hoverIntent.minified.js":1,"sites\/all\/libraries\/superfish\/sftouchscreen.js":1,"sites\/all\/libraries\/superfish\/superfish.js":1,"sites\/all\/libraries\/easing\/jquery.easing.js":1,"sites\/all\/libraries\/superfish\/supersubs.js":1,"sites\/all\/modules\/superfish\/superfish.js":1,"sites\/all\/themes\/theme1005\/js\/theme1005.core.js":1,"sites\/all\/themes\/theme1005\/js\/jquery.loader.js":1,"sites\/all\/themes\/theme1005\/js\/jquery.mobilemenu.js":1,"sites\/all\/themes\/theme1005\/js\/jquery.debouncedresize.js":1,"sites\/all\/themes\/theme1005\/js\/jquery.easing.js":1,"sites\/all\/themes\/theme1005\/js\/jquery.ui.totop.js":1,"sites\/all\/themes\/theme1005\/js\/jquery.cookie.js":1,"sites\/all\/themes\/theme1005\/js\/tm-stick-up.js":1,"sites\/all\/themes\/theme1005\/js\/tformer.js":1,"sites\/all\/themes\/theme1005\/js\/device.min.js":1,"sites\/all\/themes\/theme1005\/js\/jquery.mousewheel.min.js":1,"sites\/all\/themes\/theme1005\/js\/jquery.simplr.smoothscroll.min.js":1,"sites\/all\/themes\/theme1005\/js\/migrate.js":1,"sites\/all\/themes\/theme1005\/js\/tm-parallax.js":1},"css":{"modules\/system\/system.base.css":1,"modules\/system\/system.menus.css":1,"modules\/system\/system.messages.css":1,"modules\/system\/system.theme.css":1,"sites\/all\/modules\/tipsy\/stylesheets\/tipsy.css":1,"modules\/comment\/comment.css":1,"sites\/all\/modules\/date\/date_api\/date.css":1,"modules\/field\/theme\/field.css":1,"modules\/node\/node.css":1,"modules\/poll\/poll.css":1,"modules\/search\/search.css":1,"sites\/all\/modules\/tm_shortcodes\/css\/shortcodes.css":1,"modules\/user\/user.css":1,"modules\/forum\/forum.css":1,"sites\/all\/modules\/views\/css\/views.css":1,"sites\/all\/modules\/tm_lazyload\/css\/tm_lazyload.css":1,"sites\/all\/modules\/cctags\/cctags.css":1,"sites\/all\/libraries\/colorbox\/example1\/colorbox.css":1,"sites\/all\/modules\/ctools\/css\/ctools.css":1,"sites\/all\/modules\/panels\/css\/panels.css":1,"sites\/all\/modules\/tm_animate\/css\/animate.css":1,"sites\/all\/modules\/tm_font_awesome\/css\/font-awesome.css":1,"sites\/all\/modules\/flexslider\/assets\/css\/flexslider_img.css":1,"sites\/all\/libraries\/flexslider\/flexslider.css":1,"sites\/all\/modules\/dismiss\/css\/dismiss.base.css":1,"sites\/all\/modules\/tm_follow\/css\/tm_follow.css":1,"sites\/all\/libraries\/superfish\/css\/superfish.css":1,"sites\/all\/themes\/theme1005\/css\/boilerplate.css":1,"sites\/all\/themes\/theme1005\/css\/style.css":1,"sites\/all\/themes\/theme1005\/css\/maintenance-page.css":1,"sites\/all\/themes\/theme1005\/css\/skeleton.css":1,"sites\/all\/themes\/theme1005\/css\/custom.css":1}},"colorbox":{"opacity":"0.85","current":"{current} of {total}","previous":"\u00ab Prev","next":"Next \u00bb","close":"Close","maxWidth":"98%","maxHeight":"98%","fixed":true,"mobiledetect":false,"mobiledevicewidth":"960px"},"tipsy":{"custom_selectors":[{"selector":".tipsy","options":{"fade":1,"gravity":"w","trigger":"hover","delayIn":"0","delayOut":"0","opacity":"0.8","offset":"0","html":0,"tooltip_content":{"source":"attribute","selector":"title"}}}]},"flexslider":{"optionsets":{"default":{"namespace":"flex-","selector":".slides \u003E li","easing":"swing","direction":"horizontal","reverse":false,"smoothHeight":false,"startAt":0,"animationSpeed":600,"initDelay":0,"useCSS":true,"touch":true,"video":false,"keyboard":true,"multipleKeyboard":false,"mousewheel":0,"controlsContainer":".flex-control-nav-container","sync":"","asNavFor":"","itemWidth":0,"itemMargin":0,"minItems":0,"maxItems":0,"move":0,"animation":"fade","slideshow":true,"slideshowSpeed":"7000","directionNav":true,"controlNav":true,"prevText":"","nextText":"","pausePlay":false,"pauseText":"Pause","playText":"Play","randomize":false,"thumbCaptions":false,"thumbCaptionsBoth":false,"animationLoop":true,"pauseOnAction":true,"pauseOnHover":false,"manualControls":""},"carousel":{"namespace":"flex-","selector":".slides \u003E li","easing":"swing","direction":"horizontal","reverse":false,"smoothHeight":false,"startAt":0,"animationSpeed":600,"initDelay":0,"useCSS":true,"touch":true,"video":false,"keyboard":true,"multipleKeyboard":false,"mousewheel":0,"controlsContainer":".flex-control-nav-container","sync":"","asNavFor":"","itemWidth":0,"itemMargin":0,"minItems":1,"maxItems":1,"move":1,"animation":"slide","slideshow":false,"slideshowSpeed":"7000","directionNav":false,"controlNav":true,"prevText":"","nextText":"","pausePlay":false,"pauseText":"Pause","playText":"Play","randomize":false,"thumbCaptions":false,"thumbCaptionsBoth":false,"animationLoop":true,"pauseOnAction":true,"pauseOnHover":false,"manualControls":""}},"instances":{"flexslider-1":"default","flexslider-2":"carousel"}},"dismiss":{"fadeout":0},"olark":{"disable_ios":1,"enabled":1},"superfish":{"1":{"id":"1","sf":{"animation":{"opacity":"show","height":["show","easeOutCubic"]},"speed":"\u0027fast\u0027","autoArrows":true,"dropShadows":false,"disableHI":false},"plugins":{"touchscreen":{"mode":"useragent_custom","useragent":"iphone|android|ipad"},"supposition":false,"bgiframe":false,"supersubs":{"minWidth":"12","maxWidth":"27","extraWidth":1}}}}});
//--><!]]>
</script>
<!--[if LT IE 9]>
		<script src="//html5shim.googlecode.com/svn/trunk/html5.js"></script>
	<![endif]-->
<script>
		if (jQuery.cookie('the_cookie') != 0) {
			document.write('<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1.0, user-scalable=no">')
		} else {
			document.write('<meta name="viewport" content="width=device-width">')
		}
	</script>
<link rel="stylesheet" href="/drupal_54829/sites/all/themes/theme1005/css/style-mobile.css" media="screen" id="style-mobile">
<link rel="stylesheet" href="/drupal_54829/sites/all/themes/theme1005/css/skeleton-mobile.css" media="screen" id="skeleton-mobile">
<script type="text/javascript">
/* <![CDATA[ */
var _gaq = _gaq || [];
_gaq.push(['_setAccount', 'UA-7078796-5']);
_gaq.push(['_trackPageview']);

(function() {
var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
})();

(function(b){(function(a){"__CF"in b&&"DJS"in b.__CF?b.__CF.DJS.push(a):"addEventListener"in b?b.addEventListener("load",a,!1):b.attachEvent("onload",a)})(function(){"FB"in b&&"Event"in FB&&"subscribe"in FB.Event&&(FB.Event.subscribe("edge.create",function(a){_gaq.push(["_trackSocial","facebook","like",a])}),FB.Event.subscribe("edge.remove",function(a){_gaq.push(["_trackSocial","facebook","unlike",a])}),FB.Event.subscribe("message.send",function(a){_gaq.push(["_trackSocial","facebook","send",a])}));"twttr"in b&&"events"in twttr&&"bind"in twttr.events&&twttr.events.bind("tweet",function(a){if(a){var b;if(a.target&&a.target.nodeName=="IFRAME")a:{if(a=a.target.src){a=a.split("#")[0].match(/[^?=&]+=([^&]*)?/g);b=0;for(var c;c=a[b];++b)if(c.indexOf("url")===0){b=unescape(c.split("=")[1]);break a}}b=void 0}_gaq.push(["_trackSocial","twitter","tweet",b])}})})})(window);
/* ]]> */
</script>
</head>
<body id="body" class="html front not-logged-in no-sidebars page-node with-navigation with-subnav">
<a href="#main-menu" class="element-invisible element-focusable">Skip to navigation</a>
<a href="#content" class="element-invisible element-focusable">Skip to main content</a>
<div id="page-wrapper" class="page-wrapper">
<div id="page" class="page">
 
<header id="header" class="header page-header clearfix" role="banner">
 
<div class="stickup header-section-1">  
<div class="container-12">
<div class="grid-12">
<div class="col1">
 
<div id="logo" class="logo">
<a href="/drupal_54829/" title="Home" rel="home" id="img-logo" class="img-logo">
<img src="http://livedemo00.template-help.com/drupal_54829/sites/all/themes/theme1005/logo.png" alt="Home">
</a>
</div> 
</div>
<div class="col2">
 
<div class="region region-menu">
<div id="block-superfish-1" class="block-superfish-1 block block-superfish block-odd">
 
 
<div class="content block-content">
<ul id="superfish-1" class="menu sf-menu sf-main-menu sf-horizontal sf-style-none sf-total-items-5 sf-parent-items-2 sf-single-items-3"><li id="menu-201-1" class="active-trail first odd sf-item-1 sf-depth-1 sf-total-children-3 sf-parent-children-3 sf-single-children-0 menuparent"><a href="/drupal_54829/" title="Front page" class="sf-depth-1 menuparent active">Home</a><ul class="sf-megamenu"><li class="sf-megamenu-wrapper active-trail first odd sf-item-1 sf-depth-1 sf-total-children-3 sf-parent-children-3 sf-single-children-0 menuparent"><ol><li id="menu-5076-1" class="first odd sf-item-1 sf-depth-2 sf-total-children-2 sf-parent-children-0 sf-single-children-2 sf-megamenu-column menuparent"><div class="sf-megamenu-column"><a href="/drupal_54829/?q=archive" title="" class="sf-depth-2 menuparent">Archive</a><ol><li id="menu-5077-1" class="first odd sf-item-1 sf-depth-3 sf-no-children"><a href="/drupal_54829/?q=faqs" title="" class="sf-depth-3">FAQs</a></li><li id="menu-5944-1" class="last even sf-item-2 sf-depth-3 sf-no-children"><a href="/drupal_54829/?q=testimonials" title="" class="sf-depth-3">Testimonials</a></li></ol></div></li><li id="menu-5612-1" class="middle even sf-item-2 sf-depth-2 sf-total-children-2 sf-parent-children-0 sf-single-children-2 sf-megamenu-column menuparent"><div class="sf-megamenu-column"><a href="http://drupal.org" title="" class="sf-depth-2 menuparent">Cras suscipit</a><ol><li id="menu-5945-1" class="first odd sf-item-1 sf-depth-3 sf-no-children"><a href="http://drupal.org" title="" class="sf-depth-3">Lorem ipsum</a></li><li id="menu-5614-1" class="last even sf-item-2 sf-depth-3 sf-no-children"><a href="http://drupal.org" title="" class="sf-depth-3">Vestibulum</a></li></ol></div></li><li id="menu-5615-1" class="last odd sf-item-3 sf-depth-2 sf-total-children-2 sf-parent-children-0 sf-single-children-2 sf-megamenu-column menuparent"><div class="sf-megamenu-column"><a href="http://drupal.org" title="" class="sf-depth-2 menuparent">Cras euismod</a><ol><li id="menu-5616-1" class="first odd sf-item-1 sf-depth-3 sf-no-children"><a href="http://drupal.org" title="" class="sf-depth-3">Vivamus sit</a></li><li id="menu-5940-1" class="last even sf-item-2 sf-depth-3 sf-no-children"><a href="http://drupal.org" title="" class="sf-depth-3">Dolore sit</a></li></ol></div></li></ol></li></ul></li><li id="menu-5074-1" class="middle even sf-item-2 sf-depth-1 sf-no-children"><a href="/drupal_54829/?q=about" class="sf-depth-1">About</a></li><li id="menu-739-1" class="middle odd sf-item-3 sf-depth-1 sf-total-children-3 sf-parent-children-1 sf-single-children-2 menuparent"><a href="/drupal_54829/?q=portfolio" title="" class="sf-depth-1 menuparent">Services </a><ul><li id="menu-3768-1" class="first odd sf-item-1 sf-depth-2 sf-no-children"><a href="/drupal_54829/?q=portfolio-2" title="" class="sf-depth-2">Services 2</a></li><li id="menu-3769-1" class="middle even sf-item-2 sf-depth-2 sf-total-children-3 sf-parent-children-0 sf-single-children-3 menuparent"><a href="/drupal_54829/?q=portfolio-3" title="" class="sf-depth-2 menuparent">Services 3</a><ul><li id="menu-5079-1" class="first odd sf-item-1 sf-depth-3 sf-no-children"><a href="/drupal_54829/?q=taxonomy/term/31" title="" class="sf-depth-3">Category 1</a></li><li id="menu-5080-1" class="middle even sf-item-2 sf-depth-3 sf-no-children"><a href="/drupal_54829/?q=taxonomy/term/30" title="" class="sf-depth-3">Category 2</a></li><li id="menu-5081-1" class="last odd sf-item-3 sf-depth-3 sf-no-children"><a href="/drupal_54829/?q=taxonomy/term/29" title="" class="sf-depth-3">Category 3</a></li></ul></li><li id="menu-3767-1" class="last odd sf-item-3 sf-depth-2 sf-no-children"><a href="/drupal_54829/?q=portfolio-4" title="" class="sf-depth-2">Services 4</a></li></ul></li><li id="menu-668-1" class="middle even sf-item-4 sf-depth-1 sf-no-children"><a href="/drupal_54829/?q=blog" title="" class="sf-depth-1">News</a></li><li id="menu-4931-1" class="last odd sf-item-5 sf-depth-1 sf-no-children"><a href="/drupal_54829/?q=contacts" class="sf-depth-1">Contacts</a></li></ul> </div>
</div> </div>
</div>
</div>
</div>
</div>
 
<div id="slider_wrapper" class="slider_wrapper region-fullwidth">
<div class="region region-slider">
<div id="block-views-slider-block" class="block-views-slider-block block block-views block-even">
 
 
<div class="content block-content">
<div class="view view-slider view-id-slider view-display-id-block view-dom-id-fdb74968657bfb3bdbec265fe9abd274">
<div class="view-content">
<div id="flexslider-1" class="flexslider">
<ul class="slides"><li>
<div class="views-field views-field-field-slide-image"> <div class="field-content"><img src="http://livedemo00.template-help.com/drupal_54829/sites/default/files/styles/flexslider_full/public/slide-1.jpg?itok=Z5Dyyrwq" width="2050" height="560"/></div> </div><div class="flex-caption"><div class="container-12">
<div class="grid-12">
<div class="inner">
<div class="slogan"><p>Providing comprehensive <span>dental services</span></p>
</div>
<div class="btn"><a href="/drupal_54829/?q=node/50">Read more</a></div>
</div>
</div>
</div></div></li>
<li>
<div class="views-field views-field-field-slide-image"> <div class="field-content"><img src="http://livedemo00.template-help.com/drupal_54829/sites/default/files/styles/flexslider_full/public/slide-2.jpg?itok=zlynOqrC" width="2050" height="560"/></div> </div><div class="flex-caption"><div class="container-12">
<div class="grid-12">
<div class="inner">
<div class="slogan"><p>Achieve your desired <span>perfect smile!</span></p>
</div>
<div class="btn"><a href="/drupal_54829/?q=node/47">Read more</a></div>
</div>
</div>
</div></div></li>
<li>
<div class="views-field views-field-field-slide-image"> <div class="field-content"><img src="http://livedemo00.template-help.com/drupal_54829/sites/default/files/styles/flexslider_full/public/slide-3.jpg?itok=OiFIZDwS" width="2050" height="560"/></div> </div><div class="flex-caption"><div class="container-12">
<div class="grid-12">
<div class="inner">
<div class="slogan"><p>Providing proper treatment <span>for each individual</span></p>
</div>
<div class="btn"><a href="/drupal_54829/?q=node/51">Read more</a></div>
</div>
</div>
</div></div></li>
</ul></div>
</div>
</div> </div>
</div> </div>
</div>
 
<div id="header_wrapper" class="header_wrapper">
<div class="container-12"><div class="grid-12"> <div class="region region-header">
<div id="block-views-block-1-block" class="block-views-block-1-block block block-views wow fadeInUp block-odd">
 
 
<div class="content block-content">
<div class="view view-block-1 view-id-block_1 view-display-id-block mobile-two-column view-dom-id-9b4b19a5e721e3a6378b49bd460f4d35">
<div class="view-content">
<div class="grid-3 views-row align-center first alpha odd">
<div class="views-field views-field-field-article-icon-img"> <div class="field-content"><img src="http://livedemo00.template-help.com/drupal_54829/sites/default/files/icon1.png" width="62" height="66"/></div> </div>
<h3 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/124">Package services</a></span> </h3>
<div class="views-field views-field-body"> <span class="field-content">Aenean quis mattis magna. In pulvinar interdum mauris in ornare.</span> </div> </div>
<div class="grid-3 views-row align-center even">
<div class="views-field views-field-field-article-icon-img"> <div class="field-content"><img src="http://livedemo00.template-help.com/drupal_54829/sites/default/files/icon2.png" width="62" height="66"/></div> </div>
<h3 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/123">Oral surgery</a></span> </h3>
<div class="views-field views-field-body"> <span class="field-content">Aenean quis mattis magna. In pulvinar interdum mauris in ornare.</span> </div> </div>
<div class="grid-3 views-row align-center odd">
<div class="views-field views-field-field-article-icon-img"> <div class="field-content"><img src="http://livedemo00.template-help.com/drupal_54829/sites/default/files/icon3.png" width="62" height="66"/></div> </div>
<h3 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/122">Implantology</a></span> </h3>
<div class="views-field views-field-body"> <span class="field-content">Aenean quis mattis magna. In pulvinar interdum mauris in ornare.</span> </div> </div>
<div class="grid-3 views-row align-center last omega even">
<div class="views-field views-field-field-article-icon-img"> <div class="field-content"><img src="http://livedemo00.template-help.com/drupal_54829/sites/default/files/icon4.png" width="62" height="66"/></div> </div>
<h3 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/121">Cosmetic dentistry</a></span> </h3>
<div class="views-field views-field-body"> <span class="field-content">Aenean quis mattis magna. In pulvinar interdum mauris in ornare.</span> </div> </div>
</div>
</div> </div>
</div> </div>
</div></div></div>
 
<div id="header_bottom_wrapper" class="header_bottom_wrapper">
<div class="container-12"><div class="grid-12"> <div class="region region-header-bottom">
<div id="block-block-8" class="block-block-8 block block-block wow fadeInUp block-even">
 
<h4 class="title block-title">About</h4>
 
<div class="content block-content">
<div class="clearfix">
<div class="grid-6 alpha"><figure class="img-indent"><img src="/drupal_54829/sites/all/themes/theme1005/images/page1_img1.jpg" alt=""/></figure></div>
<div class="grid-3">Lorem ipsum dolor sit amet conse ctetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Lorem ipsum dolor sit amet conse ctetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip.</div>
<div class="grid-3 omega">Dolor sit amet conse ctetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Lorem ipsum dolor sit amet conse ctetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim.</div>
</div> </div>
</div> </div>
</div></div></div> </header>
 
<div id="main-wrapper" class="main-wrapper" role="main">
 
<div id="content_top_wrapper" class="content_top_wrapper">
<div class="container-12"><div class="grid-12"> <div class="region region-content-top">
<div id="block-views-services-block" class="block-views-services-block block block-views wow fadeInUp block-odd">
 
<h4 class="title block-title">Services</h4>
 
<div class="content block-content">
<div class="view view-services view-id-services view-display-id-block mobile-two-column view-dom-id-bff3491e8cfb51d724af43b439d8c066">
<div class="view-content">
<div class="grid-3 views-row first alpha clear-left odd">
<h5 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/132"><i class="fa fa-angle-right"></i>Incididunt ut labore et dol</a></span> </h5>
<div class="views-field views-field-body"> <span class="field-content">Aenean quis mattis magna. In pulvinar interdum mauris in ornare. Fusce molestie erat id sapien aliquam</span> </div> </div>
<div class="grid-3 views-row even">
<h5 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/131"><i class="fa fa-angle-right"></i>veniam quis nostrud</a></span> </h5>
<div class="views-field views-field-body"> <span class="field-content">Aenean quis mattis magna. In pulvinar interdum mauris in ornare. Fusce molestie erat id sapien aliquam</span> </div> </div>
<div class="grid-3 views-row odd">
<h5 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/130"><i class="fa fa-angle-right"></i>laboris nisi</a></span> </h5>
<div class="views-field views-field-body"> <span class="field-content">Aenean quis mattis magna. In pulvinar interdum mauris in ornare. Fusce molestie erat id sapien aliquam</span> </div> </div>
<div class="grid-3 views-row last omega even">
<h5 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/129"><i class="fa fa-angle-right"></i>voluptate velit</a></span> </h5>
<div class="views-field views-field-body"> <span class="field-content">Aenean quis mattis magna. In pulvinar interdum mauris in ornare. Fusce molestie erat id sapien aliquam</span> </div> </div>
<div class="grid-3 views-row first alpha clear-left odd">
<h5 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/128"><i class="fa fa-angle-right"></i>IUt enim ad minim</a></span> </h5>
<div class="views-field views-field-body"> <span class="field-content">Aenean quis mattis magna. In pulvinar interdum mauris in ornare. Fusce molestie erat id sapien aliquam</span> </div> </div>
<div class="grid-3 views-row even">
<h5 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/127"><i class="fa fa-angle-right"></i>exercitation ullamco</a></span> </h5>
<div class="views-field views-field-body"> <span class="field-content">Aenean quis mattis magna. In pulvinar interdum mauris in ornare. Fusce molestie erat id sapien aliquam</span> </div> </div>
<div class="grid-3 views-row odd">
<h5 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/126"><i class="fa fa-angle-right"></i>reprehenderit in</a></span> </h5>
<div class="views-field views-field-body"> <span class="field-content">Aenean quis mattis magna. In pulvinar interdum mauris in ornare. Fusce molestie erat id sapien aliquam</span> </div> </div>
<div class="grid-3 views-row last omega even">
<h5 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/125"><i class="fa fa-angle-right"></i>esse cillum dolore eu</a></span> </h5>
<div class="views-field views-field-body"> <span class="field-content">Aenean quis mattis magna. In pulvinar interdum mauris in ornare. Fusce molestie erat id sapien aliquam</span> </div> </div>
</div>
</div> </div>
</div> </div>
</div></div></div>
 
<div id="section_1_wrapper" class="section_1_wrapper region-fullwidth">
<div class="region region-section-1">
<div id="block-views-our-team-block-2" class="block-views-our-team-block-2 block block-views wow fadeInUp block-even">
 
 
<div class="content block-content">
<div class="view view-our-team view-id-our_team view-display-id-block_2 clearfix view-dom-id-5e47262be27f00c1fef3569b44fc9dc8">
<div class="view-content">
<div class="views-row views-row-1 views-row-odd views-row-first">
<div class="views-field views-field-field-employee-photo"> <div class="field-content"><img src="http://livedemo00.template-help.com/drupal_54829/sites/default/files/styles/171x171/public/emp-1.jpg?itok=0rP3FBxw" width="171" height="171"/></div> </div>
<h5 class="views-field views-field-field-employee-position"> <div class="field-content">DR</div> </h5>
<h3 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/69">Tom Cooper</a></span> </h3>
<div class="views-field views-field-body"> <div class="field-content">Vivamus vel eros eget magna volutpat sagittis. Nulla faucibus nibh a magna</div> </div>
<div class="views-field views-field-field-office-hours"> <div class="views-label views-label-field-office-hours">Office Hours: </div> <div class="field-content"><div class="item-list"><ul><li class="first">Mon – Fri: 10am – 8pm</li>
<li class="last">Sat – Sun: By Special Appointment</li>
</ul></div></div> </div> </div>
<div class="views-row views-row-2 views-row-even">
<div class="views-field views-field-field-employee-photo"> <div class="field-content"><img src="http://livedemo00.template-help.com/drupal_54829/sites/default/files/styles/171x171/public/emp-2.jpg?itok=LrJ3r-5X" width="171" height="171"/></div> </div>
<h5 class="views-field views-field-field-employee-position"> <div class="field-content">DR</div> </h5>
<h3 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/65">Amir CARTER</a></span> </h3>
<div class="views-field views-field-body"> <div class="field-content">Vivamus vel eros eget magna volutpat sagittis. Nulla faucibus nibh a magna</div> </div>
<div class="views-field views-field-field-office-hours"> <div class="views-label views-label-field-office-hours">Office Hours: </div> <div class="field-content"><div class="item-list"><ul><li class="first">Mon – Fri: 10am – 8pm</li>
<li class="last">Sat – Sun: By Special Appointment</li>
</ul></div></div> </div> </div>
<div class="views-row views-row-3 views-row-odd">
<div class="views-field views-field-field-employee-photo"> <div class="field-content"><img src="http://livedemo00.template-help.com/drupal_54829/sites/default/files/styles/171x171/public/emp-3.jpg?itok=MqQ3TtKc" width="171" height="171"/></div> </div>
<h5 class="views-field views-field-field-employee-position"> <div class="field-content">DR</div> </h5>
<h3 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/73">Amanda CARTER</a></span> </h3>
<div class="views-field views-field-body"> <div class="field-content">Vivamus vel eros eget magna volutpat sagittis. Nulla faucibus nibh a magna</div> </div>
<div class="views-field views-field-field-office-hours"> <div class="views-label views-label-field-office-hours">Office Hours: </div> <div class="field-content"><div class="item-list"><ul><li class="first">Mon – Fri: 10am – 8pm</li>
<li class="last">Sat – Sun: By Special Appointment</li>
</ul></div></div> </div> </div>
<div class="views-row views-row-4 views-row-even views-row-last">
<div class="views-field views-field-field-employee-photo"> <div class="field-content"><img src="http://livedemo00.template-help.com/drupal_54829/sites/default/files/styles/171x171/public/emp-4.jpg?itok=N-sy7Ywb" width="171" height="171"/></div> </div>
<h5 class="views-field views-field-field-employee-position"> <div class="field-content">DR</div> </h5>
<h3 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/71">Kay NELSON</a></span> </h3>
<div class="views-field views-field-body"> <div class="field-content">Vivamus vel eros eget magna volutpat sagittis. Nulla faucibus nibh a magna</div> </div>
<div class="views-field views-field-field-office-hours"> <div class="views-label views-label-field-office-hours">Office Hours: </div> <div class="field-content"><div class="item-list"><ul><li class="first">Mon – Fri: 10am – 8pm</li>
<li class="last">Sat – Sun: By Special Appointment</li>
</ul></div></div> </div> </div>
</div>
</div> </div>
</div> </div>
</div>
<div class="container-12">
<div class="grid-12">
<div id="main" class="main clearfix">
 
<div id="content" class="content content-main ">
 
<div class="region region-content">
<div id="block-system-main" class="block-system-main block block-system block-odd">
 
 
<div class="content block-content">
</div>
</div>
<div id="block-views-testimonials-block" class="block-views-testimonials-block block block-views wow fadeInUp block-even">
 
<h4 class="title block-title">Testimonials</h4>
 
<div class="content block-content">
<div class="view view-testimonials view-id-testimonials view-display-id-block view-dom-id-75921442ba96855e8067f9916c25d6e6">
<div class="view-content">
<div id="flexslider-2" class="flexslider">
<ul class="slides"><li>
<div class="views-field views-field-body"> <span class="field-content">Cras elementum sed mi sit amet ullamcorper. Cras sed felis a enim rutrum lobortis a eu nisi. Curabitur justo libero, hendrerit at consequat ut, sagittis convallis lorem. Morbi interdum mattis justo, sed commodo nibh ultricies nec. Duis ornare lacus quam, sit amet dapibus augue sodales non. Maecenas</span> </div>
<h5 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/86"> Incididunt ut l</a></span> </h5></li>
<li>
<div class="views-field views-field-body"> <span class="field-content">Cras sit amet metus id odio sollicitudin eleifend non id lectus. Vivamus commodo est magna, ut hendrerit elit hendrerit in. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Sed pulvinar quam varius sapien commodo vehicula. Integer quis viverra diam.</span> </div>
<h5 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/85"> Incididunt ut l</a></span> </h5></li>
<li>
<div class="views-field views-field-body"> <span class="field-content">Etiam eget accumsan neque, et sollicitudin lacus. Ut nunc nibh, molestie vel varius in, placerat vel velit. Etiam non euismod ante. Nulla id fermentum augue, eu elementum risus. Donec sit amet turpis tempus, vehicula mi hendrerit, dictum felis. Cras tincidunt est ac commodo feugiat. Sed nec urna</span> </div>
<h5 class="views-field views-field-title"> <span class="field-content"><a href="/drupal_54829/?q=node/84"> Incididunt ut l</a></span> </h5></li>
</ul></div>
</div>
</div> </div>
</div> </div>
</div>
</div>
</div>
</div>
 
</div>
 
<footer id="footer" class="footer page-footer" role="contentinfo">
 
<div id="footer_top_wrapper" class="footer_top_wrapper">
<div class="container-12"><div class="grid-12"> <div class="region region-footer-top">
<div id="block-block-9" class="block-block-9 block block-block wow fadeInUp align-center block-odd">
 
 
<div class="content block-content">
<p>One of our representatives will happily contact you within 24 hours. For urgent needs call us at</p>
<p class="tel"><i class="fa fa-phone"></i>(800) 2345-6789</p>
<p class="text-1"><i class="fa fa-map-marker"></i>4578 Marmora Road,Glasgow D04 89GR</p>
<p class="text-1"><i class="fa fa-envelope-o"></i><a href="/cdn-cgi/l/email-protection#462f2820290622232b292a2f282d68293421"><span class="__cf_email__" data-cfemail="b3daddd5dcf3d7d6dedcdfdaddd89ddcc1d4">[email&#160;protected]</span><script data-cfhash='f9e31' type="text/javascript">/* <![CDATA[ */!function(t,e,r,n,c,a,p){try{t=document.currentScript||function(){for(t=document.getElementsByTagName('script'),e=t.length;e--;)if(t[e].getAttribute('data-cfhash'))return t[e]}();if(t&&(c=t.previousSibling)){p=t.parentNode;if(a=c.getAttribute('data-cfemail')){for(e='',r='0x'+a.substr(0,2)|0,n=2;a.length-n;n+=2)e+='%'+('0'+('0x'+a.substr(n,2)^r).toString(16)).slice(-2);p.replaceChild(document.createTextNode(decodeURIComponent(e)),c)}p.removeChild(t)}}catch(u){}}()/* ]]> */</script></a></p>
</div>
</div>
<div id="block-tm-follow-site" class="block-tm-follow-site block block-tm-follow wow fadeInUp block-even">
 
 
<div class="content block-content">
<div class='tm-follow-links clearfix site'><span class='tm-follow-link-wrapper tm-follow-link-wrapper-facebook without-label'><a href="http://facebook.com/" class="tm-follow-link tm-follow-link-facebook tm-follow-link-site"></a>
</span><span class='tm-follow-link-wrapper tm-follow-link-wrapper-twitter without-label'><a href="http://twitter.com/" class="tm-follow-link tm-follow-link-twitter tm-follow-link-site"></a>
</span></div> </div>
</div> </div>
</div></div></div>
<div class="footer-wrapper">
<div class="container-12">
<div class="grid-12 clearfix">
 
<div class="region region-footer">
<div id="block-block-5" class="block-block-5 block block-block block-copyright wow fadeInUp block-odd">
 
 
<div class="content block-content">
<div><span class="sitename">Dentic</span> &copy; 2016. <a href="?q=privacy-policy">Privacy Policy</a></div>
<div class="switcher">Desktop Version Only</div> </div>
</div> </div>
 
</div>
</div>
</div>
</footer>
</div>
</div> <div class="region region-page-bottom">
 
<script type="text/javascript" data-cfasync="false">// <![CDATA[
/*<![CDATA[*/window.olark||(function(c){var f=window,d=document,l=f.location.protocol=="https:"?"https:":"http:",z=c.name,r="load";var nt=function(){
f[z]=function(){
(a.s=a.s||[]).push(arguments)};var a=f[z]._={
},q=c.methods.length;while(q--){(function(n){f[z][n]=function(){
f[z]("call",n,arguments)}})(c.methods[q])}a.l=c.loader;a.i=nt;a.p={
0:+new Date};a.P=function(u){
a.p[u]=new Date-a.p[0]};function s(){
a.P(r);f[z](r)}f.addEventListener?f.addEventListener(r,s,false):f.attachEvent("on"+r,s);var ld=function(){function p(hd){
hd="head";return["<",hd,"></",hd,"><",i,' onl' + 'oad="var d=',g,";d.getElementsByTagName('head')[0].",j,"(d.",h,"('script')).",k,"='",l,"//",a.l,"'",'"',"></",i,">"].join("")}var i="body",m=d[i];if(!m){
return setTimeout(ld,100)}a.P(1);var j="appendChild",h="createElement",k="src",n=d[h]("div"),v=n[j](d[h](z)),b=d[h]("iframe"),g="document",e="domain",o;n.style.display="none";m.insertBefore(n,m.firstChild).id=z;b.frameBorder="0";b.id=z+"-loader";if(/MSIE[ ]+6/.test(navigator.userAgent)){
b.src="javascript:false"}b.allowTransparency="true";v[j](b);try{
b.contentWindow[g].open()}catch(w){
c[e]=d[e];o="javascript:var d="+g+".open();d.domain='"+d.domain+"';";b[k]=o+"void(0);"}try{
var t=b.contentWindow[g];t.write(p());t.close()}catch(x){
b[k]=o+'d.write("'+p().replace(/"/g,String.fromCharCode(92)+'"')+'");d.close();'}a.P(2)};ld()};nt()})({
loader: "static.olark.com/jsclient/loader0.js",name:"olark",methods:["configure","extend","declare","identify"]});
/* custom configuration goes here (www.olark.com/documentation) */
olark.identify('7830-582-10-3714');/*]]>*/
// ]]></script>
<noscript><a href="https://www.olark.com/site/7830-582-10-3714/contact" title="Contact us" target="_blank">Questions? Feedback?</a> powered by <a href="http://www.olark.com?welcome" title="Olark live chat software">Olark live chat software</a></noscript>
  </div>
<script type="text/javascript">
<!--//--><![CDATA[//><!--
/**
 * @file
 *   Main JavaScript file for Dismiss module
 */

(function ($) {

  Drupal.behaviors.dismiss = {
    attach: function (context, settings) {

      // Prepend the Dismiss button to each message box.
      $('.messages').each(function () {
        var flag = $(this).children().hasClass('dismiss');

        if (!flag) {
          $(this).prepend('<button class="dismiss"><span class="element-invisible">' + Drupal.t('Close this message.') + '</span></button>');
        }
      });

      // When the Dismiss button is clicked hide this set of messages.
      $('.dismiss').click(function () {
        $(this).parent().hide('fast');
      });

      // Fadeout out status messages when positive value defined.
      if (Drupal.settings.dismiss.fadeout > 0) {
        setTimeout(function () { $('.messages.status').fadeOut(); }, Drupal.settings.dismiss.fadeout);
      }

    }
  }

})(jQuery);

//--><!]]>
</script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/flexslider/assets/js/flexslider.load.js?o3m4mb"></script>
<script type="text/javascript" src="http://livedemo00.template-help.com/drupal_54829/sites/all/modules/addthis/addthis.js?o3m4mb"></script>
<script type="text/javascript">window.NREUM||(NREUM={});NREUM.info={"beacon":"bam.nr-data.net","licenseKey":"72d7dcce33","applicationID":"1388850","transactionName":"ZV1TZ0FTVkFVWkwKXlwXcFBHW1dcG1dXB1RtSFBUVm1cV1JYTQ9F","queueTime":0,"applicationTime":6384,"atts":"SRpQEQlJRU8=","errorBeacon":"bam.nr-data.net","agent":""}</script><script type="text/javascript">/* <![CDATA[ */(function(d,s,a,i,j,r,l,m,t){try{l=d.getElementsByTagName('a');t=d.createElement('textarea');for(i=0;l.length-i;i++){try{a=l[i].href;s=a.indexOf('/cdn-cgi/l/email-protection');m=a.length;if(a&&s>-1&&m>28){j=28+s;s='';if(j<m){r='0x'+a.substr(j,2)|0;for(j+=2;j<m&&a.charAt(j)!='X';j+=2)s+='%'+('0'+('0x'+a.substr(j,2)^r).toString(16)).slice(-2);j++;s=decodeURIComponent(s)+a.substr(j,m-j)}t.innerHTML=s.replace(/</g,'&lt;').replace(/>/g,'&gt;');l[i].href='mailto:'+t.value}}catch(e){}}}catch(e){}})(document);/* ]]> */</script></body> <noscript><iframe src="//www.googletagmanager.com/ns.html?id=GTM-N7VWVN" height="0" width="0" style="display:none;visibility:hidden"></iframe></noscript> <script>(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push( {'gtm.start': new Date().getTime(),event:'gtm.js'} );var f=d.getElementsByTagName(s)[0], j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src='//www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f); })(window,document,'script','dataLayer','GTM-N7VWVN');</script>  
</html>