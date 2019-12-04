#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      thiba
#
# Created:     11/09/2019
# Copyright:   (c) thiba 2019
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    print("Table de multiplication par 8")
    compteur = 1 # initialisation de la variable de comptage
    while compteur <= 10 :
    # ce bloc est exécuté tant que la condition (compteur<=10) est vraie
        print(compteur,"* 8 =",compteur*8)
        compteur += 1 # incrémentation du compteur : compteur = compteur + 1
	# on sort de la boucle
    print("Eh voilà !")
pass

if __name__ == '__main__':
    main()
