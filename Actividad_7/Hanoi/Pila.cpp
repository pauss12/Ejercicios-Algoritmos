#include"Pila.h"
#include"assertdomjudge.h"
using namespace std;

/*
    Constructor ------------------------
    
    Constructor de la clase Pila, que inicializa el nombre de la pila y la cima a NULL.

*/
Pila::Pila(string name)
{
    this->name = name;
    this->cima = NULL;
}

/*
    //Nombre pila ------------------------

    Funcion que devuelve el nombre de la pila.
*/
std::string Pila::nombrePila()
{
    return name;
}

/*
    Apilar ------------------------

    Funcion que sirve para apilar un disco en la pila. Creamos un nuevo nodo con el valor del disco y la cima de la pila que le pasamos por parametros, y lo apilamos en la cima de la pila; es decir, arriba del todo de la pila.

*/
void Pila::apilar(int num)
{
    assertdomjudge(num > 0);

    Nodo *nuevo = new Nodo(num, this->cima);

    this->cima = nuevo;

    cout << "Apilando disco " << num << " en poste " << name << endl;

}
/*
    Desapilar ------------------------

    Funcion que sirve para desapilar un disco de la pila. Eliminamos el nodo que esta en la cima de la pila, y devolvemos el valor del disco que hemos desapilado.


*/
int Pila::desapilar()
{    
    assertdomjudge(this->cima != nullptr);

    Nodo *nodoEliminado = this->cima;

    this->cima = cima->siguiente;

    int valor=nodoEliminado->valor;

    delete nodoEliminado;

    cout << "Desapilando disco " << valor << " del poste " <<name << endl;

    return valor;

}
/*
    Esta vacia ------------------------

    Funcion que sirve para saber si la pila esta vacia o no. Devuelve un booleano, true si esta vacia y false si no lo esta.
*/
bool Pila::estaVacia()
{
    return (this->cima == nullptr);
}

