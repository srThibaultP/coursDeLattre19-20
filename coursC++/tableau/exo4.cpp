#include <iostream>
#include <vector>
using namespace std;

double note();

int main() {
  note();
}

double note() {
  int nbCopies;
  cout << "Combien de copies ? (< 100)" << endl;
  cin >> nbCopies;
  vector < int > copies(nbCopies);
  for (size_t i = 0; i < nbCopies; i++) {
    cout << "Entrez les notes : ";
    cin >> copies[i];
  }
  return 0;
}
