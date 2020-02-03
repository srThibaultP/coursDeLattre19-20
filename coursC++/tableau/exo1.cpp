#include <iostream>
#include <vector>
using namespace std;

void tableau();

int main() {
  cout << "Saisie de 3 entiers" << endl;
  tableau();
}

void tableau() {
  int j(1);
  vector < int > entier(3);
  for (size_t i = 1; i < entier.size() + j; ++i) {
    cout << "Entrez entier numero " << i << " : ";
    cin >> entier[i];
    if(entier[i] == 0) {
      //cout << "Supression du tableau" << endl;
      entier.clear();
      tableau();
    }
    else if(entier[i] < 0) {
      //cout << "Supression de la derniere valeur" << endl;
      i=i-2;
      j=j+1;
      entier.pop_back();
    }
  }
  for (size_t i = 1; i < entier.size() + j; i++) {
    cout<<entier[i]<<" ";
  }
}
