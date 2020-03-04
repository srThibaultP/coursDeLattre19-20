#include <iostream>
using namespace std;

struct Complexe {
  double re;
  double im;
};

void affichageComplexe(Complexe z);
Complexe additionComplexe(Complexe z1, Complexe z2);
Complexe soustractionComplexe(Complexe z1, Complexe z2);
Complexe produitComplexe(Complexe z1, Complexe z2);

int main() {
  Complexe nbr1({1.0,-1.0});
  Complexe nbr2({1.0,1.0});
  Complexe nbr3(additionComplexe(nbr1, nbr2));
  affichageComplexe(nbr1);
  affichageComplexe(nbr2);
  affichageComplexe(nbr3);
  affichageComplexe(additionComplexe(nbr1,nbr2));
  affichageComplexe(soustractionComplexe(nbr1,nbr2));
  affichageComplexe(produitComplexe(nbr1,nbr2));
}

void affichageComplexe(Complexe z) {
  cout<<" (" <<z.re<<" , "<<z.im<<") "<<endl;
}

Complexe additionComplexe(Complexe z1, Complexe z2) {
  return {(z1.re + z2.re), (z1.im + z2.im)};
}

Complexe soustractionComplexe(Complexe z1, Complexe z2) {
  return {(z1.re - z2.re), (z1.im - z2.im)};
}

Complexe produitComplexe(Complexe z1, Complexe z2) {
  return {(z1.re * z2.re), (z1.im * z2.im)};
}
