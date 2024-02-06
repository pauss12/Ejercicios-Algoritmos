#include <iostream>

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