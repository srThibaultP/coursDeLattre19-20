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

def main():
    a = input("Chiffre 1: ")
    b = input("Chiffre 2: ")
    if a>b:
        print("a est supérieur à b")
    elif a<b:
        print("a est inférieur à b")
    else:
        print(erreur)
    pass

if __name__ == '__main__':
    main()
