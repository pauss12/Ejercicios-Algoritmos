
#include "ListaCircular.h"
#include <iostream>

//CONSTRUCTOR ------------------------------------------------
ListaCircular::ListaCircular()
{
    lista = NULL;
    n = 0;
}

//DESTRUCTOR -------------------------------------------------
ListaCircular::~ListaCircular()
{
    while (n > 0)
    {
       eliminar(0);
    }
}

/*
    GET NODO  ---------------------------

    La funcion "getNodo()" lo que hace es devolver el nodo que se encuentra en la posicion que le pases; se recorre la lista hasta llegar a la posicion que le pases.
*/
Nodo *ListaCircular::getNodo(int posicion)
{

    Nodo* nodoActual = lista;
    int i = 0;

    while (i < posicion)
    {
        nodoActual = nodoActual->siguienteNodo;
        i++;
    }
    return nodoActual;
}

/*
    GET VALOR -------------------------------------------------

    Me dan una posicion, me recorro la lista circular con la ayuda de un contador y de la "n", que es el numero total de nodos que hay dentro de la lista.

    Una vez el "i" coincida con la "posicion", es que ese es el nodo del que quieres coger el valor y devolverlo.
*/
string ListaCircular::getValor(int posicion)
{
    Nodo *temp;
    
    temp = getNodo(posicion);
    return temp->elemento;
}

/*
    SET VALOR ----------------------------------------------------

    Me dan una posicion y una cadena.

    Me recorro la lista circular con la ayuda de un contador y de la "n", que es el numero total de nodos que hay dentro de la lista. 

    Una vez el "i" coincida con la "posicion", es que ese es el nodo al que quieres cambiarle la cadena de texto.
*/
void ListaCircular::setValor(int posicion, string nuevoValor)
{
    Nodo *temp;

    temp = getNodo(posicion);
    temp->elemento = nuevoValor;
}

/*
    GET N ------------------------------------------  

*/
int ListaCircular::getN()
{
    return n;
}

/*
    INSERTAR -----------------------------------

    Me dan una posicion y una cadena; tengo que ir a esa posicion, crear el nodo, integrarlo en esa posicion, mover el resto de nodos y asignarle la cadena que me pasan.

*/
void    ListaCircular::insertar(int posicion, string nuevoValor)
{
    Nodo *nodo = new Nodo();
    nodo->elemento = nuevoValor;

    if (n == 0){

        nodo->anteriorNodo = nodo;
        nodo->siguienteNodo = nodo;
        lista = nodo;

    }else if (posicion == n) {

        Nodo *nodoAnterior = getNodo(n - 1);
        nodo->anteriorNodo = nodoAnterior;
        nodo->siguienteNodo = lista;
        nodoAnterior->siguienteNodo = nodo;
        lista->anteriorNodo = nodo;

    }else {

        Nodo *nodoAnterior = getNodo(posicion - 1);
        Nodo *nodoSiguiente = nodoAnterior->siguienteNodo;
        nodo->anteriorNodo = nodoAnterior;
        nodo->siguienteNodo = nodoSiguiente;
        nodoAnterior->siguienteNodo = nodo;
        nodoSiguiente->anteriorNodo = nodo;
    }
    n++;
}

/*
    ELIMINAR --------------------------------------

    

*/
void ListaCircular::eliminar(int posicion)
{

    if (n == 1)
    {
        delete lista;
        lista = NULL;
    }
    else
    {
        Nodo *nodoAhora = getNodo(posicion);
        Nodo *nodoAnterior = nodoAhora->anteriorNodo;
        Nodo *nodoSiguiente = nodoAhora->siguienteNodo;
        nodoAnterior->siguienteNodo = nodoSiguiente;
        nodoSiguiente->anteriorNodo = nodoAnterior;

        if (posicion == 0)
            lista = nodoSiguiente;

        delete nodoAhora;
    }
    n--;
}

/*
    //GIRAR --------------------------------------------

    Gira todos los elementos de la lista hacia la izquierda o la derecha
    como indique su valor. Si el valor es positivo todos los elementos de la lista se desplazarán tantas posiciones a la derecha como indique el valor. Si el valor es negativo el desplazamiento será hacia la izquierda

*/
void ListaCircular::girar(int p)
{
    if (n == 0)
        return ;
    if (p > 0)
    {
        p = p % n;
        for(int i=0; i<p; i++){
            lista = lista->siguienteNodo;
        }
    }
    else if (p < 0)
    {
        p = -p % n;
        for(int k=0; k<p; k++){
            lista = lista->anteriorNodo;
        }
    }
}