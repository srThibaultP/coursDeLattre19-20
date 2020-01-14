#include <iostream>
using namespace std;

int main() {
  int a(1);
  int b(2);
  bool c(true);
  bool d(a==b);
  bool z(a<b);
  bool e(d or (a<b));
  if(e){cout<<"e est vraie"<<endl;}}
