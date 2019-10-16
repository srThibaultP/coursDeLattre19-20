def filtreCommentaire(fichierAfiltrer, fichierFiltre):
    fsource = open(fichierAfiltrer, 'r')
    fdest = open(fichierFiltre, 'a')
    while 1:
        modif = fsource.readline()
        if modif == '':
            break
        if modif [0] != "#":
            fdest.write(modif)
    fsource.close()
    fdest.close()


def main():
    filtreCommentaire('fComm.txt', 'fNv.txt')
    pass

if __name__ == '__main__':
    main()
