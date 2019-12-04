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

def surfCercle(R):
    R = int(3.14*R*R)
    print(R)

def main():
    R = int(input("Surface du cercle : "))
    surfCercle(R)
    pass

if __name__ == '__main__':
    main()
