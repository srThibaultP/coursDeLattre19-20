from tkinter import *                                                           # Ajout de la librairie tkinter

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

def selection(event):                                                           # Détection du choix de conversion avec event (ici le choix d'une conversion)
    ligne = listTemp.curselection()                                             # Détection de la selection dans la liste (aka chiffre)
    ligneTxt = listTemp.get(ligne)                                              # Récupération du texte (aka conversion dans la liste)
    labelResultatconversion.config(text=ligneTxt)                               # Affichage du choix dans le résultat

fen1 = Tk()
fen1.title("Convertisseur Température °C/°F/°K")
fen1.geometry("400x200+700+200")

labelEntree = Label(fen1, text="Valeur temp", fg="blue")
labelEntree.grid(row=0, column=0, padx=5, pady=5)

entree = Entry(fen1,)
entree.bind("<Return>", conversion)
entree.grid(row=0, column=1, padx=5, pady=5)

listTemp = Listbox(fen1, height=5, bg="lightblue", fg="yellow")
for listeComplete in ["°C->°F", "°C->°K", "°K->°F", "°K->°C", "°F->°K"]:        # Liste des conversions
    listTemp.insert(END, listeComplete)
listTemp.grid(row=0, column=2, padx=5, pady=5)
listTemp.bind("<<ListboxSelect>>", selection)                                   # Appelle la définition selection() lors d'un choix
listTemp.select_set(0)

labelResultatconversion = Label(fen1, width=30, height=4, text="°C->°F", bg="lightgreen", fg="blue")
labelResultatconversion.grid(row=1, column=1)

boutonQuitter = Button(fen1, text="Quitter", bg="purple", command = fen1.destroy)
boutonQuitter.grid(row=1, column=2, sticky=W, padx=50, pady=5)

mainloop()
