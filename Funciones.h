#ifndef FUNCIONES_HPP 
#define FUNCIONES_HPP
#include <string.h>

using namespace std;

struct nodo;
struct n_hijos;
void crearPila(struct Pila );
int vacia(struct Pila);
void push(string , struct Pila);
string pop(struct Pila);
string top(struct Pila);
n_hijos *crearN_H();
nodo *crearN();
n_hijos *empy_H(struct n_hijos*);
nodo* CrearArbol(string);
///////////////////////////////////////////////////////////////////////

void ruta(struct Pila);
void N_T(struct nodo*);
void mostarH(struct n_hijos*);
nodo *entrar(struct n_hijos*, string);
nodo *recorrer_copy(struct nodo*, struct nodo*,int ,struct nodo*);//al llamar la funcion, el counter debe ser 0
void eliminar(struct nodo*); //al llamar la funcion, el counter debe ser 0
void cortar(struct n_hijos*, struct nodo*);
void pegar(struct n_hijos*,struct nodo*);

#endif