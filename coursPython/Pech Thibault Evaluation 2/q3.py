def dizaines(a):
    if a == 10:
        return "X"
    elif a == 20:
        return "XX"
    elif a == 30:
        return "XXX"
    elif a == 40:
        return "XL"
    elif a == 50:
        return "L"
    elif a == 60:
        return "LX"
    elif a == 70:
        return "LXX"
    elif a == 80:
        return "LXXX"
    elif a == 90:
        return "XC"

if __name__ == '__main__':
    print(dizaines(10))
    print(dizaines(20))
    print(dizaines(30))
    print(dizaines(40))
    print(dizaines(50))
    print(dizaines(60))
    print(dizaines(70))
    print(dizaines(80))
    print(dizaines(90))
