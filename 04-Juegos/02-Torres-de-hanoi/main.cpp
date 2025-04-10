/*
Nombre:     Christian Alonso Arevalos Gonzalez
Edad:       19
Recidencia: Tepatitlán
Fecha:      25/03/2025
Carrera:    Ingeniería en Computación
Semestre:   Segundo
Código:     Torres de Hanoi
*/

#include <iostream>
using namespace std;

#include "funciones.cpp"

//declaracion de variables
int opcion;
bool ejecucion = true;

int main() {
    pantallaInicio();
    while (ejecucion) {



        mostrarMenu();                // Mostrar opciones al usuario
        opcion = obtenerNumero(); // Leer opción con validación

        switch (opcion) {
        case 1:
            jugarHanoi(); // Iniciar partida
            break;
        case 2:
            ejecucion = false;
            cout << "\nSaliendo del juego. ¡Hasta luego!\n";
            break;
        default:
            cout << "Opcion invalida. Intenta de nuevo.\n";
            break;
        }
    }
    return 0;
}
