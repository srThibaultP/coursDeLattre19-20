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

a = 33		# variable globale

def testPorteeVariable():
    a = 10	# variable locale à la fonction
    print(a)
    return
def main():
    print(a)
    testPorteeVariable()
    print(a)

if __name__ == '__main__':
    main()