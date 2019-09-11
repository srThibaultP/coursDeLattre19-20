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
    note = 15
    if note<5:
        print("Jojo vous êtes lamentable!!")
    elif note>=5 and note<10:
        print("En dessous de la moyenne Jojo!!")
    elif note>=10 and note<15:
        print("En progrès Jojo!!")
    elif note>=15 and note<20:
        print("Bravo Jojo!!")
    elif note == 20:
        print("Jojo le Luma c'est le plus fort!!")
    else:
        print("error")
    pass

if __name__ == '__main__':
    main()
