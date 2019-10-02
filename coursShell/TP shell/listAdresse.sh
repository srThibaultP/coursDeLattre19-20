#!/bin/bash

#tr , '\n' <'adressesRaw.txt' >adresses.txt #Mettre les adresses sur une nouvelle ligne
nbAdresse=`grep -c @<adresses.txt`
echo "Votre fichier contient" $nbAdresse "adresse(s) mail"
