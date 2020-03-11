#include <iostream>
using namespace std;

struct point {
  char c;
  int x, y;
};

void affichage(point &p);

int main() {
  point s;
  s.c='A';
  s.x='1';
  s.y='2';
  affichage(s);
}

void affichage(point &p) {
  cout << "Point " << p.c << " de coordonnees (" << p.x << ";" << p.y << ")" << endl;
}
