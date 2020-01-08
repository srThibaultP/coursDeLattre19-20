#include <iostream>

using namespace std;

int main()
{
    int age, annee;
    cout << "Quel est votre age?" << endl;
    cin >> age;
    cout << "Vous avez " << age << " ans." << endl;
    annee = 2020 - age;
    cout << "Vous etes nee en " << annee << endl;
    return 0;
}
