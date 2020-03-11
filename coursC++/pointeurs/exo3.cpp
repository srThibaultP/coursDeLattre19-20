#include <iostream>
using namespace std;

int main() {
  const int Nombre(5);
  int mini, maxi;
  int tab[Nombre];
  cout << "Donner " << Nombre << " entiers" << endl;
  for (int i(0); i<Nombre; ++i) {
    cin>>tab[i];
  }
  cout << "Vous avez saisi : " << endl;
  for (int i(0); i<Nombre; ++i) {
    cout << tab[i] << " ";
  }
  cout << endl;
  maxi = mini = tab[0];
  for (int i(1); i<Nombre; ++i) {
    if (tab[i]>maxi) maxi=tab[i];
    if (tab[i]<mini) mini=tab[i];
  }
  cout << "Maxi : " << maxi << endl;
  cout << "Mini : " << mini << endl;
  return 0;
}
