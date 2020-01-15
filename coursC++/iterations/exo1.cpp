#include <iostream>
using namespace std;

int main() {
  for (int i(2); i<=10; ++i) {
    cout << "Table de multiplication de " << i << ":" << endl;
    for (int j(1); j<=10; ++j) {
      cout << " " << i << " multiplie par " << j << " = " << j*i << endl;
    }
    cout << endl;
  }
}
