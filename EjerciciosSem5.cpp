#include "EjerciciosSem5.h"

#ifndef EJERCICIOSSEM5_CPP
#define EJERCICIOSSEM5_CPP

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int& n)
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

NodoLista* insert(NodoLista* l, int elem) {

	if (l == NULL || elem <= l->dato) {
		NodoLista* n = new NodoLista;
		n->dato = elem;
		n->sig = l;

		return n;
	}
	else {
		l->sig = insert(l->sig, elem);
		return l;
	}


}

NodoLista* insertSort(NodoLista*& l) {
	if (l != NULL)
		return insert(insertSort(l->sig), l->dato);
	else
		return NULL;

}
NodoLista* listaNueva(NodoLista * l) {
	if (l == NULL) {
		return NULL;
	}
	else {
		NodoLista* n = new NodoLista;
		n->dato = l->dato;
		n->sig = listaNueva(l->sig);

		return n;
	}
}
NodoLista* listaOrdenadaInsertionSort(NodoLista * l)
{
	NodoLista* ln = listaNueva(l);

	return insertSort(ln);
}

void listaOrdenadaSelectionSort(NodoLista*& l)
{
	//int puntero = 0;
	//while (!estaOrdenada(l, l->dato)) {
	//	recorrida(l, puntero);
	//}

}
/*
void recorrida(NodoLista*& l, int desdeDonde) {

}

bool estaOrdenada(NodoLista*& l, int valorAnterior) {
	bool valor = true;
	if (l != NULL) {


		if (valorAnterior > l->dato) {
			valor = false;
		}
		else {
			valor = valor && estaOrdenada(l->sig, l->dato);
		}
	}
	else {
		return true;
	}
	return valor;

}
void swapNodeValues(NodoLista*& l, NodoLista*& y) {
	int aux = l->dato;
	l->dato = y->dato;
	y->dato = aux;
}
*/
NodoLista* invertirParcial(NodoLista * l)
{
	NodoLista* l1 = listaNueva(l);
	int pep = 1;
	eliminarNesimoDesdeElFinal(l1, pep);

	if (l1 != NULL) {
		NodoLista* n = NULL;

		while (l1 != NULL) {
			NodoLista* nodo = new NodoLista;

			if (n == NULL) {
				nodo->sig = NULL;
			}
			else {
				nodo->dato = l1->dato;
				nodo->sig = n->sig;

				n->sig = nodo;

			}

			l1 = l1->sig;
		}

		return n;

	}
	else {
		return NULL;
	}
}

NodoLista* intercalarIter(NodoLista * l1, NodoLista * l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* intercalarRec(NodoLista * l1, NodoLista * l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* insComFin(NodoLista * l, int x)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* exor(NodoLista * l1, NodoLista * l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista * &l)
{
	// IMPLEMENTAR SOLUCION
}

bool palindromo(NodoLista * l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

void eliminarSecuencia(NodoLista * &l, NodoLista * secuencia)
{
	// IMPLEMENTAR SOLUCION
}

void moverNodo(NodoLista * &lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}


#endif