#include "PruebasSem3.h"

#ifndef PRUEBASSEM3_CPP
#define PRUEBASSEM3_CPP

void PruebasSem3() {
	int nroPrueba = 1;
	int correctos = 0, error = 0;
	int correctosTotal = 0, errorTotal = 0, ejCorrectosTotal = 0, ejErrorTotal = 0;

	FrameworkA1::ver(PruebaInvertirCase("","", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirCase("hola","HOLA", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirCase("Write in C","wRITE IN c", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirCase("es UNA cosa DE locos","ES una COSA de LOCOS", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirCase("EsCrIbIR asi Es MoLeSTOOO","eScRiBir ASI eS mOlEstooo", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirCase("1434","1434", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirCase("#&/()|A","#&/()|a", nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaInvertirCase", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);


	FrameworkA1::ver(PruebaIslas(
		"['T','A','T','A','T','A']", 6, 1, 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIslas(
		"['T','A','T','A','T','A',"\
		 "'T','T','T','T','T','T']", 6, 2, 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIslas(
		"['T','A','T','A','T','T','T','A','T','A',"\
		 "'A','T','T','A','A','T','T','T','T','A']", 10, 2, 2, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIslas(
		"['T','A','T','A','T','A',"\
		 "'A','T','A','T','A','T',"\
		 "'T','A','A','T','A','T',"\
		 "'T','T','T','A','T','T']", 6, 4, 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIslas(
		"['A','A','A','A','A','A','A','A','A','A',"\
		 "'A','T','T','A','T','T','A','T','T','A',"\
		 "'A','T','T','A','T','T','A','T','T','A',"\
		 "'A','A','A','A','A','A','A','A','A','A']", 10, 4, 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIslas(
		"['A','T','T','T','T','T','A','T','T','T',"\
		 "'A','T','A','A','A','T','A','T','A','T',"\
		 "'A','T','A','A','T','T','A','T','A','T',"\
		 "'A','T','T','T','T','A','A','A','T','A']", 10, 4, 2, nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaIslas", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaOcurrenciasSubstring("['hola']", "hola", 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcurrenciasSubstring("['abc','ab','ab']", "ab", 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcurrenciasSubstring("['holaho','holahol','holahola','holaholahola','holaholaholaho']", "holahola", 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcurrenciasSubstring("['abcjsdf','sagsdfg','afgadfg','afgadfg12','wertewrt','tyafgadfgsegfdxv','jo']", "afgadfg", 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcurrenciasSubstring("['solsol']", "sol", 1, nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaOcurrenciasSubstring", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaOrdenarVecStr("['paso','pasa','pasado','pasaron']" , "['pasa','pasado','pasaron','paso']", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecStr("['hola']", "['hola']", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecStr("['string','strings','substring','strong','strength']", "['strength', 'string', 'strings', 'strong','substring']", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecStr("['1234','15324567','1563248','5132135']", "['1234', '15324567', '1563248', '5132135']", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecStr("['153243','1532468','153246','15324679']", "['153243', '153246', '15324679', '1532468']", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecStr("['algoritmos','algoritmia','algoritmo','algo']", "['algo', 'algoritmia', 'algoritmo', 'algoritmos']", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecStr("['123456','123546','123645','123598','123754','12365498','1232','12','123','12911']", "['12','123', '1232', '123456', '123546','123598', '123645', '12365498', '123754', '12911']", nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaOrdenarVecStr", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaIntercalarVector("[1,2,3]", "[1,2,3]", "[1,1,2,2,3,3]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarVector("[1,3,5]", "[2,4]", "[1,2,3,4,5]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarVector("[1,100]", "[2,53]", "[1,2,53,100]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarVector("[]", "[]", "[]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarVector("[2]", "[4]", "[2,4]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarVector("[1,2,3,4,5]", "[6,7,8]", "[1,2,3,4,5,6,7,8]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarVector("[6,7,8]", "[1,2,3,4,5]", "[1,2,3,4,5,6,7,8]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarVector("[]", "[1,2,3]", "[1,2,3]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarVector("[1,2,3]", "[]", "[1,2,3]", nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaIntercalarVector", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaSubconjuntoVector("[100,400,200,300,300,400,400]", "[100,400,200]", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSubconjuntoVector("[1,2,3]", "[1,2,3,4,5,6]", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSubconjuntoVector("[2,2,2,3,54,6,7]", "[1,2,3,4]", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSubconjuntoVector("[2,2,2,3,54,6,7]", "[7,6,54,6,3,2]", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSubconjuntoVector("[1,1,1,4,2]", "[1,2,5]", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSubconjuntoVector("[]", "[]", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSubconjuntoVector("[]", "[2,3,1]", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSubconjuntoVector("[2,3,4]", "[]", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSubconjuntoVector("[1]", "[1]", true, nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaSubconjuntoVector", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaSplitStr("", '@', "[]", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr(" ", '@', "[' ']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("@", '@', "[]", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("@@ @@ @@ @@ @@", '@', "[' ', ' ', ' ', ' ']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("A@B", '@', "['A','B']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("A@B@C", '@', "['A','B', 'C']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("A@", '@', "['A']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("@B", '@', "['B']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("@@@", '@', "[]", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("@@@A", '@', "['A']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("A@@@B", '@', "['A','B']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("The-Lannisters-send-their-regards", '-', "['The','Lannisters','send','their','regards']", nroPrueba),  correctos, error);
	FrameworkA1::ver(PruebaSplitStr("Hola@Mundo", '-', "['Hola@Mundo']", nroPrueba),  correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaSplitStr", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[]", "[]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[4]", "[4]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,1,1]", "[1,1,1]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,2,3]", "[1,2,3]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,4,2]", "[1,2,4]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[2,3,1]", "[1,2,3]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[-2,-3,-1]", "[-3,-2,-1]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,1,4,1,3,8]", "[1,1,1,3,4,8]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[-2,3,1]", "[-2,1,3]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[3,5,2,1,0]", "[0,1,2,3,5]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[9,2,2,5,1]", "[1,2,2,5,9]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[3,1,-1,1,0]", "[-1,0,1,1,3]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[10,9,8,7,6,5,4,3,2,1,0,-1,-2]", "[-2,-1,0,1,2,3,4,5,6,7,8,9,10]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[7,3,7,10,-1,1,-6,0,-10,2,1,2]", "[-10,-6,-1,0,1,1,2,2,3,7,7,10]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[10,9,8,7,6,5,4,3,2,1,0,-1,-2]", "[-2,-1,0,1,2,3,4,5,6,7,8,9,10]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[8,7,5,2,-3,-1]", "[-3,-1,2,5,7,8]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,2,0,10,3,4]", "[0,1,2,3,4,10]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,2,4,3]", "[1,2,3,4]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[-2,0,3,1,1]", "[-2,0,1,1,3]", nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaOrdenarVecIntMergeSort", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	cout << "----------------------------------------------"<<endl;
	cout << "----------------------------------------------"<<endl;
	cout << "PRUEBAS FUNCIONES " << endl;
	cout << "PRUEBAS FUNCIONES " << setw(48) << std::right << "RESULTADO SEM3 =>" << " CORRECTAS: " << setw(2) << std::right << ejCorrectosTotal << " INCORRECTAS: " << setw(2) << std::right << ejErrorTotal << endl;
	cout << "PRUEBAS FUNCIONES " << endl;
}

#endif