<?php


include_once ("executa.php");


function moures($dir){

    if(is_dir($dir)){

        $_SESSION['path']= $dir;
    }

}

?>