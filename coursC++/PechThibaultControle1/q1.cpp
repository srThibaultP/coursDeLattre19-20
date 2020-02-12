#include <iostream>
using namespace std;

int main() {
  int b =2;                                                                     //création de la variable b et ajout de la valeur 2 à la variable
  int a = 4;                                                                    //création de la variable a et ajout de la valeur 4 à la variable
  int & ref1 = b;                                                               //création de la variable ref1 qui possède la valeur de b (donc 2)
  int & ref2 = a;                                                               //création de la variable ref2 qui possède la valeur de a (donc 4)
  ref2 += ref1;                                                                 //calcul de ref2 + ref 1 = ref2 (4 + 2 = 6). 6 vas dans la variable ref2
  ref1 -= ref2;                                                                 //calcul de ref1 - ref 2 = ref2 (2 - 6 = -4). -4 vas dans la variable ref1
  cout << ref2 << " " << ref1 << endl;                                          //affichage du résultat des deux opérations avec un saut à la ligne à la fin
}
