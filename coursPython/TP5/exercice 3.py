#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      thiba
#
# Created:     25/09/2019
# Copyright:   (c) thiba 2019
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def volBoite(x1,x2,x3):
    x1 = int(x1*x2*x3)
    print(x1)

def main():
    x1 = int(input("Longueur : "))
    x2 = int(input("Largeur : "))
    x3 = int(input("Hauteur : "))
    volBoite(x1,x2,x3)
    pass

if __name__ == '__main__':
    main()
