#include "Agenda.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;

void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) cout << "Posicion " << i << " | Ocupada: " << ocupada[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

/*
	Constructor de la clase Agenda -------------

	Recibe un entero que representa la capacidad de la agenda. Todos los arreglos se inicializan con la capacidad dada y se llena el arreglo ocupada con false para indicar que todas las posiciones están vacías.
*/

Agenda::Agenda(int capacidad) {

	this->capacidad = capacidad;

	nombres = new string[capacidad];

	telefonos = new long[capacidad];

	ocupada = new bool[capacidad];

	for (int i = 0; i < capacidad; i++)
		ocupada[i] = false;
}

/*
	Destructor de la clase Agenda -------------

	Libera la memoria de los arreglos nombres, telefonos y ocupada.
*/
Agenda::~Agenda() {

	delete[] nombres;

	delete[] telefonos;

	delete[] ocupada;
}

/*
	Función obtenerPosicion -------------

	Recibe un entero que representa un número de teléfono y devuelve la posición en la que se encuentra en el arreglo telefonos. Si el número de teléfono no se encuentra en el arreglo, devuelve -1.
*/

int Agenda::obtenerPosicion(long telefono) {

	for (int i = 0; i < capacidad; i++) {

		if (telefonos[i] == telefono) 
			return i;
	}

	return -1;
}

/*
	Función existeContacto -------------

	Recibe un entero que representa un número de teléfono y devuelve true si el número de teléfono se encuentra en el arreglo telefonos, de lo contrario devuelve false.
*/
bool Agenda::existeContacto(long telefono) {

	int posicion = obtenerPosicion(telefono);

	if (ocupada[posicion] && telefonos[posicion] == telefono) 
		return true;
	else 
		return false;
}

/*
	Función getContacto -------------

	Recibe un entero que representa un número de teléfono y devuelve el nombre asociado a ese número de teléfono. Si el número de teléfono no se encuentra en el arreglo telefonos, devuelve un string vacío.
*/
string Agenda::getContacto(long telefono) {

	int posicion = obtenerPosicion(telefono);

	assertdomjudge(ocupadps[posicion] == false)

	if (ocupada[posicion] && telefonos[posicion] == telefono) 
		return nombres[posicion];
	else 
		return "";
}