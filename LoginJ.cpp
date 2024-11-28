#include <iostream >
#include <sqlite3.h>
#include "LoginJ.h"
#include <string>
#include "JFunciones.h"
#include <Windows.h>
#include "SFunciones.h"
#define Tab "\t\t\t\t\t\t"
#define color SetConsoleTextAttribute


using namespace std;
void cargando();
void dibujar();
bool verificarCI(string CI);
void conexion();
bool CIexistente(string CI);
void insertarUsuario(string CI, string password, string Nombre, int roll);//inserta los datos en la tabla 
bool validacion(string CI, string password, string Nombre);
sqlite3 *db;
sqlite3_stmt *stmt;
int result;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void loginJ(int &eleccion1, int &eleccion2){
	string CI,Nombre,password,passwordcheck;
	int roll=0; 
	bool verifyCI;
	conexion(); //se conecta a la base de datos 
	
	if (eleccion1 == 1) {
		system("cls");
		color(hConsole, 4);
		dibujar();
		color(hConsole, 7);
		cout << endl;
		cout << endl;
		cout << Tab << "==================================" << endl;
		cout << Tab << "1. Volver al menu principal" << endl; 
		cout << Tab << "2. Continuar con el registro" << endl;
		cout << Tab << "=================================" << endl;
		eleccion2 = obtenerEntero("Ingrese una opcion: ");

		if (eleccion2 == 1) {
			return;
		}
		
		
			if (eleccion2 == 2) {
				system("cls");
				color(hConsole, 4);
				dibujar();
				color(hConsole, 7);
				cout << Tab << "==================================" << endl;
				cout << Tab << "||      Registro de Usuarios    ||" << endl;
				cout << Tab << "==================================" << endl;
				cout << endl;
			}
			do{
			cout << Tab << "Ingrese su CI:"; //pide Carnet
			cin >> CI;
			verifyCI = CIexistente(CI);
			if (!verifyCI) {
				cout << Tab << "El CI ya está registrado, intente con otro." << endl;
				continue;
			}
			if (!verificarCI(CI)) {
				cout << Tab << "El CI ingresado no es válido, intente nuevamente." << endl;
			}
			} while (!verifyCI || !verificarCI(CI)); //Verifica validez del Carnet
			
		do {
			
			cout << Tab << "Ingrese su usuario: ";
			cin >> Nombre;
			if (Nombre.empty()) {
				cout << "Ingresar usuario OBLIGATORIO" << endl; //Si no puso nada pide obligatoriamente
			}
		} while (Nombre.empty());
		do {
			do {
				cout << Tab << "Ingrese su contrasenia(sin espacios, valido con _): "; //Lo mismo con la contrasenia
				cin.ignore();
				getline(cin,password);
				if (Nombre.empty()) { //verifica si no ingreso nada
					cout << "Ingresar contrasenia OBLIGATORIO" << endl;
				}
			} while (password.empty());
			cout << Tab << "Confirme su contrasenia: ";
			cin >> passwordcheck;
			if (password != passwordcheck) {
				cout << Tab << "Las contrasenias no coinciden, ingrese nuevamente" << endl;
			}
		} while (password != passwordcheck); //repite mientras las contrasenias sean distintas
		roll = 2; 
		if (CIexistente(CI)) {

			insertarUsuario(CI, passwordcheck, Nombre, roll);
		}	
	
	}
	else if (eleccion1 == 2) {
		do {
			system("cls");
			color(hConsole, 4);
			dibujar();
			color(hConsole, 7);
			cout << Tab << "==================================" << endl;
			cout << Tab << "||	Inicio de sesion        ||" << endl;
			cout << Tab << "==================================" << endl;
			cout << endl;
			cout << endl;
			cout << Tab << "Ingrese su usuario: ";
			cin >> Nombre;
			cout << Tab << "Ingrese su CI: ";
			cin >> CI;
			cout << Tab << "Ingrese su contrasenia: ";
			cin >> password;
			cargando();
		}while(!validacion(CI, password, Nombre));
		cout << Tab << "!!Inicio de sesion exitoso!!" << endl;
		cout << Tab << "Bienvenid@ " << Nombre;
		Sleep(2000);
	}
	sqlite3_close(db);
}
void conexion() {
	if (sqlite3_open("users.db", &db) == SQLITE_OK) {
		result = sqlite3_prepare_v2(db, "CREATE TABLE IF NOT EXISTS user(CI varchar(8),password varchar(50),name varchar(50), roll INT);", -1, &stmt, NULL);
		if (result == SQLITE_OK) {
			sqlite3_step(stmt);
		}
		sqlite3_finalize(stmt); // Finaliza el stmt aquí
		if (result != SQLITE_OK) {
			cout << "Error al crear la tabla: " << sqlite3_errmsg(db) << "\n";
		}
	}
}

//Verifica si en la base de datos existe un CI igual
bool CIexistente(string CI) {
	const char* sql = "SELECT CI FROM user WHERE CI = ?;"; 
	sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

	sqlite3_bind_text(stmt, 1, CI.c_str(), -1, SQLITE_STATIC);

	int result = sqlite3_step(stmt);
	sqlite3_finalize(stmt);

	if (result == SQLITE_ROW) {
		return false;
	}

	return true;
}
//Permite ingresar los datos del usuario
void insertarUsuario(string CI, string password, string Nombre, int roll) {
	const char* sql = "INSERT INTO user (CI, password, name, roll) VALUES (?, ?, ?, ?);";

	if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
		sqlite3_bind_text(stmt, 1, CI.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(stmt, 3, Nombre.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_int(stmt, 4, roll);

		if (sqlite3_step(stmt) == SQLITE_DONE) {
			cout << Tab << "Usuario registrado exitosamente." << endl;
			Sleep(2000);
			return;
		}
		else {
			cout << Tab << "Error al registrar el usuario: " << sqlite3_errmsg(db) << endl;
			Sleep(4000);
		}

		sqlite3_finalize(stmt);
	}
	else {
		cout << Tab << "Error al preparar la consulta: " << sqlite3_errmsg(db) << endl;
	}
}
//Valida al momento de loguearse
bool validacion(string CI, string password, string Nombre) {
	const char* CIver;
	const char* passwordVer;
	const char* nombreVer;
	bool encontrar = false;

	// Abrir base de datos
	if (sqlite3_open("users.db", &db) != SQLITE_OK) {
		cout << Tab << "Error al abrir la base de datos: " << sqlite3_errmsg(db) << endl;
		return false;
	}

	// Preparar consulta
	const char* sql = "SELECT CI, password, name,roll FROM user;";
	if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
		cout << Tab << "Error al preparar la consulta: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		return false;
	}

	// Recorrer filas
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		// Leer valores de la fila
		CIver = (const char*)sqlite3_column_text(stmt, 0);
		if (CI == string(CIver)) { // Comparar CI
			encontrar = true;
			passwordVer = (const char*)sqlite3_column_text(stmt, 1);
			nombreVer = (const char*)sqlite3_column_text(stmt, 2);

			// Comparar password y nombre
			if (password != string(passwordVer)) {
				cout << Tab << "Contraseña incorrecta" << endl;
				Sleep(1000);
				sqlite3_finalize(stmt);
				sqlite3_close(db);
				return false;
			}
			else if (Nombre != string(nombreVer)) {
				cout << Tab << "Usuario incorrecto" << endl;
				Sleep(1000);
				sqlite3_finalize(stmt);
				sqlite3_close(db);
				return false;
			}
			else {
				sqlite3_finalize(stmt);
				sqlite3_close(db);
				return true;
			}
		}
	}

	// Finalizar y cerrar si no se encontró el CI
	sqlite3_finalize(stmt);
	sqlite3_close(db);

	if (!encontrar) {
		cout << Tab << "CI incorrecto" << endl;
		Sleep(1000);
		return false;
	}

	return false;
}
