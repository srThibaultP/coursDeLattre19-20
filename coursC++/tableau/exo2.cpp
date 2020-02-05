#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int taille(10);                                                         //Il y a la valeur 10 dans la variable taille

  vector<int> tab;                                                              //Création du tableau "tab"
  for (size_t i(0); i<taille; ++i) {                                            //Tant que i est inférieur à 10
    tab.push_back(tab.size());                                                  //Il ajoute une ligne au tableau
    cout << tab.size();
    cout << " & " << tab[i] << endl;
  }
}
// Le programme ajoute une ligne au tableau avec la valeur précédente à l'intérieur
// ex. Pour i=2, la ligne du tableau est égal à 1
