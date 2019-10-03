#!/bin/bash

case $1 in
  janvier | mars | mai | juillet | août | octobre | décembre) echo "31 jours" ;;
  février) echo "28 jours" ;;
  avril | juin | septembre | novembre) echo "30 jours" ;;
  *) echo "erreur" ;;
esac
