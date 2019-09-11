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
    while True : # l’expression est toujours vraie
        print("Heure courante",time.strftime('%H:%M:%S'))
        quitter = input("Voulez‐vous quitter le programme (o/n) ?")
        if quitter == 'o' :
            break
    # on sort de la boucle
    print("A bientôt")
    pass

if __name__ == '__main__':
    main()
