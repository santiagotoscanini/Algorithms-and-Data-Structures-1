#include "EjerciciosSem3.h"
#include "EjerciciosSem2.h"

#ifndef EJERCICIOSSEM3_CPP
#define EJERCICIOSSEM3_CPP

int largoArrChar(char * lista) {
	int i;
	for (i = 0; lista[i] != '\0'; i++);
	return i;
}

char* copyArr(char* ar, int len) {
	char* a = new char[len];

	for (int i = 0; i < len; i++)
	{
		a[i] = ar[i];
	}
	a[len] = '\0';

	return a;
}

char **noComparteMemoria(char **vec, int str) {

	char ** hola = new char*[str]();
	for (int i = 0; i < str; i++)
	{
		hola[i] = new char[largoArrChar(vec[i]) + 1];
	}

	for (int i = 0; i < str; i++)
	{
		int length = largoArrChar(vec[i]);

		for (int j = 0; j < length; j++)
		{
			hola[i][j] = vec[i][j];
		}
		hola[i][length] = '\0';
	}
	return hola;
}
void hundoIsla(int i, int j, int fil, int col, char ** mapa);
char invertirChar(char altoChar);

char* invertirCase(char* palabra)
{
	int i = 0;
	for (i = 0; palabra[i] != '\0'; i++);

	char* invertir = new char[i];
	invertir[i] = '\0';
	for (int x = 0; x < i; x++)
	{
		invertir[x] = invertirChar(palabra[x]);
	}
	return invertir;

}
char invertirChar(char altoChar) {
	if ((int)altoChar >= 65 && (int)altoChar <= 90) {//es mayus
		return (char)((int)altoChar + 32);
		}
	else if ((int)altoChar >=97 && (int)altoChar <= 122) {//es miniscula
		return (char)((int)altoChar - 32);
	}
	else {
		return altoChar;
	}
}

int islas(char** mapa, int fil, int col){
	
	
	int contadorIsla = 0;
	char ** mapita = noComparteMemoria(mapa, fil);
	for (int i = 0; i < fil; i++)
	{
		for (int j = 0; j < col;j++)
		{
			if (mapita[i][j] == 'T') {
				contadorIsla++;
				hundoIsla(i, j, fil,col,mapita);
			}
		}
	}

    return contadorIsla;

}
void hundoIsla(int i, int j, int fil, int col, char ** mapa) {
	if (i >= 0 && i < fil && j >= 0 && j < col) {
		if (mapa[i][j]=='T')
		{
			mapa[i][j] = 'A';
			int meMuevoEnI[] = {1,-1,0,0,1,-1,1,-1};
			int meMuevoEnJ[] = {0,0,1,-1,1,1,-1,-1};
			for (int k = 0; k < 8; k++)
			{
				int posIAdyacente = i + meMuevoEnI[k];
				int posJAdyacente = j + meMuevoEnJ[k];
				hundoIsla(posIAdyacente, posJAdyacente, fil, col, mapa);
			}
		}
	}
}

unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{

	int countStr = 0;
	int countChars = 0;
	int countSub;
	for (countSub = 0; substr[countSub] != '\0'; countSub++);

	for (int i = 0; i < largoVecStr; i++)
	{
		for  (int j = 0; vecStr[i][j]!='\0' && countChars !=countSub; j++)
		{
			if (vecStr[i][j]==substr[countChars]) {
				countChars++;
			}
			else {
				countChars = 0;
			}

		}
		countStr += (countChars == countSub) ? 1 : 0;
		countChars = 0;
	}

    return countStr;
}

bool mayor(char* ar1, char* ar2) {
	int min = largoArrChar(ar1) > largoArrChar(ar2)
		? largoArrChar(ar2) : largoArrChar(ar1);
	bool may=false;

	for (int i = 0; i < min && !may; i++)
	{
		may = may || ar1[i] > ar2[i];
	}

	return !may && largoArrChar(ar1) > largoArrChar(ar2);
}

void swap(char** mat,int i,int j) {
	char* i1 = copyArr(mat[i], largoArrChar(mat[i]));

	mat[i] = mat[j];
	mat[j] = i1;
}

char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	char ** hola = noComparteMemoria(vecStr,largoVecStr);
	int n = largoVecStr;
	do {
		int newn = 0;
		for (int i = 0; i < n; i++)
		{
			if (mayor(hola[i], hola[i + 1])) {
				swap(hola,i,i+1);
				newn = i;
			}
		}
		n = newn;

	} while (n<=1);

    return hola;
}

int *noComparteMemoria(int*vec, int str) {

	int * hola = new int[str]();
	for (int i = 0; i < str; i++)
	{
		hola[i] = vec[i];
	}

	return hola;
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){

	int * v3 = new int[l1 + l2];
	
	if (l1 + l2 != 0) {
		for (int i = 0; i < l1; i++)
		{
			int num = v1[i];
			v3[i] = num;
		}
		for (int i = l1; i < l1 + l2; i++)
		{
			int num = v2[i - l1];

			v3[i] = num;
		}



		return quickSort(v3, 0, l1 + l2 - 1);
	}
		
	else {
		return NULL;
	}
	
}

bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	
	if (l1 == 0) {
		return true;
	}
	else if (l2 == 0) {
		return false;
	}

	for (int i = 0; i < l1; i++)
	{
		int j;
		for (j = 0;  (j < l2) && (v1[i] != v2[j]) ; j++) {

		}

		if (j == l2) {
			return false;
		}
	}


	return true;
}
bool esVacio(char* ar, int len) {
	int i;
	for (i = 0;  ar[i] == ' ' && i<len; i++)
	{

	}
	
	return i == len;
}
	
char** splitStr(char* str, char separador, int &largoRet)
{	
	char* spt1 = strtok(copyArr(str,largoArrChar(str)), &separador);

	int len = 0;

	if (spt1 == NULL) {
		largoRet = 0;
		return NULL;
	}

	for (len = 0; spt1 != NULL; len++) {

		spt1 = strtok(NULL, &separador);
	}

	char* spt2= strtok(copyArr(str, largoArrChar(str)), &separador);
	largoRet = len;

	char** mat = new char *[len];

	for (int i = 0; spt2 != NULL; i++)
	{
		mat[i] = copyArr(spt2, largoArrChar(spt2));

		spt2 = strtok(NULL, &separador);
	}


	return mat;
}

void ordenarVecIntMergeSort(int* vector, int largo) 
{
	
}



#endif