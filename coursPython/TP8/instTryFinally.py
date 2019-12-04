import sys

def main():

    try:
        filename = sys.argv[1]  # ici on passe le fichier en paramètre ….
        fhi = open( filename, "r" )
        indx = 1

        try:
            for line in fhi.readlines():
                print (indx, ":", line)
                indx = indx + 1
        finally:
            print ("fermeture du fichier...")
            fhi.close()

    except IndexError:
        print( "pas d'argument sur la ligne de commande !")
        sys.exit(1)

    except IOError:
        print ("Le fichier", filename, "  n'existe pas !")
        sys.exit(2)

    else:
        print ("fin du traitement")

if __name__ == '__main__':
    main()
