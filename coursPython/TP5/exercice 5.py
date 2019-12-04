from turtle import *

def triangle(a):
        right(60)
        forward(a)
        left(120)
        forward(a)
        left(120)
        forward(a)

def main():
    for i in range(1):
        a = int(input("Longueur du triangle : "))
        triangle(a)
    pass

if __name__ == '__main__':
    main()
