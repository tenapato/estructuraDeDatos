#include <iostream>
#include "sort.cpp"
using namespace std;


template <class T>
class Vector{
	private:
		T *a;
		void extender(){
			size=size*2;
			T *temp=new T[size]();
			for(int i=0; i<count; i++){
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
			
		void append(T elemento){
			if(count<size){
				a[count]=elemento;
				count++;
			}else{
				extender();
				append(elemento);
			}
		}
		
		void insert(T elemento, int posicion){
			if(posicion>=count){//caso 1
				append(elemento);
			}else if(count<size){//caso 2
				for(int i=count; i>posicion; i--){
					a[i]=a[i-1];
				}
				a[posicion]=elemento;
				count++;
			}else{//caso 3
				extender();
				insert(elemento, posicion);//llamar para caso 2
			}
		}
		
		void setElemento(T elemento, int posicion){
			if(posicion<count){
				a[posicion]=elemento;
			}
		}
		
		
		
		void imprimir(){
			for(int i=0; i<count; i++){
				cout<<a[i]<<",";
			}
			cout<<endl;
		}
		
		void ordenar(){
			QuickSort<T> quicksort;
			quicksort.sort(a, count);
		}
		
		T removerPosicion(int posicion){
			if(posicion>=count){
				return NULL;
			}
			T elemento=a[posicion];
			for(int i=posicion; i<count; i++){
				a[i]=a[i+1];
			}
			count--;
			return elemento;
		}
		
		void remover(T elemento){
			for(int i=0; i<count; i++){
				if(elemento==a[i]){
					removerPosicion(i);
					return;
				}
			}
		}
		
};

/*
int main(){
	Vector<int> v(10);
	v.append(3);
	v.imprimir();
	cout<<"count: "<<v.count<<", size: "<<v.size<<endl;
	v.append(2);
	v.imprimir();
	cout<<"count: "<<v.count<<", size: "<<v.size<<endl;
	v.insert(0, 1);
	cout<<"count: "<<v.count<<", size: "<<v.size<<endl;
	v.imprimir();
	v.insert(6, 1);
	v.imprimir();
	v.remover(3);
	v.imprimir();
} */