#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
	
	private:
  		double **matriz;

  		int n_filas;
  		int n_columnas;

 	public:

		/*
		Constructor por defecto; asignara las filas y columnas a 0; y la matriz la hara apuntar a NULL
		*/
		Matriz();

		/*
		Constructor que me crea una matriz con el numero de filas y columnas que me pasen por parametros
		*/
		Matriz(int n_filas, int n_columnas);

		/*
		Constructor que basandose en otra matriz ya creada, crea una nueva matriz
		*/
		Matriz(const Matriz &m1);

		/*
		Destructor que libera la memoria reservada de la matriz creada con memoria dinamica
		*/

		~Matriz();

		/*
		Realiza la suma o resta de matrices mediante la sobrecarga del operador(operator+, operator-)

		Comprueba que las dimensiones de las dos matrices son iguales para poder realizar la suma o resta

		Crea un nuevo objeto Matriz donde guardará el resultado.

		Va recorriendo las dos matrices a la vez, elemento a elemento para sumarlos y restarlos, e ir colocando el resultado en la misma posicion de la nueva matriz.
		*/
		Matriz& operator+ (const Matriz &m);
		Matriz& operator- (const Matriz &m);

		/*
		
		*/

		Matriz& operator* (const Matriz &m);



		/* Realiza la asignación entre dos objetos de la clase Matriz. Crea una nueva matriz  con el resultado.
			Parámetro: la matriz que se va a asignar
			Retorno: una nueva matriz con la matriz pasada como parámetro.
			Precondicion: Ninguno.
			Complejidad Temporal: O(n_filas*n_columnas)
			Complejidad Espacial: O(n_filas*n_columnas)
		*/

		Matriz& operator= (const Matriz &m);

		/*
		Sobrecarga del operador "*"; en este caso, le pasamos por parametros un entero y a cada uno de los elementos de la matriz original, los multiplica por ese numero

		Y el resultado de esa matriz, se va a guardar en una nueva matriz
		*/

		Matriz& operator*(int a);

		/*
			Para comprobar si una matriz es simetrica hay que tener en cuenta que la matriz debe ser cuadrada, es decir mismo numero de filas y columnas

			Comprobamos que la sdimensiones de la matriz son las correctas y creamos una variable bool que cambiará a false en el momento que se verifique que no es simetrica

			Vamos recorriendo la matriz por filas y columnas; si los numeros a ambos lados de la diagonal no coinciden, es que no es simetrica, la booleana cambia a false y sale
		*/

		bool esSimetrica();

		/* Permite rellenar todos los elementos de la matriz del objeto actual preguntando al usuario 
			Parámetro: Ninguno
			Retorno: Ninguno
			Precondicion: La matriz no debe estar vacía
			Complejidad Temporal: O(n_filas*n_columnas)
			Complejidad Espacial: O(1)
		*/
  
		void rellenarManual();

		/*
			Tanto en la de "obtenerMaximo" como en la de "obtenerMinimo"; tienen una logica parecida, uno va buscando el menor numero de la matriz; mientras que la otra va buscando el numero máximo.

			Asignamos como valor max o min el primer elemento de la matriz, es decir, matriz[0][0]. Y una vez ya tenemos eso, vamos recorriendo la matriz y si encontramos otro mayor (en el caso del maximo) u menor (en el caso del meinimo), lo cambiamos y asi hasta que llegamos al final de la matriz
		*/

		double obtenerMaximo();
		double obtenerMinimo();

		/*
			Para calcular la traspuesta primero creamos un objeto Matriz para guardar la matriz traspuesta con las dimensiones columnas x filas
		
			Recorremos la matriz original mediante bucles for, recorriendo cada elemento de la matriz y posicionando dichos elementos en la traspuesta.
			Esto lo realizamos guardando la posicion (i,j) de la matriz original a (j,i) en la matriz traspuesta.
		*/

		Matriz& calcularTraspuesta();


		/* Permite rellenar todos los elementos de la matriz del objeto actual de forma aleatoria 
			Parámetro: semilla que se utiliza para el generador aleatorio
			Retorno: Ninguno
			Precondicion: La matriz no debe estar vacía
			Complejidad Temporal: O(n_filas*n_columnas)
			Complejidad Espacial: O(1)
		*/

		void rellenarAleatorio(long seed);

		/* Imprime por pantalla todos los elementos de la matriz del objeto actual  
			Parámetro: Ninguno
			Retorno: Ninguno
			Precondicion: La matriz no debe estar vacía
			Complejidad Temporal: O(n_filas*n_columnas)
			Complejidad Espacial: O(1)
		*/

  		void mostrarMatriz();
  
};

#endif // MATRIZ_H
