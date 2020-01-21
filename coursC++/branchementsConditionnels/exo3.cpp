#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int a,b,c,r1,r2,delta1,delta2,delta(22);
  cout<<"Donner les coefficients a, b et c"<<endl;
  cin>>a>>b>>c;
  /*
  cout<<"a"<<a<<"b"<<b<<"c"<<c<<"deltafsdjhfisdj"<<delta<<endl;
  delta = (pow(b,2))-((4*a)*c);
  cout<<"a"<<a<<"b"<<b<<"c"<<c<<"delta"<<delta<<endl;
  cout<<pow(b,2)<<endl;
  cout<<((4*a)*c)<<endl;
  cout<<delta<<endl;
  */
  delta1 = b*b;
  delta2 = ((4*a)*c);
  cout<<"delta1="<<delta1<<endl;
  cout<<"delta2="<<delta2<<endl;
  delta = delta1 - delta2;
  cout<<"delta="<<delta<<endl;

  if(delta<0) {
    cout<<"Il y a pas de solutions reel"<<endl;
  }
  else if(delta==0){
    r1 = -b/(2*a);
    cout<<"La solution est "<<r1<<endl;
  }
  else {
    r1 = ((-b)+sqrt(delta))/2*a;
    r2 = ((-b)-sqrt(delta))/2*a;
    cout<<"Les solutions sont "<<r1<<" et "<<r2<<endl;
  }
}
