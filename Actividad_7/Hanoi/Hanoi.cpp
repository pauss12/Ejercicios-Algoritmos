#include<iostream>
#include"Pila.h"
#include"assertdomjudge.h"
using namespace std;

/*
    Hanoi ------------------------

    Funcion que resuelve el problema de las torres de Hanoi, que consiste en mover n discos de un poste origen a un poste destino, utilizando un poste temporal.

    Se resuelve de forma recursiva, moviendo n-1 discos del poste origen al poste temporal, moviendo el disco n del poste origen al poste destino, y moviendo n-1 discos del poste temporal al poste destino.
*/
void Hanoi(int n,Pila *origen,Pila *destino,Pila *temporal) 
{
    assertdomjudge(n >= 0);

    if (n==1)
    {
        int disco=origen->desapilar();
        destino->apilar(disco);
    }
    else
    {
        Hanoi(n-1,origen,temporal,destino);

        int disco=origen->desapilar();

        destino->apilar(disco);

        Hanoi(n-1,temporal,destino,origen);
    }
}

/*
    MAIN ------------------------

    Funcion principal que lee el numero de discos, crea las tres pilas, apila los discos en la pila A, y llama a la funcion Hanoi para resolver el problema de las torres de Hanoi.

    Finalmente, desapila los discos de la pila C.
*/
int main()
{  
    Pila *A=new Pila("A");
    Pila *B=new Pila("B");
    Pila *C=new Pila("C");

    int n;

    cin >> n;

    for (int i = n; i > 0; i--)
        A->apilar(i);

    Hanoi(n,A,C,B);

    for(int i = 0; i < n; i++)
        C->desapilar();

    return 0;

}

