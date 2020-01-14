#include <iostream>
using namespace std;

int main() {
  int x(1),y(2),z(3);
  cout<<"Entrer trois entiers :"<<endl;
  cin>>x>>y>>z;
  cout<<"Valeur de X : "<<x<<endl;
  cout<<"Valeur de Y : "<<y<<endl;
  cout<<"Valeur de Z : "<<z<<endl;

  if (x==y){
    if(y==z){
      cout<<"Les 3 valeurs sont egales"<<endl;
    }else{
      cout<<"Les 2 premieres valeurs sont egales"<<endl;
    }
  }
  else{
    if (x==z){
      cout<<"La premiere et la troisieme sont egales"<<endl;
    }else if(y==z){
      cout<<"Les 2 dernieres sont egales"<<endl;
    }else{
      cout<<"Les 3 valeurs sont differentes"<<endl;
    }
  }
}
