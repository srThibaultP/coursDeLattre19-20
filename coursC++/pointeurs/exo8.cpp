#include <iostream>
using namespace std;

struct point {
  char c;
  int x, y;
};

void affichage(point pa);

int main() {
  point pa;
  pa.c = 'A';
  pa.x = 10;
  pa.y = 20;
  cout << " " << pa.c << " (" << pa.x << "," << pa.y << ")" << endl;
  point *ptr;
  ptr = &pa;
  cout << " " << ptr -> c << " (" << ptr -> x <<"," << ptr -> y << ") " << endl;
  affichage(pa);
}

void affichage(point pa) {
  cout << "Point " << pa.c << " de coordonees " << pa.x << " " << pa.y;
}
