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

NodoLista* menorDeLaLista(NodoLista * &lista) {
	NodoLista* menorActual = lista;
	NodoLista* elQueRecorre = lista;

	while (elQueRecorre != NULL) {
		if (elQueRecorre->dato < menorActual->dato) {
			menorActual = elQueRecorre;
		}
		elQueRecorre = elQueRecorre->sig;
	}
	return menorActual;
}

void swapNodeValues(NodoLista * &l, NodoLista * &y) {

	int aux = l->dato;
	l->dato = y->dato;
	y->dato = aux;

}

void listaOrdenadaSelectionSort(NodoLista * &l)
{
	if (l != NULL) {
		NodoLista* menor = menorDeLaLista(l);
		swapNodeValues(l, menor);
		listaOrdenadaSelectionSort(l->sig);
	}

}

NodoLista* invertirParcial(NodoLista * l)
{
	NodoLista* l1 = listaNueva(l);
	int pep = 1;
	eliminarNesimoDesdeElFinal(l1, pep);

	if (l1 != NULL) {
		NodoLista* n = NULL;

		while (l1 != NULL) {
			NodoLista* nodo = new NodoLista;
			nodo->dato = l1->dato;

			if (n == NULL) {
				nodo->sig = NULL;
			}
			else {
				nodo->sig = n;
			}
			n = nodo;

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
	if (l1 == NULL) {
		return listaNueva(l2);
	}
	else if (l2 == NULL) {
		return listaNueva(l1);
	}
	else {
		NodoLista* lis = new NodoLista;
		NodoLista* last = lis;

		NodoLista* ll1 = l1;
		NodoLista* ll2 = l2;

		if (ll1->dato <= ll2->dato) {
			lis->dato = ll1->dato;
			lis->sig = NULL;

			ll1 = ll1->sig;
		}
		else {
			lis->dato = ll2->dato;
			lis->sig = NULL;

			ll2 = ll2->sig;
		}


		while (ll1 != NULL && ll2 != NULL) {

			NodoLista* n = new NodoLista;
			last->sig = n;

			if (ll1->dato <= ll2->dato) {
				n->dato = ll1->dato;
				n->sig = NULL;

				ll1 = ll1->sig;
			}
			else {
				n->dato = ll2->dato;
				n->sig = NULL;

				ll2 = ll2->sig;
			}

			last = last->sig;

		}
		NodoLista* ult = ll1 == NULL ? ll2 : ll1;

		while (ult != NULL) {
			NodoLista* n = new NodoLista;
			n->dato = ult->dato;
			n->sig = NULL;

			last->sig = n;
			ult = ult->sig;

			last = last->sig;
		}

		return lis;
	}
}

NodoLista* intercalarRec(NodoLista * l1, NodoLista * l2)
{
	NodoLista* n = new NodoLista;

	if (l1 == NULL && l2 == NULL) {
		n = NULL;
	}
	else if (l1 == NULL) {
		n->dato = l2->dato;
		n->sig = intercalarRec(l1, l2->sig);
	}
	else if (l2 == NULL) {
		n->dato = l1->dato;
		n->sig = intercalarRec(l1->sig, l2);
	}
	else if (l1->dato <= l2->dato) {
		n->dato = l1->dato;
		n->sig = intercalarRec(l1->sig, l2);
	}
	else {
		n->dato = l2->dato;
		n->sig = intercalarRec(l1, l2->sig);
	}

	return n;
}

NodoLista* insComFin(NodoLista * l, int x)
{
	if (l != NULL) {
		NodoLista* l1 = new NodoLista; //LISTA A DEVOLVER
		NodoLista* lastL = l; //ARREGLAR LA FUNCION QUE BORRA AL FINAL
		NodoLista* last = l1; // ULTIMO DE LA LISTA A DEVOLVER

		l1->dato = x;

		while (lastL->sig != NULL) {
			lastL = lastL->sig;
		}

		last->sig = new NodoLista;
		last = last->sig;
		last->dato = lastL->dato;
		last->sig = invertirParcial(l);

		while (last->sig != NULL) {
			last = last->sig;
		}

		last->sig = new NodoLista;
		last = last->sig;
		last->dato = x;
		last->sig = NULL;

		return l1;
	}
	else {
		NodoLista* n = new NodoLista;
		n->dato = x;
		n->sig = new NodoLista;
		n->sig->dato = x;
		n->sig->sig = NULL;

		return n;
	}
}

NodoLista* dif(NodoLista * l1, NodoLista * l2) {

	NodoLista* n = new NodoLista; //LISTA A RETORNAR

	if (l1 == NULL && l2 == NULL) {
		n = NULL;
	}
	else if (l1 == NULL) {
		n->dato = l2->dato;
		n->sig = dif(l1, l2->sig);
	}
	else if (l2 == NULL) {
		n->dato = l1->dato;
		n->sig = dif(l1->sig, l2);
	}
	else if (l1->dato == l2->dato) {
		n = dif(l1->sig, l2->sig);
	}
	else if (l1->dato < l2->dato) {
		n->dato = l1->dato;
		n->sig = dif(l1->sig, l2);
	}
	else {
		n->dato = l2->dato;
		n->sig = dif(l1, l2->sig);
	}

	return n;
}

void elimRep(NodoLista * &l)
{
	if (l != NULL) {
		if (l->sig != NULL) {
			if (l->dato == l->sig->dato) {
				int dat = l->dato;
				NodoLista* aux = l;

				while (l != NULL && l->dato == dat) {
					l = l->sig;
				}
				aux->sig = l;
				l = aux;

				elimRep(l);

			}
			else {
				elimRep(l->sig);
			}
		}
	}

}

NodoLista* exor(NodoLista * l1, NodoLista * l2)
{
	NodoLista* n1 = listaNueva(l1);
	NodoLista* n2 = listaNueva(l2);

	elimRep(n1);
	elimRep(n2);

	return dif(n1, n2);
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista * &l)
{
	if (l != NULL) {
		if (l->sig != NULL) {
			if (l->dato == l->sig->dato) {
				int dat = l->dato;

				while (l != NULL && l->dato == dat) {
					l = l->sig;
				}


				eliminarDuplicadosListaOrdenadaDos(l);

			}
			else {
				eliminarDuplicadosListaOrdenadaDos(l->sig);
			}
		}
	}

}

bool palindromo(NodoLista * l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

void eliminarSecuencia(NodoLista*& l, NodoLista* secuencia)
{
	if (l != NULL && secuencia != NULL) {
		if (l->dato != secuencia->dato) {
			eliminarSecuencia(l->sig, secuencia);
		}
		else {
			NodoLista* r = l;
			NodoLista* rs = secuencia;
			bool b = true;

			while (r != NULL && rs != NULL) {
				b = b && r->dato == rs->dato;

				rs = rs->sig;
				r = r->sig;
			}

			if (b && rs == NULL) {
				l = r;
			}
			else {
				eliminarSecuencia(l->sig, secuencia);
			}

		}
	}
}
bool insertarNodo(NodoLista*& lista, NodoLista *nodo, int num) {
	if (lista != NULL) {
		if (num == 1) {
			NodoLista* aux = lista;
			lista = nodo;
			nodo->sig = aux;
			return true;
		}
		else {
			return insertarNodo(lista->sig, nodo, num - 1);
		}
	}
	else {
		return false;
	}
}

NodoLista* borraDevuelve(NodoLista *& lista, int inicial) {
	if (lista != NULL) {
		if (inicial == 1) {
			NodoLista* aux = lista;
			NodoLista* devolver = new NodoLista;
			devolver->dato = lista->dato;
			devolver->sig = NULL;
			lista = lista->sig;

			delete aux;

			return devolver;
		}
		else {
			return borraDevuelve(lista->sig, inicial - 1);
		}
	}
	else {
		return NULL;
	}
}

void moverNodo(NodoLista * &lista, unsigned int inicial, unsigned int final)
{
	if (lista != NULL) {
		if (inicial == 1) {

			NodoLista* aux = lista;

			NodoLista* nodoNuevo = new NodoLista;
			nodoNuevo->dato = aux->dato;
			nodoNuevo->sig = NULL;

			lista = lista->sig;

			if (!insertarNodo(lista, nodoNuevo, final)) {
				lista = aux;
				delete nodoNuevo;
			}
			else {
				delete[]aux;
			}
		}
		else if (final == 1)
		{
			NodoLista* aux = lista;
			NodoLista* agregar = borraDevuelve(lista, inicial);
			if (agregar != NULL) {
				lista = agregar;
				lista->sig = aux;
			}
		}
		else {
			moverNodo(lista->sig, inicial - 1, final - 1);
		}
	}
}
#endif