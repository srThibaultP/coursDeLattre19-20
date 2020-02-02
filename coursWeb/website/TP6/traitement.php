<?php
$nom = $_POST['nom'];                                                           //Récupération du nom (Partie 1)

$AdresseIP1 = $_POST['ip1'];                                                    //Récupération de l'adresse IP (en 4 partie)
$AdresseIP2 = $_POST['ip2'];
$AdresseIP3 = $_POST['ip3'];
$AdresseIP4 = $_POST['ip4'];

$MasqueDSR1 = $_POST['ma1'];                                                    //Récupération du masque (en 4 partie)
$MasqueDSR2 = $_POST['ma2'];
$MasqueDSR3 = $_POST['ma3'];
$MasqueDSR4 = $_POST['ma4'];

$ClassA1 = 0;                                                                   //Intervale de la classe A
$ClassA2 = 2130706431;                                                          //Valeurs récupérée de la fonction ip2long()
$ClassB1 = 2147483648;                                                          //Intervale de la classe B
$ClassB2 = 3221225471;
$ClassC1 = 3221225472;                                                          //Intervale de la classe C
$ClassC2 = 3758096383;
$ClassD1 = 3758096384;                                                          //Intervale de la classe D
$ClassD2 = 4026531839;
$ClassE1 = 4026531840;                                                          //Intervale de la classe E
$ClassE2 = 4294967295;

if (isset($AdresseIP1) && isset($AdresseIP2) && isset($AdresseIP3) && isset($AdresseIP4) && isset($MasqueDSR1) && isset($MasqueDSR2) && isset($MasqueDSR3) && isset($MasqueDSR4)) { //Vérifier si on récupère des valeurs
  if (is_numeric($AdresseIP1) && is_numeric($AdresseIP2) && is_numeric($AdresseIP3) && is_numeric($AdresseIP4) && is_numeric($MasqueDSR1) && is_numeric($MasqueDSR2) && is_numeric($MasqueDSR3) && is_numeric($MasqueDSR4)) {  //Vérifier si les variables sont des chiffres
    $AdresseIP = "$AdresseIP1.$AdresseIP2.$AdresseIP3.$AdresseIP4";             //IP complète
    $MasqueDSR = "$MasqueDSR1.$MasqueDSR2.$MasqueDSR3.$MasqueDSR4";             //Masque complet

    $EntierAdresseIP = ip2long($AdresseIP);                                     //Conversion de l'IP en entier (X*255^3+X*255^2+X*255^1+X*255^0)
    $BinaryAdresseIP = str_pad(decbin($EntierAdresseIP), 32, 0, STR_PAD_LEFT);  //Conversion de l'IP "entier" en binaire. Ajout des 0 à gauche de l'octet (11 => 0011)

    $ReverseMasqueDSR = long2ip(~ip2long($MasqueDSR));                          //Conversion de l'IP en entier puis inversion de l'entier puis conversion en IP (Inversion du Masque)
    $BinaryMasqueDSR = str_pad(decbin(ip2long($MasqueDSR)), 32, 0, STR_PAD_LEFT); //Conversion du masque en entier puis passage en binaire. Ajout des 0 à gauche de l'octet (11 => 0011)

    $EntierAdresseReseau = bindec(str_pad($BinaryAdresseIP & $BinaryMasqueDSR, 32, 0, STR_PAD_LEFT)); //"ET logique" entre le masque et l'adresse IP, avec l'ajout des 0 à gauche de l'octet. Conversion binaire vers entier
    $DefaultAdresseReseau = long2ip($EntierAdresseReseau);                      //Conversion entier vers Adresse réseau
    $FirstAdresseReseau = long2ip($EntierAdresseReseau+1);                      //Conversion entier vers première adresse réseau (+1 car sinon c'est l'adresse réseau)
    $LastAdresseReseau = long2ip(($EntierAdresseIP | ip2long($ReverseMasqueDSR)) - 1); // Conversion entier vers dernière adresse réseau ("OU logique" entre l'adresse IP et le masque de sous réseau inversée (-1 car sinon on tombe sur l'adresse de broadcast))

    if($EntierAdresseIP>=$ClassA1 && $EntierAdresseIP<=$ClassA2) {              //Détection de la classe réseau A
      $Class = "A";
    }
    else if($EntierAdresseIP>=$ClassB1 && $EntierAdresseIP<=$ClassB2) {         //Détection de la classe réseau B
      $Class = "B";
    }
    else if($EntierAdresseIP>=$ClassC1 && $EntierAdresseIP<=$ClassC2) {         //Détection de la classe réseau C
      $Class = "C";
    }
    else if($EntierAdresseIP>=$ClassD1 && $EntierAdresseIP<=$ClassD2) {         //Détection de la classe réseau D
      $Class = "D";
    }
    else if($EntierAdresseIP>=$ClassE1 && $EntierAdresseIP<=$ClassE2) {         //Détection de la classe réseau E
      $Class = "E";
    }
    else {                                                                      //Au cas ou l'utilisateur rentre des valeurs éronées
      $Class = "Erreur";
    }
  }
}
?>


<!DOCTYPE html>
<html>
<head>
  <title>PHP-3 les formulaires</title>
</head>
<body>
  <a href="../index.php"><img src="/img/LogoSN.png" width="200" height="100" align="right"/></a>
  <h1 align="middle">TP5 : PHP-3 les formulaires</h1>
  <h2>PECH Thibault</h2>
  <p> <?php                                                                     //Récupération de la date
  $d = date("d/m/y ");
  $h = date("H:i");
  echo "Le $d à $h";
  ?> </p>
  <p> <?php if (isset($nom)) {                                                  //Vérifier si on récupère le nom
    echo "Bonjour $nom !";
  } ?> </p>
  <?php if (isset($AdresseIP) && isset($MasqueDSR) && isset($DefaultAdresseReseau) && isset($FirstAdresseReseau) && isset($LastAdresseReseau) && isset($Class)) { //Vérifier si il n'y a pas eu de problèmes lors des calculs
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
    <th>$Class</th>
    </tr>
    ";}?>
    <a href="../TP6/index.php"><img src="/img/back.png" width="50" height="50" align="right"/></a>
  </body>
  </html>
