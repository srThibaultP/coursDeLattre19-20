#include <iostream>
using namespace std;

void cesarCara();

int main() {
  cesarCara();
}

void cesarCara() {
  char caractere, alphabet[] = ("abcdefghijklmnopqrstuvwxyz");
  int clef, cesarfin, position(0);
  cout << "Caractere a coder : " << endl;
  cin >> caractere;
  cout << "Clef ? (decalage de l'alphabet) : " << endl;
  cin >> clef;
  for (size_t i(0); caractere != alphabet[i]; ++i) {
    position = 1+i;
  }
  cesarfin = clef + position;
  cout << "Le caractere est maintenant cryptee : " << alphabet[cesarfin];
}
