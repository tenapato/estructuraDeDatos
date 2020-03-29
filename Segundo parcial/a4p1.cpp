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

int busquedaOrdenada1(int *a, int buscado, int size){
	if (buscado>a[size-1]){
		return -1;
	}
	for(int i=0; i<size; i++){
		if(a[i]>buscado){
			return -1;
		}
		if(a[i]==buscado){
			return i;
		}
	}
	return -1;
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
int aSize = 10;
int a[aSize]={1,3,5,7,9,11,13,15,17,20};
int bSize = 1000;
int b[bSize];
for(int i=0;i<bSize;i++){
    b[i] = i+1;
    //cout<<b[i]<<endl;
}
int cSize = 1000000;
int c[cSize];
for(int i=0;i<cSize;i++){
    b[i] = i+1;
    //cout<<c[i]<<endl;
}

/*Arreglo de 10*/
cout<<"Arreglo de 10"<<endl;
string arreglo = "arreglo de 10: ";
//numero pequeño con busqueda secuencial
auto inicialTiempo = high_resolution_clock::now();
busquedaSecuencial(a,1,aSize);
auto fintiempo = high_resolution_clock::now();
auto duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero pequeño con busqueda secuencial con "<<arreglo<<duracion<<endl;



//numero grande con busqueda secuencial
inicialTiempo = high_resolution_clock::now();
busquedaSecuencial(a,11,aSize);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero grande con busqueda secuencial con "<<arreglo<<duracion<<endl;



//numero pequeño con busqueda ordenada 1
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada1(a,1,aSize);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero pequeño con busqueda ordenada 1 con "<<arreglo<<duracion<<endl;


//numero grande con busqueda ordenada 1
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada1(a,11,aSize);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero grande con busqueda ordenada 1 con "<<arreglo<<duracion<<endl;


//numero pequeño con busqueda ordenada 2
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,aSize,1,2);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero pequeño con busqueda ordenada 2 con "<<arreglo<<duracion<<endl;

//numero grande con busqueda ordenada 2
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(a,aSize,11,2);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero grande con busqueda ordenada 2 con "<<arreglo<<duracion<<endl;


//numero pequeño con busqueda binaria
inicialTiempo = high_resolution_clock::now();
busquedaBinaria(a,0,aSize-1,1);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero pequeño con busqueda bianria con "<<arreglo<<duracion<<endl;
    
//numero pequeño con busqueda binaria
inicialTiempo = high_resolution_clock::now();
busquedaBinaria(a,0,aSize-1,11);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero grande con busqueda bianria con "<<arreglo<<duracion<<endl;

cout<<endl;

/*Arreglo de 1000*/
cout<<"Arreglo de 1000"<<endl;
arreglo = "arreglo de 1000: ";
//numero pequeño con busqueda secuencial
inicialTiempo = high_resolution_clock::now();
busquedaSecuencial(b,10,bSize);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero pequeño con busqueda secuencial con "<<arreglo<<duracion<<endl;



//numero grande con busqueda secuencial
inicialTiempo = high_resolution_clock::now();
busquedaSecuencial(b,999,bSize);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero grande con busqueda secuencial con "<<arreglo<<duracion<<endl;



//numero pequeño con busqueda ordenada 1
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada1(b,10,bSize);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero pequeño con busqueda ordenada 1 con "<<arreglo<<duracion<<endl;


//numero grande con busqueda ordenada 1
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada1(b,999,bSize);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero grande con busqueda ordenada 1 con "<<arreglo<<duracion<<endl;


//numero pequeño con busqueda ordenada 2
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(b,bSize,10,2);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero pequeño con busqueda ordenada 2 con "<<arreglo<<duracion<<endl;

//numero grande con busqueda ordenada 2
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(b,bSize,999,2);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero grande con busqueda ordenada 2 con "<<arreglo<<duracion<<endl;


//numero pequeño con busqueda binaria
inicialTiempo = high_resolution_clock::now();
busquedaBinaria(b,0,bSize-1,10);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero pequeño con busqueda bianria con "<<arreglo<<duracion<<endl;
    
//numero pequeño con busqueda binaria
inicialTiempo = high_resolution_clock::now();
busquedaBinaria(b,0,bSize-1,999);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero grande con busqueda bianria con "<<arreglo<<duracion<<endl;

cout<<endl; 

/*Arreglo de 1,000,000*/
cout<<"Arreglo de 1,000,000"<<endl;
arreglo = "arreglo de 1,000,000: ";
//numero pequeño con busqueda secuencial
inicialTiempo = high_resolution_clock::now();
busquedaSecuencial(c,100,cSize);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero pequeño con busqueda secuencial con "<<arreglo<<duracion<<endl;



//numero grande con busqueda secuencial
inicialTiempo = high_resolution_clock::now();
busquedaSecuencial(c,800985,cSize);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero grande con busqueda secuencial con "<<arreglo<<duracion<<endl;



//numero pequeño con busqueda ordenada 1
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada1(c,100,cSize);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero pequeño con busqueda ordenada 1 con "<<arreglo<<duracion<<endl;


//numero grande con busqueda ordenada 1
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada1(c,800985,cSize);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero grande con busqueda ordenada 1 con "<<arreglo<<duracion<<endl;


//numero pequeño con busqueda ordenada 2
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(c,cSize,100,2);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero pequeño con busqueda ordenada 2 con "<<arreglo<<duracion<<endl;

//numero grande con busqueda ordenada 2
inicialTiempo = high_resolution_clock::now();
busquedaOrdenada2(c,cSize,800985,2);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero grande con busqueda ordenada 2 con "<<arreglo<<duracion<<endl;


//numero pequeño con busqueda binaria
inicialTiempo = high_resolution_clock::now();
busquedaBinaria(c,0,cSize-1,100);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero pequeño con busqueda bianria con "<<arreglo<<duracion<<endl;
    
//numero pequeño con busqueda binaria
inicialTiempo = high_resolution_clock::now();
busquedaBinaria(c,0,cSize-1,800985);
fintiempo = high_resolution_clock::now();
duracion=duration_cast<nanoseconds>(fintiempo-inicialTiempo).count();
cout<<"Numero grande con busqueda bianria con "<<arreglo<<duracion<<endl;

cout<<endl; 

    return 0;
}