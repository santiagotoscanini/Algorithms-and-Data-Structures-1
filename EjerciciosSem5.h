#ifndef EJERCICIOSSEM5_H
#define EJERCICIOSSEM5_H

#include <iostream>
using namespace std;
#include "Definiciones.h"

/*
PRE: Recibe una lista simplemente encadenada
POS: Elimina n-�simo elemento de la lista, empezando a contar desde el �ltimo nodo. 
	 Si n es mayor al largo de la lista, o menor a 1, la operaci�n no tendr� efecto.
	 Esta operaci�n no debe recorrer la lista m�s de una vez. No se pueden usar funciones auxiliares.
	 (Recomendado resolver de forma recursiva)

Ejemplo 
Entrada: ((1,2,3,4,5), 2) 
Lista resultado: (1,2,3,5) 

Ejemplo
Entrada: ((2, 8, -7, 4), 5 )
Lista resultado: (2, 8, -7, 4)
*/
void eliminarNesimoDesdeElFinal(NodoLista*& lista, int &n);

/*
PRE: Recibe una lista de enteros simplemente encadenada.
POS: Retorna una nueva lista (que no comparte memoria con la anterior) que contiene todos los elementos
     de la lista original, ordenados de menor a mayor.
     La lista retornada no deber� compartir memoria con la lista recibida ni deber� modificarla.
     Se deber� utilizar el algoritmo InsertionSort para ordenar los elementos.

Ejemplo
Entrada: (6,1,1,9)
Salida: (1,1,6,9)
*/
NodoLista* listaOrdenadaInsertionSort(NodoLista* l);

/*
PRE: Recibe una lista de enteros simplemente encadenada.
POS: Ordena la lista utilizando SelectionSort sin utilizar estructuras auxiliares (vector, otra lista , etc).
     (Puede intecambiar los nodos o los datos en los nodos.)

Ejemplo
Entrada: (4,0,1,3)
Salida: (0,1,3,4)
*/
void listaOrdenadaSelectionSort(NodoLista*& l);


/*
PRE: Recibe una lista de enteros simplemente encadenada con al menos 1 elemento.
POS: Retorna una nueva lista (que no comparte memoria con la anterior) que tiene todos los elementos de la 
     lista original en orden Invertido, excluyendo el �ltimo elemento.
     La lista retornada no deber� compartir memoria con la lista recibida ni deber� modificarla.

Ejemplo
Entrada: (1,2,3,4)
Salida: (3,2,1)
*/
NodoLista* invertirParcial(NodoLista* l); 

/*
PRE: Recibe dos listas simplemente encadenadas, ambas ordenadas en orden creciente
POS: Retorna una nueva lista con todos los elementos de l1 y l2, incluyendo repetidos, ordenados en orden creciente.
	 La lista retornada no puede compartir memoria con las listas recibidas, y estas no pueden ser modificadas.
	 La funcion no debe recorrer l1 o l2 mas de una vez, y la lista resultado no debera recorrerse
	 El ejercicio se deber� resolver de forma iterativa.

Ejemplo
Entrada: (((1,3,5,7,9,9), (2,2,4,6,8))
Salida: (1,2,2,3,4,5,6,7,8,9,9)
*/
NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2);

/*
PRE: Recibe dos listas simplemente encadenadas, ambas ordenadas en orden creciente
POS: Retorna una nueva lista con todos los elementos de l1 y l2, incluyendo repetidos, ordenados en orden creciente.
	 La lista retornada no puede compartir memoria con las listas recibidas, y estas no pueden ser modificadas.
	 La funcion no debe recorrer l1 o l2 mas de una vez, y la lista resultado no debera recorrerse
	 El ejercicio se deber� resolver de forma recursiva. 

Ejemplo
Entrada: (((1,3,5,7,9,9), (2,2,4,6,8))
Salida: (1,2,2,3,4,5,6,7,8,9,9)
*/
NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2);

/*
PRE: Recibe una lista l simplemente encadenada y un entero x
POS: Retorna una nueva lista, que tiene todos los elementos de l en orden inverso, y x como primer y ultimo elemento
     la lista retornada no puede compartir memoria con la lista recibida, y esta no puede ser modificada
	 la funcion no debe recorrer l mas de una vez, y la lista resultado no debera recorrerse

Ejemplo
Entrada: ((1,2,3,4), 5)
Retorno: (5,4,3,2,1,5)
*/
NodoLista* insComFin(NodoLista* l, int x);

/*
PRE: Recibe dos listas simplemente encadenadas, ambas ordenadas en orden creciente con elementos repetidos.
POS: Retorna una nueva lista ordenada, que tiene los elementos que se encuentran en una de las listas recibidas, pero no en ambas.
	 La lista retornada no puede compartir memoria con las listas recibidas, y estas no pueden ser modificadas.
	 La lista retornada no debe tener elementos repetidos.
	 La funcion no debe recorrer l1 o l2 mas de una vez, y la lista resultado no debera recorrerse.
	 (es bueno saber hacer este ejercicio de forma recursiva e iterativa)

Ejemplo
Entrada: ((1,2,3,3,4,4), (2,3,5,7))
Retorno: (1,4,5,7)
*/
NodoLista* exor(NodoLista* l1, NodoLista* l2);

/*
PRE: Recibe lista l simplemente encadenada, ordenada.
POS: Elimina todos los elementos de l que tienen al menos un duplicado.
	 Esta operaci�n se debe realizar en O(n), siendo n la cantidad de elementos en la lista.

Ejemplo
Entrada: (1,2,2,2,2,3,3,4)
Lista resultado: (1,4)
*/
void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l); 


/*
PRE: Recibe una lista simplemente encadenada
POS: Retorna si la lista es pal�ndroma o no. En otras palabras, el primer elemento es igual al �ltimo, el segundo 
	 al pen�ltimo, etc. (Se puede leer igual de los dos lados).

Ejemplos:
{1,2,3,4,3,2,1} -> true
{1,2,3,4,5,4,3,2} -> false
*/
bool palindromo(NodoLista* l);


/*
PRE: recibe dos listas simplemente encadenadas l y secuencia
POS: modifica la lista l eliminando la primera ocurrencia de la secuencia (si existe).
	 Los elementos se deben encontrar en el mismo orden y contiguos.
	 En caso de que no exista la secuencia la lista l no debe verse afectada.
	 La lista secuencia no se deber� modificar.

Ejemplos:

Lista: (1,2,3,4,5,6,7,8,9)
Secuencia: (4,5,6)
Resultado: (1,2,3,7,8,9)

Lista: (1,2,3,4,5,6,7,8,9)
Secuencia: (2,4,5,6)
Resultado: (1,2,3,4,5,6,7,8,9)

*/
void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia);


/*
PRE: recibe una lista simplemente encadenada
POS: mueve el nodo que se encuentra en la posici�n inicial a la posici�n final.
	 Las posiciones de la lista ser�n numeradas a partir del 1, 
	 sindo �sta la posici�n del primer nodo y el largo de la lista la �ltima posici�n.
	 Si alguna de las posiciones no se encuentra dentro del rango
	 de la lista, �sta no debe verse afectada.

Ejemplos:

Lista: (4,5,6,3,4,6,8)
inicial: 2
final: 7
Resultado: (4,6,3,4,6,8,5)

Lista: (4,5,6,3,4,6,8)
inicial: 3
final: 1
Resultado: (6,4,5,3,4,6,8)

Lista: (4,5,6,3,4,6,5)
inicial: 2
final: 10
Resultado: (4,5,6,3,4,6,5)
*/
void moverNodo(NodoLista *&lista, unsigned int inicial, unsigned int final);

#endif