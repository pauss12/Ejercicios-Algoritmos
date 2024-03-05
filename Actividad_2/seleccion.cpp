#include<iostream>
using namespace std;

/*
    Ordena un arreglo de enteros de menor a mayor
    utilizando el algoritmo de selección
    
    x: arreglo de enteros
    len: longitud del arreglo
    T(n) = O(n^2)
    M(n) = O(1)
    Orden: O(n^2)
    
*/
void ordenarSeleccion(int x[],int len)
{
    int minimo;
    
    for(int i = 0; i < len ; i++)
    {
        minimo = i;
        for(int j = i + 1; j < len; j++)
        {
            if(x[j] < x[minimo])
                minimo = j;
        }
        if(i != minimo)
        {
            int temp = x[i];
            x[i] = x[minimo];
            x[minimo] = temp;
        }
        
        for(int k=0;k<len;k++)
            cout << x[k] << " " ;

        cout<<endl;
    }
}

int main()
{
    int n;

    cin>>n;

    int *x=new int[n];

    for(int i=0;i<n;i++)
        cin>>x[i];

    ordenarSeleccion(x,n);
    return 0;
}
