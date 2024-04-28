#include "Supermercado.h"

using namespace std;

/*
    CONSTRUCTOR

    Se crea un arreglo de colas de prioridad, cada una de las cuales representa una caja del supermercado. Y se establece que el valor de n_cajas es igual a "n".que le pasan por parametros.
*/
Supermercado::Supermercado(int n)
{
    cajas = new ColaPrioridad[n];
    n_cajas = n;

}

/*
    NUEVO USUARIO

    Agrega un nuevo usuario a la cola de prioridad de la caja n; se le pasa el "id" del usuario que va a encolar en la caja n.
*/
void Supermercado::nuevoUsuario(int n,int id)
{
    cajas[n].encolar(id);
}

/*
    CERRAR CAJA

    Cierra la caja n, liberando la memoria de la cola de prioridad de la caja n.
*/
void Supermercado::cerrarCaja(int n)
{
    int i = 0;

    while(!cajaVacia(n) && i != n_cajas)
    {
        if(i != n && !cajaVacia(i))
        {
           nuevoUsuario(i, atenderUsuario(n));
        }
        
        i = (i + 1) % n_cajas;
    }

}

/*
    ATENDER USUARIO

    Atiende al usuario de la caja n, desencolando al usuario de la caja n; y lo quita de la lista de esa caja. Y devuelve el "id" del usuario al que se acaba de atender.
*/
int Supermercado::atenderUsuario(int n)
{
    return cajas[n].desencolar();
}

/*
    CAJA VACIA

    Le pasas un entero, que va a ser el numero de la caja que quieres comprobar si esta vacia o no. Si la caja n está vacía, devuelve true y false en caso contrario.

*/
bool Supermercado::cajaVacia(int n)
{
    return cajas[n].estaVacia();
}