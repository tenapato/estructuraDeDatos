#include <iostream>

using namespace std;

template <class T>
class Nodo{
    public:
    T value;
    Nodo<T> *next;
    Nodo<T> *prev;

    Nodo(T value){
        this->value=value;
        next=NULL;
        prev=NULL;
    }

    Nodo(){
        this->value=NULL;
        next=NULL;
        prev=NULL;
    }

};



template <class T>
class DoubleLinkedList{
    public:
    Nodo<T> *root;
    int count;
    DoubleLinkedList(){
        count=0;
        root=NULL;
    }
    void append(Nodo<T> *toAdd);
    void append(T value);
    void imprimir();
    void insert(Nodo<T> *toAdd, int pos);
    void remover(T value);
    void removerPos(int pos);
};



template <class T>
void DoubleLinkedList<T>::append(Nodo<T> *toAdd){
    if(root==NULL){
        root=toAdd;
        return;
    }
    Nodo<T> *temp=root;
    while(temp->next!=NULL){
        temp=temp->next;

    }
    temp->next=toAdd;
    toAdd->prev=temp;
    count++;

}

template <class T>
void DoubleLinkedList<T>::insert(Nodo<T> *toAdd, int pos){
    if(root==NULL || pos>= count){
        append(toAdd);
        return;
    }
    if(pos==0){
        root->prev=toAdd;
        toAdd->next=root;
        root=toAdd;
        count++;
    }else{
        Nodo<T> *temp=root;
        int c=0;
        while(temp->next!=NULL&&c<pos){
            temp=temp->next;
            c++;
        }
        toAdd->prev=temp->prev;//1
        toAdd->next=temp;//2 
        temp->prev->next=toAdd;
        temp->prev=toAdd;
    }
}

template <class T>
void DoubleLinkedList<T>::imprimir(){
    Nodo<T> *temp=root;
    while(temp!=NULL){

        cout<<temp->value<<",";
        temp=temp->next;
    }
    cout<<endl;
}

template <class T>
void DoubleLinkedList<T>::append(T value){
    Nodo<T> *toAdd=new Nodo<T>(value);
    append(toAdd);


}


template <class T>
void DoubleLinkedList<T>::removerPos(int pos){
    Nodo<T> *temp=root;
    int c= 0;
    while(temp!=NULL){
        if(c==pos){
            //t1->next=t3;
            temp->prev->next=temp->next;
            //t3-prev->t1
            temp->next->prev=temp->prev;
            count--;
            delete temp;
            return;
        }else{
            temp=temp->next;
            c++;
        }
    }
}

template <class T>
void DoubleLinkedList<T>::remover(T value){
    Nodo<T> *temp=root;
    int c= 0;
    while(temp!=NULL){
        if(temp->value==value){
            //t1->next=t3;
            temp->prev->next=temp->next;
            //t3-prev->t1
            temp->next->prev=temp->prev;
            count--;
            delete temp;
            return;
        }else{
            temp=temp->next;
            c++;
        }
    }
}

void sort(){
    Nodo<T> *posI=root;
}

int main(){
    DoubleLinkedList<int> dll;
    dll.append(2);
    dll.append(3);
    dll.append(1);
    dll.imprimir();
    dll.removerPos(1);
    dll.imprimir();
    //dll.remover(1);
    dll.imprimir();
    return 0;
}