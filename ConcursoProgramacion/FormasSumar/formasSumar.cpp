#include <iostream>

using namespace std;

void    calcularPosiblesSumas(int numeroNTotal, int *posiblesCombinaciones, int sumaTotal, int numeroElementos)
{
    if (sumaTotal == numeroNTotal)
    {
        for (int j = 0; j < numeroElementos; j++)
            cout << posiblesCombinaciones[j] << " ";
        cout << endl;
        return ;
    }
    else if (sumaTotal > numeroNTotal)
        return ;
    else if (sumaTotal < numeroNTotal) {

        for (int i = 1; i < numeroNTotal; i++)
        {
            posiblesCombinaciones[numeroElementos] = i;
            calcularPosiblesSumas(numeroNTotal, posiblesCombinaciones, sumaTotal + i, numeroElementos + 1);
        }
    }
}

int main()
{
    int numeroNTotal = 0;

    cin >> numeroNTotal;

    int *posiblesCombinaciones = new int[numeroNTotal];
    
    calcularPosiblesSumas(numeroNTotal, posiblesCombinaciones, 0, 0);
    
    return (0);
}