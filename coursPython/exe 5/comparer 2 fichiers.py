def comp():
    fSource = open('fSource.txt', 'r')
    fDiff = open('fDiff.txt', 'r')

    while 1:
        lSource = fSource.readline()
        lDiff = fDiff.readline()
        if lDiff != lSource:
            print("Différence détectée :")
            print(lDiff)
            break
    fSource.close()
    fDiff.close()

def main():
    comp()
    pass

if __name__ == '__main__':
    main()
