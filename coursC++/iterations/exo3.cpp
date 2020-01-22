#include <iostream>
using namespace std;

int main() {
  double emprun, remb, taux, inter(0), i(0);
  cout << "Indiquer le montant de la somme emprunte :" << endl;
  cin >> emprun;
  cout << "Indiquer le montant du remboursement mensuel :" << endl;
  cin >> remb;
  cout << "Indiquer le taux d'interet :" << endl;
  cin >> taux;
  while(emprun != 0) {
    ++i;
    inter = ((emprun*taux)/100)+inter;
    emprun = emprun - remb;
    cout << i << " : Reste = " << emprun << ", somme interets = " << inter << endl;
  }
}
