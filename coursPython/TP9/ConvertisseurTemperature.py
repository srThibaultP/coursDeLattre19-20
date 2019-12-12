from tkinter import *

def conversion(arg=None):
    valeur = entree.get()
    labelResultatconversion.config(text=valeur)

def tempFahrenheit(cel):
    return(cel*9/5+32)

def tempCelsius(kel):
    return(kel-491.67)

def tempKelvin(fah):
    return((fah+459.67)*5/9)

def tempKelvin(cel):
    return(cel+491.67)

def tempFahrenheit(kel):
    return(kel*9/5-459.67)

def selection(evt):
    value = str((listTemp.get(ACTIVE)))
    print(value)

fen1 = Tk()
fen1.title("Convertisseur Température °C/°F/°K")
fen1.geometry("400x200+700+200")

labelEntree = Label(fen1, text="Valeur temp", fg="blue")
labelEntree.grid(row=0, column=0, padx=5, pady=5)

entree = Entry(fen1,)
entree.bind("<Return>", conversion)
entree.grid(row=0, column=1, padx=5, pady=5)

listeComplete = ["°C->°F", "°C->°K", "°K->°F", "°K->°C", "°F->°K"]
listTemp = Listbox(fen1, height=5, bg="lightblue", fg="yellow")
listTemp.bind('<<ListboxSelect>>', selection)
listTemp.grid(row=0, column=2, padx=5, pady=5)

listTemp.select_set(0)

labelResultatconversion = Label(fen1, width=30, height=4, bg="lightgreen", fg="blue")
labelResultatconversion.grid(row=1, column=1)

boutonQuitter = Button(fen1, text="Quitter", bg="purple", command = fen1.destroy)
boutonQuitter.grid(row=1, column=2, sticky=W, padx=50, pady=5)

for i in listeComplete:
    listTemp.insert(END,i)

listTemp.mainloop()
