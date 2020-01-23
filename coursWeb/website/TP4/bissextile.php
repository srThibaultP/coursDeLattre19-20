<?php
/* Pour qu'une année soit bissextile,
   il faut que le reste de la division de 4 ou 400 donne 0
   Source : https://www.astro.oma.be/GENERAL/INFO/fri002.html */
function bissextile($a) {
  if(($a % 4) == 0 || ($a % 400) == 0) {
    echo "$a est une année bissextile.";
  }
  else {
    echo "$a n'est pas une année bissextile.";
  }
}
bissextile("2028");
 ?>
