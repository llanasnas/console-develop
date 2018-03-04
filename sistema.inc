<?php


include_once("executa.php");


function moures($dir)
{

    if (is_dir($dir)) {

        $_SESSION['path'] = $dir;
    }

}

function ruta()
{
    escriure(getcwd());
}

function stats_sistema()
{
    $porcentaje = (disk_free_space("/")*100)/disk_total_space("/");
    escriure("Free :" . disk_free_space("/")." ".$porcentaje."%");
    escriure("Total :" . disk_total_space("/"));
}

?>