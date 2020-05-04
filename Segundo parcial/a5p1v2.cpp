#include <iostream>
#include <ctime>
#include "sort.cpp"
#include "vector.cpp"
using namespace std;

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


template <class T>

class Tienda{
    public:
    T *articulos;
    
    int count;
    int size;

    Tienda(int prod){
    size = prod;    
    srand(time(NULL));
    
    articulos = new int [size]( );
   
         for(int i=0; i<=1300;i++){
        articulos[i]= rand()%2000000 ;
       //cout<<articulos[i]<<endl; 
    }
    


    }

    void ordenar(){
       
         QuickSort<T> quicksort;
         quicksort.sort(articulos, 1300); //no sirve cuando le pongo size solo cuando pongo 1300
         for(int i=0; i<=1300;i++){
         cout<<articulos[i]<<endl;  }  
    }

     
void verificar(int idABuscar){
    if( busquedaBinaria(articulos, 0, size, idABuscar) == -1){
       cout<<"No se encontro el articulo"<<endl;
   }
    else{
       cout<<"El articulo si ha sido verificado"<<endl;
   }
} //permite verificar si el id de un producto esta registrado

/*
void agregar(int num){
    Vector <T> vect;
    vect.append(num);
}
*/
};



int main(){
    
    Tienda <int> a(1500);
    a.ordenar();
    //a.verificar(1528047);
    //a.agregar(1528047);
    
    //a.verificar(1528047);

    return 0;
}