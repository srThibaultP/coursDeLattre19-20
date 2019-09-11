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
    unNombre = 0
    while unNombre < 50 :
        unNombre += 1
        if unNombre % 2 != 0:
            continue
    print("unNombre =",unNombre)
    pass

if __name__ == '__main__':
    main()
