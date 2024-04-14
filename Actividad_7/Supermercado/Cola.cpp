#include"Cola.h"
#include <iostream>
using namespace std;

/*
    Constructor ------------------------

    Constructor de la clase Cola, que inicializa los punteros principio y final a NULL.

*/
Cola::Cola() {
    principio = NULL;
    final = NULL;
}

/*
    Encolar ------------------------

    Funcion que sirve para encolar un elemento en la cola. Recibe un entero que seria el valor del nodo a encolar.


*/
void Cola::encolar(int num) {

    Nodo *nuevo = new Nodo(num);

    if (principio == NULL) {
        principio = nuevo;
        final = nuevo;
    } else {
        
        final = nuevo;
        Nodo *aux = principio;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

/*
    Desencolar ------------------------

    Funcion que sirve para desencolar un elemento de la cola. Deuelve un entero que seria el valor del nodo desencolado, el orden en el que estaria en la lista.

*/
int Cola::desencolar() {

    if (principio == NULL) {

        return -1;
    }
    else{
        
        Nodo *aux = principio;
        int num = aux->valor;
        principio = aux->siguiente;
        delete aux;
        if (principio == NULL) {
            final = NULL;
        }
        return num;
    }
}

/*
    Esta vacia ------------------------

    Funcion que sirve para saber si la cola esta vacia o no. Devuelve un booleano, true si esta vacia y false si no lo esta.

*/
bool Cola::estaVacia() {
    
    if (principio == NULL) {
        return true;
    }
    return false;
}