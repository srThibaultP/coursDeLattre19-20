from tkinter import *                                                           # Ajout de la librairie tkinter

ligne = (0,)                                                                    # Fix auto set

def conversion(arg=None):                                                       # Convertisseur
    try:
        valeur = float(entree.get())                                            # Récupération de la température choisi
    except ValueError:
        return sendResult("Impossible de convertir du texte")
    try:                                                                        # Détections d'erreurs
        if ligne == (0,):                                                       # sendResult: envoie le resultat de la conversion
            return sendResult(str(round(tempCelVERSFahrenheit(valeur), 2)) + "°F")# *str: Convertis le float en string (texte en fr)
        elif ligne == (1,):                                                     # Permet aussi d'ajouter du texte (°X)*
            return sendResult(str(round(tempCelVERSKelvin(valeur), 2)) + "°K")  # round: arrondi (ici 2)
        elif ligne == (2,):                                                     # tempXVERSY: appel de la définition choisi
            return sendResult(str(round(tempKelVERSFahrenheit(valeur), 2)) + "°F")
        elif ligne == (3,):
            return sendResult(str(round(tempKelVERSCelsius(valeur), 2)) + "°C")
        elif ligne == (4,):
            return sendResult(str(round(tempFahVERSKelvin(valeur), 2)) + "°K")
        elif ligne == (5,):
            return sendResult(str(round(tempFahVERSCelsius(valeur), 2)) + "°C")
        else:
            return sendResult("Vous n'avez pas choisi de conversion")           # Préviens en cas de non selection
    except:
        return sendResult("Vous n'avez pas choisi de conversion")               # Seul cas possible?

def sendResult(resultat):                                                       # Affiche les résultats
    labelResultatconversion.config(text=resultat)                               # .config: Permet de changer les paramètres actuel

def tempCelVERSFahrenheit(cel):
    return(cel*9/5+32)

def tempCelVERSKelvin(cel):
    return(cel+491.67)

def tempKelVERSFahrenheit(kel):
    return(kel*9/5-459.67)

def tempKelVERSCelsius(kel):
    return(kel-491.67)

def tempFahVERSKelvin(fah):
    return((fah+459.67)*5/9)

def tempFahVERSCelsius(fah):
    return((fah-32)*5/9)

def selection(event):                                                           # Détection du choix de conversion avec event (ici le choix d'une conversion)
    global ligne                                                                # Passage de la variable en global pour la detection de la ligne
    ligne = listTemp.curselection()                                             # Détection de la selection dans la liste (aka chiffre)
    try:
        ligneTxt = listTemp.get(ligne)                                          # Récupération du texte (aka conversion dans la liste)
        labelResultatconversion.config(text=ligneTxt)                           # Affichage du choix dans le résultat
    except:
        return sendResult("Vous n'avez pas choisi de conversion")               # Fix en cas de non selection (double click ds box valeur)

fen1 = Tk()
fen1.title("Convertisseur Température °C/°F/°K")
fen1.geometry("400x175+750+300")

labelEntree = Label(fen1, text="Valeur temp", fg="blue")
labelEntree.grid(row=0, column=0)

entree = Entry(fen1,)
entree.bind("<Return>", conversion)
entree.grid(row=0, column=1)

listTemp = Listbox(fen1, height=6, width=7, bg="lightblue", fg="yellow", selectmode=SINGLE)
for listeComplete in ["°C->°F", "°C->°K", "°K->°F", "°K->°C", "°F->°K", "°F->°C"]:# Liste des conversions
    listTemp.insert(END, listeComplete)
listTemp.grid(row=0, column=2, padx=5, pady=5)
listTemp.bind("<<ListboxSelect>>", selection)                                   # Appelle la définition selection() lors d'un choix
listTemp.select_set(0)                                                          # Auto set first index

labelResultatconversion = Label(fen1, width=30, height=3, text="Convertisseur - ThibaultP", bg="lightgreen", fg="blue")
labelResultatconversion.grid(row=1, column=1)

boutonQuitter = Button(fen1, text="Quitter", bg="purple", command = fen1.destroy)
boutonQuitter.grid(row=1, column=2, sticky=W, padx=50, pady=5)

mainloop()
