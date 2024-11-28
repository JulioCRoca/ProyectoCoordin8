#ifndef SFunciones_H
#define SFunciones_H

#include <string>
#include <vector>
#include <limits>

using namespace std;

// Estructuras
struct Horario {
    string dia;
    string horaInicio;
    string horaFin;
};

struct Lugar {
    string nombre;
    string tipo;
    string ubicacion;
    int capacidad;
    double precio;
    vector<Horario> horariosDisponibles;
};

// Declaraciones de funciones
void mostrarHorarios(const vector<Horario>& horarios);
void mostrarLugares(const vector<Lugar>& lugares);
int obtenerEntero(const string& mensaje);
#endif // SFunciones_H

