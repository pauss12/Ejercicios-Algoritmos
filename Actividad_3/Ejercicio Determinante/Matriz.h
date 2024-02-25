#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
 public:
  Matriz();
  Matriz(int, int);
  Matriz(const Matriz &m);
  ~Matriz();
  
  Matriz operator+ (const Matriz &m);
  Matriz operator- (const Matriz &m);
  Matriz operator* (const Matriz &m);
  Matriz operator* (double a);
  Matriz& operator= (const Matriz &m);
  Matriz calcularTraspuesta();
  
  bool esSimetrica();
  
  double obtenerMaximo();
  double obtenerMinimo();
  
  void rellenarManual();
  void rellenarAleatorio(long seed);
  void mostrarMatriz();

  /* Calcula el determinante de la matriz del objeto actual
      Parámetro: Ninguno
      Retorno: el determinante de la matriz
      Precondicion: La matriz debe ser cuadrada
      Complejidad Temporal: O(n!)
      Complejidad Espacial: O(n)
*/
    double calcularMatriz2x2();
    double calcularDeterminante();
  
 private:
  double **matriz;
  
  int n_filas;
  int n_columnas;
};

#endif // MATRIZ_H
