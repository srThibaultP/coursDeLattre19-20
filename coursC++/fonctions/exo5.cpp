#include <iostream>
using namespace std;

void mult2(int i);
int mult3(int i);

int main() {
  int i;
  cout << "Choisir une valeur : " << endl;
  cin >> i;
  mult2(i);
  mult3(i);
}

void mult2(int i) {
  if (i%2==0) {
    cout << i << " est un multiple de 2" << endl;
  }
  else {
    cout << i << " n'est pas un multiple de 2" << endl;
  }
}

int mult3(int i) {
  if (i%3==0) {
    cout << i << " est un multiple de 3" << endl;
    return 0;
  }
  if (i%6==0) {
    cout << i << " est un multiple de 6" << endl;
    return 0;
  }
  else {
    cout << i << " n'est pas un multiple de 3 ou de 6" << endl;
    return 0;
  }
}
