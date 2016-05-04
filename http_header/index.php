<meta content="text/html; charset=UTF-8" http-equiv="Content-Type" />
<?php
// cette fonction tÃ©cupÃ¨re le contenu d'un document distant
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


// cette fonction rÃ©cupÃ¨re le contenu des tags sÃ©lectionnÃ©s
function get_tag1($file,$tag="header"){
   preg_match_all("/(<".$tag.".*>)(\w.*)(<\/".$tag.">)/ismU",$file,$patterns);
       return $patterns;
       
} 
?>
<?php
// recuperer le contenu de cette page
$data=geturl("http://".$_SERVER['SERVER_NAME']."/?q=http_header");
// rÃ©cupÃ¨re le contenu du tag, tag compris
$extrait=get_tag1($data,"header");
// ce qui revient est un tableau, on liste tous les rÃ©sultats avec foreach
foreach($extrait[0] as $contenu){
echo $contenu;        
}
?>


