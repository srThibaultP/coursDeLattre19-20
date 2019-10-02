from turtle import *

def triangle(a):
        right(60)
        forward(a)
        left(120)
        forward(a)
        left(120)
        forward(a*2)
        right(120)

def main():
    b = int(input("Nombre de triangle (10 max) : "))
    a = int(input("Longueur du triangle : "))
    for i in range(b):
        triangle(a)
    pass

if __name__ == '__main__':
    main()
