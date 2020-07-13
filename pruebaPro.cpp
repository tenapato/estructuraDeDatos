#include <iostream>

using namespace std;






int main(){

    int size = 11;
    int *escenas;
    int input;
    escenas = new int [size]();

    escenas[0] = 0;
    escenas[1] = 1;
    escenas[2] = 2;
    escenas[3] = 3;
    escenas[4] = 4;
    escenas[5] = 5;
    escenas[6] = 6;
    escenas[7] = 7;
    escenas[8] = 8;
    escenas[9] = 9;
    escenas[10] = 10;
   

    
 

       


  

    //Primer input
    cout<<"Ingrese a que escena quiera pasar: "<<endl;
    cin>>input;
    
    switch (input)
    {
        //Escena 1
    case 0:
        cout<<"Esta es la escena 0:"<<escenas[0]<<endl;
        

        cout<<"A que escena quieres ir: "<<endl;
        cin>>input;
        switch (input)
        {
        case 1:
            cout<<"Esta es la escena: "<<escenas[input]<<endl;
            break;
        
        case 2:
            cout<<"Esta es la escena: "<<escenas[input]<<endl;
            break;
        case 3:
            cout<<"Esta es la escena: "<<escenas[input]<<endl;
            break;
        default:

        cout<<"Esa escena no existe"<<endl;
            cout<<"A que escena quieres ir: "<<endl;
        cin>>input;


        } 

    
    default:
        break;
    } //fin switch 1







    return 0;
}