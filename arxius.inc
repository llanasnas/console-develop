<?php



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
    if (file_exists("dirs_and_files/".$fitxer)){
        escriure(sha1($fitxer));
    }else{
        escriure("Unknown file");
    }

}


function md5_peix($fitxer){
    if (file_exists("dirs_and_files/".$fitxer)){
        escriure(md5($fitxer));
    }else{
        escriure("Unknown file");
    }

}

function file_stat($dir){

    $status = stat($dir);
    $file = fopen("text_consola.txt","a")OR die("Cannot Open this file");
    $content = "Acces Time:". $status['atime'] . PHP_EOL . " Size: " . $status['size'];
    fwrite($file,$content);
    fclose($file);

}

function cat_fitcher($filename){

    $file = fopen("text_consola.txt","a")OR die("Cannot Open this file");
    fwrite($file, file_get_contents($filename). PHP_EOL);
    fclose($file);
    
}



?>