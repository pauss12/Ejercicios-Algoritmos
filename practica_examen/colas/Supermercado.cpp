#include "Supermercado.h"
#include "assertdomjudge.h"

/*
    Constructor de la clase Supermercado -------------------------------

    Inicializa el numero de cajas y crea un arreglo de cola; y lo apunta a NULL.
*/
Supermercado::Supermercado(int n)
{
    assertdomjudge(n > 0);
    cajas = new Cola[n];
    n_cajas = n;
}

/*  Nuevo usuario ------------------------

    Funcion que sirve para encolar un nuevo usuario en la caja n.

    n: numero de caja
    id: id del usuario

*/
void Supermercado::nuevoUsuario(int n, int id)
{
    assertdomjudge(n >= 0 && n < n_cajas);
    cajas[n].encolar(id);
}

/*
    Cerrar caja ------------------------

    Funcion que sirve para cerrar la caja n

    Va a simular que los usuarios que estan en la caja n se van a la siguiente caja que este abierta, ya que se cierra esa caja.

    las cajas por orden de 0 a N-1 e introduciremos un único usuario por cada caja que no esté vacía. Cuando hayamos introducido un usuario en cada una de las cajas volveremos a empezar desde la caja 0 hasta que no queden más usuarios
    
*/
void Supermercado::cerrarCaja(int n)
{
    assertdomjudge(n >= 0 && n < n_cajas);
    while (!cajas[n].estaVacia())
    {  
        for (int i = 0; i < n_cajas; i++) 
        {
            if ((!cajas[i].estaVacia()) && (i != n)) 
            {
                cajas[i].encolar(cajas[n].desencolar());
            }
        }
    }
}

/*
    Atender usuario ------------------------

    Funcion que sirve para atender al usuario en la caja n
*/
int Supermercado::atenderUsuario(int n)
{
    assertdomjudge(n >= 0 && n < n_cajas);
    return cajas[n].desencolar();
}

/*
    Caja vacia ------------------------

    Funcion que sirve para saber si la caja n esta vacia
*/
bool Supermercado::cajaVacia(int n)
{
    assertdomjudge(n >= 0 && n < n_cajas);
    return cajas[n].estaVacia();
}