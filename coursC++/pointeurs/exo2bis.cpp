#include <iostream>
using namespace std;

int main() {
  int a(2), b(3);
  int *pa;
  pa = &a;
  int *pb(&b);
  cout<<"Adresse de a : "<< pa <<endl;
  cout<<"Adresse de b : "<< pb <<endl;
  cout<<"Taille de a : "<<sizeof(*pa)<<" octets "<<endl;
  int tab[3]={10, 11, 12};
  int *ptab;
  ptab = tab;
  cout<<"Taille de tab : "<<sizeof(tab)<<" octets"<<endl;
  for (int i(0); i < 3; ++i) {
    cout<<"Adresse element "<<i<<" : "
    <<&(*(ptab))<<" contenu : "<<*(ptab)<<endl;
    ++ptab;
  }
  return 0;
}
