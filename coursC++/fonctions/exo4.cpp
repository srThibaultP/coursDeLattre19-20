#include <iostream>
using namespace std;

int resultat(double val1, double val2);

int main() {
  double val1, val2;
  cout << "Choisir deux valeurs : " << endl;
  cin >> val1 >> val2;
  cout << resultat(val1, val2) << " est le total des operations" << endl;
}

int resultat(double val1, double val2) {
  double resultat, resultat1;
  resultat = val1 + val2;
  cout << "Le resultat de l'addition est " << resultat << endl;
  resultat1 = val1 - val2;
  cout << "Le resultat de la soustraction est " << resultat << endl;
  //cout << "resultat=" << resultat << "**resultat1=" << resultat1 <<endl;

  resultat = resultat + resultat1;
  //cout << "resultat=" << resultat << "**resultat1=" << resultat1 <<endl;

  resultat1 = val1 * val2;
  cout << "Le resultat de la multiplication est " << resultat << endl;
  //cout << "resultat=" << resultat << "**resultat1=" << resultat1 <<endl;

  resultat = resultat + resultat1;
  //cout << "resultat=" << resultat << "**resultat1=" << resultat1 <<endl;

  resultat1 = val1 / val2;
  cout << "Le resultat de la division est " << resultat << endl;
  //cout << "resultat=" << resultat << "**resultat1=" << resultat1 <<endl;
  resultat = resultat + resultat1;
  return resultat;
}
