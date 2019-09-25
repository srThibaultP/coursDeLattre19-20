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

a = 33		# variable globale pour tout le programme

def testPorteeVariable():
    global b
    b=10 	# variable globale à la fonction
    print(b)
    c=66
    print(b)
    a=44
    print(a)
    print(b)
    return

def main():
    print(a)
    testPorteeVariable()
    print(a)
    print(b)

if __name__ == '__main__':
    main()