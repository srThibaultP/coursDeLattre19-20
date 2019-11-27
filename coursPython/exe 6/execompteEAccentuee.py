def compteCar(ch, car):
    if len(ch) == 0:
        return 0
    n = 0
    for c in ch:
        if c == car:
            n = n + 1
    return n

def compteCarDeListe(chaine, serie):
    for cLi in serie:
        nc = compteCar(chaine, cLi)
        print("Caractère", cLi, ":", nc)

if __name__ == '__main__':
    txt = "René et Célimène étaient eux-mêmes nés à Noël de l'année dernière"
    print(txt)
    compteCarDeListe(txt, "eéèêë")
