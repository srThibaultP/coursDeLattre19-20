def tempCelsius(fah):
    return((fah-32)*(5/9))

def main():
    cel=float(input("Température en F"))
    resultat=tempCelsius(cel)
    print(resultat)
if __name__ == '__main__':
    main()
