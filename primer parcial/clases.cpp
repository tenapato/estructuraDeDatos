#include <iostream>
using namespace std;

class Ejemplo{
    public: 
        int a=1;
    private:
        int b=2;
    protected:
        int c=3;
};

class Hijo: public Ejemplo{

    public: 
    Hijo(int valor){
        a=valor;
    }
};



int main(){
    Ejemplo e;
    Hijo h(10); 
    cout<<h.a<<endl;
    return 0;
}