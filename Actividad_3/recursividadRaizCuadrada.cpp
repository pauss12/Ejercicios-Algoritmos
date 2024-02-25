#include <iostream>
#include <cmath>
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

double calcularRaizCuadrada(double number, double error, double minimo, double maximo){
    
    double nuevaAproximacion = (minimo + maximo) / 2;

    cout << nuevaAproximacion << endl;
    if (abs((nuevaAproximacion*nuevaAproximacion) - number) < error){
        return nuevaAproximacion;
    }else if ((nuevaAproximacion*nuevaAproximacion) > number){
        return calcularRaizCuadrada(number, error, minimo, nuevaAproximacion);
    }else{
        return calcularRaizCuadrada(number, error, nuevaAproximacion, maximo);
    }
}

int main(){
    double number, error, min, max;

    cin >> number >> error;

    assertdomjudge(number > 0);

    max = number;
    min = 0;

    calcularRaizCuadrada(number, error, min, max);
    return 0;
}