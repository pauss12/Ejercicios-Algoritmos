
#include <iostream>
#define TAM_MAX 10

using namespace std;

/*
    ..********
    *.*......*
    *.*.****.*
    *.*.*..*.*
    *.*.*T.*.*
    *.*.**.*.*
    *.*....*.*
    *.******.*
    *........*
    **********

*/

/*
    LEYENDA:

    ‘*’ Celda de pared que no puede atravesarse.
    ‘.’ Celda libre que puede atravesarse.
    ‘X’ Celda por la que ha pasado el aventurero.
    ‘T’ Celda donde se encuentra el tesoro.

*/

/*
    void probar()
    {
        int k = -1; // posibles movimientos

        do { 
            k++;
            int u = x + dx[k];

            int v = y + dy[k];

            if ((0 <= u) && (u < N) && (0 <= v) && (v < N)) {
                
                if (tablero[u][v] == 0) {
                    
                    tablero[u][v] = numMovimientos;
                
                    if (numMovimientos < N*N) {
                        probar(tablero, numMovimientos + 1, u, v, exito);

                        if (!*exito) tablero[u][v] = 0;

                    } else {
                        *exito = true;
                    }
                }
            }
        } while (!*exito && k < 7)
    }

*/
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

void resolverLaberinto(char mapa[TAM_MAX][TAM_MAX], int *exito)
{
    for (int i = 0; i < TAM_MAX; i++){

        for (int j = 0; j < TAM_MAX; j++)
        {
            if (mapa[i][j] == '.')
            {
                mapa[i][j] = 'X';
            }

            if (mapa[i][j] == 'T')
            {
                exito = 1;
            }
        }
    }
    print_mapa(mapa);
}


int main(void)
{
    char mapa[TAM_MAX][TAM_MAX];
    int exito = 0;

    for (int i = 0; i < TAM_MAX; i++)
    {
        for (int j = 0; j < TAM_MAX; j++)
        {
            cin >> mapa[i][j];
        }
    }

    print_mapa(mapa);

    resolverLaberinto(mapa, &exito);


    return (0);
}