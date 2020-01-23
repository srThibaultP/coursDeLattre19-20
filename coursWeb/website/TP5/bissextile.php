<?php
$annee = $_GET["annee"];
if(isset($annee)) {
  if(is_numeric($annee)) {
    $annee = (int)$annee;
    if($annee>=3000) {
      echo "On calcule l'année bissextile jusqu'a l'année 3000.";
    }
    else {
      if(($annee % 4) == 0 || ($annee % 400) == 0) {
        echo "$annee est une année bissextile. <br/>";
        echo "Les années ci dessous sont également bissextiles :<br/><br/>";
        for($i = 0; 0 <= $annee ; $i++) {
          --$annee;
          if(($annee % 4) == 0 || ($annee % 400) == 0) {
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
    echo "$annee n'est pas une année.";
  }
}
else {
  echo "Veuillez insérer une année.";
}
?>
