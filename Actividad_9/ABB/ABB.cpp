#include "ABB.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;

/*
    CONSTRUCTOR ----------------------------------------------------------

    Inicializa el arbol binario de busqueda vacio. y el valor de n a 0.
*/
ABB::ABB(){

  this->n = 0;
  this->raiz = NULL;

}

/*
    DESTRUCTOR ----------------------------------------------------------

    Elimina el arbol binario de busqueda. Lo que va a hacer es llamar dinamicamente a la funcion eliminarSubarbol, que se encarga de liberar la memoria de todos los nodos del arbol. Y finalmente pone el puntero raiz a NULL y el valor de n a 0.
*/
ABB::~ABB(){

  delete[] raiz;

}

/*
    IMPRIMIR RECORRIDO ----------------------------------------------------------

    Imprime el contenido de los nodos del arbol binario de busqueda en preorden. Si el arbol esta vacio imprime "VACIO". Pero sino, va a llamar a la funcion imprimirRecorrido que se encarga de imprimir el contenido de los nodos del arbol en preorden.
*/
void ABB::imprimir()
{
  if (raiz == NULL)
    cout << "VACIO" << endl;
  else   
      imprimirRecorrido(raiz);    
}

/*
    ELIMINAR

    Elimina un elemento del arbol binario de busqueda.
*/
void ABB::eliminar(int elementoAEliminar){
   
    Nodo* nodoAEliminar = buscar(elementoAEliminar);

    eliminarNodo(nodoAEliminar);

    n--;

    if (n == 0)
      raiz = NULL;

}

/*
    IMPRIMIR RECORRIDO ----------------------------------------------------------

    Imprime el contenido de los nodos del arbol binario de busqueda en preorden. Si el arbol esta vacio imprime "VACIO". Pero sino, va a llamar a la funcion imprimirRecorrido que se encarga de imprimir el contenido de los nodos del arbol en preorden.
*/
void ABB::imprimirRecorrido(Nodo *raizSubarbol)
{
    cout << raizSubarbol->contenido << endl;
    
    if (raizSubarbol->hijoIzquierdo != NULL)
    {
      cout << "I";
      imprimirRecorrido(raizSubarbol->hijoIzquierdo);
      cout << endl;
    }

    if (raizSubarbol->hijoDerecho != NULL)
    {
      cout << "D";
      imprimirRecorrido(raizSubarbol->hijoDerecho);
      cout << endl;
    }
}

/*
    LEER ARBOL ----------------------------------------------------------

    Va a llamar a la funcion de leer el subarbol, que se encarga de leer el contenido de los nodos del arbol binario de busqueda. Y finalmente asigna el puntero raiz al arbol leido.
*/
void ABB::leerArbol()
{
    raiz = leerSubarbol(NULL);
}

/*
    LEER SUBARBOL ----------------------------------------------------------

    Lee un subarbol del arbol binario de busqueda. Si el contenido del nodo es negativo, devuelve NULL. Sino, crea un nodo y le asigna el contenido. Luego llama recursivamente a leerSubarbol para leer el hijo izquierdo y el hijo derecho del nodo. Y finalmente devuelve el nodo.

*/
Nodo* ABB::leerSubarbol(Nodo *padre)
{
    int contenido;
    
    cin >> contenido;

    if (contenido >= 0)
    {
        Nodo *arbol = new Nodo;
        arbol->contenido = contenido;
        arbol->hijoIzquierdo = leerSubarbol(arbol);
        arbol->hijoDerecho = leerSubarbol(arbol);
        arbol->padre = padre;

        return arbol;
    }
    else
        return NULL;
}

/*
    INSERTAR

    Inserta un nuevo elemento en el arbol binario de busqueda. Si la "n" es 0, el nuevo nodo va a ser la raiz. Sino, va a buscar el hueco donde insertar el nuevo nodo y lo inserta.
*/
void ABB::insertar(int nuevoElemento){

  Nodo* nuevoNodo = new Nodo;

  nuevoNodo->contenido = nuevoElemento;
  nuevoNodo->padre = NULL;
  nuevoNodo->hijoDerecho = NULL;
  nuevoNodo->hijoIzquierdo = NULL;

  if (n == 0){

    raiz = nuevoNodo;

  }else{

    Nodo* nodoPadre = buscarHueco(raiz, nuevoElemento);

    if (nuevoElemento <= nodoPadre->contenido)
      nodoPadre->hijoIzquierdo = nuevoNodo;
    else
      nodoPadre->hijoDerecho = nuevoNodo;

    nuevoNodo->padre = nodoPadre;

  }
  n++;
}

/*
    BUSCAR

    Busca un elemento en el arbol binario de busqueda. Si el arbol esta vacio, devuelve NULL. Sino, llama a la funcion buscarRecursivo que se encarga de buscar el elemento en el arbol.
*/
Nodo* ABB::buscar(int elementoABuscar){
  return buscarRecursivo(raiz, elementoABuscar);
}

/*
    ES ARBOL ABB
*/
bool ABB::esABB(){
  return esSubABB(raiz);
}

/*
    ES ARBOL AVL; va a llamar a la funcion esABB para verificar si es un arbol binario de busqueda. Si es un arbol binario de busqueda, va a llamar a la funcion esSubAVL para verificar si es un arbol AVL.
*/
bool ABB::esAVL(){

  if(esABB()){

    if(esSubAVL(raiz))
      return true;

  }
  return false;
}

/*
    ELIMINAR SUBARBOL

    Elimina un subarbol del arbol binario de busqueda. Si el subarbol es la raiz, lo elimina. Sino, llama a la funcion eliminarSubarbol que se encarga de eliminar el subarbol.
*/
void ABB::eliminarSubarbol(Nodo* raizSubarbol){

  assertdomjudge(raizSubarbol != NULL);

  Nodo* nodoParent = raizSubarbol->padre;

  if(raizSubarbol->hijoIzquierdo != NULL)
    eliminarSubarbol(raizSubarbol->hijoIzquierdo);

  if(raizSubarbol->hijoDerecho != NULL)
    eliminarSubarbol(raizSubarbol->hijoDerecho);

  if(nodoParent != NULL){

    if (nodoParent->hijoIzquierdo == raizSubarbol)
      nodoParent->hijoIzquierdo = NULL;


    if(nodoParent->hijoDerecho == raizSubarbol)
      nodoParent->hijoDerecho = NULL;

  }
  delete raizSubarbol;
}

/*
    BUSCAR HUECO

    Busca el nodo donde insertar un nuevo nodo en el arbol binario de busqueda. Si el arbol esta vacio, devuelve NULL. Sino, llama a la funcion buscarHueco que se encarga de buscar el nodo donde insertar el nuevo nodo.
*/
Nodo* ABB::buscarHueco(Nodo *raizSubarbol, int elementoAInsertar){

  if (raizSubarbol == NULL)
    return NULL;

  if (elementoAInsertar <= raizSubarbol->contenido) {

    if (raizSubarbol->hijoIzquierdo == NULL) 
      return raizSubarbol;

    return buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar);

  }else{
  
    if(raizSubarbol->hijoDerecho == NULL)
      return raizSubarbol;

    return buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar);
  }
}

/*
    BUSCAR RECURSIVO

    Busca un elemento en el arbol binario de busqueda. Si el arbol esta vacio, devuelve NULL. Sino, llama a la funcion buscarRecursivo que se encarga de buscar el elemento en el arbol.
*/
Nodo* ABB::buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar) {

  Nodo* nodoEncontrado = new Nodo();

  if(raizSubarbol == NULL)
    return NULL;
  else if(elementoABuscar == raizSubarbol->contenido)
     return raizSubarbol;  
  else if(elementoABuscar < raizSubarbol->contenido)
    raizSubarbol = buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
  else if(elementoABuscar > raizSubarbol->contenido)
    raizSubarbol = buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);


  return raizSubarbol;

}

/*
    BUSCAR MAXIMO

    Busca el nodo con el contenido maximo del arbol binario de busqueda. Si el arbol esta vacio, devuelve NULL. Sino, llama a la funcion buscarMaximo que se encarga de buscar el nodo con el contenido maximo del arbol.
*/
Nodo* ABB::buscarMaximo(Nodo* raizSubarbol){

  assertdomjudge(raizSubarbol != NULL);

  Nodo* maximo = new Nodo();

  if (raizSubarbol->hijoDerecho == NULL){

    maximo =  raizSubarbol;

  }else{
      
    maximo = buscarMaximo(raizSubarbol->hijoDerecho);

  }
  
  return maximo;

}

/*
    BUSCAR MINIMO

    Busca el nodo con el valor minimo en un subarbol; mediante una llamada recursiva. Checkea con el "assertdomjudge" que el nodo no sea NULL. Si el nodo es NULL, devuelve NULL. Sino, si el hijo izquierdo del nodo es NULL, devuelve el nodo. Sino, llama recursivamente a la funcion buscarMinimo.
*/
Nodo* ABB::buscarMinimo(Nodo* raizSubarbol){

  assertdomjudge(raizSubarbol != NULL);

  Nodo* minimo = new Nodo();

  if (raizSubarbol->hijoIzquierdo == NULL){

    minimo = raizSubarbol;

  }else{

    minimo = buscarMinimo(raizSubarbol->hijoIzquierdo);

  }

  return minimo;
  
}

/*
    ELIMINAR NODO

    Elimina un nodo del arbol binario de busqueda. LLama a la funcion "assertdomjudge" para verificar que el nodo no sea NULL; si es NULL, va a lanzar un error y va a terminar el programa.
    
    Si el nodo es una hoja, lo elimina. Sino, si el nodo tiene un solo hijo, lo elimina. Sino, si el nodo tiene dos hijos, busca el maximo del hijo izquierdo y lo reemplaza por el nodo a eliminar. Y finalmente elimina el nodo a reemplazar.
*/
void ABB::eliminarNodo(Nodo* nodoParaEliminar){
  
  assertdomjudge(nodoParaEliminar != NULL);

  Nodo* nodo_borrar = new Nodo();

  if(nodoParaEliminar->hijoDerecho == NULL && nodoParaEliminar->hijoIzquierdo == NULL) {

    if(nodoParaEliminar == raiz)
      raiz = NULL;
    else if(nodoParaEliminar == nodoParaEliminar->padre->hijoDerecho)
      nodoParaEliminar->padre->hijoDerecho = NULL;
    else
      nodoParaEliminar->padre->hijoIzquierdo = NULL;

    delete nodoParaEliminar;

  }else {

    if(nodoParaEliminar->hijoDerecho == NULL && nodoParaEliminar->hijoIzquierdo != NULL){

      nodo_borrar = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
      nodoParaEliminar->contenido = nodo_borrar->contenido;
      eliminarNodo(nodo_borrar);

    }else if(nodoParaEliminar->hijoDerecho != NULL && nodoParaEliminar->hijoIzquierdo == NULL){ 

      nodo_borrar = buscarMinimo(nodoParaEliminar->hijoDerecho);
      nodoParaEliminar->contenido = nodo_borrar->contenido;
      eliminarNodo(nodo_borrar);

    }else if(nodoParaEliminar->hijoDerecho != NULL && nodoParaEliminar->hijoIzquierdo != NULL){ 

      if(alturaNodo(nodoParaEliminar->hijoDerecho) > alturaNodo(nodoParaEliminar->hijoIzquierdo)){ 

        nodo_borrar = buscarMinimo(nodoParaEliminar->hijoDerecho);
        nodoParaEliminar->contenido = nodo_borrar->contenido;
        eliminarNodo(nodo_borrar);

      }else{

        nodo_borrar = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
        nodoParaEliminar->contenido = nodo_borrar->contenido;
        eliminarNodo(nodo_borrar);

      }
    }
  }
}

/*
    ALTURA NODO

    Calcula la altura de un nodo del arbol binario de busqueda. Si el nodo es NULL, devuelve -1. Sino, calcula la altura del lado derecho y del lado izquierdo del nodo. Y finalmente devuelve la altura del nodo.
*/
int ABB::alturaNodo(Nodo* raizSubarbol){

  if(raizSubarbol == NULL)
    return -1;

  int alturaLadoDerecha = alturaNodo(raizSubarbol->hijoDerecho);
  int alturaLadoIzquierda = alturaNodo(raizSubarbol->hijoIzquierdo);
 
  if(alturaLadoIzquierda > alturaLadoDerecha){

    return alturaLadoIzquierda + 1;

  }else{

    return alturaLadoDerecha + 1;

  }
  
}

/*
    ES SUBABB

    Verifica si un subarbol es un arbol binario de busqueda. Si el subarbol es NULL, devuelve true. Sino, verifica si el hijo izquierdo del nodo es menor al nodo y si el hijo derecho del nodo es mayor al nodo. Y finalmente llama recursivamente a la funcion esSubABB para verificar si el hijo izquierdo y el hijo derecho del nodo son arboles binarios de busqueda.
*/
bool ABB::esSubABB(Nodo* raizSubarbol) {
    
  if(raizSubarbol == NULL){

    return true;

  }else{

    bool esABBIzquierda;
    bool esABBDerecha;

    esABBIzquierda = true;
    esABBDerecha = true;
  
    if(raizSubarbol->hijoIzquierdo != NULL)
      esABBIzquierda = (buscarMaximo(raizSubarbol->hijoIzquierdo)->contenido < raizSubarbol->contenido) && esSubABB(raizSubarbol->hijoIzquierdo);

    if (raizSubarbol->hijoDerecho != NULL)
      esABBDerecha = (buscarMinimo(raizSubarbol->hijoDerecho)->contenido > raizSubarbol->contenido) && esSubABB(raizSubarbol->hijoDerecho);
    
    return (esABBIzquierda && esABBDerecha);
  }
}

/*
    ES SUBAVL

    Verifica si un subarbol es un arbol AVL. Si el subarbol es NULL, devuelve true. Sino, calcula la diferencia de alturas entre el hijo izquierdo y el hijo derecho del nodo. Si la diferencia de alturas es mayor a 1 o menor a -1, devuelve false. Sino, llama recursivamente a la funcion esSubAVL para verificar si el hijo izquierdo y el hijo derecho del nodo son arboles AVL.
*/
bool ABB::esSubAVL(Nodo* raizSubarbol){

  if (raizSubarbol == NULL){

    return true;

  }

  int diferenciaAlturas = alturaNodo(raizSubarbol->hijoIzquierdo) - alturaNodo(raizSubarbol->hijoDerecho);

  if (diferenciaAlturas > 1 || diferenciaAlturas < -1){

    return false;

  }

  return esSubAVL(raizSubarbol->hijoIzquierdo) && esSubAVL(raizSubarbol->hijoDerecho);

}

