#include "Pila.h"

using namespace std;

Pila::Pila()
{
	primerElemento = nullptr;
}

Pila::~Pila()
{
	Nodo *aux = primerElemento;
	Nodo *borrar;

	while (aux != NULL)
	{
		borrar = aux;
		aux = aux->next;
		delete borrar;
	}
}

void Pila::apilar(char elemento)
{
	//assertdomjudge(elemento >= 'a' && elemento <= 'z');

	Nodo *nuevoNodo = new Nodo(elemento, this->primerElemento);

	this->primerElemento = nuevoNodo;
}

char Pila::desapilar()
{
	assertdomjudge(this->primerElemento != nullptr);

	Nodo *nodo = primerElemento;

	this->primerElemento = primerElemento->next;
	char valor = nodo->valor;
	delete nodo;

	return valor;
}

char Pila::getElemento()
{
	assertdomjudge(this->primerElemento != nullptr);
	return this->primerElemento->valor;
}

bool Pila::estaVacia()
{
	return (this->primerElemento == nullptr);
}

void Pila::mostrarPila()
{
	Nodo *aux = primerElemento;

	while (aux != NULL)
	{
		cout << aux->valor << endl;
		aux = aux->next;
	}
}