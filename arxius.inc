<?php


function crea_modifica_fitxer($name, $content)
{

    $control = fopen("dirs_and_files/" . $name, "a");
    if ($control == false) {
        escriure("can't create any files, check your permissions");
        fclose($control);
    } else {
        fclose($control);
        $file = fopen("dirs_and_files/" . $name, "a") OR die("Cannot Open this file");
        fwrite($file, $content);
        fclose($file);
    }
}

function esborra_fitxer($command)
{
    $dir = str_replace("rm ", "", $command);
    $dir = "dirs_and_files/" . $dir;
    if (!unlink($dir)) {
        escriure("can't find this file");
    }
}

function find_fitcher($fitxer, $dir)
{

    if (file_exists($dir . "/" . $fitxer)) {
        escriure("The file " . $dir . "/" . $fitxer . " exist");
    } else {
        escriure("The file " . $dir . "/" . $fitxer . " not exist");
    }

}


function sha1_peix($fitxer)
{
    if (file_exists("dirs_and_files/" . $fitxer)) {
        escriure(sha1($fitxer));
    } else {
        escriure("Unknown file");
    }

}

function moure_fitxer($fitxer, $desti)
{

    $fitxer = "dirs_and_files/" . $fitxer;
    $desti = "dirs_and_files/" . $desti;
    if (file_exists($fitxer)) {
        if (!rename($fitxer, $desti)) {
            escriure("can't find this new directory");
        }
    }
}


function md5_peix($fitxer)
{
    if (file_exists("dirs_and_files/" . $fitxer)) {
        escriure(md5($fitxer));
    } else {
        escriure("Unknown file");
    }

}

function copia_fitxer($old_file, $new_file)
{
    $old_file = "dirs_and_files/" . $old_file;
    $new_file = "dirs_and_files/" . $new_file;
    if (file_exists($old_file)) {
        if (!copy($old_file, $new_file)) {
            escriure("cannot find this new destination");
        }
    } else {
        escriure("cannot find this file");
    }
}

function file_stat($dir)
{

    $status = stat($dir);
    $file = fopen("text_consola.txt", "a") OR die("Cannot Open this file");
    $content = "Acces Time:" . $status['atime'] . PHP_EOL . " Size: " . $status['size'];
    fwrite($file, $content);
    fclose($file);

}

function cat_fitcher($filename)
{

    $file = fopen("text_consola.txt", "a") OR die("Cannot Open this file");
    fwrite($file, file_get_contents($filename) . PHP_EOL);
    fclose($file);

}


?>