#include <iostream>

using namespace std;


class Valores{

    public:
    int *a;
    int size;
    int index = 0;

    Valores(int tam){
        size = tam;
        a = new int(size);
    }

    Valores(const Valores& deDondeViene){ //Este constructor sirve para que el arreglo copia tenga un espacio de memoria diferente, y por ende, valores diferentes
        size = deDondeViene.size;
        a=new int(size);
        for(int i=0; i<size; i++){
            a[i]=deDondeViene.a[i];
        }
    }

};

int main(){
    Valores original(5);
    original.a[0]= 10;
    original.a[1]= 20;
    original.a[2]= 30;
    original.a[3]= 40;
    original.a[4]= 50;
    Valores copia=original;
    copia.a[1]=3;
    cout<<original.a[1]<<endl;
    cout<<copia.a[1]<<endl;


    return 0;
}