<div id="ori-oai-search" style="font-size:18px !important;" >
<?php
$content_search=file_get_contents('http://testv2.ori-oai.org/idneuf-dev/index.html?bloc=simple-search&includeJs=false&includeJsLight=true&addMainDiv=false');
echo $content_search;?>
<br />
<div class="ori-oai-search col-xs-12 col-md-12 col-lg-12" >
<?php
$content_nbr=file_get_contents('http://testv2.ori-oai.org/idneuf-dev/index.html?bloc=title-with-nb-results&ajax=false&includeAjaxParameters=false&addMainDiv=false');
echo $content_nbr;
?>
</div>
</div>