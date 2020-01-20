<?php
function presentation($nom, $classe, $age) {                                    // Création d'une fonction qui appelle les variables nom, classe & age
  return echo("$nom est un élève de la classe de $classe, agée de $age ans.");  // Retourne la phrase
}
presentation("Thibault", "BTSSN1", "18")                                        // Appel de la fonction avec les variables
?>
