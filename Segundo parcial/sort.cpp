#include <iostream>

using namespace std;



template <class T>
class Sort{
    public:
    virtual void sort(T *a, int size)=0;
   void intercambiar(T *a, int pos1, int pos2){
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

    return 0;
}