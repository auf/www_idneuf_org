<html>
<head>
	<link rel="stylesheet" href="http://localhost/www_idneuf_org/ori-oai-search-idneuf.css" media="screen">

</head>
<body>
<?php 
$wikipediaURL = 'http://localhost/www_idneuf_org/http_header/';
/* $ch = curl_init();
curl_setopt($ch, CURLOPT_URL, $wikipediaURL);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($ch, CURLOPT_USERAGENT, 'Le blog de Samy Dindane (www.dinduks.com)');
$resultat = curl_exec ($ch);
curl_close($ch);*/
$resultat = file_get_contents($wikipediaURL);
echo $resultat;
?>
<p>test include header</p>

<p>test include footer</p>

<?php 
$wikipediaURL = 'http://localhost/www_idneuf_org/http_footer/';
/* $ch = curl_init();
curl_setopt($ch, CURLOPT_URL, $wikipediaURL);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($ch, CURLOPT_USERAGENT, 'Le blog de Samy Dindane (www.dinduks.com)');
$resultat = curl_exec ($ch);
curl_close($ch);*/
$resultat = file_get_contents($wikipediaURL);
echo $resultat;
?>
</body>
</html>