#include <iostream>

using namespace std;

char	jugarEurocopa(char equipos[], int cuantosEquipos, int ronda)
{
	char primerGanador;
	char segundoGanador;
	char finalista;

	if (cuantosEquipos == 1)
		return (equipos[0]);
	else
	{
		primerGanador = jugarEurocopa(&equipos[0], cuantosEquipos/2, ronda + 1);
		segundoGanador = jugarEurocopa(&equipos[cuantosEquipos/2], cuantosEquipos/2, ronda + 1);

		if (ronda % 2 == 0)
			finalista = primerGanador;
		else
			finalista = segundoGanador;

		cout << "Ronda " << ronda << " Ganador " << finalista << endl;
	}
	return finalista;
}

int main()
{
	int cuantosEquipos;

	cin >> cuantosEquipos;

	char *equipos = new char[cuantosEquipos + 1];

	for (int i = 0; i < cuantosEquipos; i++)
		equipos[i] = 'A' + i;
	equipos[cuantosEquipos] = '\0';

	cout << endl;
	jugarEurocopa(equipos, cuantosEquipos, 0);
}
