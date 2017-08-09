#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "Funciones.h"

using namespace std;

struct nodo{
	string nombre;
	string tipo;
	struct nodo *papa;
	struct n_hijos *hijo;
};

struct n_hijos{
	n_hijos *sig;	
	nodo *hijo;
};

n_hijos *crearN_H(){
	n_hijos *N = new n_hijos;
	N->sig= NULL;
	N->hijo = NULL;
	return N;
};

nodo *crearN(){
	nodo *nuevo = new nodo;
	nuevo->papa = NULL;
	nuevo->hijo = NULL;
	return nuevo;
};


n_hijos *empy_H(n_hijos *lista){
	if(lista->sig == NULL) return lista;
	else {empy_H(lista->sig);}
};


nodo * CrearArbol(string archivo){ 
	fstream txt;
	string linea;
	txt.open(archivo);
	nodo *H;
	n_hijos *NH;
	nodo *h;
	n_hijos *s;
	while (! txt.eof() ) {
        	getline (txt ,linea);
            if(linea.find("home")){
        		nodo *inicial;
            	if(linea.find("/")){
            		return inicial;
            	}
            	else{
            	H = crearN();
            	H->tipo ="Carpeta";
            	H->nombre ="home";
            	NH = crearN_H();
            	H->hijo = NH;
            	inicial = H;
            	}
            	
            }
        	else if(linea.find("usuario")){
        		if(linea.find("/")){
        			H = h->papa;
        			NH = H->hijo;
        		}
    			else{
    				h = crearN();
    				h->tipo = "usuario";
    				h->papa = H;
    				s = crearN_H();
    				h->hijo = s;
    				if(NH->hijo == NULL){
    					NH->hijo = h;
    				}
    				else{
    					NH = empy_H(NH);
    					n_hijos *bro = crearN_H();
    					NH->sig = bro;
    					NH = NH->sig;
    					NH->hijo = h;
    					};
    				}
    				H = h;
    				NH = s;
    			}
			else if(linea.find("Carpeta")){
        		if(linea.find("/")){
        			H = h->papa;
        			NH = H->hijo;
        		}
    			else{
    				nodo *h = crearN();
    				h->tipo = "Carpeta";
    				h->papa = H;
    				n_hijos *s = crearN_H();
    				h->hijo = s;
    				if(NH->hijo == NULL){
    					NH->hijo = h;
    				}
    				else{
    					NH = empy_H(NH);
    					n_hijos *bro = crearN_H();
    					NH->sig = bro;
    					NH = NH->sig;
    					NH->hijo = h;
    					}
    				}
    				H = h;
    				NH = s;
    			}    
			else if(linea.find("archivo")){
        		if(linea.find("/")){
        			H = h->papa;
        			NH = H->hijo;
        		}
    			else{
    				nodo *h = crearN();
    				h->tipo = "archivo";
    				h->papa = H;
    				n_hijos *s = crearN_H();
    				h->hijo = s;
    				if(NH->hijo == NULL){
    					NH->hijo = h;
    				}
    				else{
    					NH = empy_H(NH);
    					n_hijos *bro = crearN_H();
    					NH->sig = bro;
    					NH = NH->sig;
    					NH->hijo = h;
    					}
    				}
    				H = h;
    				NH = s;
    			}
    		else if(linea.find("nombre")){
        		continue;
        	}
        	else{
        		H->nombre = linea;
        	}
};
};

void N_T(nodo *actual){
	cout<< actual->tipo<< ": "<< actual->nombre<<endl;
	};

void mostarH(n_hijos *lista){
	if(lista== NULL) return;
	else{
		cout<< (lista->hijo)->nombre <<endl;
		mostarH(lista->sig);
	};
};

nodo *entrar(n_hijos *lista, string carpeta){
	if(((lista->hijo)->nombre).compare(carpeta) == 0) return lista->hijo;
	else{
		entrar(lista->sig,carpeta);
	}
};

nodo *recorrer_copy(nodo *raiz, nodo *temp,int counter,nodo *k){  //al llamar la funcion, el counter debe ser 0
	if(counter == 0) {
		k = temp;
		counter = 1}
	if(raiz->hijo == NULL) return K;//No  hijo
	else{
		if((raiz->hijo)->sig != NULL){ // Hay hermano
			(temp->hijo)->sig = crearN_H();
			nodo *H = crearN();
			H->nombre= (((raiz->hijo)->sig)->hijo)->nombre;
			H->tipo= (((raiz->hijo)->sig)->hijo)->tipo;
			H->papa= temp;
			((temp->hijo)->sig)->hijo = H;
			return  recorrer_copy(((raiz->hijo)->sig)->hijo,H,counter,K);
			};
		nodo *H = crearN();
		H->nombre= raiz->nombre;
		H->tipo= raiz->tipo;
		H->papa= temp;
		(temp->hijo)->hijo = H;
		return recorrer_copy((raiz->hijo)->hijo,H,counter,K);
	};
};

void eliminar(nodo *raiz){  //al llamar la funcion, el counter debe ser 0
	if(raiz->hijo == NULL){ 
		delete raiz;
		return ;}//No  hijo
	else{
		if((raiz->hijo)->sig != NULL){ // Hay hermano
			return  eliminar(((raiz->hijo)->sig)->hijo);
			(raiz->hijo)->sig = NULL;
			delete (raiz->hijo);
			}
		return eliminar((nodo->hijo)->hijo);
		(nodo->hijo)->hijo = NULL;
		delete (nodo->hijo)
	};
};

void cortar(n_hijos *r, nodo *cortado){
	if(r->hijo == cortado){
		if(r->sig == NULL){
			((r->hijo)->papa)->hijo = NULL;
			r->hijo = NULL:
			delete r;
		}
		else{
			((r->hijo)->papa)->hijo = r->sig;
			r->sig = NULL;
			r->hijo = NULL;
			delete r;
		}
	}
	if((r->sig)->hijo == cr){
		(r->sig)->hijo = NULL;
		n_hijos *N = r->sig;
		r->sig = (r->sig)->sig;
		delete N;
	}	
	else{
		cortar(r->sig,cortado);
	}
};


void pegar(n_hijos *actual,nodo *temp){
	if(actual->sig == NULL){
		n_hijos *N = crearN_H()
		actual->sig = N;
		N->hijo = temp;
	};
	else{
		pegar(actual->sig,temp);
	};
};


