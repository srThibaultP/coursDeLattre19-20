def main():
    pass

def recherche(phrase):
    resultat = int(phrase.count(' '))
    if resultat == 0:
        return 0
    else:
        return resultat + 1

if __name__ == '__main__':
    main()
    print(recherche("yes i am!"))
