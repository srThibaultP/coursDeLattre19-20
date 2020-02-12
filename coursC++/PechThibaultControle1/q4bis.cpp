#include <iostream>
using namespace std;

int NombrePremier(int x);
int premier(int count);

int main() {
  premier(10);                                                                  //Changer la valeur ici pour afficher les x premiers nombres
}

int NombrePremier(int x) {                                                      //Calcul du nombes premiers
  bool r = true;
  int d = 2;
  while (r && d*d<=x)
  if(x%d == 0) r=false; else d++;
  return r;
}

int premier(int count) {                                                        //Affichage des x nombres premiers
  count = count +1;
  int res;
  for (size_t j = 0; j < count; j++) {
    int nb(0), i(2);
    while (nb != j) {
      if (NombrePremier(i)) {
        nb++;
      }
      i++;
    }
    res = i-1;
    if (res == 1) {

    } else {
      cout << (i-1) << endl;
    }
  }
}
