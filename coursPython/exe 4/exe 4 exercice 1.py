#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      thiba
#
# Created:     18/09/2019
# Copyright:   (c) thiba 2019
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    valeur = input("Valeur : ")
    valeur = float(valeur)
    if valeur % 2 !=0: #detection de impaire
        while valeur == 1 :
            valeur = valeur/3
            if valeur <1 :
                print("inf à 1")
            else:
                print("ok")
        #print("impair")
pass

if __name__ == '__main__':
    main()
