#include <iostream>
using namespace std;

int bonjourOff();
int bonjourX(int i);
int bonjourOne(int i);

int main() {
  int choix;
  bonjourOff();
  cout << "Choisir une valeur : ";
  cin >> choix;
  bonjourX(choix);
  bonjourOne(choix);
  return 0;
}

int bonjourOff() {
  cout << "Bonjour" << endl;
  return 0;
}

int bonjourX(int i) {
  for(int j(0); j<i; ++j) {
    cout << "Bonjour" << endl;
  }
  cout << endl;
  return 0;
}

int bonjourOne(int i) {
  for(int j(0); j<i; ++j) {
    cout << "Bonjour" << endl;
  }
  cout << "1" << endl;
  return 1;
}
