<?php
$valeur1 = $_GET['valeur1'];
$valeur2 = $_GET['valeur2'];
$operation = $_GET['operation'];

//echo gettype($valeur1);
//echo gettype($valeur2);

if(isset($valeur1, $valeur2, $operation) && is_numeric($valeur1) && is_numeric($valeur2)) { // Vérifie que $valeur1 & $valeur2 sont des nombres & que les 3 variable ne sont pas vide
  //echo "$valeur1 $operation $valeur2";
  switch ($operation) {                                                         // Liste des opérations
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
    echo "Opérateurs disponibles : addition, soustraction, multiplication et division"; // Message si l'utilisateur n'écris pas le bon opérateur
    break;
  }
}
else {
  echo "Insérer des valeurs (valeur1, valeur2, operation)<br/>";                // Message de base lors de la connexion
  echo "Opérateurs disponibles : addition, soustraction, multiplication et division";
}
?>
