#include <iostream>
using namespace std;

int main()
{
    int a;
    cout<<"Ingrese un año"<<endl;
    cin>>a;

    if ((a%4 == 0 && a%100 != 0)||(a%4 == 0 && a%100 == 0 && a%400 == 0))
    {
         cout<<"El año si es bisiesto"<<endl;
    }
    
    else {
        cout<<"El año no es bisiesto"<<endl;
    }


    return 0;
}