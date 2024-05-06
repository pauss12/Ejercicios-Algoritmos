#include<iostream>
using namespace std;

char calcular_ganador(char *equipos, int n, int ronda)
{
    char primerGanador;
    char segundoGanador;
    char finalista;

    if (n == 1)
        return (equipos[0]);

    //Dividir el array de equipos a la nitad y volver a llamar a la funcion
    primerGanador = calcular_ganador(&equipos[0], n/2, ronda + 1);
    segundoGanador = calcular_ganador(&equipos[n/2], n/2, ronda + 1);

    if (ronda % 2 == 0)
        finalista = primerGanador;
    else
        finalista = segundoGanador;
    cout << "Ronda " << ronda << " Ganador " << finalista << endl;
    return (finalista);
}

int main()
{
    int n = 0;

    cin >> n;

    char *equipos = new char[n + 1];

    for(int i = 0;i <n; i++)
        equipos[i]='A'+ i;

    equipos[n] = 0;

    calcular_ganador(equipos, n, 0);
}