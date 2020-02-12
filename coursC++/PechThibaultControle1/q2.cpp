#include <iostream>
using namespace std;

void afficher(int & a);                                                         //Prototype

int main() {                                                                    //Ce programme affiche la valeur insérée dans la ligne du dessous
  int a(4);                                                                     //variable a qui sera affiché
  afficher(a);                                                                  //Appel de la fonction
}

void afficher(int & a) {
    cout << a << endl;                                                          //Affiche la vaiable & dans le terminal
}
