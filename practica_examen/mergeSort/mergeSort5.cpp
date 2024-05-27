#include <iostream>

using namespace std;

void combinar(int a[], int len_a, int b[], int len_b, int c[])
{
    int i = 0;
    int j = 0;
    int k = 0;

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

void mergeSort(int x[], int n)
{
    int temp[n];

    if (n == 1)
        return ;
    else
    {
        mergeSort(&x[0], n/2);
        mergeSort(&x[n/2], n - n/2);

        combinar(&x[0], n/2, &x[n/2], n - n/2, temp);

        for (int k = 0; k < n; k++)
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
    for (int i = 0; i < n; i++)
        cin >> x[i];

    cout << endl;
    mergeSort(x, n);
}