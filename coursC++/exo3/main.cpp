#include <iostream>

using namespace std;

int main()
{
    float taille, poids, imc;
    cout << "Quel est votre taille? (m)" << endl;
    cin >> taille;
    cout << "Quel est votre poids? (kg)" << endl;
    cin >> poids;
    imc = poids/(taille*taille);
    cout << "Votre IMC est de " << imc << "kg/m²" << endl;
}
