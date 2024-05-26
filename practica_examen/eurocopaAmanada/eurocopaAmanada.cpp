#include <iostream>

using namespace std;

char calcularGanador(char *equipos, int n, int ronda)
{
	char primerGanador;
	char segundoGanador;
	char finalista;

	if (n == 1)
		return (equipos[0]);
	primerGanador = calcularGanador(&equipos[0], n/2, ronda + 1);
	segundoGanador = calcularGanador(&equipos[n/2], n/2, ronda + 1);	

	if (ronda % 2 == 0)
		finalista = primerGanador;
	else
		finalista = segundoGanador;
	
	cout << "El finalista " << "en la ronda " << ronda << " es " << finalista << endl;
	return (finalista);
}

int main(void)
{
	int numEquipos = 0;
	cout << "¿Cuantos equipos van a jugar la Eurocopa?" << endl;

	cin >> numEquipos;
	
	char *equipos = new char[numEquipos+1];
	for (int i = 0; i < numEquipos; i++)
		equipos[i] = 'A' + i;
	equipos[numEquipos] = '\0';
	calcularGanador(equipos, numEquipos, 0);
	return (0);
}
