#include<iostream>
using namespace std;

int **calcularTrianguloPascal(int n)
{
    //crear matriz para el triangulo de pascal
    int **arrayTriangulo = new int *[n];
    for(int i = 0; i < n; i++)
    {
        arrayTriangulo[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0 || j == i || i == 0)
                arrayTriangulo[i][j] = 1;
            else
                arrayTriangulo[i][j] = arrayTriangulo[i - 1][j - 1] + arrayTriangulo[i - 1][j];
        }
    }

    return (arrayTriangulo);
}

int main(void)
{
    int r, n;
    bool continuar = true;
    int tam = 10;
    int **arrayTriangulo = nullptr;

    while (continuar == true)
    {
        std::cin >> n >> r;

        if (n < 0)
            continuar = false;
        else if (r>n)
            std::cout << "ERROR" << std::endl;
        else
        {
            arrayTriangulo = calcularTrianguloPascal(tam);
            std::cout << arrayTriangulo[n][r] << std::endl;
        }
    };

    return 0;
}