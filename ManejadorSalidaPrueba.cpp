#include "ManejadorSalidaPrueba.h"

//ManejadorSalidaPrueba* ManejadorSalidaPrueba::instanciaManejador = NULL;

ManejadorSalidaPrueba::ManejadorSalidaPrueba()
{
	pantalla = cout.rdbuf();
}

ManejadorSalidaPrueba::~ManejadorSalidaPrueba()
{
	if ( archivoActual.is_open() )
		archivoActual.close();
}

ManejadorSalidaPrueba::ManejadorSalidaPrueba(const ManejadorSalidaPrueba &m)
{
	pantalla = cout.rdbuf();
}

ManejadorSalidaPrueba& ManejadorSalidaPrueba::operator=(const ManejadorSalidaPrueba &manejador)
{
	return *this;
}

ManejadorSalidaPrueba ManejadorSalidaPrueba::getInstancia()
{
	//if ( instanciaManejador == NULL )
	//	instanciaManejador = new ManejadorSalidaPrueba();

	return ManejadorSalidaPrueba();
}

void ManejadorSalidaPrueba::setSalidaArchivo(const char* nombreArchivo)
{
	if ( archivoActual.is_open() )
	{
		archivoActual.close();
	}

	archivoActual.open(nombreArchivo,ios::out);

	printf("Se creo el archivo: %s\n", nombreArchivo);

	cout.rdbuf(archivoActual.rdbuf());
}

void ManejadorSalidaPrueba::setSalidaPantalla()
{
	if ( archivoActual.is_open() )
		archivoActual.close();

	cout.rdbuf(pantalla);
}

void ManejadorSalidaPrueba::crearDirectorio(const char* nombreDirectorio)
{
	_mkdir(nombreDirectorio);
	cambiarDirectorio(nombreDirectorio);
	printf("Se creo el directorio: %s\n", nombreDirectorio);
}

void ManejadorSalidaPrueba::cambiarDirectorio(const char* nombreDirectorio)
{
	_chdir(nombreDirectorio);
}
