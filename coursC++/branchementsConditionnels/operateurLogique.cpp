#include <iostream>
using namespace std;

int n,x,y;
int main(){
  cout<<"Entrer un entier entre 1 et 10 :"<<endl;
  cin>>n;
  if((n>=1) and (n<=10)){
    cout<<"Bonne valeur"<<endl;
  }else{
    cout<<"N'est pas dans l'intervale"<<endl;
  }
  cout<<"Entrer 2 valeur :"<<endl;
  cin>>x>>y;
  if ((x>=0)or (y>=0)){
    cout<<"au moins 1 valeur positive "<<endl;
  }else{
    cout<<"Les 2 valeurs sont negatives"<<endl;
  }
}
