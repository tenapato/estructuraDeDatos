#include <iostream>
#include <vector>
using namespace std;

template <class K, class V>
class KeyPair{
	public:
	K key;
	V value;
	
	KeyPair(){
		key=NULL;
		value=NULL;
	}
	
	KeyPair(K key, V val){
		this->key=key;
		this->value=val;
	}
};

template <class K, class V>
class Dictionary{
	public:
	vector<KeyPair<K,V>> *dict;
	int positions;
	
	Dictionary(){
		positions=10;
		dict=new vector<KeyPair<K,V>>[positions];
	}
	
	Dictionary(int pos){
		positions=pos;
		dict=new vector<KeyPair<K,V>>[positions];
	}
	
	void insert(K key, V value){
		KeyPair<K,V> kp(key, value);
        int hash=key%positions;
        for(int i=0; i<dict[hash].size(); i++){
            if(dict[hash][i].key==key){
                return;
            }
        }
        dict[hash].push_back(kp);
	}
	
	V checkAtKey(K key){
        int hash=key%positions;
        for(int i=0; i<dict[hash].size(); i++){
            if(dict[hash][i].key==key){
                return dict[hash][i].value;
            }
        }
        return NULL;
	}
	
	void printDictionary(){
		
		for(int i=0; i<positions;i++){  
			cout<<"["<<i<<"]:";
			for(int a=0; a<dict[i].size(); a++){
				cout<<"("<<dict[i][a].key<<", "<<"'"<<dict[i][a].value<<"'"<<")";
			}
			cout<<endl;
		}
		
	}
};


template <class T>
class KeySola{
	public:
	T key;
	
	KeySola(){
		key=NULL;
	}
	
	KeySola(T key){
		this->key=key;
	}
};


template <class T>
class Set{
	public:
	vector<KeySola<T>> *set;
	int positions;

	Set(){
		positions=10;
		set=new vector<KeySola<T>>[positions];
	}
	
	Set(int pos){
		positions=pos;
		set=new vector<KeySola<T>>[positions];
	}
	
	
	void insert(T key){
		
        int hash=key%positions;
		
         for(int i=0; i<set[hash].size(); i++){
            if(set[hash][i].key==key){
                return;
            }
        }
        set[hash].push_back(key);
	}


	void printSet(){
		
		for(int i=0; i<positions;i++){  //lo intente hacer con iteradores pero no me salio, tambien trate lo de ->firs y second pero tampcoo pude
			cout<<"["<<i<<"]:";
			for(int a=0; a<set[i].size(); a++){
				cout<<"("<<set[i][a].key<<")";
			}
			cout<<endl;
		}
		
	}

	void find(T key){
		int hash=key%positions;
		for(int i=0; i<set[hash].size(); i++){
            if(set[hash][i].key==key){
                cout<<"La llave "<<set[hash][i].key<<" si se encuentra en el set"<<endl;
				return;
            }
	
			

        }
		cout<<"La llave "<<key<<" no existe dentro del set"<<endl;
		
	}

};

int main(){
	Dictionary<int, string> a;
    a.insert(1501, "adios");
    a.insert(301, "nuevo");
	a.insert(23, "nuevo");
	a.insert(15, "hola");
	a.insert(9, "gato");
	a.insert(5, "Oaxaca");
    //cout<<a.checkAtKey(1501)<<endl;
	a.printDictionary();

	cout<<"Ahora el Set"<<endl;
	Set<int> s;
	s.insert(1501);
	s.insert(301);
	s.insert(23);
	s.insert(15);
	s.insert(9);
	s.insert(5);
	s.printSet();
	s.find(23);
	s.find(32);
	s.find(1501);


}