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
    devise = input("Indiquer vers quelle devise vous voulez convertir. Note : E = Euro et D = Dollar ")
    if devise == "E": #de dolars en euro
        money = input("Montant en dollars ")
        money = float(money)
        money = money * 0.78
        print(money)
    elif devise == "D": #de euro en dollars
        money = input("Montant en euro ")
        money = float(money)
        money = money * 1.78
        print(money)
    else:
        print("error")
    pass

if __name__ == '__main__':
    main()
