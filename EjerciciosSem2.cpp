#include "EjerciciosSem2.h"

#ifndef EJERCICIOSSEM2_CPP
#define EJERCICIOSSEM2_CPP
int* quickSort(int *numeros, int izq, int der);
void simplificar(int n, int d)
{
	int maximoDivisorComun = 1;

	int max = n > d ? n : d;
	
	int max2 = max< 0 ? max*(-1) :max;

	for (int i = 1;i<=max2; i++) {
		int pr = (n%i);
		int sg = (d%i);
		if (pr== 0 && sg == 0) {
			maximoDivisorComun = i;
		}
	}

	int primero = (n / maximoDivisorComun) < 0 ? (n / maximoDivisorComun)*(-1) : (n / maximoDivisorComun);
	int segundo = (d / maximoDivisorComun) < 0 ? (d / maximoDivisorComun)*(-1) : (d / maximoDivisorComun);

	cout <<((n/d<0)?"-":"")<<primero<<"/"<<segundo;

}

int ocurrencias123Repetidos(int* vector, int largo) {
	int contador = 0;
	int numMasAnterior = 0;
	int numAnterior = 0;
	int actual = 1;
	
	for (int i = 0; i < largo; i++) {
		actual = vector[i];

		if (actual != numAnterior) {

			if (actual == 3) if (numMasAnterior == 1) contador++;
		
			numMasAnterior = numAnterior;
			numAnterior = vector[i];
		}
		
	}
	
	return contador;
}

int maximoNumero(unsigned int n) {

	int *arr = new int[n];

	for (int i = 0; i < n; cin >> arr[i++]);

	int max = INT_MIN;
	
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	return max;

}

void ordenarVecInt(int * vec, int largoVec) {
	vec = quickSort(vec, 0, largoVec - 1);


};

int* quickSort(int *numeros, int izq, int der) {
	if (izq >= der) { //si los punteros son iguales es porque estan en el mismo numero
		return numeros;
	}

	int i = izq, d = der;
	if (izq != der) {// si los valores son distintos es porque no estamos en el mismo numero
		int pivote = izq;//tomamos como pivote el primer valor
		int aux;
		while (izq != der) { //mientras los valores sigan siendo distintos ejecutamos
			while (numeros[der] >= numeros[pivote] && izq < der) { //mientras los numeros de la derecha sena mayores al pivote(estan bien ubicados)
																   //y el indice sea mayor vamos decrementando el indice derecho pero sin pasarnos
				der--;
			}
			while (numeros[izq] < numeros[pivote] && izq < der) { //lo mismo del lado izquierdo
				izq++;
			}
			if (der != izq) { //salimos del while, porque el numero de la izq o derecha no verifica estar bien ubicado, y intercambiamos los valores
				aux = numeros[der];
				numeros[der] = numeros[izq];
				numeros[izq] = aux;
			}
		}
		if (izq == der) {//si la izquierda es igual a la derecha entonces ya estan todos los menores de un lado y los mayores del otro 
			quickSort(numeros, i, izq - 1); //repetimos el procedimiento para las listas mas pequeñas ahora
			quickSort(numeros, izq + 1, d);
		}
	}
	else {
		return numeros;
	}
	return numeros;
}
#endif