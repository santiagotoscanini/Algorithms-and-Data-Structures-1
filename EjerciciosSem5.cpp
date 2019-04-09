#include "EjerciciosSem5.h"

#ifndef EJERCICIOSSEM5_CPP
#define EJERCICIOSSEM5_CPP

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int &n) 
{
	if (lista != NULL) {

		eliminarNesimoDesdeElFinal(lista->sig, n);

		n--;

		if (n == 0) {
			NodoLista* p = lista;
			lista = lista->sig;
			delete[]p;
		}
	}
}

void insert(NodoLista* l,NodoLista * elem) {
	if (l != NULL) {
		
		if (elem->dato <= l->dato) {
			NodoLista* n = new NodoLista;
			n->dato = l->dato;
			n->sig = l->sig;

			l->dato = elem->dato;
			l->sig = n;
		}
		else {
			insert(l->sig, elem);
		}
	}

}

void insertSort() {

}

NodoLista* listaOrdenadaInsertionSort(NodoLista* l) 
{
	if (l != NULL) {
		NodoLista* n = new NodoLista;
		n->dato = l->dato;


	}


	return NULL;
}

void listaOrdenadaSelectionSort(NodoLista*& l)
{
	// IMPLEMENTAR SOLUCION
}

NodoLista* invertirParcial(NodoLista* l) 
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
	// IMPLEMENTAR SOLUCION
}

bool palindromo(NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	// IMPLEMENTAR SOLUCION
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}


#endif