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

def carre(cote):
    return cote*cote

def main():
    surface=carre(9)
    print('surface du carré = ',surface,'metres carré' )
if __name__ == '__main__':
    main()