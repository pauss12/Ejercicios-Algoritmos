#include "Nodo.h"
#include <iostream>
#include <string>
#include <stdlib.h>

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}


class Pila
{
	private:
		Nodo *primerElemento;

	public:
		Pila();
		~Pila();
		void apilar(char elemento);
		char desapilar();
		char getElemento();
		bool estaVacia();
		void mostrarPila();
};
