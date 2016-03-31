<?php 
$AUF_URL_header = 'http://auf.eg-vm-preprod2.accelance.net/?q=node/1';
/* $ch = curl_init();
curl_setopt($ch, CURLOPT_URL, $wikipediaURL);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($ch, CURLOPT_USERAGENT, 'Le blog de Samy Dindane (www.dinduks.com)');
$resultat = curl_exec ($ch);
curl_close($ch);*/
$resultat = file_get_contents($AUF_URL_header);
echo $resultat;
?>
