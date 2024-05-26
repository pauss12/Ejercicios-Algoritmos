#include "Pila.h"
#include<iostream>

using namespace std;

bool esPareja(char apertura, char cierre)
{
    return (apertura == '(' && cierre == ')') ||
           (apertura == '{' && cierre == '}') ||
           (apertura == '[' && cierre == ']');
}

int main()
{
	string cadena;
	Pila *nuevaPila = new Pila();
	bool balanceado = true;

	getline(cin, cadena);
	
	cout << endl;
	//cout << cadena << endl;

	for (int i = 0; i < cadena.length(); i++)
	{
		char caracter = cadena.at(i);

		if (caracter == '(' || caracter == '{' || caracter == '[')
			nuevaPila->apilar(caracter);
		else if (caracter == ')' || caracter == '}' || caracter == ']')
        {
            if (nuevaPila->estaVacia())
            {
                balanceado = false;
                break;
            }
            
			//Cojo el elemento de arriba del todo de la pila
			char tope = nuevaPila->getElemento();

			//Si coincide con su caracter de apertura, lo desapila
            if (esPareja(tope, caracter))
            {
                nuevaPila->desapilar();
            }
            else
            {
				//Si no, tiene que escribir un 0, porque ha habido un error
                balanceado = false;
                break;
            }
        }
    }

	if (!nuevaPila->estaVacia())
        balanceado = false;

	if (balanceado == true)
		cout << "1" << endl;
	else
		cout << "0" << endl; 

	return 0;
}
