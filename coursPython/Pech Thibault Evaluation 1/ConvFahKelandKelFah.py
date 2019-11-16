def main():
    conv=input("Conversion [F]ahrenheit ou [K]elvin")
    if conv == "F":
     fah=float(input("Température en F"))
     resultat=tempFahrenheit(fah)
     print(resultat)
    elif conv == "K":
     kel=float(input("Température en K"))
     resultat=tempKelvin(kel)
     print(resultat)

def tempFahrenheit(kel):
    return(kel*9/5-459.67)

def tempKelvin(fah):
    return((fah+459.67)*5/9)

if __name__ == '__main__':
    main()
