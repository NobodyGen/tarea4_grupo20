#include <iostream>
#include <string.h>
#include <fstream>
#include <unistd.h>
#include "Funciones.h"
#include "Funciones.cpp"
#include "Arboles.cpp"

using namespace std;

int main () {
    nodo *H;
    n_hijos *NH;
    string archivo;
    Pila pila;
    crearPila(pila);
    bool f= false;
    char opcion = '0';
    bool M = true;
	while(M == true){
    	if(opcion == '0'){
    		while(f==true){
                cout << "Ingrese nombre archivo de carga: "<<endl;
    	    	cin>> archivo;
    	    	if(archivo.compare("0") == 0){M = false;}
    	    	else if( access( archivo, F_OK ) != -1 ) { // file exists
    	    		cout<< "Cargando Directorio..."<<endl;
    	    		H = CrearArbol(archivo);//
    	    		NH = H->hijo;
    	    		cout<<  "Arbol cargado"<<endl;
    	    		push("hombe",pila);
    	    		f=false;
    	    	}
    	    	else { // file doesn't exist
    	    	cout<< "ERROR: No se pudo abrir el archivo."<<endl;
				}
			}
		}
		else if(opcion == '1'){
			N_T(H);
		}
		else if(opcion == '2'){
			ruta(pila);
		}
		else if(opcion == '3'){
			mostarH(NH);
		}	
		else if(opcion == '4'){
			string lugar;
			cin>>lugar;
			if(lugar.compare("archivo") == 0) continue;
			else{
				H = entrar(NH,lugar);
				NH = H->hijo;
				push(H->nombre,pila);
			};
		else if(opcion == '5'){
				if((H->nombre).compare("home") == 0) continue;
				else{ 
					H = H->papa;
					NH = H->hijo;
				}
			}
		else if(opcion == '6'){
			nodo *K = crearN()
			nodo *I = crearN()
			K = recorrer_copy(H,K,0,I)
			delete I;

			}
		else if(opcion == '7'){
			nodo *K = cortar(H->hijo,H);
			 }
		else if(opcion == '8'){
				pegar(NH,K)
			}
		else if(opcion == '9'){
			eliminar(H);
			}
		cin>>opcion;
		}
    return 0;
}
}
