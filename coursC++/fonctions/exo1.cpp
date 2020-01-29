#include <iostream>
using namespace std;

int argument(int val1, int val2, double choix);

int main() {
  double choix;
  cout << "Choisir une valeur : ";
  cin >> choix;
  argument(10, 100, choix);
}

int argument(int val1, int val2, double choix) {
  bool ordre1(val1<val2);
  bool ordre2(val1>val2);
  if(ordre1) {
    if(choix>=val1 && choix<=val2) {
      cout << choix << " est bien compris entre " << val1 << " et " << val2;
      return 1;
    }
    else {
      cout << choix << " est n'est pas compris entre " << val1 << " et " << val2;
      return 0;
    }
  }
  else if(ordre2) {
    if(choix>=val2 && choix<=val1) {
      cout << choix << " est bien compris entre " << val2 << " et " << val1;
      return 1;
    }
    else {
      cout << choix << " est n'est pas compris entre " << val2 << " et " << val1;
      //cout <<endl<<val1<<"yes"<<val2<<"no"<<choix;
      return 0;
    }
  }
  else {
    cout << "Veuillez choisir deux valeurs non égal.";
    return 0;
  }
}
