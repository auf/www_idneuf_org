<div id="ori-oai-search" >
<?php
$content_search=file_get_contents('http://testv2.ori-oai.org/idneuf-dev/index.html?bloc=simple-search&includeJs=false&includeJsLight=true&addMainDiv=false');
echo $content_search;?>
<br>
<?php
$content_nbr=file_get_contents('http://testv2.ori-oai.org/idneuf-dev/index.html?bloc=title-with-nb-results&ajax=false&includeAjaxParameters=false&addMainDiv=false');
echo $content_nbr;
?>
</div>