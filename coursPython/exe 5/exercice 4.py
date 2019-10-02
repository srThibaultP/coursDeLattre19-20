def maximum(n1,n2,n3):
    if n1>n2 and n1>n3:
        print(n1)
    if n2>n1 and n2>n3:
        print(n2)
    if n3>n1 and n3>n2:
        print(n3)

def main():
    n1 = int(input("Choisir un nombre : "))
    n2 = int(input("Choisir un nombre : "))
    n3 = int(input("Choisir un nombre : "))
    maximum(n1,n2,n3)
    pass

if __name__ == '__main__':
    main()
