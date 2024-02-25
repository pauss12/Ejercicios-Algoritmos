#include <iostream>

/*
    Funcion que calcula el factorial de un numero
    Parámetro: un entero
    Retorno: el factorial del numero
    Precondicion: el numero debe ser mayor o igual a 0
    Complejidad Temporal: O(n)
    Complejidad Espacial: O(1)
       
*/

int calcularFactorial(int number)
{
    int valor;

    valor = 1;
    if (number <= 1)
        return 1;
    else
    {
        while (number > 0)
        {
            valor = valor * number;
            number--;
        }
    }
    return (valor);
}

int calcularCombinatoria(int r, int n)
{
    int final;
    int factorialN;
    int factorialR;
    int factorialResta;

    if (r == 0 || r == n)
        return 1;
    factorialN = calcularFactorial(n);
    factorialR = calcularFactorial(r);
    factorialResta = calcularFactorial(n - r);
    final = (factorialN)/((factorialR)*(factorialResta));

    return final;
}

int main(void)
{
    int n;
    int r;
    int sol;
    bool continuar = true;

    while (continuar){
        std::cin >> n >> r;
        if (n < 0)
        {
            continuar = false;
        }
        else if (r>n)
        {
            std::cout << "ERROR" << std::endl;
        }
        else
        {
            sol = calcularCombinatoria(r, n);
            std::cout << sol << std::endl;
        }

    }; 
    return 0;
}