#include <iostream>
using namespace std;

int NombrePremier(int x);
int premier(int demande);

int main() {
  int demande, nbPremier;
  cout << "Indiquer le rang du nombre premier voulu : ";
  cin >> demande;
  cout << "Le nombre premier de rang " << demande << " est : " << premier(demande) << endl;
}

int NombrePremier(int x) {
  bool r = true;
  int d = 2;
  while (r && d*d<=x)
  if(x%d == 0) r=false; else d++;
  return r;
}

int premier(int demande) {
  int nb(0), i(2);
  while (nb != demande) {
    if (NombrePremier(i)) {
      nb++;
    }
    i++;
  }
  return (i - 1);
}
