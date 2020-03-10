#include <iostream>

using namespace std;


class Animal{
    public:
        virtual void sonido()=0;

};

class Perro: public Animal{ //clase que esta heredando
    public:
        void sonido();

};

void Perro::sonido(){
    cout<<"guau"<<endl;
}

int main(){

    Perro p;
    p.sonido();

    return 0;
}