#include <iostream>

using namespace std;

int calcularNumeroCoche(int *voltajes, int numeroPilas, int voltajeNecesarioFuncionamientoCoche)
{
    int maxVoltajeTengo = 0;
    int numCoches = 0;

    for (int j = 0; j < numeroPilas; j++)
    {
        maxVoltajeTengo += voltajes[j];
    }

    if (maxVoltajeTengo < voltajeNecesarioFuncionamientoCoche)
        return (0);
    else
    {
        if (maxVoltajeTengo == voltajeNecesarioFuncionamientoCoche)
            numCoches++;
        else {

            while (maxVoltajeTengo > voltajeNecesarioFuncionamientoCoche)
            {     
                numCoches++;
                maxVoltajeTengo = maxVoltajeTengo - voltajeNecesarioFuncionamientoCoche;
            }
        }
    }
    return (numCoches);
}

int main()
{
    int numPruebas = 0;
    int numpilas = 0;
    int voltajeNecesarioFuncionamientoCoche = 0;

    cin >> numPruebas;
    int *solucionCoche = new int[numPruebas];

    for (int i = 0; i < numPruebas; i++)
    {
        cin >> numpilas >> voltajeNecesarioFuncionamientoCoche;

        int *voltajes = new int[numpilas];

        for (int i = 0; i < numpilas; i++)
        {
            cin >> voltajes[i];
        }

        solucionCoche[i] = calcularNumeroCoche(voltajes, numpilas, voltajeNecesarioFuncionamientoCoche);
        delete[] voltajes;
    }

    for (int j = 0; j < numPruebas; j++)
        cout << solucionCoche[j] << endl;

    delete[] solucionCoche;
    
    return (0);
}