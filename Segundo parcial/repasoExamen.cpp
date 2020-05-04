#include <iostream>
#include "vector.cpp"
#include "ListaLigada.cpp"

using namespace std;

class Prueba{
    private:
    Vector<int> va;
    LinkedList<string> lls;

    public:
    Prueba(){
        va=Vector<int>();
        lls=LinkedList<string>();
    }

    void agregarVector(int a){
        va.append(a);
    }
};

int main(){

    Prueba a;
    a.agregarVector(7);

    return 0;
}