from tkinter import *
fen = Tk()
cadre = Frame(fen, width =200, height =150, bg="yellow")
chaine = Label(fen)


def pointeur(event):

    chaine.configure(text = "Clic détecté en X =" + str(event.x) + ", Y =" + str(event.y))

def main():
    cadre.bind("<Button-1>", pointeur)
    cadre.pack()
    chaine.pack()
    fen.mainloop()

if __name__ == '__main__':
    main()
