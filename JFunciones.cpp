#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h>
#include "JFunciones.h"  // Incluir el archivo de cabecera
#define MAX 10
#define Tab "\t\t\t\t\t\t"
#define color SetConsoleTextAttribute


using namespace std;
void menu(string title, string fiesta[MAX], int tamanio, int& opcion);

// Definicion de la funcion musica de festividad
void musica(int fiesta) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int tipo, fiesta, musica;
	string bodam[] = { "Clasico y elegante(cuarteto de cuerdas,orquesta,etc.)","Romantico(lirico,duo acustico,etc.) ","Moderno(Bandas,trio acustico,etc.)" };
	string graduacionm[] = { "Animado(mariachi,rock clasico,etc.)","Electronico","Relajado(jazz,cantautor,etc.)" };
	string cumplem[] = { "Electronico","Relajado(jazz,cantautor,etc.)","Pesonalizado(Musica urbana,indie,etc.)" };
	do {
        cout << Tab << "Elija el tipo de ambientacion" << endl;
        cout << Tab << "===================================" << endl;
        cout << Tab << "1. Musica en vivo" << endl;
        cout << Tab << "2. Dj " << endl;
        cout << Tab << "3. Parlantes" << endl;
        cout << Tab << "===================================" << endl;
        cout << Tab << "Ingrese el tipo: ";
        cin >> tipo;
        if (tipo < 0) {
            cout << Tab << "!!PELIGRO:Ingrese una opcion valida!!";
        }
        if (tipo == 1 && fiesta == 1) {
            system("cls");
            menu("Escoja el tipo de musica para su boda", bodam, 3, musica);
        }
        else if (tipo == 1 && fiesta == 2) {
            system("cls");
            menu("Escoja el tipo de musica de graduacion", graduacionm, 3, musica);
        }
        else if (tipo == 1 && fiesta == 3) {
            system("cls");
            menu("Seleccion su musica para cumpleanios", cumplem, 3, musica);
        }
    } while (tipo < 0 || musica == 4);
}
void menu(string title, string fiesta[MAX], int tamanio, int& opcion) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, 4);
    cout << Tab << "==================================================" << endl;
    cout << Tab << "||\t" << title << "\t||" << endl;
    cout << Tab << "==================================================" << endl;
    for (int i = 0;i < tamanio;i++) {
        color(hConsole, 4);
        cout << Tab << " " << i + 1 << ". ";
        color(hConsole, 7);
        cout << fiesta[i] << endl;
    }
    cout << Tab << " 4. Volver" << endl;
    cout << Tab << "Seleccione su opcion: ";
    cin >> opcion;
    if (opcion == 4) {
        system("cls");
    }
}

