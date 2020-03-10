#include <iostream>

using namespace std;


class Estudiante{
    public:
    string nombre;
    string matricula;
   int size = materias;
   //int *a = 0;
    void crearHorario(int materias){
        
        horario=new int[materias]();
        cout<<"Registrado! El numero de materias a llevar el alumno: "<<nombre<< " es: "<<materias<<endl;
        cout<<"Ahora, ingrese el horario de cada materia :"<<endl;
       for(int i=0;i<materias;i++){
           cin>>horario[i];
       }
    
    }
    public:
    int* horario;
    
    public:
    
    Estudiante (){

    }


     Estudiante(const Estudiante& deDondeViene){ //Este constructor sirve para que el arreglo copia tenga un espacio de memoria diferente, y por ende, puede tener valores diferentes
        size = deDondeViene.size;
        //a=new int[size]();
        for(int i=0; i<size; i++){
            horario[i]=deDondeViene.horario[i];
        }
    }
    
    ~Estudiante(){
        delete[]materias;
    }

};


int main(){
Estudiante a;
int materias;
string copia;
a.nombre = "Roberto";
a.matricula = "A0123";
cout<<"Ingrese el numero de materias a llevar"<<endl;
cin>>materias;
a.crearHorario(materias);

Estudiante b;
b.nombre = "Maria";
b.matricula = "A0146";

cout<<"Para el alumno "<<b.nombre<<" desea copiar el horario de "<<a.nombre<< " ?"<<endl;
cin>>copia;
if (copia == "si"){
    Estudiante b = a;
}
else {
    cout<<"Ingrese el numero de materias a llevar"<<endl;
    cin>>materias;
    b.crearHorario(materias);
}


//cout<<a.horario[2]<<endl;
//cout<<b.horario[2]<<endl;

return 0;
}