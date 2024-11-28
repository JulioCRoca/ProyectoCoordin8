#include "SFunciones.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h>
#include <limits>

#define Tab "\t\t\t\t\t\t"
#define logo "\t\t\t\t"
#define color SetConsoleTextAttribute

using namespace std; 
//Cambiar color pantalla
void pintar(int i) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, i);
}
// Implementación de mostrarHorarios
void mostrarHorarios(const vector<Horario>& horarios) {
    pintar(4);
    cout << Tab<<"Horarios disponibles:"<<endl;
    pintar(7);
    for (const auto& horario : horarios) {
        cout <<Tab<< "   Día: " << horario.dia << " | " << horario.horaInicio << " - " << horario.horaFin << endl;
    }
}

// Implementación de mostrarLugares
void mostrarLugares(const vector<Lugar>& lugares) {
    for (size_t i = 0; i < lugares.size(); ++i) {
        cout <<Tab<< i + 1 << ". " << lugares[i].nombre << " (" << lugares[i].tipo << " - Capacidad: " << lugares[i].capacidad << " personas)" << endl;
        pintar(4);
        cout << Tab << "   Ubicación: ";
        pintar(7);
        cout<<lugares[i].ubicacion << endl;
        pintar(4);
        cout << Tab << "   Precio: $";
        pintar(7);
        cout<<lugares[i].precio << endl;
        mostrarHorarios(lugares[i].horariosDisponibles);
    }
}
int obtenerEntero(const string& mensaje) {
    while (true) {
        int numero;
        cout << Tab << mensaje; 
        cin >> numero;
        // Verificar si la entrada fue válida
        if (cin.fail()) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(1000, '\n'); // Descarta el resto de la linea hasta 1000 caracteres 
            cout <<Tab<< "Entrada inválida.Ingrese una opcion valida.\n";
        }
        else {
            return numero; // Retorna el número válido
        }
    }
}