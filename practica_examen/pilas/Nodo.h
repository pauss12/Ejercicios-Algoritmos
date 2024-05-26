#include <stdlib.h>

using namespace std;

class Nodo
{
	public:
		char valor;
		Nodo *next;
	
		Nodo(char val, Nodo *siguiente = nullptr)
		{
			valor = val;
			next = siguiente;
		}
};
