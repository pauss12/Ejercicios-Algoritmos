#include "Agenda.h"
#include "assertdomjudge.h"
#include <iostream>

using namespace std;

void Agenda::imprimir() {

	for (int i=0; i<capacidad; i++) 
		cout << "Posicion " << i << " | Vacia: " << vacias[i] << " | Borrada: " << borradas[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

/*
	//CONSTRUCTOR 

	Inicializamos los atributos de la clase, reservando memoria para los arrays de nombres, telefonos, vacias y borradas.
	Además, inicializamos todas las posiciones de vacias y borradas a true, para indicar que están vacías.
*/
Agenda::Agenda(int capacidad) {

	this->capacidad = capacidad;
	tamano = 0;
	nombres = new string[capacidad];
	telefonos = new long[capacidad];
	vacias = new bool[capacidad];
	borradas = new bool[capacidad];

	for (int i = 0; i < capacidad; i++) {
		vacias[i] = true;
		borradas[i] = false;
	}
}

/*
	DESTUCTOR

	Libera la memoria reservada para los arrays de nombres, telefonos, vacias y borradas.
*/
Agenda::~Agenda() {

	delete[] nombres;
	delete[] telefonos;
	delete[] vacias;
	delete[] borradas;
}

/*
	OBTENER POSICION

	Devuelve la posición en la que se encuentra un teléfono en la tabla hash.
*/

int Agenda::obtenerPosicion(long telefono) {

	return telefono % capacidad;
}

/*
	BUSCAR CONTACTO

	Devuelve la posición en la que se encuentra un teléfono en la tabla hash.
	Si no se encuentra, devuelve -1.
*/
int Agenda::buscarContacto(long telefono) {

	int pos = obtenerPosicion(telefono);

	for (int i = pos; i < capacidad; i++)
	{
		if (telefonos[i] == telefono && borradas[i] == false)
			return i;

	}

	return -1;
}

/*
	BUSCAR HUECO

	Devuelve la posición en la que se puede insertar un teléfono en la tabla hash.
	
*/
int Agenda::buscarHueco(long telefono) {

	int pos = obtenerPosicion(telefono);

	for (int i = pos; i < capacidad; i++)
	{
		if (vacias[i] || borradas[i])
			return i;
	}

	return -1;
}

/*
	ESTA LLENA

	Devuelve true si la tabla hash está llena.
*/
bool Agenda::isLlena()
{
	return tamano >= capacidad;
}

/*
	EXISTE CONTACTO

	Devuelve true si el teléfono se encuentra en la tabla hash.
*/
bool Agenda::existeContacto(long telefono) 
{
	int pos = obtenerPosicion(telefono);

	for (int i = pos; i < capacidad; i++)
	{
		if (telefonos[i] == telefono && !vacias[i] && !borradas[i])
			return true;
	}

	return false;
}

/*
	GET CONTACTO

	Devuelve el nombre asociado a un teléfono.
*/
string Agenda::getContacto(long telefono) {

	assertdomjudge(existeContacto(telefono));

	int pos = buscarContacto(telefono);

	if (pos != -1)
		return nombres[pos];
	else
		return "";
}

/*
	INTRODUCIR CONTACTO

	Introduce un nuevo contacto en la tabla hash.
*/
void Agenda::introducirContacto(long telefono, string contacto) {

	assertdomjudge(!isLlena());

	int pos = buscarHueco(telefono);

	telefonos[pos] = telefono;
	nombres[pos] = contacto;
	vacias[pos] = false;
	borradas[pos] = false;

	tamano++;
}

/*
	ELIMINAR CONTACTO

	Elimina un contacto de la tabla hash.
*/
void Agenda::eliminarContacto(long telefono) {

	assertdomjudge(existeContacto(telefono));

	int pos = buscarContacto(telefono);

	borradas[pos] = true;
	vacias[pos] = true;

	tamano--;
}