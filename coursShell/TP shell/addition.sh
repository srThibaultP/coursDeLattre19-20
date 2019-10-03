#!/bin/bash

resultat=$(echo "$1 + $2" | bc) #bc = commande de calcul
echo $resultat
