
#include "ListaCircular.h"

using namespace std;

//CONSTRUCTOR ------------------------------------------------
ListaCircular::ListaCircular()
{
    lista = nullptr;
    n = 0;
}

//DESTRUCTOR -------------------------------------------------
ListaCircular::~ListaCircular()
{
    Nodo *nueva_lista = lista;

    while (n > 0)
    {
        delete nueva_lista;
        nueva_lista = nueva_lista->siguienteNodo;
        n--;
    }

    //Apuntar la lista a NULL y el numero de elementos a "0"
    lista = nullptr;
    n = 0;
}

/*
    GET VALOR -------------------------------------------------

    Me dan una posicion, me recorro la lista circular con la ayuda de un contador y de la "n", que es el numero total de nodos que hay dentro de la lista.

    Una vez el "i" coincida con la "posicion", es que ese es el nodo del que quieres coger el valor y devolverlo.
*/
string ListaCircular::getValor(int posicion)
{
    Nodo *temp = lista;
    int  i = 0;

    while (i < n)
    {

        if (i == posicion)
            return (temp->elemento);
        temp = temp->siguienteNodo;
        i++;
    }
}

/*
    SET VALOR ----------------------------------------------------

    Me dan una posicion y una cadena.

    Me recorro la lista circular con la ayuda de un contador y de la "n", que es el numero total de nodos que hay dentro de la lista. 

    Una vez el "i" coincida con la "posicion", es que ese es el nodo al que quieres cambiarle la cadena de texto.
*/
void ListaCircular::setValor(int posicion, string nuevoValor)
{
    Nodo *temp = lista;
    int  i = 0;

    while (i < n)
    {

        if (i == posicion)
        {
            temp->elemento = nuevoValor;
        }
        temp = temp->siguienteNodo;
        i++;
    }
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
    Nodo *nueva_lista = lista;
    Nodo *nodo = ListaCircular();
    int  i = 0;

    //Me voy recorriendo la lista circular
    while (i < n)
    {
        if (i == posicion)
        {
            nodo.elemento = nuevoValor;

            Nodo *siguienteNodoFinal = nueva_lista.siguienteNodo;

            //cambiar los punteros para meterlo en esa posicion
            nueva_lista.anteriorNodo = nodo;
            nodo.siguienteNodo = siguienteNodoFinal;

        }
        nueva_lista = nueva_lista->siguienteNodo;
        i++;
    }
}

/*
    ELIMINAR --------------------------------------

    

*/