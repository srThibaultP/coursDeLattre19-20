#include <iostream>
#include <vector>
using namespace std;

void cesarCara();
void cesar();
void explodeCara(char chaine);

char alphabet[] = ("abcdefghijklmnopqrstuvwxyz");

int main() {
  cesar();
}

void cesarCara() {
  char caractere;
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

void cesar() {
  char caractere, alphabet[] = ("abcdefghijklmnopqrstuvwxyz");
  int clef, cesarfin, position(0);
  cout << "Caractere a coder : " << endl;
  cin >> caractere;
  cout << "Clef ? (decalage de l'alphabet) : " << endl;
  cin >> clef;

  explodeCara(caractere);

  for (size_t i(0); caractere != alphabet[i]; ++i) {
    position = 1+i;
  }
  cesarfin = clef + position;
  cout << "Le caractere est maintenant cryptee : " << alphabet[cesarfin];
}

void explodeCara(string chaine) {
  vector < int > caractereChifree;
  for (size_t i(0); chaine[i] != chaine.size(); ++i) {
    return 1;
  }
}
