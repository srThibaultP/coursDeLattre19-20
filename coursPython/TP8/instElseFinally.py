try:
    chaine = input('Entrer un nombre : ')
    nb = float(chaine)
    inverseValeur = 1.0/nb
except ValueError:
    #ce bloc est exécuté si une exception de type ValueError est levée dans le bloc try
    print(chaine,"n'est pas un nombre !")
except ZeroDivisionError:
    #ce bloc est exécuté si une exception de type ZeroDivisionError est levée dans le bloc try
    print("Division par zéro !")
else:
    #on arrive ici si aucune exception n'est levée dans le bloc try
    print("L'inverse de",nb,"est : ",inverseValeur)
