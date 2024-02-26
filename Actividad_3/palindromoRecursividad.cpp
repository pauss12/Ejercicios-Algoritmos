#include <iostream>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

/*
    Funcion que calcula la longitud de una cadena; es decir, el numero de caracteres que tiene
    Parámetro: La cadena
    Retorno: Un entero que te dice la longitud de la cadena
    Precondicion: la cadena debe ser un char*, y menos de 20 caracteres
    Complejidad Temporal: O(n)
    Complejidad Espacial: O(1)
*/

//HAY QUE HACERLO DE FORMA RECURSIVA
int ft_strlen(char *str)
{
    int cont;
    while(str[cont] != '\0')
    {
        cont++;
    }
    return cont;
}

int main(void)
{
    int i;
    int j;
    int esPalindromo;
    char cadena[20];

    i = 0;
    esPalindromo = 0;
    std::cin >> cadena;
    assertdomjudge(ft_strlen(cadena) < 20);
    j = ft_strlen(cadena) - 1;
    while (cadena[i] != '\0' && i < j)
    {
        if (cadena[i] != cadena[j])
        {
           esPalindromo = 0;
        }
        else if (cadena[i] == cadena[j])
        {
            esPalindromo = 1;
        }
        i++;
        j--;
    }
    std::cout << esPalindromo << std::endl;
    return 0;
}