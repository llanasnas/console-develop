<?php
/**
 * Created by PhpStorm.
 * User: Alumne
 * Date: 19/02/2018
 * Time: 18:08
 */




?>
<html >

<head>

    <title>Console Aplication</title>
    <!-- Latest compiled and minified CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">

    <!-- Optional theme -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css" integrity="sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp" crossorigin="anonymous">
    <style>
        ::placeholder {
            color: chartreuse; !important;
            opacity: 1;
        }
    </style>
    <!-- Latest compiled and minified JavaScript -->
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>

</head>
<body>
<div style="background-color: blue;width: 100%;height: 100%;">
<div class="container-fluid col-md-4 col-md-offset-4" style="margin-top:5%;">

<form method="post" action="console.php" class="form-group">

    <br>
    <div class="pagination-centered">
        <div style="overflow-y: scroll; background-color: black">
            <?php
                include_once ("actualitza_canvis.php");
                llegirFitxer();
            ?>
        </div>
        <input type="text" name="command" class="form-control" id="exampleFormControlInput1" placeholder="root@gerard-PC~#" style=" background-color: black; color: chartreuse">
        <!--<textarea class="form-control" name="command" placeholder="root@gerard-PC~#" id="exampleFormControlTextarea1" rows="1" style=" background-color: black; color: chartreuse"></textarea>-->
    </div>
    <br>

    <div><input class="btn btn-primary center center-block"  type="submit" name="submit" value="submit"></div>
</form>
</div>
</div>
</body>
</html>
