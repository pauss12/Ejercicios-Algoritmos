#include<iostream>
using namespace std;

void  combinar (int a[ ] , int len_a , int b[ ] , int len_b , int c[ ])
{
	int k = 0;	//Recorrer el array de C
	int i = 0;	//Recorrer el array A
	int j = 0;	//Recorrer el array B

	while (i < len_a && j < len_b)
	{
		if (a[i] <= b[j])
		{
			c[k] = a[i];
			i++;
		}
		else
		{
			c[k] = b[j];
			j++;
		}
		k++;
	}

	while (i < len_a)
	{
		c[k] = a[i];
		i++;
		k++;
	}

	while (j < len_b)
	{
		c[k] = b[j];
		j++;
		k++;
	}
}


void ordenarMergeSort (int x[], int len)
{
	int temp[len];
	
	if (len == 1)
    		return ;
	else
    	{
      		/*Ordenar dos mitades */
		ordenarMergeSort(&x[0], len/2);
		ordenarMergeSort(&x[len/2], len - len/2);

	      	/*Combinar ambas mitades y guardarlo en temp */
		combinar(&x[0], len/2, &x[len/2], len - len/2, temp);

      		/*Copiar del array temporal al array resultado */
		for (int k = 0; k < len; k++)
		{
			x[k] = temp[k];
			cout << x[k] << " ";
		}
		cout << endl;
	}
}



int main()
{
	int n;

 	cin >> n;
 	int *x = new int[n];
 
 	for (int i = 0; i<n; i++)
		cin >> x[i];
	ordenarMergeSort(x,n);
}
