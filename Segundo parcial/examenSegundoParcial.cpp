#include <iostream>
#include "vector2.cpp"
#include "ListaLigada.cpp" //asi se llama mi decumento de listas ligadas

using namespace std;


  //Modificado para buscar string

int busquedaSecuencial2(Vector<string> a, string buscado){
  
    //cout<<buscado<<endl;
   // cout<<a.count<<endl;
   // cout<<a.size<<endl;
     for(int i = 0; i<(a.count);i++){
     //cout<<a.getElemento(i)<<endl;
        if(a.getElemento(i)==buscado){
            return i; //si lo encuentra
            //break;
        }
        
    } 
    
    return -1;

}


int busquedaSecuencial(Vector<int> a, int buscado, int size){
	for(int i=0; i<size; i++){
		if(a[i]==buscado){
			return i;
		}
	}
	return -1;
}


class votoElectronico{
    private:
    LinkedList<int> electores;
    Vector<string> candidatos;
    Vector<int> votos;

    public:
        
        votoElectronico(){
            
        }
        votoElectronico(int num){
        electores = LinkedList<int>();
        candidatos = Vector<string>(num); //a fuerzas tengo que darle un tamaño o sale segmentation fault
        votos = Vector<int>();
         srand(time(NULL));     
           
         for(int i=0; i<num;i++){
            electores.append(rand()%1000);
            
    }
    electores.imprimir();

      for(int i=0; i<votos.size;i++){ //inicializa los votos en 0


                
                votos.append(0);
            }

        

    }//fin constructor

    void formarElector(int num);//agrega un elector al final de la lista
    void anadirCandidato(string name){
        candidatos.append(name);
        
       
    }
    
    void votarSiguiente(string nombreCandidato){
        int elector = 0;
        
         //cout<<busquedaSecuencial2(candidatos, nombreCandidato)<<endl;
    
        //cout<<electores.vacio()<<endl;
       
        if(electores.vacio()==1){//Esto checa si la lista esta vacia /CHECA EL ROOT SI ES NULL
            cout<<"No se puede votar ya que la lista esta vacia"<<endl;
           
        }
    
        else if(busquedaSecuencial2(candidatos,nombreCandidato) > -1 && votos.getElemento(busquedaSecuencial2(candidatos, nombreCandidato))==0){ //borra el priemr elemento del vector y añade el voto
            elector = electores.imprimirPos();
            electores.removePos(0); //borra a un elector
            //elector = electores.getElemento(0);
            
            int res;
            int primerIntento;
            int v = 1;
            res= busquedaSecuencial2(candidatos, nombreCandidato);
            //cout<<res<<endl;
           votos.setElemento(v, res);
            //electores.imprimir();
            cout<<"El elector con numero: "<<elector<<" ha votado por: "<<nombreCandidato<<endl;

               // electores.imprimir();
              //votos.imprimir();
        }else if(busquedaSecuencial2(candidatos,nombreCandidato) > -1 && votos.getElemento(busquedaSecuencial2(candidatos, nombreCandidato))>0){ //suma votos
            elector = electores.imprimirPos();
            electores.removePos(0); //borra a un elector
            cout<<"El elector con numero: "<<elector<<" ha votado por: "<<nombreCandidato<<endl;
            int v = votos.getElemento(busquedaSecuencial2(candidatos,nombreCandidato));
            
            votos.setElemento(v+1, busquedaSecuencial2(candidatos,nombreCandidato));

           // votos.imprimir();

        }else if(busquedaSecuencial2(candidatos,nombreCandidato)==-1){ //si no existe un candidato, lo añade y le suma 1 voto
            //aqui no se muestra que elector añada a un independiente a la lista, sin embargo se podria mostrar
            elector = electores.imprimirPos();
            electores.removePos(0); //borra a un elector
            cout<<"Ese candidato no se encuentra, añadido a la lista: "<<nombreCandidato<<endl;
            candidatos.append(nombreCandidato);
            
            int v = votos.getElemento(busquedaSecuencial2(candidatos,nombreCandidato));
            
            votos.setElemento(v+1, busquedaSecuencial2(candidatos,nombreCandidato));
            
            //votos.imprimir();
            //candidatos.imprimir();

        }

        //electores.imprimir();
    } // NOTE: los votos.imprimir() sirven para ver el array de votos y ver que si se etsan guardando


    void ganador(){
        
        
       
        int masGrande= votos.getElemento(0);
        int indiceGrande = 0;
        int segundoLugar = 0;
        int indiceSegundo = 0;
        int tercerLugar = 0;
        int indiceTercero = 0;
        for(int i=0; i<candidatos.size;i++){
            //cout<<masGrande<<endl;
            //cout<<votos.getElemento(i)<<endl;
            if(masGrande<votos.getElemento(i)){

             masGrande = votos.getElemento(i); //determina la cantidad de votos mas alta
                
            }
          

        }
             segundoLugar = 0;  //Buscar el segundo lugar
             for(int i=0; i<candidatos.size;i++){

                if(votos.getElemento(i)>segundoLugar){
                    
                    if(votos.getElemento(i)<masGrande){
                    
                        segundoLugar = votos.getElemento(i);
                    }
                }

             }

            tercerLugar = 0;  //Buscar el tercer lugar
             for(int i=0; i<candidatos.size;i++){

                if(votos.getElemento(i)>tercerLugar){
                    
                    if(votos.getElemento(i)<segundoLugar){
                    
                        tercerLugar = votos.getElemento(i);
                    }
                }

             }

        //cout<<masGrande<<endl;
       // cout<<"Segundo lugar: "<<segundoLugar<<endl;
       // cout<<"Tercer lugar: "<<tercerLugar<<endl;


       indiceGrande = busquedaSecuencial(votos,masGrande,votos.size); //encuentra a la persona con mas votos, basado en el indice de los votos mas grandes
       indiceSegundo = busquedaSecuencial(votos,segundoLugar,votos.size); //encuentra a la persona cde segundo lugar, basado en el indice de los segundos con mas votos
        indiceTercero = busquedaSecuencial(votos,tercerLugar,votos.size); //encuentra a la persona cde segundo lugar, basado en el indice de los terceros con mas votos
        
       // cout<<masGrande<<endl;

        cout<<"El primer lugar es: "<<candidatos.getElemento(indiceGrande)<<" con: "<<masGrande<<" voto(s)"<<endl;
        cout<<"El segundo lugar es: "<<candidatos.getElemento(indiceSegundo)<<" con: "<<segundoLugar<<" voto(s)"<<endl;
        cout<<"El tercer lugar es: "<<candidatos.getElemento(indiceTercero)<<" con: "<<tercerLugar<<" voto(s)"<<endl;
    }

    

};



void votoElectronico::formarElector(int num){
    electores.append(num);
    electores.imprimir();
}


int main(){

    votoElectronico a(10); //inicializa a n electores
    
    a.formarElector(1);
    a.formarElector(100000);
    a.anadirCandidato("Miguel");
    a.anadirCandidato("Luis");
    a.anadirCandidato("Jesus");
    a.anadirCandidato("Raul");
    a.votarSiguiente("Jesus");
    a.votarSiguiente("Raul");
    a.votarSiguiente("Raul");
    a.votarSiguiente("Raul");
    
 

    a.votarSiguiente("Julian");
    a.votarSiguiente("Julian");

    a.votarSiguiente("Ernesto");
    
    
    a.ganador();
    return 0;
}