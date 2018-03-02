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
    /*if ($_FILES["file"]["error"] > 0) {
                echo "Return Code: " . $_FILES["file"]["error"] . PHP_EOL;
        $content = "";
    }
            else {
                //Print file details
                echo "Upload: " . $_FILES["file"]["name"] . PHP_EOL;
                echo "Type: " . $_FILES["file"]["type"] . PHP_EOL;
                echo "Size: " . ($_FILES["file"]["size"] / 1024) . " Kb" . PHP_EOL;
                echo "Temp file: " . $_FILES["file"]["tmp_name"] . PHP_EOL;

                //if file already exists
                if (file_exists("dirs_and_files/" . $_FILES["file"]["name"])) {
                    echo $_FILES["file"]["name"] . " already exists. ";
                }
                else {
                    //Store file in directory "upload" with the name of "uploaded_file.txt"
                    $storagename = "uploaded_file.txt";
                    move_uploaded_file($_FILES["file"]["tmp_name"], "upload/" . $storagename);
                    echo "Stored in: " . "upload/" . $_FILES["file"]["name"] . PHP_EOL;
                }
            
        }*/

    
}



?>