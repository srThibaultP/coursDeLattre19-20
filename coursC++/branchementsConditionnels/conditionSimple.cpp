#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "Entrer un nombre entier : " << endl;
  cin >> n;
  if(n<10) {
    cout << "Le nombre est plus petit que 10" << endl;
  } else{
    cout << "Le nombre est plus grand ou egal a 10 " << endl;
  }
  cout << "Au revoir " << endl;
}
