#include "EjerciciosSem3.h"

#ifndef EJERCICIOSSEM3_CPP
#define EJERCICIOSSEM3_CPP
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

int islas(char** mapa, int col, int fil){
	
	
    return 2;

}


unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{

	int countStr = 0;
	int countSub;
	int countChars = 0;
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

char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	// IMPLEMENTAR SOLUCION
    return NULL;
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

char** splitStr(char* str, char separador, int &largoRet)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void ordenarVecIntMergeSort(int* vector, int largo) 
{
	// IMPLEMENTAR SOLUCION
}

#endif