#include <iostream>
using namespace std;

int echange(double& val1, double& val2);

int main() {
  double val1, val2;
  cout << "Choisir deux valeurs : " << endl;
  cin >> val1 >> val2;
  //cout << "/////////Valeur 1 = " << val1 << " Valeur 2 = " << val2 << endl;
  cout << "Valeur 1 = " << val1 << " Valeur 2 = " << val2 << endl;
  echange(val1,val2);
  cout << "Valeur 1 = " << val1 << " Valeur 2 = " << val2 << endl;
}

int echange(double& val1, double& val2) {
  double i(0);
  i = val1;
  //cout << "******Valeur 1 = " << val1 << " Valeur 2 = " << val2 << "i=" <<i<<endl;

  val1 = val2;
  //cout << "******Valeur 1 = " << val1 << " Valeur 2 = " << val2 << "i=" <<i<<endl;

  val2 = i;
  return 0;
}
