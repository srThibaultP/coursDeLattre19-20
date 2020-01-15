#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int a,b=0;
  cout<<"Entrer un nombre plus grand que 1 :"<<endl;
  cin>>a;

  for(int i=1; i<=a; i++) {
    if(a==1) {
      b=3;
    }
    if(a%i==0) {
      b++;
    }
  }
  if(b>2) {
    cout<<a<<" n'est pas un nombre premier"<<endl;
  }
  else {
    cout<<a<<" est un nombre premier"<<endl;
  }
}
