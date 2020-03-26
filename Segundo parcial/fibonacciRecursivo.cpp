#include <iostream>
using namespace std;

int fibonacci(int n) {
   if((n==1)||(n==0)) {
      return(n);
   }else {
      return(fibonacci(n-1)+fibonacci(n-2));
   }
}

int fibonacciBuscar(int n) {
    int x, y;
    y = x-1;
   if((n==x)||(n==y)) { //esta parte llega hasta el numero que se queire buscar
      return(n);
   }else {
      return(fibonacci(n-1)+fibonacci(n-2));
   }
}


int main() {
   int tamSecuencia = 15;
   int i=0;
   int j=0;
   int numABuscar = 0;
   
   //ESto imprime la secuencia fibonacci aunque no era necesario, sin embargo hice esto primero para entender como funcionaba la recursion en esta secuencia
   while(i < tamSecuencia) {
      cout << " " << fibonacci(i);
      i++;
   }

    // Esto busca el numero en el indice indicado
    cout<< "\n Ingrese la posicion del número que desea saber "<<endl;
    cin>>numABuscar;
    cout<<fibonacci(numABuscar)<<endl;
    

   return 0;
}
