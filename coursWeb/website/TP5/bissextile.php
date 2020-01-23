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
      }
      else {
        echo"$annee n'est pas une année bissextile. <br/> Par contre, les années ci dessous sont bissextiles :<br/><br/>";
      }

      if($annee >= 0 && $annee <= 3000) {
        for(0 <= $annee) {
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
