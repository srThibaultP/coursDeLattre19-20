def miles(a):
    if a == "100":
        return "M"
    elif a == "200":
        return "MM"
    elif a == "300":
        return "MMM"
    elif a == "0":
        return " "

def centaines(a):
    if a == "100":
        return "C"
    elif a == "200":
        return "CC"
    elif a == "300":
        return "CCC"
    elif a == "400":
        return "CD"
    elif a == "500":
        return "D"
    elif a == "600":
        return "DC"
    elif a == "700":
        return "DCC"
    elif a == "800":
        return "DCCC"
    elif a == "900":
        return "CM"
    elif a == "0":
        return " "

def dizaines(a):
    if a == "10":
        return "X"
    elif a == "20":
        return "XX"
    elif a == "30":
        return "XXX"
    elif a == "40":
        return "XL"
    elif a == "50":
        return "L"
    elif a == "60":
        return "LX"
    elif a == "70":
        return "LXX"
    elif a == "80":
        return "LXXX"
    elif a == "90":
        return "XC"
    elif a == "0":
        return " "

def unites(a):
    if a == "1":
        return "I"
    elif a == "2":
        return "II"
    elif a == "3":
        return "III"
    elif a == "4":
        return "IV"
    elif a == "5":
        return "V"
    elif a == "6":
        return "VI"
    elif a == "7":
        return "VII"
    elif a == "8":
        return "VIII"
    elif a == "9":
        return "IX"
    elif a == "0":
        return " "

if __name__ == '__main__':
    valeur = 1
    temp = 0
    set = 1
    while valeur != 0:
        try:
            valeur = input("\nDécimal\n")
            valeur = int(valeur)
            #print("LA VAL EST=")
            #print(valeur)


            if valeur <0:
                print("Erreur, veuillez réessayer (inf à zero)")
            elif valeur <= 9:
                valConv = str(valeur)
                print(unites(valConv),end=' ')
            elif valeur <=3999:
                if set == 1:
                    print("\n")
                    set = 0
                    valConv = str(valeur)
                    val1 = valConv[0]+"0"
                    #print("valeur1="+val1)
                    val2 = valConv[1]
                    #print("valeur2="+val2)
                    val3 = valConv[3]
                    val4 = valConv[4]
                    rep1 = dizaines(val1)
                    rep2 = unites(val2)
                    rep3 = centaines(val3)
                    rep4 = miles(val4)
                    rep1 = str(rep1)
                    rep2 = str(rep2)
                    rep3 = str(rep3)
                    rep4 = str(rep4)
                    if temp <= 8:
                        print(rep1+rep2+rep3+rep4, end=' ')
                        #print("###########")
                        #print("DIZAINE = "+val1+val2)
                        #print("###########")
                        temp = temp +1
                    else:
                        print(rep1+rep2+rep3+rep4, end=' ')
                        print("\n")
                        temp = 0
                        valeur = valeur +1
            elif valeur <=999:
                if set == 1:
                    print("\n")
                    set = 0
                    valConv = str(valeur)
                    val1 = valConv[0]+"0"
                    #print("valeur1="+val1)
                    val2 = valConv[1]
                    #print("valeur2="+val2)
                    val3 = valConv[3]
                    rep1 = dizaines(val1)
                    rep2 = unites(val2)
                    rep1 = str(rep1)
                    rep2 = str(rep2)
                    if temp <= 8:
                        print(rep1+rep2+rep3, end=' ')
                        #print("###########")
                        #print("DIZAINE = "+val1+val2)
                        #print("###########")
                        temp = temp +1
                    else:
                        print(rep1+rep2+rep3, end=' ')
                        print("\n")
                        temp = 0
                        valeur = valeur +1
            elif valeur <=99:
                if set == 1:
                    print("\n")
                    set = 0
                    valConv = str(valeur)
                    val1 = valConv[0]+"0"
                    #print("valeur1="+val1)
                    val2 = valConv[1]
                    #print("valeur2="+val2)
                    rep1 = dizaines(val1)
                    rep2 = unites(val2)
                    rep1 = str(rep1)
                    rep2 = str(rep2)
                    if temp <= 8:
                        print(rep1+rep2, end=' ')
                        #print("###########")
                        #print("DIZAINE = "+val1+val2)
                        #print("###########")
                        temp = temp +1
                    else:
                        print(rep1+rep2, end=' ')
                        print("\n")
                        temp = 0
                        valeur = valeur +1
            else:
                print("Erreur, veuillez réessayer (sup à 3999)")

        except:
            print("Erreur, veuillez réessayer (texte)")
