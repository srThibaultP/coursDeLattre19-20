<?php
$valeur1 = $_GET['valeur1'];
$valeur2 = $_GET['valeur2'];
$operation = $_GET['operation'];

if(isset($valeur1, $valeur2, $operation)) {
  //echo "$valeur1 $operation $valeur2";
  switch ($operation) {
    case 'addition':
    $resultat = $valeur1 + $valeur2;
    echo "$valeur1 + $valeur2 = $resultat";
      break;
    case 'soustraction':
    $resultat = $valeur1 - $valeur2;
    echo "$valeur1 - $valeur2 = $resultat";
      break;
    case 'multiplication':
    $resultat = $valeur1 * $valeur2;
    echo "$valeur1 * $valeur2 = $resultat";
      break;
    case 'division':
    $resultat = $valeur1 / $valeur2;
    echo "$valeur1 / $valeur2 = $resultat";
      break;

    default:
      echo "Opérations disponibles : addition, soustraction, multiplication et division";
      break;
  }
}
else {
  echo "Insérer des valeurs (valeur1, valeur2, operation)";
}
 ?>
