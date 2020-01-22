#include <iostream>
using namespace std;

int main() {
  int ligne, star, espace, i;
  cout << "Nombre de lignes? ";
  cin >> ligne;
  for(i=0; i<ligne; i++) {
    for(espace=(ligne-i)-1; espace>0; --espace) {
      cout << " ";
    }
    for(star=(2*i)+1; star>0; star--) {
      cout << "*";
    }
    cout << endl;
  }
}
