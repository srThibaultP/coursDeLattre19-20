import pickle
def main():

    a, b, c = 27, 12.96, [5, 4.83, "Rene"]
    f =open("donnees_test", "wb")
    pickle.dump(a, f)
    pickle.dump(b, f)
    pickle.dump(c, f)
    f.close()
    f =open("donnees_test", "rb")
    j = pickle.load(f)
    k = pickle.load(f)
    l = pickle.load(f)
    print(j, type(j))
    print(k, type(k))
    print(l, type(l))
    f.close()

if __name__ == '__main__':
    main()