<?php



function crea_directoris($command){
    $dir = str_replace("mkdir ","",$command);    
    $dir= "dirs_and_files/".$dir;
    if(!file_exists($dir)){
        mkdir($dir);        
    }else{
        escriure("This file already exists");
    }
}
function esborra_directoris($dir){

    if (is_dir($dir)) {
        $objects = scandir($dir);
        foreach ($objects as $object) {
            if ($object != "." && $object != "..") {
                if (is_dir($dir."/".$object))
                    esborra_directoris($dir."/".$object);
                else
                    unlink($dir."/".$object);
            }
        }
        rmdir($dir);
        if(empty(scandir($dir))){rmdir($dir);}
    }else{
        escriure("this directory don't exist");
    }
}
function escriure($text){

    $file = fopen("text_consola.txt","a")OR die("Cannot Open this file");
    if($_SESSION['path']=="dirs_and_files/"){
        $text = "root@gerard-PC~# ". $text;
    }else {$text = "root@gerard-PC: ".$_SESSION['path']." # ". $text;}


    fwrite($file,$text . PHP_EOL);
    fclose($file);

}
function move_directory($arxiu,$nou_arxiu){

    $arxiu="dirs_and_files/".$arxiu;
    $nou_arxiu="dirs_and_files/".$nou_arxiu;
    if(!rename($arxiu,$nou_arxiu)){
        escriure("Can't find this directory");
    }
}
function ls(){

    $directories = scandir("dirs_and_files");
    foreach ($directories as $item){
        if($item == "." || $item == ".."){
        }else{
            $file = fopen("text_consola.txt","a")OR die("Cannot Open this file");
            if(is_dir("dirs_and_files/".$item)){
                fwrite($file,"<span style='color:blue; !important'>".$item ."</span>". PHP_EOL);
            }else{
                fwrite($file,"<span style='color:darkgrey; !important'>".$item ."</span>". PHP_EOL);
            }
            fclose($file);
        }
    }
}
function ls_other($path){

    $dir = "dirs_and_files/".$path;
    if(is_dir($dir)) {
        $directories = scandir($dir);

        foreach ($directories as $item) {

            if ($item == "." || $item == "..") {
            } else {
                $file = fopen("text_consola.txt", "a") OR die("Cannot Open this file");
                if (is_dir($dir."/" .$item)) {
                    fwrite($file, "<span style='color:blue; !important'>" . $item . "</span>" . PHP_EOL);
                } else {
                    fwrite($file, "<span style='color:darkgrey; !important'>" . $item . "</span>" . PHP_EOL);
                }
                fclose($file);
            }
        }
    }else{
        escriure("this path don't exists");
    }
}
function copia_directori($directorio,$destino){



    if(!is_dir("dirs_and_files/".$directorio)){
        escriure("file or directory not find");
    }else {
        $dir = opendir("dirs_and_files/".$directorio);
        @mkdir("dirs_and_files/".$destino);
        while (false !== ($file = readdir($dir))) {
            if (($file != '.') && ($file != '..')) {
                if (is_dir("dirs_and_files/".$directorio . '/' . $file)) {
                    copia_directori("dirs_and_files/".$directorio . '/' . $file, "dirs_and_files/".$destino . '/' . $file);
                } else {
                    copy("dirs_and_files/".$directorio . '/' . $file, "dirs_and_files/".$destino . '/' . $file);
                }
            }
        }
    }
    closedir($dir);
}



?>