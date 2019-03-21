#ifndef EJERCICIOSSEM7_H
#define EJERCICIOSSEM7_H

#include <iostream>
using namespace std;
#include "Definiciones.h"


/*
PRE: recibe un arbol binario
POS: devuelve la altura del arbol recibido.
	 Se define altura de un �rbol binario como la cantidad de nodos del camino m�s largo que va desde la ra�z hasta una hoja.

Ejemplo
Entrada: {1,2,3,#,#,4,#,#,5}
   1
  / \
 2   3
    /
   4
    \
     5
Retorno: 4 
*/
int altura(NodoAB* raiz);

/*
PRE: Recibe dos arboles binarios.
POS: Retorna true si y solo si los dos arboles son iguales.
(Dos arboles binarios son iguales si tienen los mismos elementos en las mismas posiciones).

Ejemplo
Entrada: {1,2,3}, {1,2,3}
   1     1
  / \   / \
 2   3 2   3
Salida: true

Entrada: {1,3,2}, {1,2,3}
   1     1
  / \   / \
 3   2 2   3
Salida: false
*/
bool sonIguales(NodoAB* p, NodoAB* q);

/*
PRE: Recibe un �rbol binario (raiz) y un entero (n)
POS: Retorna true si y solo si existe un camino desde la ra�z hasta una hoja que sume sum.
	 El �rbol vac�o suma 0.

Ejemplo
Entrada: {1,2,3}, 4
   1
  / \
 2   3
Salida: true
*/
bool existeCaminoConSuma(NodoAB* raiz, int sum);

/*
PRE: Recibe un �rbol binario
POS: Retorna true si y solo si el arbol est� balanceado.
	 Un arbol est� balanceado, si y solo si, para cualquier nodo, la diferencia de altura entre la rama
	 izquierda y la derecha es a lo sumo 1.
	 Notar que si el �rbol es vac�o entonces est� balanceado.

Ejemplo
Entrada: {1,#,2,#,3}
  1
   \
    2
     \
      3
Salida: false
*/
bool esArbolBalanceado(NodoAB* raiz);

/*
PRE: Recibe un �rbol binario (a) y un entero (k) mayor a 0.
POS: Retorna una lista con todos los elementos presentes en el nivel k del arbol a ordenados de izquierda 
a derecha. En caso de no existir el nivel retornar NULL.

El �rbol no debe ser modificado en la funci�n.

Ejemplo
Entrada: {1,2,3,4,5}, 2
        1
      /   \
     2     3
    / \    
   4   5 
Salida: (2,3)
*/
NodoLista* enNivel(NodoAB* a, int k);

/*
PRE: Recibe un �rbol (a) y dos enteros (desde y hasta) mayores a 0.
POS: Retorna la cantidad de nodos ubicados entre los niveles desde y hasta del �rbol a.

En caso de no haber ning�n nodo entre los niveles dados o que �stos no sean v�lidos (desde>hasta), se deber� 
retornar 0. Recordar que (en caso de existir) la ra�z de un �rbol ocupa el nivel 1.

Ejemplo
Entrada: {1,2,3,4,5,6,#}, desde=2, hasta=4
        1
      /   \
     2     3
    / \   /     
   4   5 6   
Salida: 5
*/
int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta);

/*
PRE: Recibe un �rbol binario de busqueda de enteros y un entero (x).
	 x pertenece al �rbol.
POS: Retorna la lista con camino de la ra�z hasta donde se encuentra el elemento x en el �rbol.

Ejemplo
Entrada: {8,3,10,1,5,9,13}, 9
        8
      /   \
     3     10
    / \   /  \  
   1   5 9    13
Salida: (8,10,9)
*/
NodoLista* camino(NodoAB* arbol, int x);

/*
PRE: recibe un arbol binario, y un entero k mayor o igual a 0
POS: retorna un nuevo �rbol en el cual cada nodo Invertir� sus punteros de izquierda y derecha, "espejando" el �rbol 
     solo se consideraran los elementos en niveles menores o iguales a k
	 si k es mayor o igual a la altura del �rbol, se deber� retornar una copia completa Invertida.
	 si k=0, retornar� NULL
	 el arbol recibido por parametro no debe ser modificado

Ejemplo:
Entrada: {1,2,3,4,5,6,7,8,9}, 3
         1
       /    \
     2       3
    /  \    /  \
   4    5  6    7
 /  \ 
8    9
Retorno:
         1
       /    \
     3       2
    /  \    /  \
   7    6  5    4
*/
NodoAB* invertirHastak(NodoAB* a, int k); 

/*
PRE: recibe un arbol binario de b�squeda a, no vac�o
POS: elimina el dato que se encuentra en la ra�z de a.
	 Luego de la funci�n el arbol debe seguir siendo una arbol binario de busqueda
	 la forma del arbol resultante no es importante (siempre que sea un ABB)

Ejemplo: {3,2,6}
   3
  / \
 2   6
Resultado: {2,#,6} 
*/
void borrarNodoRaiz(NodoAB * & A);

/*
PRE: Recibe un �rbol binario de b�squeda (ABB).
POS: Devuelve true si existen dos naturales en el ABB tales que sumados son equivalentes a n.

Ejemplo
Entrada: {5,3,7,1,4,6,#}, 8
	   5 
	  / \  
	 3   7 
	/\	 /
   1  4 6  

Salida: true
*/
bool sumaABB(NodoAB* a, int n);

/*
PRE: Recibe un �rbol binario de b�squeda (ABB) y n natural perteneciente o no al ABB.
POS: Dado un n�mero n, computa su sucesor tal que sea perteneciente al ABB.
	 Es decir el menor n�mero tal que es mayor que n y pertenece al �rbol.
	 Si no se encuentra el sucesor devuelve -1.
	 No se pueden usar estructuras auxiliares (vector, lista, otro arbol, etc).

Ejemplo 1
Entrada: {5,3,7,1,4,6,#}, 3
   5
 /    \
 3     7
/\	  /
1 4 6

Salida: 4
----------
Ejemplo 2
Entrada: {5,3,7,1,4,6,#}, 2
   5 
 /   \
 3     7
/\	  /
1 4 6

Salida: 3
----------
Ejemplo 2
Entrada: {5,3,7,1,4,6,#}, 7
   5
 /    \
3      7
/\	  /
1 4  6

Salida: -1
*/
int sucesor(NodoAB* a, int n);


/*
PRE: recibe un arbol binario
POS: Retorna el nivel con mas nodos, desde el nivel 1 hasta nivelHasta.	 
	 En caso de que el �rbol sea vacio se debera retornar cero.
	 Ante un empate debera retornar el n�mero de nivel mas peque�o.
	 NOTA: Esta operaci�n se puede realizar en O(n).

Ejemplo
Entrada: {1,2,3,#,#,4,#,#,5}
   1
  / \
 2   3
    /
   4
    \
     5
Retorno: 2
*/
int nivelMasNodos(NodoAB* raiz, int nivelHasta);

/*
PRE: 
POS: Implemente un procedimiento void borraPares(NodoAB *&arbol); que dado un �rbol binario de busqueda
	 a elimine todos los elementos pares del mismo, modificando al �rbol pasado por par�metro.

Ejemplos:
borrarPares({4,2,6,1,3,5,7}) = {5,3,7,1}
*/
void borrarPares(NodoAB* & a);



/*
PRE: Recibe un �rbol general implementado como un arbol binario (primer hijo � siguiente hermano),
POS: Retorna la altura del arbol recibido.
	 Se define altura de un �rbol general como la cantidad de nodos del camino m�s largo que va desde la ra�z hasta una hoja.

Ejemplo
Entrada: {{1,2,5,#,#,3,#,4,#,#}}
    1
   / 
  2 - 3 - 4
 /   
5        

Retorno: 3 
*/
int alturaAG(NodoAG* raiz);


/*
PRE: Recibe un arbol general implementado como un arbol binario (primer hijo � siguiente hermano) 
POS: Retorna la suma los valores de los niveles pares y resta los valores de los impares.
	 La  ra�z se encuentra en el nivel 1.

Ejemplo
Entrada: {{1,2,5,#,#,3,#,4,#,#}}
    1
   / 
  2 - 3 - 4
 /   
5        

Retorno: 3
 */
int sumaPorNiveles(NodoAG* raiz);

	
/*
PRE: Recibe un arbol general sin repetidos implementado como un arbol binario (primer hijo � siguiente hermano) 
	 y una lista de enteros  
POS: Retorna true si y s�lo si la lista es un prefijo de alg�n camino del �rbol general, comenzando desde la ra�z.
	 La lista vac�a es prefijo de cualquier camino (incluso del camino vac�o, si el �rbol es vac�o).
	 No se permite usar funciones o procedimientos auxiliares en este ejercicio.
	 NOTA: Esta operaci�n se puede realizar en O(n).

Ejemplo 1
Entrada: {{1,2,5,#,#,3,7,4,#,#}},{1,2,5}
    1
   / 
  2 - 3 - 4
 /	  |
5     7   

Retorno: true
------------------------
Ejemplo 2
Entrada: {{1,2,5,#,#,3,#,4,#,#}},{1,2,3,4}
    1
   / 
  2 - 3 - 4
 /   
5        

Retorno: false
------------------------
Ejemplo 3
Entrada: {{1,2,5,#,#,3,#,4}},{1,4}
    1
   / 
  2 - 3 - 4
 /   
5        

Retorno: true
------------------------
Ejemplo 4
Entrada: {{1,2,5,#,#,3,#,#,6,7,#,8}},{6,8}
    1   -   6
   /       /
  2 - 3   7 - 8
 /   
5        

Retorno: true
 */
bool esPrefijo(NodoAG *a, NodoLista *l);


/*
PRE: Recibe un arbol general implementado como un arbol binario (primer hijo � siguiente hermano) 
	 y un n�mero.
POS: Retorna una lista con los datos en el camino de la raiz al n�mero dado.
	 Si el n�mero est� repetido retorna el camino que incluya a los primeros hermanos.
     Si el n�mero no se encuentra en el �rbol retorna NULL.
	 No se permite usar funciones o procedimientos auxiliares en este ejercicio.
	 Resolver en O(n).

	Ejemplo:    ENTRADA   
				ARBOL              DATO 5;
				  1
				  |
				  2 -> 3
				  |    |
				  4	   5
				
				SALIDA  1->3->5;
				
*/
NodoLista* caminoAG(NodoAG *a, int dato);


/*
PRE: Recibe un arbol general implementado como un arbol binario (primer hijo � siguiente hermano).
POS: Retorna el nivel con mas nodos del AG. En caso de haber mas de un nivel con la misma cantidad 
	 de nodos retorna el menor. La  ra�z se encuentra en el nivel 1.
	 NOTA: Esta operaci�n se puede realizar en O(n).

		Ejemplo:    ENTRADA   
				ARBOL              
				  1					Nivel 1
				  |
				  2 -> 3			Nivel 2
				  |    |
				  4	   5			Nivel 3
				
				SALIDA  Nivel 2;
*/	

int nivelConMasNodosAG(NodoAG * arbolGeneral);

#endif