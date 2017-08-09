#include <iostream>
#include "Funciones.h"
using namespace std;

struct Pila{	
	int tope;
	string ruta[100];
};
void crearPila(Pila &p){	
	p.tope = -1;
};
int vacia(Pila p){
	if(p.tope < 0)	
		return 1;
	else
		return 0;
};
void push(string x, Pila &p){	
	if(p.tope == 100-1) cout<<"La pila esta llena"<<endl;
	else
	{	p.tope++;
		p.ruta[p.tope] = x;
	};
};
string pop(Pila &p) {
	if(vacia(p)) return "empy";
	else return(p.ruta[p.tope--]);
};
void ruta(Pila pila){
    string lugar = pop(pila);
    if(lugar.compare("empy") == 0) return;
    else {
        printf("%d '/' %d \n", ruta(pila), lugar);
    }//le daremos copia de a ilaoriginal
};

//string top(Pila p){
//	if(vacia(p))	cout<<"La pila esta vacia"<<endl;
//	else return(p.ruta[p.tope]);
//};
