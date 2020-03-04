#include <iostream>
using namespace std;

void echange (int &, int &);

int main() {
  int x(2);
  int y(4);
  cout<<x<<" "<<y<<endl;
  echange (x,y);
  cout<<x<<" "<<y<<endl;
  return 0;
}

void echange (int &a, int &b) {
  int c; c=a; a=b; b=c;
}
