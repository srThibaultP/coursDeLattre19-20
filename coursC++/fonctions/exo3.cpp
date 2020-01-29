#include <iostream>
using namespace std;

void affiche();
void affiche(int i);
int affiche1(int i);

int main() {
  affiche();
  affiche(3);
  affiche1(2);
}

void affiche() {
  cout << "Bonjour" << endl;
}

void affiche(int i) {
  for(int j(0); j<i; ++j) {
    cout << "Bonjour" << endl;
  }
}

int affiche1(int i) {
  for(int j(0); j<i; ++j) {
    cout << "Bonjour" << endl;
  }
  return 1;
}
