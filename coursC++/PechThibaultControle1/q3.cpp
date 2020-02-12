#include <iostream>
using namespace std;

double distance(double xa, double ya, double xb, double yb);                    //prototype

int main() {
  double xa, ya, xb, yb;                                                        //déclération de variables
  cout << "Inserer a la suite la valeur x & y du point A" << endl;              //Demande de xa & ya
  cin >> xa >> ya;                                                              //écoute des valeurs du terminal
  cout << "Inserer a la suite la valeur x & y du point B" << endl;              //Demande de xb & yb
  cin >> xb >> yb;                                                              //écoute des valeurs du terminal
  cout << "La distance AB est de " << distance(xa, ya, xb, yb) << endl;         //affichage du résultat avec l'appel de la fonction
}

double distance(double xa, double ya, double xb, double yb) {                   //fonction qui calcule la distance ab
  return sqrt(((xb-xa)*(xb-xa)) + ((yb-ya)*(yb-ya)));                           //formule
}
