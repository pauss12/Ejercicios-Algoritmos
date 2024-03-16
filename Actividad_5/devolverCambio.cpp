
#include <iostream>

using namespace std;

/*
    DESCRIPCION:

    El programa resuelve el problema de devolver cambio. El programa recibe una cantidad de dinero de pesetas por terminal y tiene que devolver el cambio en billetes y monedas de 500, 200, 100, 50, 25, 10, 5 y 1; en el menor numero de billetes y monedas posibles.

    COMPLEJIDAD TEMPORAL: La complejidad temporal del programa es de O(1) ya que el programa recorre un array de 8 elementos.

    COMPLEJIDAD ESPACIAL: La complejidad espacial del programa es de O(1) ya que no tiene que reservar memoria dinamicamente.


*/


void calcularCambio(int *soluciones, int *cambios, int cantidadDevolver)
{
    int temporal = cantidadDevolver;
    
    for (int i = 0; i < 8; i++)
    {
        if (temporal >= cambios[i])
        {
            soluciones[i] = temporal / cambios[i];
            temporal = temporal % cambios[i];
        }
    } 
}

int main(void)
{
    int cantidadDevolver;

    cantidadDevolver = 1;

    while (cantidadDevolver > 0)
    {
        cin >> cantidadDevolver;

        if (cantidadDevolver < 0)
            return 0;

        int cambios[] = {500 , 200, 100, 50, 25, 10, 5, 1};

        int *soluciones = new int[8];

        for (int i = 0; i < 8; i++)
        {
            soluciones[i] = 0;
        }

        calcularCambio(soluciones, cambios, cantidadDevolver);

        for (int i = 0; i < 8; i++)
        {
            cout << soluciones[i] << " ";
        }
        cout << endl;

    }

    return (0);
}