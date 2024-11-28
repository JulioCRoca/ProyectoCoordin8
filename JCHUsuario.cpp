#include "JFunciones.h"
#include "LoginJ.h"
#include "LauFunciones.h"
#include "SFunciones.h"
#include <iostream>
#include <windows.h>
#include <string>
#define Tab "\t\t\t\t\t\t"
#define color SetConsoleTextAttribute
void dibujar();
bool verificarCI(string CI);
using namespace std;

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int fiesta, eleccion1 = 0, eleccion2 = 0, roll,option,opmusic;
    string CI, password, name; //login
    int tipoLugar,personas; //Seleccionar lugar
    string lugarSeleccionado;
    string fiestas[3] = { "Boda","Graduacion","Cumpleanios" };
    string opcionM[3] = { "Musica en vivo","DJ","Parlantes" };
    string bodam[3] = { "Clasico y elegante(cuarteto de cuerdas,orquesta,etc.)","Romantico(lirico,duo acustico,etc.) ","Moderno(Bandas,trio acustico,etc.)" };
    string graduacionm[3] = { "Animado(mariachi,rock clasico,etc.)","Electronico","Relajado(jazz,cantautor,etc.)" };
    string cumplem[3] = { "Electronico","Relajado(jazz,cantautor,etc.)","Pesonalizado(Musica urbana,indie,etc.)" };
  
    vector<Lugar> lugares = {
        {"Arboliana Eventos", "Abierto", "Radial 10, Barrio Polanco", 350, 2000, {
            {"Lunes", "08:30", "21:00"},
            {"Martes", "08:30", "21:00"},
            {"Miércoles", "08:30", "21:00"},
            {"Jueves", "08:30", "21:00"},
            {"Viernes", "08:30", "21:00"},
            {"Sábado", "08:30", "21:00"},
            {"Domingo", "08:30", "21:00"}
        }},
        {"Garden House", "Abierto", "8vo anillo calle Almeria #1", 300, 3500, {
            {"Lunes", "09:00", "17:00"},
            {"Miércoles", "09:00", "17:00"},
            {"Viernes", "09:00", "19:00"}
        }},
        {"La Fête Casa de Eventos", "Cerrado", "Warnes 368", 200, 3000, {
            {"Lunes", "17:00", "20:00"},
            {"Martes", "17:00", "20:00"},
            {"Miércoles", "17:00", "20:00"},
            {"Jueves", "17:00", "20:00"},
            {"Viernes", "17:00", "20:00"},
            {"Sábado", "17:00", "20:00"}
        }},
        {"Imagina eventos", "Cerrado", "Bruno Racua 3205", 80, 1500, {
            {"Lunes", "14:00", "20:30"},
            {"Martes", "14:00", "20:30"},
            {"Miércoles", "14:00", "20:30"},
            {"Jueves", "14:00", "20:30"},
            {"Viernes", "14:00", "20:30"}
        }}
    };
    do {
        system("cls");
        color(hConsole, 4);
        dibujar();
        color(hConsole, 7);
        cout << endl;
        cout << Tab << "==================================" << endl;
        cout << Tab << "||      BIENVENID@ A COORDIN8   ||" << endl;
        cout << Tab << "==================================" << endl;
        cout << Tab << "|| 1. Registrarse               ||" << endl;
        cout << Tab << "|| 2. Iniciar sesión            ||" << endl;
        cout << Tab << "==================================" << endl;
        cout << endl;
        
            eleccion1=obtenerEntero("Elija una opcion: ");
            if (eleccion1 < 1 || eleccion1>2) {
                cout << Tab << "Ingrese las opciones visibles";
            }
        if (eleccion1 == 1 || eleccion1 == 2) {
            loginJ(eleccion1,eleccion2);
        }
    } while (( eleccion1 == 1 && eleccion2 == 2 )|| (eleccion2==1));
    system("cls");
    color(hConsole, 4);
    dibujar();
    color(hConsole, 7);
    cout << endl;
    cout << Tab << "==================================" << endl;
    cout << Tab << "||      EVENTOS DISPONIBLES     ||" << endl;
    cout << Tab << "==================================" << endl;
    cout <<Tab<< "1.Boda" << endl;
    cout <<Tab<< "2.Graduacion" << endl;
    cout <<Tab<< "3.Cumpleanios" << endl;
    fiesta = obtenerEntero("Elija un evento: ");
    personas = obtenerEntero("Cuantas personas asistiran al evento?: ");
        //Continuaremos con la eleccion de paquetes 
        //

        //Seleccion de lugares 
    system("cls");
    color(hConsole, 4);
    dibujar();
    color(hConsole, 7);
    cout << Tab << "=============================================" << endl;
    cout << Tab << "||  Elige el tipo de lugar para tu evento  ||" << endl;
    cout << Tab << "=============================================" << endl;
    cout << Tab<<"1. Abierto"<<endl;
    cout << Tab<<"2. Cerrado" << endl;
    tipoLugar = obtenerEntero("Seleccione el tipo de lugar: ");

    vector<Lugar> lugaresFiltrados;
    for (const auto& lugar : lugares) {
        if ((tipoLugar == 1 && lugar.tipo == "Abierto") || (tipoLugar == 2 && lugar.tipo == "Cerrado")) {
            lugaresFiltrados.push_back(lugar);
        }
    }
    vector<Lugar> lugaresDisponibles;
    for(const auto& lugar : lugaresFiltrados) {
        if (lugar.capacidad >= personas) {
            lugaresDisponibles.push_back(lugar);
        }
    }

    if (lugaresDisponibles.empty()) {
        cout <<Tab<< "No hay lugares disponibles para el número de personas que ingresaste."<<endl;
    }
    else {
            system("cls");
            color(hConsole, 4);
            dibujar();
            color(hConsole, 7);
            cout << Tab << "=============================================" << endl;
            cout << Tab << "||     Opciones de lugares disponibles     ||" << endl;
            cout << Tab << "=============================================" << endl;
            mostrarLugares(lugaresDisponibles);

        int seleccion;
        seleccion=obtenerEntero("Elige el número del lugar que deseas reservar: ");
     
        if (seleccion >= 1 && seleccion <= lugaresDisponibles.size()) {
            lugarSeleccionado = lugaresDisponibles[seleccion - 1].nombre;
            cout <<Tab<< "Has seleccionado: " << lugarSeleccionado << endl;
        }
        else {
            cout <<Tab<< "Opción inválida.\n";
        }
    }
    ambiente(fiesta,option,opmusic);
}


