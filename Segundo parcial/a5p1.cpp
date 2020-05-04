#include <iostream>
#include <ctime>
#include "vector.cpp"
#include "sort.cpp"
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


int busquedaSecuencial(int *arreglo, int buscado, int size){
    for(int i = 0; i<size;i++){
        if(arreglo[i]==buscado){
            return i; //si lo encuentra
            break;
        }
    }
    return -1; //si no lo encuentra 　これはすごいコッドですね!
}

class Tienda{
    public:
    int *articulos;
    int cantidadProductos = 0;
    int count = 1;
    int size;
    int con = 0;
    int n,i,j;
	int temp;
    Tienda(int prod);
    void verificar(int idABuscar); //permite verificar si el id de un producto esta registrado
    void agregar(int numAagregar);//metodo que agrega un nuevo articulo

    void imprimirPrueba(){
        for(int i = 0; i<1500; i++){
             cout<<articulos[i]<<endl; 
        }
    }

    void verificar2(int idABuscar); //este metodo utiliza busqueda secuancial para buscar cuando el arreglo no este ordenado
    
    void cantidad(int idUno, int idDos);
  
};


Tienda::Tienda(int prod){
    
    srand(time(NULL));
    cantidadProductos = prod;
    articulos = new int [cantidadProductos]( );
    
    
         for(int i=0; i<prod;i++){

        if(i<=1300){ //este if controla que solo sellene 1300 articulos
             articulos[i]= rand()%2000000 ;
            //cout<<articulos[i]<<endl; 
        } else if(i>=1300){ //cuando pase los 1300 se quedaran vacios esos espacios
            articulos[i] = 0;
        }   

    }

       
    
   
 
 
}//constructor que inicializa los productos




void Tienda::verificar(int idABuscar){

   if( busquedaBinaria(articulos, 0, cantidadProductos, idABuscar) == -1){
       cout<<"No se encontro el articulo"<<endl;
   }
    else{
       cout<<"El articulo si ha sido verificado"<<endl;
   }
}


void Tienda::agregar(int numAagregar){
    con = 1300 + count;
  
   

    articulos[con] = numAagregar;
    //cout<<con<<endl;
    count++;
}

 void Tienda::verificar2(int idABuscar){
     if( busquedaSecuencial(articulos, idABuscar, size) == -1){
       cout<<"No se encontro el articulo"<<endl;
   }
    else{
       cout<<"El articulo si ha sido verificado"<<endl;
   }
}
 


 /*El metodo que agrega un articulo si funciona pero no aparece en el de vrificar porque no pude hacer uqe el arreglo se ordene*/



void Tienda::cantidad(int idUno, int idDos){
    int ichi = 0;
    int ni = 0;
    int res = 0;
    int f = 0;
    int temp = 0;
    ichi = busquedaSecuencial(articulos,idUno, size);
    ni = busquedaSecuencial(articulos,idDos, size);

    //cout<<ichi<<endl;
    //cout<<ni<<endl;
    

    if(ni<ichi){
         res = ichi - ni;
        f = res+1;//le sumo uno para reemplazar el primer lugar que no esta siendo contado
    }
    
    else{
        res = ni - ichi;
        f = res+1;//le sumo uno para reemplazar el primer lugar que no esta siendo contado
    }

    
    
    

    cout<<"Entre el articulo "<<idUno<<" y el articulo: "<<idDos<<" tendriamos: "<<f<<" productos"<<endl;
}

int main(){

    Tienda a(1500);
    //a.imprimirPrueba();
    
    a.verificar(1528047); //si el numero se genera en el arrego, dira que esta verificado

    a.agregar(1528047);
    a.agregar(1);
    a.agregar(14);
    a.agregar(1000);
    /*Si se imprime el arreglo se puede ver que los numeros si se van agregando*/
    a.imprimirPrueba();
    a.verificar(1000);
    a.verificar2(1000); //Podemos ver como con este tipo de busqueda el articulo si es encontrado
    a.verificar2(1528047);


    //Para que el metodo cantidad funcione el idUno tiene que estar antes en el arreglo que id 2, se intento arreglar pero no se pudo
    a.cantidad(14, 1000);
    a.cantidad(1528047, 1000);
    a.cantidad(1, 1000);
    
   // a.cantidad(1000, 1);
    return 0;
}