#include <iostream>
using namespace std;

//metodos de busqueda
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




class Tiendita {
    public:
    int codigoBarras = 0;
    int *articulos;
    int *cantidadInventario;
    int index = 0;
    int cantidadArt = 0;
    int artVender = 0;
    Tiendita(int cB);
    Tiendita(const Tiendita& original); //este contructor de copia genera el catalogo de la otra tiendita con lo sarticulos en valor 0;
    void agregarProducto(int idProd);
    void stock(int id, int cantidad);
    void vender(int idAVender);
};


Tiendita::Tiendita(int cB){
    
    articulos= new int [codigoBarras]();
    cantidadInventario = new int[codigoBarras]();
 
}//constructor que inicializa los codigos de barra de los articulos

void Tiendita::agregarProducto(int idProd){
    codigoBarras = idProd;
    //articulos= new int [codigoBarras]();
    articulos[index]=codigoBarras;
    
    index++;

}//este metodo agrega articulos nuevos


Tiendita::Tiendita(const Tiendita& original){
    codigoBarras=original.codigoBarras;
    articulos=new int [codigoBarras]();
    cantidadInventario = new int[codigoBarras](); //esta parte debe de reiniciar los inventarios a 0
    for(int i=0;i<codigoBarras;i++){
        articulos[i]=original.articulos[i];
        cantidadInventario[i]=0;
    }
}//constructor de copia


void Tiendita::stock(int idABuscar, int cantidad){
    cantidadArt = cantidad;
   int index=busquedaOrdenada2(articulos, codigoBarras, idABuscar, 1);
	if(index==-1){
		cout<<"No tenemos ese producto, por ende no se pude añadir stock"<<endl;
		return;
	}
	if(articulos[index]==1){
        
          
        
		cout<<"Añadido stock al producto "<<idABuscar<<endl;
	}else{
        cantidadInventario[index]=cantidad;
        //index++;
		cout<<"Producto con id "<<idABuscar<<" añadido "<<cantidad<<" de stock"<<endl;
		articulos[index]=1;
	} 
}


void Tiendita::vender(int idAVender){
    artVender = idAVender;
   int index=busquedaOrdenada2(articulos, codigoBarras, idAVender, 1);
	if(index==-1){
		cout<<"No tenemos ese producto, por ende no se pude vender"<<endl;
		return;
	}
	if(articulos[index]==1){
        
		cout<<"Añadido stock al producto "<<idAVender<<endl;

	}else{
        cantidadInventario[index]= cantidadInventario[index] - 1;
        //index++;
		cout<<"Producto con id "<<idAVender<<" se ha vendido 1, cantidad restante: "<<cantidadInventario[index]<<" en stock"<<endl;
		articulos[index]=1;
	} 
}

int main(){
Tiendita t (1000);
t.agregarProducto(1001);
t.agregarProducto(1002);
t.agregarProducto(23);

cout<<t.articulos[1]<<endl;
cout<<t.articulos[2]<<endl;

Tiendita h = t;

cout<<h.articulos[0]<<endl;

t.stock(1001, 15);
t.stock(1002, 3);
t.stock(1003, 1);//debe imprimir un mensaje de que el producto no existe
t.stock(23, 1);

cout<<t.cantidadInventario[0]<<endl;//invetario tienda 1
cout<<h.cantidadInventario[2]<<endl;//inventario tienda 2

t.vender(23);
t.vender(1001);
t.vender(1003);//debe indicar que ese producto no existe
t.vender(23);//debe indicar que no hay existencias de ese producto
t.stock(23, 1);
t.vender(23);
return 0;
} 