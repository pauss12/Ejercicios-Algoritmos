
#include "ListaEnlazada.h"

using namespace std;

/*
    Constructor --------------------------

    El constructor de la clase "ListaEnlazada" lo que hace es inicializar el numero de elementos a 0 y la lista a nullptr.
*/
ListaEnlazada::ListaEnlazada()
{
    n = 0;
    lista = nullptr; 
}

/*
    Destructor --------------------------

    El destructor de la clase "ListaEnlazada" lo que hace es liberar la memoria que se ha reservado para la lista.
*/
ListaEnlazada::~ListaEnlazada()
{

    //Me creo un nuevo nodo que apunte al primer elemento de la lista
    Nodo* nodoActual = lista;

    //Me recorro la lista y voy eliminando cada uno de los nodos
    while (nodoActual != nullptr) 
    {
        Nodo* nodoAEliminar = nodoActual;
        nodoActual = nodoActual->siguienteNodo;
        delete nodoAEliminar;
    }

    //Apuntar a null y a 0 el numero de elementos
    lista = nullptr;
    n = 0;
}

/*
    Funcion para obtener el nodo -----------------------

    La funcion "getNodo()" lo que hace es devolver el nodo que se encuentra en la posicion que le pases; se recorre la lista hasta llegar a la posicion que le pases.
*/
Nodo *ListaEnlazada::getNodo(int posicion)
{

    assertdomjudge(posicion >= 0 && posicion < n);

    Nodo* nodoActual = lista;
    for (int i = 0; i < posicion; i++) {
        nodoActual = nodoActual->siguienteNodo;
    }

    return nodoActual;
}

/*
    Funcion para obtener el valor -----------------------

    La funcion "getValor()" lo que hace es devolver el valor que se encuentra en la posicion que le pases.
*/
int ListaEnlazada::getValor(int posicion)
{
    //Compruebo que la posicion sea valida
    assertdomjudge(posicion >= 0 && posicion < n);

    Nodo* nodoObtenido = getNodo(posicion);

    if (nodoObtenido != nullptr) {
        return nodoObtenido->elemento;
    } else {
        // Manejo de error, por ejemplo, lanzar una excepción o retornar un valor especial
        return -1;
    }

}

/*
    Set del valor --------------------------

    La funcion "setValor()" lo que hace es cambiar el valor que se encuentra en la posicion que le pases por el nuevo valor que le pases.
*/
void ListaEnlazada::setValor(int pos, int val)
{
    //Compruebo que la posicion sea valida
    assertdomjudge(pos >= 0 && pos < n);

    //Obtengo el nodo
    Nodo* nodoObtenido = getNodo(pos);

    //Si el nodo no es nulo, le asigno el valor
    if (nodoObtenido != nullptr) 
        nodoObtenido->elemento = val;
}

/*
    GET N --------------------------

    La funcion "getN()" devuelve el tamaño de la lista.
*/
int ListaEnlazada::getN()
{
    return n;
}

/*
    Insertar --------------------------

    La funcion "insertar()" lo que hace es insertar un valor en la posicion que le pases. Se recorre la lista enlazada hasta que llega a la posicion anterior a donde quiere añadir el nuevo nodo; apunta ese nodo anterior al nuevo nodo; y el nuevo nodo apunta al siguiente nodo del nodo anterior.
*/
void ListaEnlazada::insertar(int posicion, int val)
{
    //Compruebo que la posicion sea valida
    assertdomjudge(posicion >= 0 && posicion <= n);

    //Me creo un nuevo nodo
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->elemento = val;

    //Si la lista esta vacia; añado directamente el valor
    if (posicion == 0) {
        nuevoNodo->siguienteNodo = lista;
        lista = nuevoNodo;
    } else {
        Nodo* nodoAnterior = getNodo(posicion - 1);
        nuevoNodo->siguienteNodo = nodoAnterior->siguienteNodo;
        nodoAnterior->siguienteNodo = nuevoNodo;
    }

    //Incremento el numero de elementos
    n++;
}

/*
    Eliminar --------------------------

    La funcion "eliminar()" lo que hace es eliminar el nodo que se encuentra en la posicion que le pases. Se recorre la lista enlazada hasta que llega a la posicion anterior al nodo que quiere eliminar; apunta ese nodo anterior al siguiente nodo del nodo que quiere eliminar; y elimina el nodo que quiere eliminar.
*/
void ListaEnlazada::eliminar(int posicion)
{
    assertdomjudge(posicion >= 0 && posicion < n);

    //Si la posicion es 0, el nodo a eliminar pasa a ser el primer nodo de la lista
    if (posicion == 0) 
    {
        Nodo* nodoAEliminar = lista;
        lista = lista->siguienteNodo;
        delete nodoAEliminar;
    }
    else 
    {
        //Obtengo el nodo anterior al que quiero eliminar
        Nodo* nodoAnterior = getNodo(posicion - 1);

        //Obtengo el nodo a eliminar
        Nodo* nodoAEliminar = nodoAnterior->siguienteNodo;
        
        //El nodo anterior apunta al siguiente nodo del que quiero eliminar
        nodoAnterior->siguienteNodo = nodoAEliminar->siguienteNodo;

        delete nodoAEliminar;
    }

    //Decremento el numero de elementos
    n--;
}

/*
    Concatenar --------------------------

    La funcion "concatenar()" lo que hace es concatenar la lista enlazada que le pases a la lista enlazada que llama a la funcion. Para ello, el ultimo nodo de la lista enlazada que llama a la funcion apunta al primer nodo de la lista enlazada que le pases.
*/
void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar)
{
    //Compruebo que la lista a concatenar no sea nula
    assertdomjudge(listaAConcatenar != nullptr);

    if (lista == nullptr) 
        lista = listaAConcatenar->lista;
    else 
    {
        Nodo* ultimoNodo = getNodo(n - 1);
        ultimoNodo->siguienteNodo = listaAConcatenar->lista;
    }

    //Incremento el numero de elementos
    n += listaAConcatenar->n;

    //Apunto a null la lista a concatenar
    listaAConcatenar->lista = nullptr;
    listaAConcatenar->n = 0;
}

/*
    Buscar --------------------------

    Se recorre la lista enlazada hasta encontrar el elemento que le pases; si lo encuentra, devuelve la posicion en la que se encuentra; si no lo encuentra, devuelve -1.
*/
int ListaEnlazada::buscar(int elementoABuscar)
{
    //Me creo un nodo que apunte al primer elemento de la lista
    Nodo* nodoActual = lista;
    int posicion = 0;

    //Me recorro la lista hasta encontrar el elemento
    while (nodoActual != nullptr)
    {
        if (nodoActual->elemento == elementoABuscar) {
            return posicion;
        }
        nodoActual = nodoActual->siguienteNodo;
        posicion++;
    }

    //Si no encuentro el elemento, devuelvo -1
    return -1;
}
