<?php
function presentation($nom, $classe, $age) {                                    // Création d'une fonction qui appelle les variables nom, classe & age
  return echo("$nom est un élève de la classe de $classe, agée de $age ans.");  // Retourne la phrase
}
presentation("Thibault", "BTSSN1", "18")                                        // Appel de la fonction avec les variables
?>

<!DOCTYPE html>
<html>
<head>
  <title>Fonction Presentation</title>
</head>
<body>
  <a href="../index.php"><img src="/img/back.png" width="50" height="50" align="right"/></a>
  <p>Les variables sont modifiable dans le code.</p>
</body>
</html>
