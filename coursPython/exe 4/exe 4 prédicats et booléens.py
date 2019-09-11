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
    # Test pour savoir si a est comprise dans l'intervalleallant de 2 à 8 inclus
    a = 9
    if a >= 2:
        if a <= 8:
            print("a est dans l'intervalle.")
        else:
            print("a n'est pas dans l'intervalle.")
    else:
        print("a n'est pas dans l'intervalle.")
    pass

if __name__ == '__main__':
    main()
