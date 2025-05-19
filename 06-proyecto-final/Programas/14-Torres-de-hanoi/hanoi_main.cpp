
#include "hanoi_funciones.cpp"



void torresDeHanoi() {
    //declaracion de variables
    int opcion;
    bool ejecucion = true;

    pantallaInicio();
    while (ejecucion) {



        mostrarMenus(14);   // Mostrar opciones al usuario
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
}
