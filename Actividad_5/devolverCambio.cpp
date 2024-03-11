
#include <iostream>

using namespace std;

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