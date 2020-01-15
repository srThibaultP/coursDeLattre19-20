#include <iostream>
using namespace std;

float a;

int main() {
  cout << "Entrer un reel :" << endl;
  cin >> a;

  bool b((a>2 || a==2) && a<3);
  bool c(a>0 && (a<1 || a==1));
  bool d((a>-10 || a==-10) && (a<-2 || a==-2));
  bool e(b || c || d);

  if(e) {
    cout << a << " est dans l'intervale ";
  }
  else {
    cout << a << " n'est pas dans l'intervale";
  }
}
