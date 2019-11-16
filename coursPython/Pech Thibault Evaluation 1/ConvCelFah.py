def tempFahrenheit(cel):
    return(cel*9/5+32)

def main():
    fah=float(input("Température en C"))
    resultat=tempFahrenheit(fah)
    print(resultat)
if __name__ == '__main__':
    main()
