#include<iostream>

using namespace std;

bool calcular(int* objetos, int peso) {

	if (objetos[0] + objetos[1] <= peso) {
		return true;
	}

	return false;
}

int maximo(int* cantidad, int n) {

	//busco el maximo
	int max = cantidad[0];
	int pos = 0;


	for (int i = 1; i < n; i++) {

		if (cantidad[i] > max) {
			max = cantidad[i];
			pos = i;
		}

	}
	cantidad[pos] = 0;
	return pos;
}

int* ordenar(int* cadena, int n) {

	int* cantidad = new int[n];
	int j = 0;
	int* solucion = new int[n * 2];
	int p = 0;
	int pos = 0;

	for (int i = 0; i < n; i++) {

		cantidad[i] = cadena[j] + cadena[j + 1];

		j += 2;
	}

	for (int i = 0; i < n; i++) {
		pos = maximo(cadena, n);
		solucion[p] = cadena[pos * 2];
		solucion[p + 1] = cadena[pos * 2 + 1];
		pos += 2;
	}

	return solucion;
}

int main() {

	int peso = 0;
	int cantidad = 0;
	int objetos[2];

	int suma = 0;
	bool resultado = false;

	cin >> peso;
	cin >> cantidad;

	int* solucion = new int [cantidad * 2];
	int pos = 0;

	for (int i = 0; i < cantidad; i++) {
		cin >> objetos[0];
		cin >> objetos[1];

		resultado = calcular(objetos, peso);

		if (resultado == true) {
			
			solucion[pos] = objetos[0];
			pos++;
			solucion[pos] = objetos[1];
			pos++;

			suma++;
		}
	}

	solucion = ordenar(solucion, cantidad);

	for (int i = 0; i < cantidad; i++) {
		cout << solucion[i] << solucion[i + 1] << endl;
		i++;
	}
	cout << suma << endl;

}