<!DOCTYPE html>
<html lang="fr" dir="ltr">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <meta name="description" content="Liste des TP">
  <title>Index</title>
  <link rel="stylesheet" href="style.css">
</head>

<body>
  <header>
    <h1>Historique des TP</h1>
  </header>

  <nav>
    <h3 class="navTitle">Liste des TP</h3>
    <a href="#TP1"><p>TP1 - Apache</p></a>
    <a href="#TP2"><p>TP2 - HTML</p></a>
    <a href="#TP3"><p>TP3 - CSS</p></a>
    <a href="#TP4"><p>TP4 - PHP</p></a>
  </nav>

  <section>
    <h2><a href="http://localhost" id="TP1" class="nomTP" title="Le 10 octobre 2019">TP1</a></h2>
    <h3>Création du serveur Apache</h3>

    <h2><a href="TP2" id="TP2" class="nomTP" title="Le 7 novembre 2019">TP2</a></h2>
    <h3>Initiation au HTML</h3>
    <ul>
      <li><a href="TP2/exe1.html">Emploi du temps</a></li>
      <li><a href="TP2/exe2.html">Curriculum vitæ</a></li>
    </ul>

    <h2><a href="TP3" id="TP3" class="nomTP" title="Le 14 novembre 2019">TP3</a></h2>
    <h3>Initiation au CSS</h3>
    <ul>
      <li><a href="TP3/index.html">Page d'accueil</a></li>
      <li><a href="TP3/cvcss.html">Ajout du CSS dans le CV</a></li>
    </ul>

    <h2><a href="TP4" id="TP4" class="nomTP" title="Le 19 décembre 2019">TP4</a></h2>
    <h3>Initiation au PHP</h3>
    <ul>
      <li><a href="TP4/rappel.html">Rappels HTML</a></li>
      <li><a href="TP4/index.php">Page PHP</a></li>
      <li><a href="TP4/presentation.php">Présentation</a></li>
      <li><a href="TP4/calcul.php">Calcul</a></li>
      <li><a href="TP4/bissextile.php">Bissextile</a></li>
    </ul>
  </section>
  <footer>
    <p>PECH Thibault BTSSN1 - <?php
          $d = date("l d F Y");
          $h = date("H:i:s");
          print("$d $h");
        ?></p>
  </footer>
</body>

</html>
