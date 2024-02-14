#include "Matriz.h"
#include <iostream>
#include<math.h>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

//Constructor por defecto -------------
Matriz::Matriz()
{
    this->n_filas = 0;
    this->n_columnas = 0;
    this->matriz = NULL;
}

//Constructor por parametros ------------------------
Matriz::Matriz(int n_filas, int n_columnas)
{
    this->n_filas = n_filas;
    this->n_columnas = n_columnas;
    
    if (this->n_filas >= 0 && this->n_columnas > 0)
    {
        this->matriz = new double *[n_filas];
        for(int i = 0; i < n_filas; i++)
        {
            this->matriz[i] = new double[n_columnas];
        }
    }
}

//Constructor copia -------------------- (hay q crear nueva matriz)
Matriz::Matriz(const Matriz &m1):Matriz(m1.n_filas, m1.n_columnas)
{
    this->n_filas = m1.n_filas;
    this->n_columnas = m1.n_columnas;

    if (this->n_filas > 0 && this->n_columnas > 0)
    {
        this->matriz = new double *[n_filas];
        for(int i = 0; i < n_filas; i++)
        {
            this->matriz[i] = new double[n_columnas];
            for(int j = 0; j < n_columnas; j++)
            {
                this->matriz[i][j] = m1.matriz[i][j];
            }
        }
    }
}
//Destructor ------------------------------
Matriz::~Matriz()
{
    if(matriz != NULL)
    {
        for (int i = 0; i < n_filas; i++)
            delete[] matriz[i];
        delete[] matriz;
        matriz=NULL;
    }
}

//OPERACION SUMA ---------------------------------------------
Matriz& Matriz::operator+ (const Matriz &m)
{
    assertdomjudge(this->n_filas == m.n_filas && this->n_columnas == m.n_columnas);
    
    Matriz *matriz_resultante = new Matriz(m.n_filas, m.n_columnas); 

    for(int i = 0; i < m.n_filas; i++)
    {
        for(int j = 0; j < m.n_columnas; j++)
        {
            matriz_resultante->matriz[i][j] = m.matriz[i][j] + this->matriz[i][j];
        }
    }
    return *matriz_resultante;   
};

//OPERACION RESTA --------------------------------------------
Matriz& Matriz::operator-(const Matriz &m)
{
    assertdomjudge(this->n_filas == m.n_filas && this->n_columnas == m.n_columnas);
    
    Matriz *matriz_resultante = new Matriz(m.n_filas, m.n_columnas); 
    
    for(int i = 0; i < m.n_filas; i++)
    {
        for(int j = 0; j < m.n_columnas; j++)
        {
            matriz_resultante->matriz[i][j] = this->matriz[i][j] - m.matriz[i][j];
        }
    }
    return *matriz_resultante;
};

//OPERACION MULTIPLICACION ---------------------------------------
Matriz& Matriz::operator* (const Matriz &m)
{
    assertdomjudge(m.n_filas == this->n_columnas);

    Matriz *matriz_resultante = new Matriz(this->n_filas, m.n_columnas); 

    for(int i = 0; i < this->n_filas; i++)
    {
        for(int j = 0; j < m.n_columnas; j++)
        {
            matriz_resultante->matriz[i][j] = 0;
            for(int k = 0; k < this->n_columnas; k++)
            {
                matriz_resultante->matriz[i][j] += this->matriz[i][k] * m.matriz[k][j];
            }
        }
    }
    return *matriz_resultante;
    
};

//PRODUCTO POR UN ESCALAR
Matriz& Matriz::operator* (int a)
{
    assertdomjudge( this->n_filas == this->n_columnas);

    Matriz *matriz_resultante = new Matriz(this->n_filas, this->n_columnas); 

    for(int i = 0; i < this->n_filas; i++)
    {
        for(int j = 0; j < this->n_columnas; j++)
        {
            matriz_resultante->matriz[i][j] += this->matriz[i][j] * a;
        }
    }
    return *matriz_resultante;
    
};


//OBTENER MAXIMO ------------------------------------------------
double Matriz::obtenerMaximo()
{
    double maximo;
    maximo = matriz[0][0];
    for(int i = 0; i < this->n_filas; i++)
    {
        for(int j = 0; j < this->n_columnas; j++)
        {
            if (matriz[i][j] > maximo)
                maximo = matriz[i][j];
        }
    }
    return maximo;
};

//OBTENER MINIMO ---------------------------------------------------
double Matriz::obtenerMinimo()
{
    double minimo;
    minimo = matriz[0][0];
    for(int i = 0; i < this->n_filas; i++)
    {
        for(int j = 0; j < this->n_columnas; j++)
        {
            if (matriz[i][j] < minimo)
                minimo = matriz[i][j];
        }
    }
    return minimo;
};

//ES SIMETRICA ? -----------------------------------------------------
bool Matriz::esSimetrica()
{
    assertdomjudge(this->n_filas == this->n_columnas);
    bool esSimetrica;

    esSimetrica = false;
    for(int i = 0; i < this->n_filas; i++)
    {
        for(int j = 0; j < this->n_columnas; j++)
        {
            if (matriz[i][j] == matriz[j][i])
                esSimetrica = true;
            else
            {
                esSimetrica = false;
                break;
            }
        }
    }
    return esSimetrica;
};

//CALCULAR SU TRASPUESTA ------------------------------
Matriz& Matriz::calcularTraspuesta()
{
    Matriz *matriz_traspuesta = new Matriz(this->n_columnas, this->n_filas); 

    for(int i = 0; i < this->n_filas; i++)
    {
        for(int j = 0; j < this->n_columnas; j++)
        {
            matriz_traspuesta->matriz[j][i] = this->matriz[i][j];
        }
    }
    return *matriz_traspuesta;
};

//Asignacion de matrices
Matriz& Matriz::operator= (const Matriz &m)
{
    if(matriz != NULL)
    {
        for (int i = 0; i < n_filas; i++)
	        delete[] matriz[i];
        delete[] matriz;
        matriz=NULL;
    }

    this->n_filas=m.n_filas;
    this->n_columnas=m.n_columnas;
    this->matriz=NULL;
    if (n_filas > 0 && n_columnas > 0)
    {
        matriz= new double *[n_filas];
        for (int i = 0; i < n_filas; i++)
	    {
	        matriz[i] = new double[n_columnas];  
	        for(int j=0; j <n_columnas; j++)
	            matriz[i][j]=m.matriz[i][j];
	    }
    }
    return(*this); 
}


// Leer matriz
void Matriz::rellenarManual()
{
    double elemento;
  
    for (int i = 0; i < n_filas; i++)
    {
        cout << "Fila " << i << endl;
        for (int j = 0; j < n_columnas; j++)
	    {
	        cout << "Elemento " << j  << endl;
	        cin >> elemento;
	        matriz[i][j] = elemento;
        }
        cout << endl;
    }
}

// Rellenar Matriz Aleatoria
void Matriz::rellenarAleatorio(long seed)
{
  srand(seed);
  for (int i = 0; i < n_filas; i++)
    for (int j = 0; j < n_columnas; j++)
      matriz[i][j]=rand();
  
}

// Imprimir Matriz
void Matriz::mostrarMatriz()
{
    for (int i = 0; i < n_filas; i++){

        for (int j = 0; j < n_columnas; j++)
	        cout << matriz[i][j] << " ";       
        cout << endl;
    }
}
