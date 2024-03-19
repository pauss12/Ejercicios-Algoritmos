#include "ListaContigua.h"

using namespace std;

/*
    Constructor -----------------------------------

    El constructor de la clase "ListaContigua" lo que hace es inicializar la capacidad de la lista a 0, el tamaño de la lista a 0, el vector a nullptr y el incremento a 0.
*/
ListaContigua::ListaContigua(int incremento)
{
    this->incremento = incremento;
    capacidad = 0;
    n = 0;
    vector = nullptr;
}

/*
    Destructor -----------------------------------

    El destructor de la clase "ListaContigua" lo que hace es liberar la memoria que se ha reservado para el vector.
*/
ListaContigua::~ListaContigua()
{
    free(vector);
}

/*
    GET VALOR -----------------------------------

    La funcion "getValor()" lo que hace es coger el valor de la lista en la posicion que le digas y te lo devuelve.
*/
int ListaContigua::getValor(int posicion)
{
    assertdomjudge(posicion < n);
    return vector[posicion];
}

/*
    SET VALOR -----------------------------------

    La funcion "setValor()" lo que hace es cambiar el valor de la lista en la posicion que le digas por el nuevo valor que le pases.
*/
void ListaContigua::setValor(int posicion, int nuevoValor)
{
    assertdomjudge(posicion < n);
    vector[posicion] = nuevoValor;
}

/*
    GET N -----------------------------------

    La funcion "getN()" devuelve el tamaño de la lista.
*/
int ListaContigua::getN()
{
    return n;
}

/*
    GET CAPACIDAD -----------------------------------

    La funcion "getCapacidad()" lo que hace es devolver la capacidad de la lista.
*/
int ListaContigua::getCapacidad()
{
    return capacidad;
}

/*
    INSERTAR -----------------------------------

    La funcion de "insertar()" lo que va a hacer es incluir el nuevo valor que le pasas, en la posicion que te diga. Para ello, compruebo que la posicion que me pasan es menor o igual que el tamaño de la lista. Si es asi, compruebo si el tamaño de la lista es igual a la capacidad de la lista, si es asi, aumento la capacidad de la lista en el incremento. Despues, copio los elementos de la lista desde la posicion "posicion" hasta el final de la lista en la posicion "posicion+1". Finalmente, en la posicion "posicion" de la lista, meto el nuevo valor y aumento el tamaño de la lista en "1
*/
void ListaContigua::insertar(int posicion, int nuevoValor)
{
    assertdomjudge(posicion <= n);

    if (n == capacidad)
    {
        capacidad += incremento;
        vector = (int *)realloc(vector, capacidad * sizeof(int));
    }

    memmove(&vector[posicion + 1], &vector[posicion], (n - posicion) * sizeof(int));

    vector[posicion] = nuevoValor;

    n++;
}


/*
    ELIMINAR -----------------------------------

    La función memmove() copia n bytes desde la ubicación de memoria src a la ubicación de memoria dest.

    La funcion "eliminar" elimina el elemento en la posicion "posicion" de la lista. Para ello, compruebo que la posicion que me pasan es menor que el tamaño de la lista. Si es asi, copio los elementos de la lista desde la posicion "posicion+1" hasta el final de la lista en la posicion "posicion". Despues, si el tamaño de la lista es menor que la capacidad de la lista menos el incremento, reduzco la capacidad de la lista en el incremento. Finalmente, decremento el tamaño de la lista.
*/
void ListaContigua::eliminar(int posicion)
{
    assertdomjudge(posicion < n);

    memmove(&vector[posicion], &vector[posicion + 1], (n - posicion - 1) * sizeof(int));

    if (n < capacidad - incremento)
    {
        capacidad -= incremento;
        vector = (int *)realloc(vector, capacidad * sizeof(int));
    }

    n--;
}

/*
    CONCATENAR -----------------------------------

    La funcion "concatenar()" lo que hace es fusionar una array a la lista ya hecha anteriormente; para ello, se crea un nuevo vector de tamaño "nuevaCapacidad" que es la suma de la capacidad de la lista original y la capacidad de la lista a concatenar. Despues, se copian los elementos de la lista a concatenar en el nuevo vector desde la posicion "n" de la lista original. Finalmente, se actualiza el tamaño de la lista y la capacidad de la lista. 

*/
void ListaContigua::concatenar(ListaContigua *listaAConcatenar)
{
    int nuevaCapacidad = capacidad + listaAConcatenar->getN();
    vector = (int *)realloc(vector, nuevaCapacidad * sizeof(int));
    memmove(&vector[n], listaAConcatenar->vector, listaAConcatenar->getN() * sizeof(int));
    n += listaAConcatenar->getN();
    capacidad = nuevaCapacidad;
}

/*
    BUSCAR -----------------------------------

    La funcion "buscar()" lo que hace es buscar un elemento en la lista. Para ello, recorro la lista y si el elemento que estoy buscando es igual al elemento de la lista en la posicion "i", devuelvo la posicion "i". Si no encuentro el elemento, devuelvo "-1".
*/
int ListaContigua::buscar(int elementoABuscar)
{
    for (int i = 0; i < n; i++)
    {
        if (vector[i] == elementoABuscar)
        {
            return i;
        }
    }
    return -1;
}