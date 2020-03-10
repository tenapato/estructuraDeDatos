#include <iostream>
using namespace std;

int main()
{
    int a;
    int suma = 0;
    int resultado = 0;
    cout<<"Ingrese cuantos números quiere sumar: ";
    cin>>a;

    for (int i = 0; i < a; i++)
    {
        cin>>suma;
        resultado+=suma;
    }
    
    cout<<"El resultado es: " <<resultado<<endl;

}