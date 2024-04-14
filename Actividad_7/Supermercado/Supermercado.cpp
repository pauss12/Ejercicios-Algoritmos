#include "Supermercado.h"
#include "assertdomjudge.h"

Supermercado::Supermercado(int n)
{
    assertdomjudge(n > 0);
    cajas = new Cola[n];
    n_cajas = n;
}

void Supermercado::nuevoUsuario(int n, int id)
{
    assertdomjudge(n >= 0 && n < n_cajas);
    cajas[n].encolar(id);
}


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


int Supermercado::atenderUsuario(int n)
{
    assertdomjudge(n >= 0 && n < n_cajas);
    return cajas[n].desencolar();
}


bool Supermercado::cajaVacia(int n)
{
    assertdomjudge(n >= 0 && n < n_cajas);
    return cajas[n].estaVacia();
}