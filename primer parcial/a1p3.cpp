#include <iostream>
using namespace std;

int main()
{
    string frase;
    string palabra;
    int count = 0;
    int a = 0;
    
    cout<<"Ingrese una frase: ";
    //cin>>frase;
    getline(cin, frase);
    cout<<"Ingrese una palabra: ";
    cin>>palabra;


    
    for (int i = 0; i < frase.length(); i++)
    {
         if (tolower(frase[i] + frase[i+1] + frase[i+2]) == (palabra[0] + palabra[1] + palabra[2]))
	    {
		  count++;
	    }
        
    }
    
    
        if (count == 1){
             cout<<"Aparece: " <<count<< " vez"<<endl;
        }
        else {

              cout<<"Aparece: " <<count<< " veces"<<endl;
        }
    
    
    
}