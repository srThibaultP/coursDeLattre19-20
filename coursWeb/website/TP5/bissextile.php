<?php
$annee = $_GET["annee"];                                                        // Récupération de la valeur
if(isset($annee)) {                                                             // Détecte si l'utilisateur à écris une valeur
  if(is_numeric($annee)) {                                                      // Détecte si l'utilisateur à écris des chiffres uniquement
    $annee = (int)$annee;                                                       // Convertis la variable en entier
    if($annee>=3000) {                                                          // Année bissextile max (ici 3000)
      echo "On calcule l'année bissextile jusqu'a l'année 3000.";
    }
    else {
      if(($annee % 4) == 0 || ($annee % 400) == 0) {                            // Calcul de l'année bissextile (cf TP4/bissextile.php)
        echo "$annee est une année bissextile. <br/>";
        echo "Les années ci dessous sont également bissextiles :<br/><br/>";
        for($i = 0; 0 <= $annee ; $i++) {                                       // Compteur pour aller jusqu'a l'an zero
          --$annee;
          if(($annee % 4) == 0 || ($annee % 400) == 0) {                        // Même calcul pour aller jusqu'a l'an zero
            echo "$annee est une année bissextile. <br/>";
          }
        }
      }
      else {
        echo "$annee n'est pas une année bissextile.<br/>";
        echo "Les années ci dessous sont bissextiles :<br/><br/>";
        for($i = 0; 0 <= $annee ; $i++) {
          --$annee;
          if(($annee % 4) == 0 || ($annee % 400) == 0) {
            echo "$annee est une année bissextile. <br/>";
          }
        }
      }
    }
  }
  else {
    echo "$annee n'est pas une année.";                                         // Si l'utilisateur n'entre pas de nombre
  }
}
else {
  echo "Veuillez insérer une année.";                                           // Message de base
}
?>
