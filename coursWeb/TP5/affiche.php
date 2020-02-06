<?php
$an = $_GET['an'];                                                              // Récupération de la valeur
if(isset($an)) {                                                                // Détecte si l'utilisateur à écris une valeur
  if(is_numeric($an)) {                                                         // Détecte si l'utilisateur à écris des chiffres uniquement
    $an = (int)$an;                                                             // Convertis la variable en entier
    if(strlen($an)>4) {                                                         // Détecte le nombre de caractères dans la variable (ici il en faut 4)
      echo "$an n'est pas une année";                                           // Trop de chiffres
    }
    else {
      echo "C'est l'année $an";                                                 // Résultat
    }
  }
  else {
    echo "$an n'est pas une année";                                             // Texte
  }
}
else {
  echo "Veuillez insérer une année. (?an)";                                     // Message de base
}
 ?>

 <!DOCTYPE html>
 <html>
 <head>
   <title>Affiche PHP</title>
 </head>
 <body>
   <a href="../index.php"><img src="/img/back.png" width="50" height="50" align="right"/></a>
 </body>
 </html>
