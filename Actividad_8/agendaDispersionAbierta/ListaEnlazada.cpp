#include "ListaEnlazada.h"
#include "assertdomjudge.h"
#include <iostream>
using namespace std;


/*
    GET NODO

    devuelve el nodo en una posicion dada; le pasas la posicion y te devuelve el nodo en esa posicion. Le paso la funcion de "assertdomjudge" para que compruebe que la posicion es correcta; y recorro la lista hasta llegar a la posicion dada, y devuelvo el nodo en esa posicion
*/
Nodo *ListaEnlazada::getNodo(int posicion) 
{
    assertdomjudge(posicion >= 0 && posicion < n );

    Nodo *nodo = NULL;
    nodo = lista;

    for (int i=0; i<posicion; i++) {
        nodo = nodo->siguienteNodo;
    }

    return nodo;
}

/*
    CONSTRUCTOR

    constructor de la clase ListaEnlazada. Inicializa la lista a NULL y el numero de nodos a 0
*/

ListaEnlazada::ListaEnlazada() 
{
    this->lista = NULL;
    this->n = 0;

}

/*
    DESTRUCTOR

    destructor de la clase ListaEnlazada. Elimina todos los nodos de la lista y pone el numero de nodos a 0, ademas de apuntar la lista a NULL una vez este vacia.
*/
ListaEnlazada::~ListaEnlazada() 
{
    Nodo *nodo = lista;

    while (nodo != NULL) {
        Nodo *nodoSiguiente = nodo->siguienteNodo;
        delete nodo;
        nodo = nodoSiguiente;
    }

    lista = NULL;
    n = 0;
}

/*
    GET N

    devuelve el tama�o de la lista, que es un entero que indica el numero de nodos que tiene la lista, el cual es un atributo de la clase
*/
int ListaEnlazada::getN() 
{
    return n;
}

/*
    GET VALOR

    devuelve el valor de un nodo en una posicion dada; le pasas la posicion y te devuelve el valor del nodo en esa posicion. Le paso la funcion de "assertdomjudge" para que compruebe que la posicion es correcta; y uso la funcion de "getNodo" para que me devuelva el nodo en la posicion dada, y asi poder devolver su valor
*/
Contacto ListaEnlazada::getValor(int posicion) 
{
    assertdomjudge(posicion >= 0 && posicion < getN());

    Nodo *nodo = getNodo(posicion);
    return nodo->elemento;
}

/*
    SET VALOR

    modifica el valor de un nodo en una posicion dada; le pasas la posicion y el nuevo valor del nodo. Le paso la funcion de "assertdomjudge" para que compruebe que la posicion es correcta; y uso la funcion de "getNodo" para que me devuelva el nodo en la posicion dada, y asi poder modificar su valor
*/
void ListaEnlazada::setValor(int posicion, Contacto nuevoValor) 
{
    assertdomjudge(posicion >= 0 && posicion < getN());

    Nodo *nodo = getNodo(posicion);
    nodo->elemento = nuevoValor;
}

/*
    INSERTAR

    inserta un nodo en una posicion dada
*/
void ListaEnlazada::insertar(int posicion, Contacto nuevoValor) 
{
    assertdomjudge(posicion >= 0 && posicion <= getN());

    Nodo *temp;
    Nodo *nodo = new Nodo();
    nodo->elemento = nuevoValor;

    if (posicion == 0) {
        nodo->siguienteNodo = lista;
        lista = nodo;
    } else {
        temp = getNodo(posicion - 1);
        nodo->siguienteNodo = temp->siguienteNodo;
        temp->siguienteNodo = nodo;
    }

    n++;
}

/*
    ELIMINAR

    elimina un nodo en una posicion dada
*/
void ListaEnlazada::eliminar(int posicion) 
{
    assertdomjudge(posicion >= 0 && posicion < getN());

    Nodo *anterior;
    Nodo *siguiente;
    Nodo *aux = getNodo(posicion);

    if (posicion == 0) 
    {
        lista = lista->siguienteNodo;
    } else {

        anterior = getNodo(posicion - 1);
        siguiente = getNodo(posicion)->siguienteNodo;
        anterior->siguienteNodo = siguiente;
    }

    delete aux;
    n--;
}

/*
    CONCATENAR

    concatena una lista al final de la lista actual
*/
void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar) 
{
    int i = 0;

    while (i < listaAConcatenar->getN()) 
    {
        insertar(getN(), listaAConcatenar->getValor(i));
        i++;
    }
}

/* 
    BUSCAR

    busca un nodo en la lista; le pasas un valor y te devuelve la posicion del nodo que contiene ese valor
*/
int ListaEnlazada::buscar(Contacto elementoABuscar) 
{
    Nodo *listaInicial = lista;
    int i = 0;

    while (i < n) 
    {
        if (listaInicial->elemento.telefono == elementoABuscar.telefono) 
        {
            return i;
        }
        else
        {
            listaInicial = listaInicial->siguienteNodo;
        }
        i++;
    }

    return -1;
}