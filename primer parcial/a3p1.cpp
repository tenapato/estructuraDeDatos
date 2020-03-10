#include <iostream>

using namespace std;



class Figura{
    public:
    double perimetro;
    double area;

    virtual void calcularPerimetro()=0;
    virtual void calcularArea()=0;

};

class Triangulo: public Figura{
    public:
    void calcularPerimetro();
    void calcularArea();
};

void Triangulo::calcularPerimetro(){
   
    double lado=0;
    cout<<"Ingese el valor del lado del triangulo: ";

    cin>>lado;
    perimetro = lado*3;
    cout<<"El perimetro es: "<<perimetro<<endl;
}

void Triangulo::calcularArea(){
    double base = 0;
    double altura = 0;

    cout<<"Ingrese la base del triangulo "<<endl;
    cin>>base;
    cout<<"Ingrese la altura del triangulo"<<endl;
    cin>>altura;
    area = base*altura;
     cout<<"El area es: "<<area<<endl;

}


class Cuadrado:public Figura{
    public:
    void calcularPerimetro();
    void calcularArea();

};

void Cuadrado::calcularPerimetro(){
   
    double lado=0;
    cout<<"Ingese el valor del lado del cuadrado: ";

    cin>>lado;
    perimetro = lado*4;
    cout<<"El perimetro es: "<<perimetro<<endl;
}

void Cuadrado::calcularArea(){
    double base = 0;
    

    cout<<"Ingrese la base del cuadrado"<<endl;
    cin>>base;
    area = base*base;
     cout<<"El area es: "<<area<<endl;

}


int main(){

Triangulo tri;
tri.calcularPerimetro();
tri.calcularArea();
Cuadrado cua;
cua.calcularPerimetro();
cua.calcularArea();
}