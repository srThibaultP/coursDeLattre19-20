<?php
$an = $_GET['an'];
if(isset($an)) {
  if(is_numeric($an)) {
    $an = (int)$an;
    if(strlen($an)>4) {
      echo "$an n'est pas une année";
    }
    else {
      echo "C'est l'année $an";
    }
  }
  else {
    echo "$an n'est pas une année";
  }
}
else {
  echo "Veuillez insérer une année.";
}
 ?>
