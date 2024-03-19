#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include "Nodo.h"
#define assertdomjudge(x) if(!(x)) {std::cout << "ERROR" << std::endl; exit(0);}
#include <iostream>
#include <cstring>

class ListaEnlazada
{

    private:
        int n;
        Nodo *lista;
        Nodo *getNodo(int posicion);

    public:

        ListaEnlazada();

        int getValor(int posicion);

        void setValor(int posicion, int nuevoValor);

        int getN(); 

        void insertar (int pos, int val);

        void eliminar (int posicion);

        void concatenar(ListaEnlazada *listaAConcatenar);

        int buscar(int elementoABuscar);

        ~ListaEnlazada();

};

#endif