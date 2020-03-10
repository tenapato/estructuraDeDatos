#include <string>
#include <iostream>

using namespace std;


class ejemplo{

public:
  string nombre;
  ejemplo(){
    cout<<"Dame el nombre del estudiante: ";
    getline(cin, nombre);
  }

};

int main(){

  int num;
  cin>>num;
  string *materias=new string[num]();
  materias[2]="estructura de datos";
  cout<<materias[2]<<endl;










  return 0;
}