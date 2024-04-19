#include "Agenda.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;

void Agenda::imprimir() {

	for (int i = 0; i < capacidad; i++)
		cout << "Posicion " << i << " | Ocupada: " << ocupados[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

/*
	Constructor de la clase Agenda -------------

	Recibe un entero que representa la capacidad de la agenda. Todos los arreglos se inicializan con la capacidad dada y se llena el arreglo ocupada con false para indicar que todas las posiciones están vacías.
*/
Agenda::Agenda(int capacidad) {

	this->capacidad = capacidad;

	nombres = new string[capacidad];

	telefonos = new long[capacidad];

	ocupados = new bool[capacidad];

	for (int i = 0; i < capacidad; i++)
		ocupados[i] = false;
}

/*
	Destructor de la clase Agenda -------------

	Libera la memoria de los arreglos nombres, telefonos y ocupada.
*/
Agenda::~Agenda() {

	delete[] nombres;

	delete[] telefonos;

	delete[] ocupados;
}

/*
	Función obtenerPosicion -------------

	Recibe un entero que representa un número de teléfono y devuelve la posición en la que se encuentra en el arreglo telefonos. Si el número de teléfono no se encuentra en el arreglo, devuelve -1.
*/

int Agenda::obtenerPosicion(long telefono) {

	return telefono % capacidad;
}

/*
	Función existeContacto -------------

	Recibe un entero que representa un número de teléfono y devuelve true si el número de teléfono se encuentra en el arreglo telefonos, de lo contrario devuelve false.
*/
bool Agenda::existeContacto(long telefono) {

	int posicion = obtenerPosicion(telefono);

	if (ocupados[posicion] && telefonos[posicion] == telefono) 
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

	assertdomjudge(ocupados[posicion] == true && telefonos[posicion] == telefono)

	return nombres[posicion];
}

/*
	Función agregarContacto -------------

	Recibe un entero que representa un número de teléfono y un string que representa un nombre. Si el número de teléfono no se encuentra en el arreglo telefonos, se agrega el número de teléfono y el nombre en la primera posición vacía de los arreglos telefonos y nombres, respectivamente. Si el número de teléfono ya se encuentra en el arreglo telefonos, se actualiza el nombre asociado a ese número de teléfono.
*/

void Agenda::introducirContacto(long telefono, string contacto) {

	int posicion = obtenerPosicion(telefono);

	assertdomjudge(ocupados[posicion] == false)

	ocupados[posicion] = true;

    telefonos[posicion] = telefono;

    nombres[posicion] = contacto;
}

/*
	Función eliminarContacto -------------

	Recibe un entero que representa un número de teléfono. Si el número de teléfono se encuentra en el arreglo telefonos, se elimina el número de teléfono y el nombre asociado a ese número de teléfono.
*/

void Agenda::eliminarContacto(long telefono) {

	int posicion = obtenerPosicion(telefono);

	assertdomjudge(ocupados[posicion] == true && telefonos[posicion] == telefono)

	ocupados[posicion] = false;
}