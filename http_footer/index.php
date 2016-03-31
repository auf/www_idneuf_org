<?php 
$wikipediaURL = 'http://localhost/drupal-7.43/?q=http_footer';
/* $ch = curl_init();
curl_setopt($ch, CURLOPT_URL, $wikipediaURL);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($ch, CURLOPT_USERAGENT, 'Le blog de Samy Dindane (www.dinduks.com)');
$resultat = curl_exec ($ch);
curl_close($ch);*/
$resultat = file_get_contents($wikipediaURL);
echo $resultat;
?>