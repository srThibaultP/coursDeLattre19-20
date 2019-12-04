def main():

    ValeurPositive = input("Donnez un nombre strictement positif") # L'utilisateur entre une valeur
    try:
    	ValeurPositive  = int(ValeurPositive) # On tente de convertir l'année
    	if ValeurPositive <=0:
            raise ValueError("l'année saisie est négative ou nulle")
    except ValueError:
        print("La valeur saisie est invalide (la valeur n'est pas strictement positive).")
    else :
        print("Merci pour ce nombre >0 !")


if __name__ == '__main__':
    main()
