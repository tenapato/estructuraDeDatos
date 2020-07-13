#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>


//BST = map
//diccionario = unorderd map


using namespace std;
template <class T>
class Nodo{
    public:
    T id;
    Nodo<T> *izquierdo;
    Nodo<T> *derecho;

    Nodo(){
        id=NULL;
        izquierdo=NULL;
        derecho=NULL;
    }


    Nodo(T value){
        id=value;
        izquierdo=NULL;
        derecho=NULL;
    }


};

template <class T>
class BST{ //binary search tree
    public:
    Nodo<T> *root;

    BST(){
        root=NULL;
    }


    void insertar(T value){
        Nodo<T> *nuevo = new Nodo<T>(value);

         if(root==NULL){
            root=nuevo;

        }else{
            insertar(nuevo, root);
        }

    }
   

    void insertar(Nodo<T> *nuevo, Nodo<T> *temp){
        if(nuevo->id<temp->id){
            if(temp->izquierdo==NULL){
                temp->izquierdo=nuevo;
            }else{
                insertar(nuevo, temp->izquierdo);
            }

        }else if(nuevo->id>temp->id){
            if(temp->derecho==NULL){
                    temp->derecho=nuevo;
            }else{
            insertar(nuevo, temp->derecho);
        }
            
      }
    
    }


    void recorrido(){
        inorden(root);
        cout<<endl;
    }   

    void inorden(Nodo<T> *temp){
        if(temp==NULL){
            return;
        }
        inorden(temp->izquierdo);
        cout<<temp->id<<", ";
        inorden(temp->derecho);
    }



    bool buscar(T value){
        return buscar(root, value);
    }

    bool buscar(Nodo<T> *temp, T value){
        if(temp==NULL){
            return false;
        }else if(temp->id==value){
            return true;
        }else if(value<temp->id){
            return buscar(temp->izquierdo, value);
        }else{
            return buscar(temp->derecho, value);
        }
    }

    void borrar (T id){
        root = borrar (root, id);
    }



    Nodo<T> *borrar (Nodo<T> *raizS, T id){
        if(raizS==NULL){//el nodo actual no existe
            return NULL;
        }
        if(id<raizS->id){//el valor buscado es menor que el nodo actual
            raizS->izquierdo=borrar(raizS->izquierdo, id);
        }else if(id>raizS->id){//el valor buscado es mayor que el nodo actual
            raizS->derecho=borrar(raizS->derecho, id);
        }else{//el valor buscado es el del nodo actual
            if(raizS->derecho==NULL && raizS->izquierdo==NULL){
                delete(raizS);
                return NULL;
            }else if(raizS->derecho==NULL&&raizS->izquierdo!=NULL){
                Nodo<T> *regreso = raizS->izquierdo;
                delete(raizS);
                return regreso;
            }else if(raizS->derecho!=NULL&&raizS->izquierdo==NULL){
                Nodo<T> *regreso = raizS->derecho;
                delete(raizS);
                return regreso;
        }else{// el nodo a borrar tiene 2 hijos
            Nodo<T> *sustituto = raizS->izquierdo;
            while(sustituto->derecho!=NULL){
                sustituto=sustituto->derecho;
            }
            raizS->id = sustituto->id;
            raizS->izquierdo=borrar(raizS->izquierdo, sustituto->id);
        } 
       
    }
     return raizS;

    }






};


int main(){

    BST<int> a;
    a.insertar(10);
    a.insertar(3);
    a.insertar(11);
    a.insertar(40);
    
    a.recorrido();
    cout<<a.buscar(3)<<endl;
    cout<<a.buscar(7)<<endl;

    a.borrar(3);
    a.recorrido();

    return 0;
}