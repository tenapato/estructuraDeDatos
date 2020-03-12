#include <iostream>
using namespace std;
 


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

class Biblioteca {
    public:
    int idLibro;
    int cantidadLibros;
    int *libros;
    int *prestado;
    int size;

    Biblioteca(int cL);
    Biblioteca(const Biblioteca& original);
    ~Biblioteca();
    void prestar(int libro);
    void devolver(int libro);

};

Biblioteca::Biblioteca(int cL){
    cantidadLibros=cL;
    libros= new int [cantidadLibros]();
    prestado = new int[cantidadLibros]();

    for(int i=0;i<cantidadLibros;i++){
        libros[i]=100000+i;
        prestado[i]=0;
    }
}

Biblioteca::Biblioteca(const Biblioteca& original){
    cantidadLibros=original.cantidadLibros;
    libros=new int [cantidadLibros]();
    prestado = new int[cantidadLibros]();
    for(int i=0;i<cantidadLibros;i++){
        libros[i]=original.libros[i];
        prestado[i]=0;
    }
}

Biblioteca::~Biblioteca(){
    delete[] libros;
    delete[] prestado;
}

void Biblioteca::prestar(int libro){
 int index=busquedaOrdenada2(libros, cantidadLibros, libro, 3);
	if(index==-1){
		cout<<"No contamos con ese libro"<<endl;
		return;
	}
	if(prestado[index]==1){
		cout<<"el libro ya esta prestado"<<endl;
	}else{
		cout<<"libro "<<libro<<" prestado"<<endl;
		prestado[index]=1;//el error es que estaba indicando 0 en vez de 1
	}
}

void Biblioteca::devolver(int libro){
    int index=busquedaOrdenada2(libros, cantidadLibros, libro, 3);
	if(index==-1){
		cout<<"El libro no es de esta biblioteca"<<endl;
		return;
	}
	cout<<"libro "<<libro<<" devuelto"<<endl;
	prestado[index]=0;
}


 int main(){
    
    Biblioteca Ghandhi(50);
	Ghandhi.prestar(50);
	Ghandhi.prestar(100010);
	Ghandhi.prestar(100010);
	Ghandhi.devolver(100010);
	Ghandhi.prestar(100010);
	Ghandhi.devolver(50);
    return 0;
 }