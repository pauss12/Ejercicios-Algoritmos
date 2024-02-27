#include<iostream>
using namespace std;

void intercambiar(int *temp, int *temp2)
{
    int	aux;

	aux = *temp;
	*temp = *temp2;
	*temp2 = aux;
}

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
