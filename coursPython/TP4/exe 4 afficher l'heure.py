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
    import time # importation du module time
    quitter = 'n' # initialisation de la réponse
    while quitter != 'o' :
        # ce bloc est exécuté tant que la condition (quitter != 'o') est vraie
        print("Heure courante",time.strftime('%H:%M:%S'))
        quitter = input("Voulez‐vous quitter le programme (o/n) ?")
        # on sort de la boucle
print("A bientôt")
pass

if __name__ == '__main__':
    main()
