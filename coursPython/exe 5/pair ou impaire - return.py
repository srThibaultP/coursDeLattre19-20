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

def fonctionParite(nombre):
    """ pair ou Impair """
    if (nombre % 2) == 1:
        print(nombre,' est impair')
        return
    if (nombre % 2) == 0:
        print(nombre,' est pair')
        return

def main():
    fonctionParite(33)
    fonctionParite(22)
    fonctionParite(42)

if __name__ == '__main__':

    main()