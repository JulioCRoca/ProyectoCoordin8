#include <iostream>
using namespace std;
void mostrarPaquete1() {
    cout << "1.Paquete 1" << endl;
    cout << " Incluye:" << endl;
    cout << "   Flores:  " << endl;
    cout << "     *Centros de mesas pequeños florales" << endl;
    cout << "     *Ramo basico (Rosas blancas)" << endl;
    cout << "     *Petalos sencillos para el camino (2 colores)" << endl;
    cout << "   Mesas:  " << endl;
    cout << "     *Cubiertos, platos y vasos estandar" << endl;
    cout << "     *Servilletas" << endl;
    cout << "     *Velas pequeñas para cada mesa" << endl;
    cout << "   Iluminacion:  " << endl;
    cout << "     *Faroles" << endl;
    cout << "     *Guirnaldas calidas" << endl;
}
void mostrarPaquete2() {
    cout << "2.Paquete 2" << endl;
    cout << " Incluye:" << endl;
    cout << "   Flores:  " << endl;
    cout << "     *Centros de mesas medianos florales" << endl;
    cout << "     *Ramo (Lirios)" << endl;
    cout << "     *Petalos sencillos para el camino (3 colores)" << endl;
    cout << "   Mesas:  " << endl;
    cout << "     *Cubiertos, platos y vasos elegantes" << endl;
    cout << "     *Servilletas de tela con decoracion simple" << endl;
    cout << "     *Velas medianas para cada mesa" << endl;
    cout << "   Iluminacion:  " << endl;
    cout << "     *Faroles colgantes pequeños" << endl;
    cout << "     *Luces LED calidas" << endl;
}
void mostrarPaquete3() {
    cout << "3.Paquete 3" << endl;
    cout << " Incluye:" << endl;
    cout << "   Flores:  " << endl;
    cout << "     *Centros de mesas pequeños florales (orquideas)" << endl;
    cout << "     *Ramo (Peonias)" << endl;
    cout << "     *Petalos aromaticos para el camino (3 colores)" << endl;
    cout << "   Mesas:  " << endl;
    cout << "     *Cubiertos de plata, platos de porcelana y vasos de cristal tallado" << endl;
    cout << "     *Servilletas de tela con bordados" << endl;
    cout << "     *Velas aromaticas grandes en porta velas de cristal" << endl;
    cout << "   Iluminacion:  " << endl;
    cout << "     *Faroles" << endl;
    cout << "     *Guirnaldas LED" << endl;
}
bool confirmarPaquete(int opcion) {
    char confirmar;
    switch (opcion) {
    case 1:
        cout << "Ha seleccionado el Paquete 1." << endl;
        break;
    case 2:
        cout << "Ha seleccionado el Paquete 2." << endl;
        break;
    case 3:
        cout << "Ha seleccionado el Paquete 3." << endl;
        break;
    default:
        cout << "Opción no válida. Intente nuevamente." << endl;
        return false;
    }

    cout << "¿Desea confirmar este paquete? (s/n): ";
    cin >> confirmar;

    if (confirmar == 's' || confirmar == 'S') {
        cout << "¡Gracias! Ha confirmado su elección del paquete." << endl;
        return true;
    }
    else {
        cout << "Volviendo a mostrar las opciones..." << endl;
        return false;
    }
}