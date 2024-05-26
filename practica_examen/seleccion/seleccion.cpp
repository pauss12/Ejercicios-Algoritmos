#include <iostream>

using namespace std;

void intercambiar(int *temp1, int *temp2)
{
	int aux;

	aux = *temp1;
	*temp1 = *temp2;
	*temp2 = aux;
}

void ordenarSeleccion(int x[], int len)
{
	int temp = 0;
	for (int i = 0; i < len; i++)
	{
		temp = i;
		for (int j = i + 1; j < len; j++)
		{
			if (x[j] < x[temp])
				temp = j;
		}
		if (i != temp)
			intercambiar(&x[i], &x[temp]);
		for (int k = 0; k < len; k++)
			cout << x[k] << " ";
		cout << endl;
	}
}

int main()
{
	int n;

	cin >> n;
	int *x = new int[n];

	for (int i = 0; i < n; i++)
		cin >> x[i];

	cout << endl;
	ordenarSeleccion(x, n);
	cout << endl;
}
