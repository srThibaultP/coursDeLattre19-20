#!/bin/bash

resultat=$(echo "$1 + $2" | bc) #bc = commande de calcul, |(pipe) passe d'une chaine de caractère à un argument
echo $resultat
