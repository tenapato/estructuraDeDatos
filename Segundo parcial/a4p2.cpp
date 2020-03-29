#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

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



void comparacionConBinaria(int *a, int size, int paso, int num){ //metodo para comparar busqueda ordenada 2 con binaria


auto inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,size,num,paso);
auto fintiempo = high_resolution_clock::now();
auto duracionO2=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<" en busqueda ordenada 2: "<<duracionO2<<endl;

inicialTiempo = high_resolution_clock::now();
busquedaBinaria(a,0,size-1,num);
fintiempo = high_resolution_clock::now();
auto duracionBinaria=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con Busqueda Binaria: "<<duracionBinaria<<endl;

cout<<"Diferencia de timepo: "<<duracionO2-duracionBinaria<<endl;
};

int main(){
int Size = 100000;
int a[Size];
for(int i=0;i<Size;i++){
    a[i] = i+1;
    //cout<<a[i]<<endl;
}

/*Al acabarlo me di cuenta que pude haberlo hecho con muchos menos lineas si lo hacia en un metodo...lol*/
//Con el numero 5
int num = 5;
int paso = 2;
cout<<"Numero "<<num<<endl;
auto inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
auto fintiempo = high_resolution_clock::now();
auto duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 3;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;


paso = 4;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 4;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 5;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 6;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 7;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 8;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 9;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 10;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

cout<<endl;

//Con el numero 500
num = 500;
paso = 2;
cout<<"Numero "<<num<<endl;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 3;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;


paso = 4;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 4;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 5;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 6;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 7;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 8;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 9;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 10;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

cout<<endl;

//Con el numero 45,000
num = 45000;
paso = 2;
cout<<"Numero "<<num<<endl;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 3;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;


paso = 4;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 4;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 5;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 6;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 7;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 8;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 9;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 10;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

cout<<endl;

//Con el numero 7919
num = 7919;
paso = 2;
cout<<"Numero "<<num<<endl;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 3;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;


paso = 4;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 4;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 5;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 6;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 7;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 8;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 9;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 10;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

cout<<endl;

//Con el numero 9853
num = 9853;
paso = 2;
cout<<"Numero "<<num<<endl;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 3;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;


paso = 4;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 4;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 5;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 6;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 7;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 8;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 9;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

paso = 10;
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,Size,num,paso);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Con paso "<<paso<<": "<<duracion<<endl;

cout<<endl;



/*Comparación con busqueda binaria*/

int numero = 5;
cout<<"Numero: "<<numero<<endl;
comparacionConBinaria(a,Size,7,numero);
comparacionConBinaria(a,Size,8,numero);
cout<<endl;

numero = 500;
cout<<"Numero: "<<numero<<endl;
comparacionConBinaria(a,Size,7,numero);
comparacionConBinaria(a,Size,8,numero);
cout<<endl;

numero = 45000;
cout<<"Numero: "<<numero<<endl;
comparacionConBinaria(a,Size,7,numero);
comparacionConBinaria(a,Size,8,numero);
cout<<endl;

numero = 7919;
cout<<"Numero: "<<numero<<endl;
comparacionConBinaria(a,Size,7,numero);
comparacionConBinaria(a,Size,8,numero);
cout<<endl;


numero = 9853;
cout<<"Numero: "<<numero<<endl;
comparacionConBinaria(a,Size,7,numero);
comparacionConBinaria(a,Size,8,numero);
cout<<endl;




    return 0;

}