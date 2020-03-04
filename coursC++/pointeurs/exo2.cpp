#include <iostream>
using namespace std;

int main() {
  int a(2), b(3);
  cout<<"Adresse de a : "<< &a<<endl;
  cout<<"Adresse de b : "<< &b<<endl;
  cout<<"Taille de a : "<<sizeof(a)<<" octets "<<endl;
  int tab[3]={10, 11, 12};
  cout<<"Taille de tab : "<<sizeof(tab)<<" octets"<<endl;
  for (int i(0); i < 3; ++i) {
    cout<<"Adresse element "<<i<<" : "<<&(*(tab+i))<<" contenu : "<<*(tab+i)<<endl;
  }
  return 0;
}
