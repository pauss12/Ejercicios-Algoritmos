#include<iostream>
using namespace std;

/*
    Función que intercambia los valores de dos variables
    @param temp: puntero a un entero
    @param temp2: puntero a un entero
    T(n) = 1
    O(n) = 1

*/

void intercambiar(int *temp, int *temp2)
{
    int	aux;

	aux = *temp;
	*temp = *temp2;
	*temp2 = aux;
}

/*
    Función que ordena un arreglo de enteros con el método de la burbuja
    @param x: puntero a un arreglo de enteros
    @param len: entero, longitud del arreglo
    T(n) = n^2 + 3n - i - 1
    O(n) = n^2
    M(n) = 1
    O(n) = 1
*/
void ordenarBurbuja(int x[], int len)
{
    for(int i = 1; i < len; i++)
    {
        for(int j = 0; j < len - i; j++)
        {
            if (x[j] > x[j + 1])
                intercambiar(&x[j], &x[j + 1]);
        }

        for(int k = 0; k < len; k++)
            cout << x[k] << " ";

        cout << endl;
    }  
}

int main()
{
    int n;

    cin >> n;

    int *x = new int[n];

    for(int i = 0; i < n; i++)
        cin >> x[i];

    ordenarBurbuja(x,n);
    return 0;
}
