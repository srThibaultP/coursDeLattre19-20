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
        if valeur %3 ==0:
            print("impaire & multiple de 3")
        elif valeur %3 !=0:
            print("impaire & pas un multiple de 3")
    elif valeur %2 == 0:
        if valeur %3 ==0:
            print("paire & multiple de 3")
        elif valeur %3 !=0:
            print("impaire & pas un multiple de 3")
pass

if __name__ == '__main__':
    main()
