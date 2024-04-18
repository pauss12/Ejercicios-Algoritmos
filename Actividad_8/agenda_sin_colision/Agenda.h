
#include <iostream>
using namespace std;

class Agenda {


    int capacidad;
    string *nombres;
    long *telefonos;
    bool *ocupados;

    public:
    Agenda(int capacidad);
    ~Agenda();
    int obtenerPosicion(long telefono);
    bool existeContacto(long telefono);
    string getContacto(long telefono);
    void introducirContacto(string contacto, long telefono);
    void eliminarContacto(long telefono);
    void imprimir();
}