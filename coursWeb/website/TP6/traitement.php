<?php
$nom = $_POST['nom'];

$ip1 = $_POST['ip1'];
$ip2 = $_POST['ip2'];
$ip3 = $_POST['ip3'];
$ip4 = $_POST['ip4'];

$ma1 = $_POST['ma1'];
$ma2 = $_POST['ma2'];
$ma3 = $_POST['ma3'];
$ma4 = $_POST['ma4'];

if (isset($ip1) && isset($ip2) && isset($ip3) && isset($ip4) && isset($ma1) && isset($ma2) && isset($ma3) && isset($ma4)) {
  if (is_numeric($ip1) && isset($ip2) && isset($ip3) && isset($ip4) && isset($ma1) && isset($ma2) && isset($ma3) && isset($ma4)) {
    $ip = "$ip1.$ip2.$ip3.$ip4";
    $ma = "$ma1.$ma2.$ma3.$ma4";

    $Bip = decbin(ip2long($ip));                                                //Conversion de l'IP en entier (X*255^3+X*255^2+X*255^1+X*255^0) puis en binaire
    $Bma = decbin(ip2long($ma));                                                //Idem
    $Bre = $Bip & $Bma                                                          //ET logique entre l'IP et le masque
    $Ere = bindec($Bre);                                                        //Conversion binaire vers entier
    $re = long2ip($Ere);                                                        //Conversion entier vers IP
    $Fre = long2ip($Ere+1);
    $di = $Bre
    $Lre = long2ip($Ere-1);

  }
}
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
    <p> <?php
    $d = date("d/m/y ");
    $h = date("H:i");
    print("Le $d à $h");
    ?> </p>
    <p> <?php if (isset($nom)) {
      echo "Bonjour $nom !";
    } ?> </p>
    <?php if (isset($ip) && isset($ma) && isset($re)) {
      echo "
    <table border=black>
      <tr>
        <th>Adresse IP</th>
        <th>Masque de sous réseau</th>
        <th>Adresse du réseau</th>
        <th>Première adresse du réseau</th>
        <th>Dernière adresse du réseau</th>
        <th>Classe de l'adresse</th>
      </tr>
      <tr>
        <th>$ip</th>
        <th>$ma</th>
        <th>$re</th>
        <th>$Fre</th>
        <th>$Lre</th>
        <th></th>
      </tr>
      ";}?>
    </body>
</html>
