#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector < int > entier(3);
  cout << "Saisie de 3 entiers" << endl;
  for (size_t i = 1; i < entier.size(); ++i) {
    cout << "Entrez entier numero " << i << " : ";
    cin >> entier[i];
    if(entier[i] == 0) {
      entier.clear();
    }
    else if(entier[i] < 0) {
      entier.pop_back();
    }
  }
  for (size_t i = 0; i < entier.size(); i++) {
    cout<<i+1<<entier[i];
  }
}
