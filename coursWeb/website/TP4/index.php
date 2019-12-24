<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>TP3</title>
  </head>
  <body>
    <a href="../index.php"><img src="../img/LogoSN.png" width="200" height="100" align="right"/></a><!--Ajout du logo-->
    <p><a href="/TP4/index.php">                                               <!--Création du lien clicable-->
      <?php                                                                     //Ouverture de la balise PHP dans le code HTML
        echo "Chemin absolue de la page : /TP4/index.php";                      //Affichage de texte
      ?>
    </a></p>
    <?php
      $date = date("d-m-Y");
      $heure = date("H:i");
      print("Bonjour, nous sommes le $date et il est $heure");
    ?>
  </body>
</html>
