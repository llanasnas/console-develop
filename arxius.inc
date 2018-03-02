<?php
/**
 * Created by PhpStorm.
 * User: Alumne
 * Date: 26/02/2018
 * Time: 18:07
 */
function crea_modifica_fitxer($name,$content){

    $control = fopen("dirs_and_files/".$name,"w+");
    if($control == false){
        escriure("can't create any files, check your permissions");
        fclose($control);
    }else{
        fclose($control);
        $file = fopen("dirs_and_files/".$name,"a")OR die("Cannot Open this file");
        fwrite($file,$content);
        fclose($file);
    }
}
function esborra_fitxer($command){
    $dir = str_replace("rm ","",$command);
    $dir= "dirs_and_files/".$dir;
    if(!unlink($dir)){
        escriure("can't find this file");
    }
}
function sha1_peix($fitxer){


}
function cat_fitcher($filename){


    $file = fopen("text_consola.txt","a")OR die("Cannot Open this file");
    fwrite($file, file_get_contents($filename). PHP_EOL);
    fclose($file);


    
}



?>