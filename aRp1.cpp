#include <iostream>
using namespace std;


class Avion{

    public:
    int numAsientos;
    int *pasajeros;

  Avion(int asientosDisponibles){
    numAsientos = asientosDisponibles;
    pasajeros = new int [numAsientos]();
    for(int i =0; i<numAsientos;i++){
        pasajeros[i]=0;
    }
  }

    
    void checkIn(int numPasajero, int numAsiento){
        pasajeros[numAsiento]=numPasajero;
    }//end metodo checkIn

    int verificar(int numPasajero){
        for(int i=0;i<numAsientos;i++){
            if(pasajeros[i]==numPasajero){
                return 1;;
            }//end if
        }//end metodo verificar
        return -1;
    }

    
    ~Avion(){
        delete[] pasajeros;
    }

};//end clase avion



int main()
{
    int asientosRestantes = 15;
    Avion interjet (asientosRestantes);

    interjet.checkIn(353, 0);
    interjet.checkIn(5612, 6);
    cout<<interjet.verificar(12)<<endl;
    cout<<interjet.verificar(5612)<<endl;
    

    return 0;
}
