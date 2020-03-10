#include <iostream>

using namespace std;

int busquedaSecuencialOrdenada(int *arreglo, int buscado, int size){
    for(int i = 0; i<size;i++){
        if(arreglo[i]==buscado){
            cout<<"La posicion es "<<i<<endl;
            return i; //si lo encuentra
            break;
        }
    }
    cout<<"El numero no existe dentro del arreglo, これはすごいコッドですね!"<<endl;
    return -1; //si no lo encuentra
}

int busquedaOrdenada(int *arreglo, int buscado, int size){ //este es el codigo del profe
    if(buscado> arreglo[size-1]){
        return -1; //checa si el ultimo numero es mas grande que el que buscas, para ver si vale la pena empezar a buscar
    }
    for(int i=0; i<size;i++){
        if(arreglo[i]>buscado){
            return -1;
        }
        if(arreglo[i]==buscado){
            return i;
        }
    }
}


int main(){
    int size=10;
    int a[size]={1,2,3,4,5,7};
    int num;

    cout<<"Ingresa un numero a buscar"<<endl;
    cin>>num;
    busquedaSecuencialOrdenada(a,num,size);
    busquedaOrdenada(a,num,size);
    return 0;
    
}