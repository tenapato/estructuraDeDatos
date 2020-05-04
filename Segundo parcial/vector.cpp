#include <iostream>
//#include "sort.cpp"
using namespace std;

template <class T>
class Vector{
    private:
        T *a;
        void extender(){
            size=size*2;
            T *temp=new T[size]();
            for(int i=0;i<count; i++){
                    temp[i]=a[i];
                }
            delete [] a;
             a=temp;
        }
    public:
        int size;
        int count;
        Vector(){
            a=new T[1024]();
            count=0;
        }

        Vector(int s){
            size=s;
            a=new T[s]();
            count=0;
        }

        void append(T elemento){ //agrega el elemento al final
            if(count<size){
                a[count]=elemento;
                count++;
            }else{
                extender();
                append(elemento);
            }
        }


        void insert(T elemento, int posicion){ //agrega el elemento en n posicion
            if(posicion>=size){
                append(elemento);
            }else if(count<size){
                for(int i=count; i>posicion;i--){
                    a[i]=a[i-1];
                }
                a[posicion]=elemento;
                count++;
            }
        }


        void imprimir(){
            for(int i=0; i<count;i++){
                cout<<a[i]<<",";
            }
            cout<<endl;
        }

    
     /*void ordenar(){
         QuickSort<T> quicksort;
         quicksort.sort(a, count);
     }*/


    void setElemento(T elemento, int posicion){
			if(posicion<count){
				a[posicion]=elemento;
			}
		}
		
		T getElemento(int posicion){
			if(posicion<count){
				return a[posicion];
			}
			return NULL;
		}


    T removerPosicion(int posicion){ //remueve un elemnto por su posicion
        if(posicion>=count){
            return NULL;
        }
        T elemento = a[posicion];
        for(int i=posicion; i<count; i++){
            a[i]= a[i+1];
        }
        count--;
        return elemento;
    }


    void remover(T elemento){ //remueve un elemento
        for(int i = 0; i<count;i++){
            if(elemento==a[i]){
                removerPosicion(elemento);
                return;
            }
        }
    }





};


/*
int main(){
    Vector <int> v(10);
    v.append(3);
    v.imprimir();
    cout<<"count: "<<v.count<<" size: "<<v.size<<endl;
    v.append(2);
    v.imprimir();
    cout<<"count: "<<v.count<<" size: "<<v.size<<endl;
    v.append(1);
    v.imprimir();
    cout<<"count: "<<v.count<<" size: "<<v.size<<endl;

    v.ordenar();
    v.imprimir();

    v.insert(0, 1);
    v.imprimir();

    v.removerPosicion(1);
    v.imprimir();

    v.remover(3);
    v.imprimir();
    return 0;
}*/