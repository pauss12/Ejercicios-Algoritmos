#include "Agenda.h"
#include "ListaEnlazada.h"
#include "assertdomjudge.h"
#include <iostream>
#include "impresionListasEnlazadas.h" // Para el m�todo imprimir de la tabla hash

using namespace std;

void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) {
		cout << "Posicion " << i << ": ";
		imprimirListaEnlazada(&tabla[i]);
	}
}

/*
	CONSTRUCTOR DE LA CLASE AGENDA

	Le paso la capacidad de la tabla por parametro a la funcion. Inicializo la tabla de contactos con la capacidad que le paso por parametro. Inicializo el numero de contactos a 0. Y creo una tabla de contactos con la capacidad que le paso por parametro.

*/
Agenda::Agenda(int capacidad) {
	
	this->capacidad = capacidad;
	n = 0;
	tabla = new ListaEnlazada[capacidad];
}

/*
	DESTRUCTOR DE LA CLASE AGENDA

	Simplemente elimina la tabla de contactos.

*/
Agenda::~Agenda() {
	delete[] tabla;
}

/*
	OBTENER POSICION

	Devuelve la posicion en la tabla de un numero de telefono. Le paso el telefono por parametro a la funcion. Devuelve la posicion en la tabla de un numero de telefono. La posicion en la tabla es el resto de la division del telefono entre la capacidad de la tabla.

*/
int Agenda::obtenerPosicion(long telefono) {
	return telefono % capacidad;
}

/*
	EXISTE CONTACTO

	Devuelve si un contacto este en la tabla hash o no. Le paso el telefono por parametro a la funcion. Si el contacto existe, devuelve true; si no existe, devuelve false.

*/
bool Agenda::existeContacto(long telefono) {
	
	Contacto contacto;

	contacto.telefono = telefono;

	if (tabla[obtenerPosicion(telefono)].buscar(contacto) != -1) {
		return true;
	}

	return false;
}

/*
	GET CONTACTO

	Le paso el telefono por parametro a la funcion. Le paso la funcion de DOM JUDGE para que compruebe si el contacto existe; devuelve el nombre de un contacto. Si no existe, devuelve una cadena vacia
*/
string Agenda::getContacto(long telefono) {
	
	assertdomjudge(existeContacto(telefono));

	int pos = obtenerPosicion(telefono);

	for (int i = 0; i < tabla[pos].getN(); i++) {
		if (tabla[pos].getValor(i).telefono == telefono) {
			return tabla[pos].getValor(i).nombre;
		}
	}

	return "";
}

/*
	INTRODUCIR CONTACTO

	Introduce un contacto en la tabla. Le paso el telefono y el nombre del contacto por parametro a la funcion. Le paso la funcion de DOM JUDGE para que compruebe si el contacto existe; si existe, no lo introduce. Si no existe, lo introduce en la tabla. Y luego aumento el numero de contactos en la tabla.
*/
void Agenda::introducirContacto(long telefono, string contacto) {
	
	assertdomjudge(!existeContacto(telefono));

	Contacto c;
	c.telefono = telefono;
	c.nombre = contacto;

	tabla[obtenerPosicion(telefono)].insertar(0, c);

	n++;
}

/*
	ELIMINAR CONTACTO

	Elimina un contacto de la tabla; le paso el telefono por parametro a la funcion. Le paso la funcion de DOM JUDGE para que compruebe si el contacto existe.

	Despues de eliminar el contacto, disminuyo el numero de contactos en la tabla.
*/
void Agenda::eliminarContacto(long telefono) {
	
	assertdomjudge(existeContacto(telefono));

	int pos = obtenerPosicion(telefono);

	for (int i = 0; i < tabla[pos].getN(); i++) {
		if (tabla[pos].getValor(i).telefono == telefono) {
			tabla[pos].eliminar(i);
			
		}
	}

	n--;
}