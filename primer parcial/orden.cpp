#include <iostream>

using namespace std;

int busquedaSecuencial(int *arreglo, int buscado, int size){
    for(int i = 0; i<size;i++){
        if(arreglo[i]==buscado){
            return i; //si lo encuentra
            break;
        }
    }
    return -1; //si no lo encuentra 　これはすごいコッドですね!
}



int busquedaAux(int *a, int inicio, int fin, int buscando){
    for(int i=inicio; i<fin; i++){
        if(a[i]==buscando){
            return i;
        }
    }
    return -1;
}




int busquedaOrdenada2(int *a, int size, int buscado, int paso){//metdodo que busca cada n numeros
    
    if(size%paso !=0){
        size = size +(size%paso);
    }
    
    for(int i = paso-1; i<=size; i+=paso){
        if(a[i-1]>=buscado){
                return busquedaAux(a, i-paso,i,buscado);
        }
    } 
    return -1;
}



int main(){
    int size=7;
    int a[size]={1,3,5,7,9,11,13};
   
    cout<<busquedaOrdenada2(a,size,11,2)<<endl;

    return 0;
}
