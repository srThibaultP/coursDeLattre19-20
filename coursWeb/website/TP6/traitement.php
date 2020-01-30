<?php
$nom = $_POST['nom'];

$AdresseIP1 = $_POST['ip1'];
$AdresseIP2 = $_POST['ip2'];
$AdresseIP3 = $_POST['ip3'];
$AdresseIP4 = $_POST['ip4'];

$MasqueDSR1 = $_POST['ma1'];
$MasqueDSR2 = $_POST['ma2'];
$MasqueDSR3 = $_POST['ma3'];
$MasqueDSR4 = $_POST['ma4'];

if (isset($AdresseIP1) && isset($AdresseIP2) && isset($AdresseIP3) && isset($AdresseIP4) && isset($MasqueDSR1) && isset($MasqueDSR2) && isset($MasqueDSR3) && isset($MasqueDSR4)) {
  if (is_numeric($AdresseIP1) && isset($AdresseIP2) && isset($AdresseIP3) && isset($AdresseIP4) && isset($MasqueDSR1) && isset($MasqueDSR2) && isset($MasqueDSR3) && isset($MasqueDSR4)) {
    $AdresseIP = "$AdresseIP1.$AdresseIP2.$AdresseIP3.$AdresseIP4";
    $MasqueDSR = "$MasqueDSR1.$MasqueDSR2.$MasqueDSR3.$MasqueDSR4";

    $BinaryIP = str_pad(decbin(ip2long($AdresseIP)), 32, 0, STR_PAD_LEFT);                                    //Conversion de l'IP en entier (X*255^3+X*255^2+X*255^1+X*255^0) puis en binaire
    $BinaryMasqueDSR = str_pad(decbin(ip2long($MasqueDSR)), 32, 0, STR_PAD_LEFT);                             //Conversion entier vers binaire
    $BinaryAdresseReseau = str_pad($BinaryIP & $BinaryMasqueDSR, 32, 0, STR_PAD_LEFT);                        //ET logique entre l'IP et le masque = Adresse réseau (binaire)
    $ReverseMasqueDSR = ~ip2long($MasqueDSR);
    $EntierAdresseReseau = bindec($BinaryAdresseReseau);                        //Conversion binaire vers entier
    $DefaultAdresseReseau = long2ip($EntierAdresseReseau);                      //Conversion entier vers IP
    $FirstAdresseReseau = long2ip($EntierAdresseReseau+1);
    $LastAdresseReseau = "MDRSAMARCHEPAS-1";
    echo "$ReverseMasqueDSR";
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
    <?php if (isset($AdresseIP) && isset($MasqueDSR) && isset($DefaultAdresseReseau)) {
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
        <th>$AdresseIP</th>
        <th>$MasqueDSR</th>
        <th>$DefaultAdresseReseau</th>
        <th>$FirstAdresseReseau</th>
        <th>$LastAdresseReseau</th>
        <th></th>
      </tr>
      ";}?>
    </body>
</html>
