def main():

    ValeurPositive = input("Donnez un nombre strictement positif") # L'utilisateur entre une valeur
    try:
        ValeurPositive  = float(ValeurPositive) # On tente de convertir l'année
        assert ValeurPositive > 0
    except ValueError:
	    print("Vous n'avez pas saisi un nombre.",ValeurPositive)
    except AssertionError:
	    print("La valeur  saisie est inférieure ou égale à 0  ",  ValeurPositive)
    else :
        print("Merci pour ce nombre >0 !")
if __name__ == '__main__':
    main()
