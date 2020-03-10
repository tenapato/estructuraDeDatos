#include <iostream>
using namespace std;


int busquedaSecuencial(int *arreglo, int buscado, int size){
    for(int i = 0; i<size;i++){
        if(arreglo[i]==buscado){
            return i; //si lo encuentra
            break;
        }
    }
    return -1; //si no lo encuentra 　これはすごいコッドですね!
}

class Paciente{
    public:
    int id;
    string nombre;
    int edad;
    string enfermedad;
};

class Hospital{
    private:
        int* camas;
        Paciente* pacientes; //usas un apuntador a array cuando quieres que sea dinámico
        int camaDisponible;
    public:
        int numCamas;
        Hospital(int numCamas);
        void asignarPaciente(int id, string nombre, int edad);
        void asignarEnfermedad(int id, string enfermedad);
};

Hospital::Hospital(int nCamas){
    numCamas=nCamas;
    camas=new int[numCamas]();
    pacientes = new Paciente[numCamas]();
    camaDisponible=0;
}


void Hospital::asignarPaciente(int id, string nombre, int edad){
    if(camaDisponible>=numCamas){
        cout<<"No hay camas disponibles"<<endl;
        return;
    }
    camas[camaDisponible]=id;
    pacientes[camaDisponible].nombre=nombre;
    pacientes[camaDisponible].id=id;
    pacientes[camaDisponible].edad=edad;
    camaDisponible++;
}

void Hospital::asignarEnfermedad(int id, string enfermedad){
    int cama=busquedaSecuencial(camas, id, numCamas);
    if(cama!=-1){
        pacientes[cama].enfermedad=enfermedad;
    }
}
int main(){


    return 0;
}