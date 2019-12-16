from tkinter import *
from random import randrange

x1, y1 = 10, 10 # coordonnÃ©es initiales
fen1 = Tk()
fen1.title("Exercice d'animation avec tkinter")
can1 = Canvas(fen1,bg='dark grey',height=300,width=300)
oval1 = can1.create_oval(x1,y1,x1+30,y1+30,width=2,fill='red')


# procÃ©dure gÃ©nÃ©rale de dÃ©placement :

def avance(gd, hb):
    global x1, y1
    x1, y1 = x1 +gd, y1 +hb
    can1.coords(oval1, x1,y1, x1+30,y1+30)


# gestionnaires d'Ã©vÃ©nements :
def depl_gauche():
    avance(-10, 0)
    print(x1,y1)
def depl_droite():
    avance(10, 0)
    print(x1,y1)
def depl_haut():
    avance(0, -10)
    print(x1,y1)
def depl_bas():
    avance(0, 10)
    print(x1,y1)
def rcouleur():
    global color
    pal=['purple','cyan','maroon','green','red','blue','orange','yellow']
    i = randrange(8)
    can1.itemconfig(oval1, fill=pal[i])
#------ Programme principal -------

def main():

    x1, y1 = 10, 10 # coordonnÃ©es initiales
    # crÃ©ation des widgets "esclaves" :

    can1.coords(oval1, x1,y1, x1+30,y1+30)
    can1.pack(side=LEFT)
    Button(fen1,text='Quitter',command=fen1.quit).pack(side=BOTTOM)
    Button(fen1,text='Gauche',command=depl_gauche).pack()
    Button(fen1,text='Droite',command=depl_droite).pack()
    Button(fen1,text='Haut',command=depl_haut).pack()
    Button(fen1,text='Bas',command=depl_bas).pack()
    Button(fen1,text='Couleur' , command=rcouleur).pack(side=BOTTOM)

    fen1.mainloop()

if __name__ == '__main__':
    main()
