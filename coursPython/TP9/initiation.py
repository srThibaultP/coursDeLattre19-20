from tkinter import *

def main():

    fen1 = Tk()
    tex1 = Label(fen1, text='Bonjour Jojo !', fg='red')
    tex1.pack()
    bou1 = Button(fen1, text='Quitter', command = fen1.destroy)
    bou1.pack()
    fen1.mainloop()

if __name__ == '__main__':
    main()
