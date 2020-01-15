#include <iostream>
using namespace std;

float a;

int main() {
  cout << "Entrer un reel :" << endl;
  cin >> a;
  if((a>=-1) && (a<1)) {
    cout << a << " est dans l'intervale [-1,1[";
  }
  else {
    cout << a << " n'est pas dans l'intervale [-1,1[";
  }
}
