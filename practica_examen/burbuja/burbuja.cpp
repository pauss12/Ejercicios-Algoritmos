#include <iostream>

using namespace std;

void	intercambiar(int *temp1, int *temp2)
{
	int aux;
	aux = *temp1;
	*temp1 = *temp2;
	*temp2 = aux;
}

void burbuja(int numeros[], int cantidadNumeros)
{
	for (int i = 1; i < cantidadNumeros; i++)
	{
		for (int j = 0; j < cantidadNumeros - i; j++)
		{
			if (numeros[j] > numeros[j + 1])
				intercambiar(&numeros[j], &numeros[j + 1]);

		}

		for (int k = 0; k < cantidadNumeros; k++)
			cout << numeros[k] << " ";
		cout << endl;
	}
}

int main(void)
{
	int cantidadNumeros = 0;
	cin >> cantidadNumeros;

	int *numeros = new int[cantidadNumeros];
	for (int i = 0; i < cantidadNumeros; i++)
		cin >> numeros[i];
	burbuja(numeros, cantidadNumeros);
	return 0;
}
