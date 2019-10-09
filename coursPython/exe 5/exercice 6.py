from turtle import *

def ligne():
    forward(100)

def triangle() :

    for i in range (1):
            right(120)
            forward(50)


def main():
    for l in range (3): #nb de triangle
        for i in range (3) :
            triangle()
        for j in range (1) :
            ligne()


    pass

if __name__ == '__main__':
    main()
