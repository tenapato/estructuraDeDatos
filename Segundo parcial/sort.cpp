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
        sortAux(a, 0, size-1);
	}

    private:
    void sortAux(T *a, int inicio, int fin){
        if(inicio>=fin){
            return;
        }
        int medio = (fin+inicio)/2;
        sortAux(a, inicio, medio);
        sortAux(a, medio+1, fin);
        merge(a,inicio, medio, fin);
    }


	void merge(T *a, int inicio, int medio, int fin){
		//Tam de la copia
		int tamIzq=medio-inicio+1;
		int tamDer=fin-medio;

		//Crear espacio para copia
		T *copiaIzq=new T[tamIzq]();
		T *copiaDer=new T[tamDer]();
		//Copiando los elementos
		for(int i=0; i<tamIzq; i++){
			copiaIzq[i]=a[inicio+i];
		}
		for(int i=0; i<tamDer; i++){
			copiaDer[i]=a[medio+1+i];
		}
		//Indices
		int I=0;
		int D=0;
		int x=inicio;
		//Comparaciones
		while(I<tamIzq&&D<tamDer){
			if(copiaIzq[I]<copiaDer[D]){
				a[x]=copiaIzq[I];
				I++;
			}else{
				a[x]=copiaDer[D];
				D++;
			}
			x++;
		}
		if(I==tamIzq){
			while(D<tamDer){
				a[x]=copiaDer[D];
				D++;
				x++;
			}
		}else{
			while(I<tamIzq){
				a[x]=copiaIzq[I];
				I++;
				x++;
			}
		}	
	}
};






template <class T>
class QuickSort: public Sort<T>{
	public:
	void sort(T *a, int size){
		sortAux(a, 0, size-1);
	}
	
	private:
	void sortAux(T *a, int inicio, int fin){
		if(fin<=inicio){
			return;
		}
		int v=partition(a, inicio, fin);
		sortAux(a, inicio, v-1);
		sortAux(a, v+1, fin);
	}
	
	int partition(T *a, int inicio, int fin){
		int v=inicio;
		int lo=v+1;
		int hi=fin;
		while(true){
			while(a[lo]<a[v] && lo<=fin){
				lo++;
			}
			while(a[hi]>a[v]&&hi>=inicio){
				hi--;
			}
			if(lo>=hi){
				break;
			}
			this->intercambiar(a, lo,hi);
		}
		this->intercambiar(a, v, hi);
		return hi;
	}
};

/*int main(){
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

    MergeSort<int> ms;
	ms.imprimirArreglo(a, size);
	ms.sort(a, size);
	ms.imprimirArreglo(a,size);

	QuickSort<int> qs;
	qs.imprimirArreglo(a, size);
	qs.sort(a, size);
	qs.imprimirArreglo(a,size);
    return 0;
} */