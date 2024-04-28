#include "ColaPrioridad.h"
#include <iostream>
#include "assertdomjudge.h"

using namespace std;

/*
    ENCOLAR -----------------------------------------------------------

    Recibe un numero que indica el orden de llegada de un cliente que llegan al supermercado y lo pondra al final de la lista. Como es cola de prioridad, el cliente que llegue con un numero menor sera atendido primero e ira escalando en posiciones dentro del monticulo.

    Ira subiendo en el monticulo escalando a sus padres hasta que llegue a la raiz, ya que no puede seguir subiendo.
*/
void ColaPrioridad::encolar(int nuevoElemento)
{
    this->vector.insertarAlFinal(nuevoElemento);

    int posActual = this->vector.getN() - 1;
    int posPadre = (posActual - 1) / 2;

    while (posActual > 0 && this->vector.getValor(posActual) < this->vector.getValor(posPadre))
    {
        int valorActual = this->vector.getValor(posActual);
        int valorPadre = this->vector.getValor(posPadre);

        this->vector.setValor(posActual, valorPadre);
        this->vector.setValor(posPadre, valorActual);

        posActual = posPadre;
        posPadre = (posActual - 1) / 2;
    }
}

/*
    DESENCOLAR -----------------------------------------------------------

    Metodo que elimina el primer elemento de la cola de prioridad, que es el que tiene la prioridad mas alta. Para ello, se intercambia el primer elemento con el ultimo y se elimina el ultimo elemento. Luego, se reestructura el monticulo para que el elemento que ha subido a la raiz, baje a su posicion correcta.
*/
int ColaPrioridad::desencolar()
{
    assertdomjudge(!this->estaVacia());

    int valorDesencolar = this->vector.getValor(0);
    int lastValue = this->vector.getValor(this->vector.getN() - 1);

    this->vector.setValor(0, lastValue);
    
    this->vector.eliminarAlFinal();

    this->reestructurar();

    return valorDesencolar;
}

/*
    ESTA VACIA -----------------------------------------------------------

    Metodo que devuelve un booleano indicando si la cola de prioridad esta vacia o no. Para ello, se comprueba si la "N", con la funcion de "getN()" es 0 o no lo es.
*/
bool ColaPrioridad::estaVacia()
{
    return this->vector.getN() == 0;
}

/*
    REESTRUCTURAR -----------------------------------------------------------

    Metodo que reestructura el monticulo para que el elemento que ha subido a la raiz, baje a su posicion correcta. Para ello, se compara el elemento con sus hijos y se intercambia con el hijo que tenga mayor prioridad. Se seguira intercambiando con el hijo que tenga mayor prioridad hasta que el elemento sea mayor que sus hijos.
*/
void ColaPrioridad::reestructurar()
{
    if (this->vector.getN() > 1)
    {
        int tam = this->vector.getN();
        int pos = 0;

        while (true)
        {
            int hijoIzq = 2 * pos + 1;
            int hijoDer = 2 * pos + 2;
            int menor = pos;

            if (hijoIzq < tam && this->vector.getValor(hijoIzq) < this->vector.getValor(menor))
                menor = hijoIzq;

            if (hijoDer < tam && this->vector.getValor(hijoDer) < this->vector.getValor(menor))
                menor = hijoDer;

            if (menor != pos){

                int aux = this->vector.getValor(menor);
                this->vector.setValor(menor, this->vector.getValor(pos));
                this->vector.setValor(pos, aux);

                pos = menor;

            }else{

                break;
				
            }
        }
    }
}