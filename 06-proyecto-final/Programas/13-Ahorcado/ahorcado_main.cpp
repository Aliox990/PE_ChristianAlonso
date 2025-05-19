

#include "ahorcado_funciones.cpp"



void Ahorcado(){
    srand(time(0));//Para generar aleatoriedad cuando juegue la computadora

    // Declaracion de variables
    int opcion;
    bool ejecucion = true;

    while(ejecucion){
        // Mostrar menú principal del juego
        mostrarMenus(13);
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
}// fin del main
