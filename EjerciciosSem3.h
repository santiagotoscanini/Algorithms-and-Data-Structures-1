#ifndef EJERCICIOSSEM3_H
#define EJERCICIOSSEM3_H

#include <iostream>
using namespace std;
#include "Definiciones.h"

/*
PRE: Recibe un string palabra.
POS: Retorna un nuevo string con el case Invertido. Es decir si un caracter es lowercase 
     debe pasar a ser uppercase y viceversa. 
	 Se pueden utilizar funciones auxiliares, pero no funciones de bibliotecas 
	 de C/C++ (como strcpy, toupper, tolower etc.).

Ejemplo 1
Entrada: "hola"
Retorno: "HOLA"

Ejemplo 2
Entrada: "Write IN C"
Retorno: "wRITE in c"
*/
char* invertirCase(char* palabra);

/*
PRE:  recibe un mapa representado por una matriz, de dimensiones col x fil, en la cual 'A' representa un lugar donde hay agua, y 'T' donde hay tierra
POS:  devuelve la cantidad de islas del mapa. Una isla es un conjunto de tierras adyacentes, ortogonal o diagonal (puede ser una sola).
      Los indices del mapa recibido se deben usar como mapa[c][f] donde c y f corresponden a la columna y fila respectivamente.
	  La matriz recibida debe ser retornada sin cambios.

Ejemplo 1
Entrada: (['T','A','T','A'], 4, 1)
Retorno: 2

Ejemplo 2
Entrada: (['T','T','A'
		   'A','A','T'
		   'A','A','A'
		   'T','T','A'], 3, 4)
Retorno: 2
*/
int islas(char** mapa, int col, int fil);

/*
PRE: Recibe un vector de strings, la cantidad de strings que hay en el vector y el substring a buscar.
POS: Devuelve la cantidad de ocurrencias de ese substring en los strings del vector.
	 El subtring a buscar se puede encontrar contenido dentro del string (con caracteres antes y despu�s) y 
	 solamente se debe contar una vez por string.
	 El vector recibido y los strings que contiene no deber�n ser modificados.
	 Se pueden utilizar funciones auxiliaries pero no se pueden usar las funciones de las bibliotecas del sistema (ejemplo strlen, strcpy, etc).

Ejemplo 1
Entrada: vecStr=['chauhcar','chanu','cha'] substr="chau"
Salida: 1

Ejemplo 2
Entrada: vecStr=['so','l'] substr="sol"
Salida: 0

Ejemplo 3
Entrada: vecStr=['holahola','hola'] substr="hola"
Salida: 2
*/
unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr);

/*
PRE: recibe un vector de strings, y su largo
POS: retorna un nuevo vector, que contiene los strings de vecStr ordenados. Este nuevo vector, no debe compartir memoria con vecStr.
	 los strings se deber�n ordenar, comparando caracter a caracter, seg�n la tabla ASCII.
	 El vector recibido y los strings que contiene no deber�n ser modificados.
	 Se pueden usar funciones auxiliares, que deber�n implementar. 
	 No se pueden usar las funciones de las bibliotecas del sistema (ejemplo strlen, strcpy, etc).
	 NOTA: recordar que un string es un puntero al primer caracter de una serie de caracteres consecutivos, y termina en '\0'

Ejemplo 1: 
Entrada: (["hola","tierra","arriba"], 3)
Retorno: (["arriba","hola","tierra"])

Ejemplo 2:
Entrada: (["134","122","122","567"], 4)
Retorno: (["122","122","134","567"])
*/
char **ordenarVecStrings(char **vecStr, int largoVecStr);

/*
PRE: Recibe dos vectores ordenados ascendentemente v1 y v2 y sus respectios largos l1 y l2
POS: Retorna un nuevo vector ordenado con los elementos de v1 y v2. 
	 Los vectores pueden contener elementos repetidos, y deber�n aparecer todos ellos.
	 El vector retornado no debe compartir memoria.
	 Resolver en O(l1+l2)

Ejemplo
Entrada: (1,3,5,6), (2,3,4)
Lista resultado: (1,2,3,3,4,5,6)
*/
int* intercalarVector(int* v1, int* v2, int l1, int l2);

/*
PRE: Recibe 2 vectores v1 y v2, no ordenados, y sus respectios largos l1 y l2
POS: Retorna true si y solo si v1 es un subconjunto de v2
	 Los vectores pueden contener elementos repetidos.
	 Nota: el vector vac�o ser� considerado como el conjunto vac�o. Recordar que el conjunto vac�o por definici�n es subconjunto de cualquier otro conjunto.

Ejemplo 1:
Entrada: (5,2,2,1), (1,2,3,4,5,6)
Salida: TRUE

Ejemplo 2:
Entrada: (), (1, 2, 3)
Salida: TRUE

Ejemplo 3:
Entrada: (1, 1, 1, 4, 2) (1, 2, 5)
Salida: FALSE

*/
bool subconjuntoVector(int* v1, int* v2, int l1, int l2);

/*
PRE: Recibe un string str y un caracter separador
POS: Retorna un array de string que contiene los substrings que se encuentran en str entre los separadores.
	 Descarta los substrings vac�os. Si no hay substrings retorna NULL.
	 Se debe setear el par�metro largoRet (no leer) con el tama�o del vector retornado.
	 Se pueden usar las funciones de la biblioteca string.h (por ejemplo strtok/strtok_s)

Ejemplo 
Entrada: "ab:cdef:gh"
Salida: ['ab', 'cdef', 'gh']

Ejemplo 
Entrada: ":cdef:gh"
Salida: ['cdef', 'gh']

Ejemplo 
Entrada: "ab:cdef:"
Salida: ['ab', 'cdef']

Ejemplo
Entrada: "::"
Salida: NULL
*/
char** splitStr(char* str, char separador, int &largoRet);

/*
PRE: Recibe un vector de enteros y su largo.
POS: Modifica el vector recibido de tal forma que los elementos queden ordenados de menor a mayor.
     Se deber� utilizar el algoritmo MergeSort para ordenar los elementos.
	
Ejemplo:  
Entrada = ( [5,3,2,4,1], 5 )

SALIDA
Resultado = ( [1,2,3,4,5], 5 )
*/
void ordenarVecIntMergeSort(int *vector, int largoVector);

#endif