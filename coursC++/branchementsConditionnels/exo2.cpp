#include <iostream>
using namespace std;

float a;

int main() {
  cout << "Entrer un reel :" << endl;
  cin >> a;

  bool b((2<a || a==2) && a<3);
  bool c(0<a && (a<1 || a==1));
  bool d((-10<a || a==-10) && (a<-2 || a==-2));
  bool e(b || c || d);

  if(e) {
    cout << a << " est dans l'intervale ";
  }
  else {
    cout << a << " n'est pas dans l'intervale";
  }
}
