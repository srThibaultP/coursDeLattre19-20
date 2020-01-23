<?php
$ip1 = $_POST['ip1'];
$ip2 = $_POST['ip2'];
$ip3 = $_POST['ip3'];
$ip4 = $_POST['ip4'];

$ma1 = $_POST['ma1'];
$ma2 = $_POST['ma2'];
$ma3 = $_POST['ma3'];
$ma4 = $_POST['ma4'];
 ?>


<!DOCTYPE html>
<html>
  <head>
    <title>PHP-3 les formulaires</title>
  </head>
  <body>
    <a href="./indexhtml"><img src="/img/LogoSN.png" width="200" height="100" align="right"/></a>
    <h1 align="middle">TP5 : PHP-3 les formulaires</h1>
    <h2>PECH Thibault</h2>
    <p><?php
          $d = date("d/m/y ");
          $h = date("H:i");
          print("Le $d à $h");
        ?>
    </p>

    <p><?php echo "Votre adresse IP est $ip1.$ip2.$ip3.$ip4";?></p>
    <p><?php echo "Votre masque de sous réseau est $ma1.$ma2.$ma3.$ma4";?></p>
  </body>
</html>
