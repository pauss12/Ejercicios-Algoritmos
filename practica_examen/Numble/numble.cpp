#include <iostream>
#include <vector>

using namespace std;

/*
    Usaremos backtracking para resolver este problema. El backtracking es una técnica que explora todas las posibilidades y retrocede cuando se da cuenta de que una ruta no lleva a una solución válida.
*/

// Función de backtracking para encontrar todas las combinaciones que sumen a X
void encontrarCombinaciones(vector<int>& numeros, int indice, int sumaActual, int X, vector<int>& resultado) {

    if (indice == 4) {
        if (sumaActual == X) {
            for (int i = 0; i < 4; ++i) {
                cout << resultado[i] << " ";
            }
            cout << endl;
        }
        return ;
    }
    
    if (numeros[indice] == -1)
    {
        for (int i = 0; i <= 9; ++i) 
        {
            resultado[indice] = i;
            encontrarCombinaciones(numeros, indice + 1, sumaActual + i, X, resultado);
        }

    } else 
    {
        resultado[indice] = numeros[indice];
        encontrarCombinaciones(numeros, indice + 1, sumaActual + numeros[indice], X, resultado);
    }
}

int main() 
{
    int X;
    vector<int> numeros(4);
    
    cin >> X;
    for (int i = 0; i < 4; ++i) {
        cin >> numeros[i];
    }
    
    vector<int> resultado(4);
    
    // Encontrar y mostrar todas las combinaciones
    encontrarCombinaciones(numeros, 0, 0, X, resultado);

    return 0;
}
