def main():
    Fichier = open('TestFichier','a')
    Fichier.write('Bonjour, Jojo !')
    Fichier.write("Quel beau temps, pour les lumas !")
    Fichier.close
    fic = open("Fichiertexte", "w")
    fic.write("Ceci est la ligne un\nVoici la ligne deux\n")
    fic.write("Voici la ligne trois\nVoici la ligne quatre\n")
    fic.close()
    ouvFichier = open('TestFichier', 'r')
    t = ouvFichier.read(10)
    print(t)
    ouvFichier.close()

if __name__ == '__main__':
    main()