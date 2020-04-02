#include <iostream>

using namespace std;



template <class T>
class Sort{
    public:
    virtual void sort(T *a, int size)=0;
   void intercambiar(T *a, int pos1, int pos2){ //este metedo intercambia la pocision de 2 objetos
        T x;
        x = a[pos1];
        a[pos1] = a[pos2];
        a[pos2] = x;
    } 
    void imprimirArreglo(T *a, int size){
        cout<<a[0];
        for(int i=1;i<size;i++){
            cout<<", "<<a[i];
        }
        cout<<endl;
    }
};

template <class T>
class LuckySort: public Sort<T>{ //algoritmo de ordenamiento de ejemplo
	public:
	void sort(T *a, int size){
		this->intercambiar(a, 0, size-1);
	}
};

template <class T>
class SelectionSort: public Sort<T>{
	public:
	void sort(T *a, int size){
		for(int i=0; i<size-1; i++){
			int p=i;
			for(int j=i+1; j<size; j++){
				if(a[j]<a[p]){
					p=j;
				}
			}
			this->intercambiar(a, i, p);
		}
	}
};


template <class T>
class BubbleSort: public Sort<T>{
	public:
	void sort(T *a, int size){
    }
};

template <class T>
class InsertionSort: public Sort<T>{
	public:
	void sort(T *a, int size){

        for(int i=1;i<size;i++){
            for(int j=i;j>0;j--){
                if(a[j]<a[j-1]){
                    this->intercambiar(a,j,j-1);

                } else{
                    break;
                }
            }
        }
    }

};


template <class T>
class MergeSort: public Sort<T>{
	public:
    void sort(T *a, int size){

    }
	void merge(T *a, int inicio, int medio, int fin){
        int tamIzq = medio-inicio+1;
        int tamDer=fin-medio;
        //crear arreglos para copiar
        T copiaIzq[tamIzq];
        T copiaDer[tamDer];
        //Copiar los elementos
        for(int i =inicio; i<tamIzq+inicio; i++){
            copiaIzq[i]=a[i];
        }
    
      for(int i =medio+1; i<tamDer; i++){
            copiaDer[i]=a[i];
        }
        //Inidces
        int I=0;
        int D=0;
        //Comparaciones

    }


};

int main(){
    int size = 5;
    int a[size]={5,4,3,2,1};
    LuckySort<int> s;
    s.imprimirArreglo(a, size);
	s.sort(a, size);
	s.imprimirArreglo(a,size);

    SelectionSort<int> ss;
    ss.imprimirArreglo(a,size);
	ss.sort(a, size);
	ss.imprimirArreglo(a,size);


    InsertionSort<int> is;
    is.imprimirArreglo(a,size);
	is.sort(a, size);
	is.imprimirArreglo(a,size);

    return 0;
}