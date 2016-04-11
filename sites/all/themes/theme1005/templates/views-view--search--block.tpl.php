<?php
$content_search=file_get_contents('http://testv2.ori-oai.org/idneuf-dev/index.html?bloc=simple-search&includeJs=false&addMainDiv=false');
echo $content_search;
$content_nbr=file_get_contents('http://testv2.ori-oai.org/idneuf-dev/index.html?bloc=title-with-nb-results&includeJs=false&addMainDiv=false');
echo $content_nbr;
?>