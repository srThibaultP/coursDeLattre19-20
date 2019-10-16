from os import *
#import sys
#chdir("C:\Portable Python 3.2.5.1/essai") pour changer le répertoire de travail
#sys.path.append("C:\Portable Python 3.2.5.1/essai") pour ajouter le répertoire essai dans la recherhe des modules
from essai.multiplication import *


def main():
    rep_cour = getcwd() # recupére le répertoire de travail
    print(rep_cour)
    table (3, 20)

if __name__ == '__main__':
    main()
