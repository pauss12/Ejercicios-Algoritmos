#include<iostream>
using namespace std;

void intercambiar(int *temp, int *temp2)
{
    int	aux;

	aux = *temp;
	*temp = *temp2;
	*temp2 = aux;
}

void ordenarInsercion(int x[], int len)
{
    for(int i = 1; i < len; i++)
    {
        int temp = i;

        /*Añadir código de ordenación mediante inserción*/

        while (x[temp - 1] > x[temp] && temp > 0)
        {
            intercambiar(&x[temp -1], &x[temp]);
            temp--;
        }

        //FOR PARA IMPRIMIR LAS ITERACIONES
        for(int k = 0; k < len; k++)
            cout << x[k] << " ";

        cout << endl;
    }  
}


int main()
{
    int n;

    cin>>n;

    int *x =new int[n];

    for(int i = 0; i < n; i++)
        cin >> x[i];

    ordenarInsercion(x,n);
    return 0;
}