#include <iostream>
using namespace std;

void minMax(int *ptab, int taille, int *pmini, int*pmaxi);

int main() {
  int tab[5] = {100, 10, -2, 3, 4};
  int mini, maxi;
  minMax(tab, 5, &mini, &maxi);
  cout << "Valeur la plus grande : " << maxi << endl;
  cout << "Valeur la plus petite : " << mini << endl;
  return 0;
}

void minMax(int *ptab, int taille, int *pmini, int *pmaxi) {
  *pmini = *pmaxi = *ptab;
  for(int i(1); i < taille; ++i) {
    ++ptab;
    if (*ptab < *pmini) {
      *pmini = *ptab;
    }
    if (*ptab > *pmaxi) {
      *pmaxi = *ptab;
    }
  }
}
