
<?php
// cette fonction técupère le contenu d'un document distant
function geturl($laurl){
        $data=null;
        if($http= fopen($laurl,"r")){
                while(!feof($http)){
                $data .=fgets($http,1024);        
                }
                fclose($http);
        }
        return($data);
}


// cette fonction récupère le contenu des tags sélectionnés
function get_tag1($file,$tag="header"){
   preg_match_all("/(<".$tag.".*>)(\w.*)(<\/".$tag.">)/ismU",$file,$patterns);
       return $patterns;
       
} 
?>
<?php
// recuperer le contenu de cette page
$data=geturl("http://localhost/www_idneuf_org/?q=http_header");
// récupère le contenu du tag, tag compris
$extrait=get_tag1($data,"header");
// ce qui revient est un tableau, on liste tous les résultats avec foreach
foreach($extrait[0] as $contenu){
echo $contenu;        
}
?>


