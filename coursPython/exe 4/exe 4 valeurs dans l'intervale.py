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
    a=5
    if a>2 and a<8:
        print("a n'est pas dans l'intervalle.") #2,3,4,5,6,7 & 8 doivent trigger le if
    else:
        print("a est dans l'intervalle.")
pass

if __name__ == '__main__':
    main()
