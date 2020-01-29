#include <iostream>
using namespace std;

double argument(double x, double& y);

int main() {
  double z;
  argument(2, z);
  cout << "Le resultat est " << z << endl;
}

double argument(double x, double& y) {
  cout << "Choisir une valeur : " << endl;
  cin >> y;
  return y = y + x;
}
