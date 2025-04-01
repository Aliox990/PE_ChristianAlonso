
/*
Nombre:     Christian Alonso Arevalos Gonzalez
Edad:       19
Recidencia: Tepatitlan
Fecha:      30/03/2025
Carrera:    Ingenieria en Computacion
Semestre:   Segundo
Codigo:     Ahorcado
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "funciones.cpp"

// Declaracion de variables
int opcion;
bool ejecucion = true;

int main(){
    srand(time(0));//Para generar aleatoriedad cuando juegue la computadora



    while(ejecucion){
        // Mostrar menú principal del juego
        Menu();
        opcion = obtenerNumero();

        switch(opcion){
        case 1: // Jugador contra Jugador
            jugarPvP();
            break;
        case 2: // Jugador contra Computadora
            jugarPvC();
            break;
        case 3: // Salir
            ejecucion = false;
            cout << "\nSaliendo del juego. Gracias por jugar!" << endl;
            break;
        default:
            cout << "Opcion no valida. Intente nuevamente." << endl;
            break;
        }
    }// fin del while

    return 0;
}// fin del main
