<?php
$an = $_GET['an'];
//echo gettype($an), "\n";
//echo "$an", "\n";
if(is_numeric($an)) {
  echo "C'est l'année $an";
}
else {
  echo "$an n'est pas une année";
}
/*
if(isset($an)) {
    echo "Année : $an";
}*/
 ?>
