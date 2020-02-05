#include <iostream>
#include <vector>
using namespace std;

void f1(vector<int>& tab, vector<int>& tab2);

int main() {
  vector<int> tab = {1, 2, 3};                                                  //Création du tableau 1
  vector<int> tab2;                                                             //Création du tableau 2
  f1(tab, tab2);                                                                //Envoie des paramètres dans la fonction

  for (size_t i(0); i < tab.size(); i++) {                                      //Affichage des valeurs
    cout<<"tab1 = "<<tab[i]<<" tab2 = ";
    cout<<tab2[i]<<endl;                                                        //Affichage du résultat de la multiplication de tab*tab
  }
}

void f1(vector<int>& tab, vector<int>& tab2) {                                  //Création de 2 tableaux avec des valeurs modifiable hors de la fonction
  for (size_t i(0); i< tab.size(); i++) {                                       //Tant que i est inférieur à la taille du tableau
    tab2.push_back(tab[i]*tab[i]);                                              //Ajout de la multiplication de tab*tab
  }
}
