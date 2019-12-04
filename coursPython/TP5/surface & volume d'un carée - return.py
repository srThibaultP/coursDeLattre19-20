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

def carreCube(cote):
    return cote*cote,cote*cote*cote


def main():
    surface,volume=carreCube(9)
    print('Surface du carré = ',surface,'metres carré' )
    print('Volume du carré = ',volume,'metres cube' )
if __name__ == '__main__':
    main()