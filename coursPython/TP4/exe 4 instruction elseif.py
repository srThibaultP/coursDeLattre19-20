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
    nb = input("Entrer un nombre plus petit que 100")
    nb = float(nb)
    if nb == 100 :
        print("Ce nombre vaut 100")
    elif nb == 0 :
        print("Ce nombre est nul")
    elif nb > 0 and nb < 100:
        print("Le nombre",nb,"convient")
    else :
        print("Le nombre",nb,"est trop grand")
pass

if __name__ == '__main__':
    main()
