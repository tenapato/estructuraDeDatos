#include <iostream>

using namespace std;
 //busqueda Secuencial
int busquedaSecuencialR(int *a, int size ,int pos, int buscado){
    if(buscado==a[pos]){
        return pos;
    }
    if(pos>size){
        return -1;
    }
    else{
        if(buscado != a[pos]){
            return busquedaSecuencialR(a, size, pos+1, buscado);
        }
    }
}

int busquedaSecuencialRecursiva(int *a, int size, int buscado){
    busquedaSecuencialR(a, size, 0, buscado);
}

//Busqueda ordenada 1
int busquedaOrdenadaR(int *a, int size, int place, int buscado){
    if (buscado>size+1){
        return -1;
    }
    if(buscado == a[place]){
        return place;
    }
    else{
        if(buscado>place){
        return busquedaOrdenadaR(a, size, place+1, buscado);}
    }   
}

int busquedaOrdenadaRecursiva(int *a, int size, int buscado){
    busquedaOrdenadaR(a, size, 0, buscado);
}




int main(){
    int size=7;
    int a[size]={1,3,5,7,9,11,13};
    cout<<busquedaSecuencialRecursiva(a,size,5)<<endl;
    cout<<busquedaOrdenadaRecursiva(a,size,7)<<endl;
    return 0;
}