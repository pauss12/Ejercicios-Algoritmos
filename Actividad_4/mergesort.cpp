#include<iostream>

using namespace std;

//a[] = {9, 8, 7, 6, 5}
//b[] = {4, 3, 2, 1, 0}
//len_a = 5
//len_b = 5
void  combinar (int a[ ] , int len_a , int b[ ] , int len_b , int c[ ])
{
    /*Añadir código que permite combinar dos arrays */
   int i = 0, j = 0, k = 0;

    while (i < len_a && j < len_b)
    {
        //1ª iteracion ==> 9 <= 4
        //2ª iteracion ==> 8 <= 4
        
        if (a[i] <= b[j])
        {
            //c[0] = 9
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

//9 8 7 6 5 4 3 2 1 0
void ordenarMergeSort (int x[], int len)
{
    int temp[len];

    if (len == 1)
        return;
    else
    {
        /*Ordenar dos mitades */
        ordenarMergeSort(&x[0], len/2);
        ordenarMergeSort(&x[len/2], len - len/2);

        /*Combinar ambas mitades y guardarlo en temp */

        //a[] = {8, 8, 7, 6, 5}
        //b[] = {4, 3, 2, 1, 0}
        combinar(&x[0], len/2, &x[len/2], len - len/2, temp);

        /*Copiar del array temporal al array resultado */
        for (int k = 0; k < len; k++)
        {
            x[k] = temp[k];
            cout << x[k] << " ";
        }
        cout<<endl;
    }
}



int main()
{
    int n;

    cin >> n;
    int *x = new int[n];

    for(int i=0;i<n;i++)
        cin >> x[i];

    ordenarMergeSort(x, n);
}
