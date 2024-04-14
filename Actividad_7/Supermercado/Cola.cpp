#include"Cola.h"
#include <iostream>
using namespace std;

Cola::Cola() {
    principio = NULL;
    final = NULL;
}

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

bool Cola::estaVacia() {
    
    if (principio == NULL) {
        return true;
    }
    return false;
}