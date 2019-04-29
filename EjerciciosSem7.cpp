#include "EjerciciosSem7.h"
#include <algorithm>
#include "EjerciciosSem5.h"

#ifndef EJERCICIOSSEM7_CPP
#define EJERCICIOSSEM7_CPP

NodoLista* listaNueva(NodoLista* l);

int altura(NodoAB* raiz) {
	if (raiz == NULL) {
		return 0;
	}
	return 1 + max(altura(raiz->izq), altura(raiz->der));
}

bool sonIguales(NodoAB* p, NodoAB* q) {
	if (p == NULL && q == NULL) {
		return true;
	}
	else if (p == NULL || q == NULL) {
		return false;
	}

	return p->dato == q->dato && sonIguales(p->izq, q->izq) && sonIguales(p->der, q->der);
}

int sumaAr(NodoAB* l, bool b) {
	if (l == NULL) {
		return 0;
	}
	return l->dato + sumaAr(b ? l->izq : l->der, b);
}

bool existeCaminoConSuma(NodoAB* raiz, int sum) {
	if (raiz == NULL && sum == 0) {
		return true;
	}
	else if (raiz == NULL && sum != 0) {
		return false;
	}
	else if (raiz->der == NULL && raiz->izq == NULL) {
		return raiz->dato == sum;
	}
	else if (raiz->der == NULL) {
		return existeCaminoConSuma(raiz->izq, sum - raiz->dato);
	}
	else if (raiz->izq == NULL) {
		return existeCaminoConSuma(raiz->der, sum - raiz->dato);
	}
	else {
		return existeCaminoConSuma(raiz->der, sum - raiz->dato) || existeCaminoConSuma(raiz->izq, sum - raiz->dato);
	}

}

bool esArbolBalanceado(NodoAB * raiz) {
	if (raiz == NULL) {
		return true;
	}
	int ai = altura(raiz->izq);
	int ad = altura(raiz->der);

	return (ai == ad || (ai - 1) == ad || ai == (ad - 1)) && esArbolBalanceado(raiz->izq) && esArbolBalanceado(raiz->der);
}

NodoLista * concatL(NodoLista * a, NodoLista * b) {
	if (a == NULL) {
		return listaNueva(b);
	}
	NodoLista* lr = new NodoLista;
	lr->dato = a->dato;
	if (a->sig == NULL) {
		lr->sig = listaNueva(b);
	}
	else {
		lr->sig = concatL(a->sig, b);
	}
	return lr;
}

NodoLista* enNivel(NodoAB * a, int k) {
	k--;
	if (a == NULL) {
		return NULL;
	}
	else if (k == 0) {
		NodoLista* l = new NodoLista;
		l->dato = a->dato;
		l->sig = NULL;
		return l;
	}
	else {
		return concatL(enNivel(a->izq, k), enNivel(a->der, k));
	}
}

int largoLista(NodoLista * l) {
	if (l == NULL) {
		return 0;
	}
	return 1 + largoLista(l->sig);
}

int cantNodosEntreNiveles(NodoAB * a, int desde, int hasta) {

	if (desde > hasta || a == NULL)
		return 0;

	int r = 0;
	for (int i = desde; i <= hasta; i++)
	{
		r += largoLista(enNivel(a, i));
	}
	return r;
}

NodoLista* camino(NodoAB * arbol, int x) {
	NodoLista* l = new NodoLista;
	l->dato = arbol->dato;
	l->sig = NULL;
	if (arbol->dato > x) {
		l->sig = camino(arbol->izq, x);
	}
	else if (arbol->dato < x) {
		l->sig = camino(arbol->der, x);
	}

	return l;
}

NodoAB* invertirHastak(NodoAB * a, int k) {
	if (a == NULL || k == 0) {
		return NULL;
	}
	else {
		NodoAB* ab = new NodoAB;
		ab->dato = a->dato;
		ab->der = invertirHastak(a->izq, k - 1);
		ab->izq = invertirHastak(a->der, k - 1);
		return ab;

	}
}

NodoAB * &menorDelArbol(NodoAB * &tree) {

	if (tree->izq == NULL) {
		return tree;
	}
	else {
		return menorDelArbol(tree->izq);
	}
}

void borrarNodoRaiz(NodoAB * &A) {
	if (A->izq == NULL) {

		NodoAB* X = A;
		A = A->der;
		delete[]X;
	}
	else if (A->der == NULL) {
		NodoAB* X = A;
		A = A->izq;
		delete[]X;
	}
	else {
		menorDelArbol(A->der)->izq = A->izq;
		NodoAB* X = A;
		A = A->der;
		delete X;
	}
}

bool existeABB(NodoAB * a, int num) {
	if (a == NULL) {
		return false;
	}
	else if (a->dato == num) {
		return true;
	}
	else {
		return existeABB(a->dato > num ? a->izq : a->der, num);
	}
}
bool inOrder(NodoAB * lo, NodoAB * lb, int n) {
	if (lb == NULL) {
		return false;
	}
	inOrder(lo, lb->izq, n);
	if (n - lb->dato != lb->dato && existeABB(lo, n - lb->dato)) {
		return true;
	}
	inOrder(lo, lb->der, n);
}

bool sumaABB(NodoAB * a, int n)
{
	if (a == NULL) {
		return false;
	}
	else {
		NodoAB* miron = a;
		return inOrder(a, miron, n);
	}

}
int* minPositivos(int& n1, int& n2) {
	int* re = new int;
	if (&n1 == NULL && &n2 == NULL) {
		re = NULL;
	}
	else if (&n1 == NULL) {
		*re = n2;
	}
	else if (&n2 == NULL) {
		*re = n1;
	}
	else if (n1 >= 0 && n2 >= 0) {
		*re = min(n1, n2);
	}
	else if (n1 < 0 && n2 < 0) {
		re = NULL;
	}
	else {
		*re = n1 >= 0 ? n1 : n2;
	}
	return re;
}
int* menorMasCercano(NodoAB * ar, int n) {
	if (ar == NULL) {
		return NULL;
	}
	int res = ar->dato - n;
	if (res > 0) {
		return minPositivos(res, *minPositivos(*menorMasCercano(ar->izq, n), *menorMasCercano(ar->der, n)));
	}
	else {
		return minPositivos(*menorMasCercano(ar->izq, n), *menorMasCercano(ar->der, n));
	}
}
int sucesor(NodoAB * a, int n)
{
	int* num = menorMasCercano(a, n);
	int j = 3;

	if (num == NULL) {
		num = new int;
		*num = -1;
	}
	else {
		*num = *num + n;
	}

	return *num;
}

void cargarArr(NodoAB * a, int esta, int hasta, int*& arr) {
	if (a != NULL) {
		cargarArr(a->izq, esta + 1, hasta, arr);
		if (esta <= hasta) {
			arr[esta]++;
		}
		cargarArr(a->der, esta + 1, hasta, arr);
	}
}
int mayor(int* arr, int largo) {
	if (arr == NULL) {
		return 0;
	}
	int m = arr[0];

	for (int i = 0; i < largo; i++) {
		m = arr[i] > m ? arr[i] : m;
	}
	for (int i = 0; i < largo; i++)
	{
		if (arr[i] == m) {
			return i;
		}
	}

}

int nivelMasNodos(NodoAB * raiz, int nivelHasta) {
	int* ar = new int[nivelHasta + 1]();

	cargarArr(raiz, 1, nivelHasta + 1, ar);
	int ma = mayor(ar, nivelHasta + 1);
	//delete ar;
	return ma;
}

void borrarPares(NodoAB * &a) {
	if (a != NULL) {
		if (a->dato % 2 == 0) {
			NodoAB* miron = a;
			borrarNodoRaiz(a);
			borrarPares(a);		
		}
		else {
			borrarPares(a->izq);
			borrarPares(a->der);
		}
	}
}

int alturaAG(NodoAG * raiz)
{

	return raiz == NULL ? 0 : max(alturaAG(raiz->sh), alturaAG(raiz->ph) + 1);
}

int sumaAux(NodoAG * a, int nivel) {

	return a == NULL ? 0 : ((nivel % 2 == 0 ? a->dato : -a->dato) + sumaAux(a->ph, nivel + 1) + sumaAux(a->sh, nivel));
}
int sumaPorNiveles(NodoAG * raiz) {
	return sumaAux(raiz, 1);
}

bool esPrefijo(NodoAG * a, NodoLista * l)
{
	if (l == NULL) {
		return true;
	}
	else if (a == NULL && l == NULL) {
		return true;
	}
	else if (a == NULL && l != NULL) {
		return false;
	}
	else {
		if (a->dato == l->dato) {
			return esPrefijo(a->ph, l->sig);
		}
		else {
			return esPrefijo(a->sh, l);
		}
	}
}

NodoLista* caminoAG(NodoAG * arbolGeneral, int dato) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int nivelConMasNodosAG(NodoAG * arbolGeneral) {
	// IMPLEMENTAR SOLUCION
	return 0;
}


#endif