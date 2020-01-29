#include <iostream>
using namespace std;

double resultat(double val1, double val2);

int main() {
  double val1, val2, total;
  cout << "Choisir deux valeurs : " << endl;
  cin >> val1 >> val2;
  total = resultat(val1, val2);
  cout << total << " est le total des operations." << endl;
}

double resultat(double val1, double val2) {
  double resultat, resultat1;
  resultat = val1 + val2;
  cout << "Le resultat de l'addition est " << resultat << endl;
  resultat1 = val1 - val2;
  cout << "Le resultat de la soustraction est " << resultat1 << endl;
  //cout << "resultat=" << resultat << "**resultat1=" << resultat1 <<endl;

  resultat = resultat + resultat1;
  //cout << "resultat=" << resultat << "**resultat1=" << resultat1 <<endl;

  resultat1 = val1 * val2;
  cout << "Le resultat de la multiplication est " << resultat1 << endl;
  //cout << "resultat=" << resultat << "**resultat1=" << resultat1 <<endl;

  resultat = resultat + resultat1;
  //cout << "resultat=" << resultat << "**resultat1=" << resultat1 <<endl;

  resultat1 = val1 / val2;
  cout << "Le resultat de la division est " << resultat1 << endl;
  //cout << "resultat=" << resultat << "**resultat1=" << resultat1 <<endl;
  return resultat + resultat1;
}
