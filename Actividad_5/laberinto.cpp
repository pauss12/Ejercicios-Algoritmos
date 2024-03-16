
#include <iostream>
#define TAM_MAX 10

using namespace std;

/*
    DESCRIPCION:
    
    El programa resuelve un laberinto de 10x10, donde el aventurero se encuentra en la posicion (0,0), tiene un mapa del laberinto que se lo pasan por la terminal  y debe encontrar el tesoro que se encuentra en una posicion aleatoria del laberinto.

    El programa imprime el mapa del laberinto y la posicion del tesoro si lo encuentra, si no lo encuentra imprime "INALCANZABLE".

    El programa utiliza la recursividad para resolver el laberinto. En la leyenda, aparece lo que siginifican los diferentes simbolos de las celdas del laberinto.

    COMPLEJIDAD TEMPORAL: La complejidad temporal del programa es de O(n^2) ya que recorre cada una de las celdas del laberinto.

    COMPLEJIDAD ESPACIAL: La complejidad espacial del programa es de O(n^2) ya que utiliza una matriz de 10x10 para el laberinto.

*/



/*
    LEYENDA:

    ‘*’ Celda de pared que no puede atravesarse.
    ‘.’ Celda libre que puede atravesarse.
    ‘X’ Celda por la que ha pasado el aventurero.
    ‘T’ Celda donde se encuentra el tesoro.

*/

//Imprimir el mapa
void print_mapa(char mapa[TAM_MAX][TAM_MAX])
{
    for (int i = 0; i < TAM_MAX; i++)
    {
        for (int j = 0; j < TAM_MAX; j++)
        {
            cout << mapa[i][j];
        }
        cout << endl;
    }
}

//Funcion para resolver el laberinto
bool resolverLaberinto(char mapa[TAM_MAX][TAM_MAX], int x, int y, int& filaFinal, int& columnaFinal)
{
    //Comprobar si la posicion es valida, es decir si esta fuera de los limites, se sale
    if (x < 0 || x >= TAM_MAX || y < 0 || y >= TAM_MAX)
        return false;

    //Comprobar si la posicion es una pared o una por la que ya ha pasado, se sale -----
    if (mapa[x][y] == '*' || mapa[x][y] == 'X')
        return false;

    //Comprobar si la posicion es el tesoro, se sale y se guarda la posicion en la que se ha encontrado
    if (mapa[x][y] == 'T')
    {
        filaFinal = x;
        columnaFinal = y;
        return true;
    }

    //Marcar la posicion por la que ha pasado
    mapa[x][y] = 'X';

    //Comprobar la izquierda
    if (resolverLaberinto(mapa, x - 1, y, filaFinal, columnaFinal))
    {
        return true;
    }

    //Comprobar abajo
    if (resolverLaberinto(mapa, x, y + 1, filaFinal, columnaFinal))
    {
        return true;
    }

    //Comprobar la derecha
    if (resolverLaberinto(mapa, x + 1, y, filaFinal, columnaFinal))
    {
        return true;
    }

    //Comprobar arriba
    if (resolverLaberinto(mapa, x, y - 1, filaFinal, columnaFinal))
    {
        return true;
    }

    //Si encuentra el tesoro, sale del bucle y muestra la posicion del tesoro
    if (mapa[x][y] == 'T')
    {
        return true;
    }

    //Si no encuentra el tesoro, desmarca la posicion por la que ha pasado
    mapa[x][y] = '.';

    return false;
}



int main(void)
{
    char mapa[TAM_MAX][TAM_MAX];
    int filaFinal = -1;
    int columnaFinal = -1;
    int x = 0;
    int y = 0;

    for (int i = 0; i < TAM_MAX; i++)
    {
        for (int j = 0; j < TAM_MAX; j++)
        {
            cin >> mapa[i][j];
        }
    }

    //llamar a resolver laberinto
    if (resolverLaberinto(mapa, x, y, filaFinal, columnaFinal))
    {
        if (mapa[filaFinal][columnaFinal] == 'T')
        {
            print_mapa(mapa);
            cout << "ENCONTRADO " << filaFinal << " " << columnaFinal << endl;
        }
    }
    else
         cout << "INALCANZABLE" << endl;

    return (0);
}