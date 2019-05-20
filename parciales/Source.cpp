#include <algorithm>
#include <iostream>

using namespace std;

typedef struct NodoLista* Lista;
struct NodoLista {
	unsigned int dato;  
	Lista sig; 
};

void enPos(Lista& l, int e, int pos);
void borrar(Lista& l);
void impar(Lista& l);

int main() {

	Lista l = new NodoLista;
	l->dato = 1;
	l->sig = new NodoLista;
	l->sig->dato = 4;
	l->sig->sig = new NodoLista;
	l->sig->sig->dato = 90;
	l->sig->sig->sig = new NodoLista;
	l->sig->sig->sig->dato = 10;
	l->sig->sig->sig->sig = NULL;

	impar(l);

	while (l != NULL) {
		cout << l->dato;
		l = l->sig;

	}

	return 0;
}
void impar(Lista& l) {
	if (l != NULL) {
		NodoLista* a1 = l;
		l = l->sig;
		delete a1;

		NodoLista* iter = l;
		while (iter!=NULL && iter->sig!=NULL)
		{
			NodoLista* a = iter->sig;
			iter->sig = iter->sig->sig;
			delete a;
			iter = iter->sig;
		}
	}
};

void enPos(Lista& l, int e, int pos) {
	NodoLista* n = l;

	if (l != NULL) {
		while (pos != 1) {
			n = n->sig;
			pos--;
		}
		n->dato = e;
		borrar(n->sig);
	}
}

void borrar(Lista& l) {
	NodoLista* n = l;
	while (l != NULL) {
		l = l->sig;
		delete n;
		n = l;
	}
};
