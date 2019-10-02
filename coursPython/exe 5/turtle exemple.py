from turtle import *

def dessine_carre () :
    for i in range (4) :
        forward (50)
        right (90)
        left (5)
        forward (5)
        speed (5)

def main():
    for i in range (72) :
        dessine_carre()

if __name__ == '__main__':
    main()
