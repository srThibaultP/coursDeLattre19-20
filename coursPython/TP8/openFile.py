import os as os_sys
'''modification de l'espace nom pour utiliser la fonction open native de python
et non la fonction open de os '''
import sys
sys.path.append("D:\PROGRAMATION\coursDeLattre19-20\coursPython\exe 8") #pour ajouter le repertoire essai dans l
os_sys.chdir("D:/PROGRAMATION/coursDeLattre19-20/coursPython/exe 8")#le fichier d'exemple la_cuisson_des_lumas.txt est dans le répertoie essai

def main():
     fichier='yes.txt'#fichier='la_cuisson_des_lumas.txt'  avec un s à luma
     try :
        with open (fichier,'rt') as varEnreg :
            textelu=varEnreg.readline()
            print(textelu)
     except IOError as e :
         print ("I/O error({0}): {1}".format(e.errno, e.strerror))
         print('fichier non trouvé')

if __name__ == '__main__':
    main()
