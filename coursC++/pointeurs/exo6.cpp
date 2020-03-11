#include <iostream>
using namespace std;

void minMax(int t[], int, int &, int&);

int main() {
  int tab[5] = {100, 10, -2, 3, 4};
  int mini, maxi;
  minMax(tab, 5, mini, maxi);
  cout << "Valeur la plus grande : " << maxi << endl;
  cout << "Valeur la plus petite : " << mini << endl;
  return 0;
}

void minMax(int t[], int taille, int &mini, int &maxi) {
  mini = maxi = t[0];
  for(int i(1); i < taille; ++i) {
    if (t[i] < mini) mini = t[i];
    if (t[i] > maxi) maxi = t[i];
  }
}
