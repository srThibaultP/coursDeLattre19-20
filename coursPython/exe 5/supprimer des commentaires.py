def filtreCommentaire():
    fsource=open("fComm.txt", "r")
    fdest=open("fNv.txt", "w")
    while 1:
        modif=fsource.readlines()
        print(modif)
        if modif == '':
            print("uno")
            print(modif)
            break
        if modif[0] != "#":
            print("dos")
            fdest.write(modif)
            print(modif)
    fsource.close()
    fdest.close()


def main():
    filtreCommentaire()
    pass

if __name__ == '__main__':
    main()
