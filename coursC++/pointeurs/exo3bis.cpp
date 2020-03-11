#include <iostream>
using namespace std;

int main() {
  const int Nombre(5);
  int mini(0), maxi(0);
  int *pmini(&mini);
  int *pmaxi(&maxi);
  int tab[Nombre];
  int *ptab;
  ptab = tab;
  cout << "Donner " << Nombre << " entiers" << endl;
  for (int i(0); i<Nombre; ++i) {
    cin>>*ptab;
    ++ptab;
  }
  cout << "Vous avez saisi : " << endl;
  ptab = tab;
  for (int i(0); i<Nombre; ++i) {
    cout << *ptab << " ";
    ++ptab;
  }
  cout << endl;
  //*pmaxi = *pmini = *ptab;
  maxi = mini = tab[0];
  ptab = tab;
  for (int i(0); i<Nombre; ++i) {
    if (*ptab>*pmaxi) *pmaxi=*ptab;
    if (*ptab<*pmini) *pmini=*ptab;
    ++ptab;
  }
  cout << "Maxi : " << *pmaxi << endl;
  cout << "Mini : " << *pmini << endl;
  return 0;
}
