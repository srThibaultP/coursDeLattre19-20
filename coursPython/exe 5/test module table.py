import os
# test de la fonction table

def table(nb, max=10):
        i = 0
        while i < max:
                print(i + 1, "*", nb, "=", (i + 1) * nb)
                i += 1
def main():
    table(3, 20)
   # os.system("pause")

if __name__ == '__main__':
    main()
