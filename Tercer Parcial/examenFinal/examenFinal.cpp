#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <map>



using namespace std;

/*----------------------------Grafos-----------------------------*/
template <class T>
class Nodo{
	public:
	T id;
	unordered_map<Nodo<T> *, int> arcos;
	
	Nodo(){
		id=NULL;
	}
	
	Nodo(T value){
		id=value;
	}
	
	void agregarArco(Nodo<T> *next, int peso){
		arcos[next]=peso;
	}
	
	void agregarArco(Nodo<T> *next){
		arcos[next]=1;
	}
	
	void print(){
		string i=id;
        cout<<i;
        cout<<endl;
        for(auto i: arcos){
            cout<<i.second;
            cout<<", ";
            cout<<i.first->id;
            cout<<endl;
        }
	}
	
};

template <class T>
class Graph{
	public:
	unordered_map<T, Nodo<T> *> vertices;
	
	void agregarVertice(T id){
		Nodo<T> *nuevo=new Nodo<T>(id);
		if(vertices.find(id)==vertices.end()){
			vertices[id]=nuevo;
		}else{
			//cout<<"el nodo ya existe"<<endl;
		}	
	}
	
	void agregarArco(T idFuente, T idDestino, int peso){
		vertices[idFuente]->agregarArco(vertices[idDestino],peso);
		//vertices[idDestino]->agregarArco(vertices[idFuente],peso);
	}
	
	void imprimirGrafo(){
		for(auto i: vertices){
			i.second->print();
		}
	}

    
    
  
	
};
/*-------------------------Fin Grafos-----------------------------*/


/*-------------------------Dict-----------------------------*/

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

/*-------------------------Fin Dict-----------------------------*/







struct Data{
    string user1;
    int inter;
    string user2;
    
    Data(string u1, int i, string u2){
        user1=u1;
        inter=i;
        user2=u2;
    }
};

vector<Data> interacciones;

void leerData(string path){
    ifstream fIn;
    fIn.open(path);
    string temp, line, parts;
    vector<string> valores;
    while(fIn.good()){
        getline(fIn, line); 
        istringstream s(line); 
        while (getline(s, parts, ',')) { 
                valores.push_back(parts);
         }
         interacciones.push_back(Data(valores[0], stoi(valores[1]), valores[2].substr(0, valores[2].size()-1)));
         valores.clear(); 
    }
    fIn.close();
}

class Objeto{
	public:
	string a;
	string b;
	
	Objeto(){
		a="";
		b="";
	}
	
	Objeto(string a, string b){
		this->a=a;
		this->b=b;;
	}
};

class Set1{

    //Ejercicio 1.1
    public:
    void usuarioExistente(string us){
        unordered_set <string> usuarios;


     
                        
        for(auto i: interacciones){
            usuarios.insert(i.user1);
            usuarios.insert(i.user2);
       
        }
    
      /*  for(auto j = usuarios.begin(); j != usuarios.end(); j++){
            cout<<(*j)<<endl;
        } */
       
       if (usuarios.find(us) == usuarios.end()) 
        cout << us << " no existe" << endl << endl ; 
        else
        cout << "Si existe " << us << endl << endl ;
       
        //cout<<usuarios.size()<<endl;
    }

    //Ejercicio 1.2

    /*
    void esSeguidor(string us1, string us2){
   
    
    unordered_map <string, vector<string>>usuarios2;

    vector<string> a;
    

	usuarios2.insert(make_pair("Suller9", usuarios2->));
   
 
    //usuarios2.insert(make_pair(0, );
           

   
        
       
        
         for (auto itr = usuarios2.begin(); itr != usuarios2.end(); itr++) 
    { 
       
        cout << itr->first << "  " << itr->second << endl; 
     } 


*/
     

   
    
    


//}


};//Agrega aqui los datos y metodos para resolver los problemas del set 1


class Set2{
public:


//Problema 2.2
    void mayorInterraccion(string usuario){
    Graph<string> a;


      int count = 0;
      int cont = 0;

      vector<string> encontrados;
        for(auto i: interacciones){
            //cout<<i.user1<<endl;
            int j = 0;
           // cout<<i.user2<<endl;
          //  a.agregarVertice(i.user2);
           a.agregarVertice(i.user1);
           a.agregarVertice(i.user2);
           a.agregarArco(i.user1, i.user2, 0);
           a.agregarArco(i.user2, i.user1, 0);

           if(i.user1 == usuario) {
             
            encontrados.push_back(i.user2);    
           } if(i.user2 == usuario){
            encontrados.push_back(i.user1);
            }
          

        
            if(i.user1 == usuario){
                if(i.user2 == usuario){
                    count++;
                }
                
            } else if(i.user2 == usuario){
                count++;
            }
            
           
     }  

       /* for(int i = 0; i<encontrados.size();i++){
                cout<<encontrados[i]<<endl;
            } */

        //Guardo los datos en un mapa para poder asociar cuantas veces inteactua con quien,no pude modificar el arco
        // Falta arregalr cuando 2 o mas tienen la misma cantidad de interacciones 
        unordered_map<string, int> cuenta;

        int num = 1;
        for(int i =0; i<encontrados.size();i++){
            if(cuenta.find(encontrados[i]) == cuenta.end()){
                cuenta.insert(make_pair(encontrados[i], num));
            }else{
                cuenta.at(encontrados[i])+=1;
            }
            
        }
        
         for (auto itr = cuenta.begin(); itr != cuenta.end(); itr++) 
    { 
        
        //cout << itr->first << "  " << itr->second << endl; 
     } 
    

   

    string masGrande = "";
    int grande = 0;
    for (auto itr = cuenta.begin(); itr != cuenta.end(); itr++){
        if(itr->second>grande){
            masGrande = itr->first;
            grande = itr->second;
        }
    }

cout << "Con el que más interactua es: " << masGrande << ", interactua: " << grande << " veces " << endl;

   // a.imprimirGrafo();
	//cout<<count<<endl;
   





  
    }
    

   



};//Agrega aqui los datos y metodos para resolver los problemas del set 2

class Set3{
public:



//Ejercicio 3.1
 void mayorSeguidor(){
     
    Graph<string> b;
    map<int, string> seguidos; 
    int count = 0;
    int compartir_0 = 0;
    int comentar_1 = 0;
    int sigue = 0;
    unordered_set<string> uss; //el set sirve para guardar usuarios unicos
    vector<string>users; //el vector sirve para iterar esos usuarios y contar a cuantos siguen
    vector<string>masInteractua;
    for(auto i: interacciones){
        uss.insert(i.user1);
        uss.insert(i.user2);
    }

    for (auto i = uss.begin(); i != uss.end(); i++) {
      //  cout << (*i) << endl; 
        users.push_back(*i);
    }  

  /*  for (auto i = users.begin(); i != users.end(); ++i) {
        cout << *i << " "; 
    } */
        
 
            for(int j = 0; j<users.size(); j++){

            sigue = 0;

            for(auto i: interacciones){   
            b.agregarVertice(i.user1);
            b.agregarVertice(i.user2);

             if((i.user1 == users[j]) && (i.inter == 0)){ //si el usuario comenta quiere decir que lo sigue por ense se le suma

                 compartir_0++;
                // count++;

            }else if((i.user1 == users[j]) && (i.inter == 1)){ //si comprate, los 2 se siguen, por ende se suma
                
                comentar_1++;
            }   
            else if((i.user2 == users[j]) && (i.inter == 1)){ //le comentan por ende igual sigue de vuelta
                
                comentar_1++;
            }  
                
        }//fin del for
         
            sigue = compartir_0 + comentar_1;
            //cout<<sigue<<endl;
            seguidos.insert(pair<int, string>(sigue, users[j]));
            sigue = 0;
            compartir_0 = 0;
            comentar_1 = 0;

            
        }


   // cout<<compartir_0<<endl;
   // cout<<comentar_1<<endl;

    //------------------------------------------------este  for imprime el arbol -descomentar para verlo-----------------------------------------------------------
     /*       for (auto i = seguidos.begin(); i != seguidos.end(); ++i) { 
        cout << "Seguidos: " << i->first 
             << '\t' << i->second << '\n'; 
    } 
    cout << endl; */




    string masGrande = "";
    int grande = 0;
    for (auto itr = seguidos.begin(); itr != seguidos.end(); itr++){
        if(itr->first>grande){
            masGrande = itr->second;
            grande = itr->first;
        }
    }   

    cout << "El usuario que más cuentas sigue es: " << masGrande << ", siguiendo a: " << grande << " cuentas " << endl;

 }//fin metodo mayorSeguidor



//Ejercicio 3.2

void amplificador(){

Graph<string> c;
    map<int, string> comparte; 
    
    int compartir_0 = 0;
  //  int comentar_1 = 0;
    int sigue = 0;
    unordered_set<string> us; //el set sirve para guardar usuarios unicos
    vector<string>users2; //el vector sirve para iterar esos usuarios y contar a cuantos siguen

    for(auto i: interacciones){
        us.insert(i.user1);
        us.insert(i.user2);
    }

    for (auto i = us.begin(); i != us.end(); i++) {
      //  cout << (*i) << endl; 
        users2.push_back(*i);
    }  

  /*  for (auto i = users.begin(); i != users.end(); ++i) {
        cout << *i << " "; 
    } */
        
 
            for(int j = 0; j<users2.size(); j++){

            

            for(auto i: interacciones){   
            c.agregarVertice(i.user1);
            c.agregarVertice(i.user2);

             if((i.user1 == users2[j]) && (i.inter == 0)){ //si el usuario comenta quiere decir que lo sigue por ense se le suma

                 compartir_0++;
             }
                
        }//fin del for
         
           // sigue = compartir_0 + comentar_1;
            comparte.insert(pair<int, string>(compartir_0, users2[j]));
           // cout<<compartir_0<<endl;
            compartir_0 = 0;
           
        }
     

   // cout<<compartir_0<<endl;
   // cout<<comentar_1<<endl;

    //------------------------------------------------este  for imprime el arbol -descomentar para verlo-----------------------------------------------------------
       /*     for (auto i = comparte.begin(); i != comparte.end(); ++i) { 
        cout << "Compartidos: " << i->first 
             << '\t' << i->second << '\n';  
    } */
    cout << endl; 

    string masGrande = "";
    int grande = 0;
    for (auto itr = comparte.begin(); itr != comparte.end(); itr++){
        if(itr->first>grande){
            masGrande = itr->second;
            grande = itr->first;
        }
    }

    cout << "El usuario que más comparte: " << masGrande << ", con: " << grande << " compartidas " << endl;


} //fin metodo amplificador

//Ejercicio 3.3

void llamarCallado(){

    Graph<string> c;
    map<int, string> comparte; 
    
    int comenta_1 = 0;
  //  int comentar_1 = 0;
    int sigue = 0;
    unordered_set<string> us; //el set sirve para guardar usuarios unicos
    vector<string>users2; //el vector sirve para iterar esos usuarios y contar a cuantos siguen
    vector<string>menosComenta; //este vector es por si se repite el que menos comenta

    for(auto i: interacciones){
        us.insert(i.user1);
        us.insert(i.user2);
    }

    for (auto i = us.begin(); i != us.end(); i++) {
      //  cout << (*i) << endl; 
        users2.push_back(*i);
    }  

  /*  for (auto i = users.begin(); i != users.end(); ++i) {
        cout << *i << " "; 
    } */
        
 
            for(int j = 0; j<users2.size(); j++){

            

            for(auto i: interacciones){   
            c.agregarVertice(i.user1);
            c.agregarVertice(i.user2);

             if((i.user1 == users2[j]) && (i.inter == 1)){ //si el usuario comenta quiere decir que lo sigue por ense se le suma

                 comenta_1++;
             }
                
        }//fin del for
         
           // sigue = compartir_0 + comentar_1;
           if(comenta_1 <=1){
            menosComenta.push_back(users2[j]);
           }
            comparte.insert(pair<int, string>(comenta_1, users2[j]));
           // cout<<comenta_1<<endl;
            comenta_1 = 0;
           
        }

       /* for (auto i = menosComenta.begin(); i != menosComenta.end(); ++i) {
        cout << *i << " "<<endl; 
    } */

   // cout<<compartir_0<<endl;
   // cout<<comentar_1<<endl;

    //------------------------------------------------este  for imprime el arbol -descomentar para verlo-----------------------------------------------------------
       /*     for (auto i = comparte.begin(); i != comparte.end(); ++i) { 
        cout << "Comentarios: " << i->first 
             << '\t' << i->second << '\n'; 
    } */
   // cout << endl; 

    string masPeque = "";
    int peque = 1;
    for(auto i = menosComenta.begin(); i != menosComenta.end(); ++i){
    for (auto itr = comparte.begin(); itr != comparte.end(); itr++){
        
        if(itr->first<=peque){
            masPeque = itr->second;
            peque = itr->first;
           
        }
    }

    cout << "El usuario que menos comenta: " << *i << ", con: " << peque << " compartidas " << endl;

    }


}



};//Agrega aqui los datos y metodos para resolver los problemas del set 3


class Set4{

};//Agrega aqui los datos y metodos para resolver los problemas del set 4

int main(){
    //Cambia la ruta a donde se encuentra el archivo
    //Ejemplo windows en WSL: /mnt/c/Users/Jorge/Desktop/file.txt
    //Ejemplo Mac: /Users/Jorge/Desktop/file.txt
    //En la misma carpeta: file.txt
    string path="examenA01027293Patricio.txt";
    leerData(path);
   // for(int i=0;i<10;i++){
        //cout<<i.user1<<":"<<i.inter<<":"<<i.user2<<endl;
   //     cout<<interacciones[i].user1<<", "<<interacciones[i].inter<<", "<<interacciones[i].user2<<endl;
    //}

     //cout<<interacciones[0].user1<<endl;
    //cout<<interacciones[0].user2<<endl;
    //cout<<interacciones[0].inter<<endl;


    /*-----Set1-------------------*/
    Set1 s1;
    
    cout<<"|----------------------------------Ejercicio 1.1-------------------------------------|"<<endl;
    s1.usuarioExistente("Suellen9");
    s1.usuarioExistente("Andres12");

    //s1.esSeguidor("hola", "adios");

    /*-----Set2-------------------*/
	cout<<"|----------------------------------Ejercicio 2.2-------------------------------------|"<<endl;
    Set2 s2;
    s2.mayorInterraccion("Suellen9");






    /*-----Set3-------------------*/
    cout<<"|----------------------------------Ejercicio 3.1-------------------------------------|"<<endl;
    Set3 s3;
    s3.mayorSeguidor();
    cout<<"|----------------------------------Ejercicio 3.2-------------------------------------|"<<endl;
    s3.amplificador();
    cout<<"|----------------------------------Ejercicio 3.2-------------------------------------|"<<endl;
    s3.llamarCallado();



    /*-----Set4-------------------*/

    return 0;
}