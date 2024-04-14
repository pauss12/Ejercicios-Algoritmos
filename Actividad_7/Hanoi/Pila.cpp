#include"Pila.h"
#include"assertdomjudge.h"
using namespace std;

Pila::Pila(string name)
{
    this->name = name;
    this->cima = NULL;
}

std::string Pila::nombrePila()
{
    return name;
}

void Pila::apilar(int num)
{

    assertdomjudge(num>0);

    Nodo *nuevo = new Nodo(num, this->cima);

    this->cima = nuevo;

    cout << "Apilando disco " << num << " en poste " << name << endl;

}
  
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

bool Pila::estaVacia()
{
    return (this->cima == nullptr);
}

