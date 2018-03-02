<?php
/**
 * Created by PhpStorm.
 * User: Alumne
 * Date: 19/02/2018
 * Time: 18:16
 */
include_once("console.php");
include_once("directoris.inc");
include_once("arxius.inc");

function executa($comanda)
{
    if ($comanda) {
        escriure($comanda);
        $arr = explode(' ', trim($comanda));
        if ($arr[0] == "mkdir") {
            crea_directoris($comanda);
        } else if ($arr[0] == "vim") {
            if (empty($arr[1])) {
                escriure("No file name expected");
            } else {
                $content = "";
                if (empty($arr[2])) {
                    crea_modifica_fitxer($arr[1], $content);
                } else {
                    for ($i = 2; $i <= sizeof($arr); $i++) {
                        $content = $content . $arr[$i] . " ";
                    }
                    crea_modifica_fitxer($arr[1], $content);
                }

            }

        } else if ($arr[0] == "rm") {
            if ($arr[1] == "-d") {
                esborra_directoris($arr[2]);
            } else {
                esborra_fitxer($comanda);
            }
        } else if ($arr[0] == "clear") {
            buidar_fitxer();
        } else if ($arr[0] == "mv") {
            if ($arr[1] == "-d") {
                if (empty($arr[2])) {
                    escriure("Check the syntax ( mv -d 'directory' 'new location' )");
                }
                if (empty($arr[3])) {
                    escriure("Check the syntax ( mv -d 'directory' 'new location' )");
                } else {
                    move_directory($arr[2], $arr[3]);
                }
            }
        } else if ($arr[0] == "ls") {
            if (empty($arr[1])) {
                ls();
            } else {
                ls_other($arr[1]);
            }
        } else if ($arr[0] == "cat") {
            if (file_exists("dirs_and_files/" . $arr[1])) {
                cat_fitcher("dirs_and_files/" . $arr[1]);
            }
        }else if($arr[0]=="cp"){
            if ($arr[1] == "-d") {
                if (empty($arr[2]) || empty($arr[3])) {
                    escriure("Check the syntax ( cp -d 'directory' 'new location' )");
                }else{
                    copia_directori($arr[2],$arr[3]);
                }
            }
        }
        
        
        else {
            escriure("unknown command");
        }
    }
}

function llegirFitxer()
{

    $file = fopen("text_consola.txt", "r") OR die("Cannot Open this file");
    $filesize = filesize("text_consola.txt");
    if ($filesize > 0) {
        $text = str_replace(PHP_EOL, "</br>", fread($file, filesize("text_consola.txt")));
        echo "<p style='color: chartreuse'>" . $text . "</p>";
    } else {
        echo " ";
    }


    fclose($file);
}

function buidar_fitxer()
{


    borrar_consola("text_consola.txt", "");

}

function borrar_consola($name)
{
    fopen($name, "w+");

    $file = fopen($name, "a") OR die("Cannot Open this file");

    fclose($file);

}


?>