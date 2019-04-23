#include "EjerciciosSem7.h"
#include <algorithm>
#include "EjerciciosSem5.h"

#ifndef EJERCICIOSSEM7_CPP
#define EJERCICIOSSEM7_CPP

NodoLista* listaNueva(NodoLista* l);

int altura(NodoAB* raiz){
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

	return p->dato == q->dato && sonIguales(p->izq,q->izq) && sonIguales(p->der,q->der);
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
	}else{
		return existeCaminoConSuma(raiz->der,sum - raiz->dato) || existeCaminoConSuma(raiz->izq,sum -raiz->dato);
	}
	
}

bool esArbolBalanceado(NodoAB *raiz) {
	if (raiz == NULL) {
		return true;
	}
	int ai = altura(raiz->izq);
	int ad = altura(raiz->der);

	return (ai== ad || (ai-1) == ad || ai == (ad-1)) && esArbolBalanceado(raiz->izq) && esArbolBalanceado(raiz->der);
}

NodoLista* concatL(NodoLista* a, NodoLista* b) {
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
}

NodoLista* enNivel(NodoAB *a, int k) {
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
		return concatL(enNivel(a->der, k), enNivel(a->izq, k));
	}
}

int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

NodoLista* camino(NodoAB *arbol, int x) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoAB* invertirHastak(NodoAB* a, int k){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void borrarNodoRaiz(NodoAB * & A) {
	// IMPLEMENTAR SOLUCION
}

bool sumaABB(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

int sucesor(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return 0;
}

int nivelMasNodos(NodoAB* raiz, int nivelHasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

void borrarPares(NodoAB* & a){
	// IMPLEMENTAR SOLUCION
}

int alturaAG(NodoAG* raiz)
{
	// IMPLEMENTAR SOLUCION
	return 0;
}

int sumaPorNiveles(NodoAG* raiz){
	// IMPLEMENTAR SOLUCION
	return 0;
}

bool esPrefijo(NodoAG *a, NodoLista *l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

NodoLista* caminoAG(NodoAG *arbolGeneral, int dato) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int nivelConMasNodosAG(NodoAG * arbolGeneral) {
	// IMPLEMENTAR SOLUCION
	return 0;
}


#endif