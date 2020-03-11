#include <iostream>
using namespace std;

int main() {
  int* px(nullptr);
  px = new int;
  *px=3;
  cout << *px << endl;
  delete px;
  px = nullptr;
}
