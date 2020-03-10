#include <iostream>
using namespace std;


class Ejemplo{
    public:
        int *a;
        int size;
        Ejemplo(int valor){
            size=valor;
            a= new int(valor);
        }

        ~Ejemplo(){
            cout<<"Borranndo arreglo"<<endl;
            delete [] a;
        }
};



int main (){
    Ejemplo *e= new Ejemplo(10);
    cout<<e->a<<endl;
    return 0;
}