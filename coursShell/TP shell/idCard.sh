#!/bin/bash

echo "Insérez votre nom et prénom"
read nomPrenom
echo "Insérez votre année de naissance"
read birth
echo "Insérez votre adresse"
read adresse
echo "Insérez votre numéro de téléphone"
read tel

anneeActuel=`date +%Y`
anneeID=`$birth | cut -d'/' -f3`
age=$(echo "$anneeID - $anneeActuel" | bc)

clear
echo "Votre carte d'identité :"
echo "Nom, Prénom :" $nomPrenom
echo "Né(e) le :" $birth
echo "Age :" $age
echo "Adresse :" $adresse
echo "Numéro de téléphone :" $tel
