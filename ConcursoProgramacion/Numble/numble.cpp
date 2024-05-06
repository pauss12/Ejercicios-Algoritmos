#include <iostream>

using namespace std;

/*
     //Hago la suma de los valores, si es igual al numero total, pero no he terminado de rellenar los valores, y quedan mas comodines, los relenamos con 0
    if (suma >= numeroTotal)
    {
        for (int k = 0; k < 4; k++)
        {
            if (valoresRecibidos[k] == -1)
            {
                valoresRecibidos[k] = 0;
            }
        }
    }
*/

void calcularSuma(int *valoresRecibidos, int numeroTotal, int suma)
{

    int valorAntesComodin = 0;

    //Por backtracking, tengo que ir probando los numeros entre 0 y 9; cuando encuentre un "-1", lo sustituyo por un numero entre 0 y 9. Si se pasa de numero, lo quita y sigue probando. Sino continua al siguiente numero.
    for (int i = 0; i < 4; i++)
    {
        if (valoresRecibidos[i] == -1)
        {      
            valorAntesComodin = suma;

            for (int j = 0; j < 10; j++)
            {
                suma = suma + j;

                //cout << "Suma: " << suma << " con la prueba de j " << j << endl;

                if (suma == numeroTotal)
                {
                    valoresRecibidos[i] = j;
                    break ;
                }

                if (suma > numeroTotal)
                    suma = valorAntesComodin;
            }
        }
        else
        {
            suma = suma + valoresRecibidos[i];

            if (suma > numeroTotal)
            {
                return ;
            }
        }
        
    }

    cout << "Valores finales: " << endl;
    for (int j = 0; j < 4; j++)
    {
        cout << valoresRecibidos[j] << " ";
    }
    cout << endl;
    
}

int main()
{
    int *valoresRecibidos = new int[4];
    int numeroTotal = 0;
    int n;

    for (int i = 0; i < 4; i++)
    {
        cin >> n;
        if (n >= -1 && n <= 9)
        {
            valoresRecibidos[i] = n;
        }
    }

    cin >> numeroTotal;

    calcularSuma(valoresRecibidos, numeroTotal, 0);

    return (0);
}