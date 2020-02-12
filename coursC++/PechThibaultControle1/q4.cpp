#include <iostream>
using namespace std;

int premier(int x);                                                             //prototype

int main() {
  int x(32);                                                                    //verifier si ce nombre est premier
  cout << premier(x);                                                           //appel de la fonction
}

int premier(int x) {                                                            //vérification du nombre
  bool r = true;
  int d = 2;
  while(r && d*d<=x)
  if(x%d == 0) r=false; else d++;
  return r;
}
