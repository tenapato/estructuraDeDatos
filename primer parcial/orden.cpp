#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

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



int busquedaBinaria(int *a, int inicio, int fin, int buscado){

    if(fin<inicio){
        return -1;
    }

    int medio = (fin+inicio)/2;
    if(buscado==a[medio]){
        return medio;
    }
    else if(buscado<a[medio]){
        return busquedaBinaria(a, inicio, medio-1, buscado);
    }
    else{
        busquedaBinaria(a, medio+1, fin, buscado);
    }
}


int main(){
    int size=7;
    int a[size]={1,3,5,7,9,11,13};
   
    cout<<busquedaOrdenada2(a,size,11,2)<<endl;

    auto inicialTiempo = high_resolution_clock::now();
    cout<<busquedaBinaria(a, 0, size-1, 3)<<endl;
    auto fintiempo = high_resolution_clock::now();

    auto duracion=duration_cast<seconds>(fintiempo-inicialTiempo).count();

    cout<<duracion<<endl;
    return 0;
}
