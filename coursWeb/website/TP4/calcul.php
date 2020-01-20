<?php
function calcul($x, $o, $y) {
  if ($o == "+") {                                                              // Test des opérateurs logiques
    echo "$x $o $y = " .($x + $y). "<br>";
  }
  elseif ($o == "-") {
    echo "$x $o $y = " .($x - $y). "<br>";
  }
  elseif ($o == "*") {
    echo "$x $o $y = " .($x * $y). "<br>";
  }
  elseif ($o == "/") {
    echo "$x $o $y = " .($x / $y). "<br>";
  }
  else {
    echo "$o n'est pas reconnu en tant qu'opérateur";                           // Au cas ou l'utilisateur ne met pas d'opérateur logique
  }
}
calcul("14", "*", "45");
?>
