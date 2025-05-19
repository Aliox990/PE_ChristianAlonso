
#include "conjuntos_funciones.cpp"

void operacionesConjuntos() {
    vector<string> conjuntoA, conjuntoB, universo;
    int opcion;
    bool ejecucion = true;

    cout << "Bienvenido, este programa realiza operaciones de conjuntos." << endl;

    do {
        mostrarMenus(10); // Muestra el menú al usuario
        opcion = obtenerNumero(); // Obtiene la opción seleccionada por el usuario

        switch (opcion) {
            case 1:
                // Agregar elemento a A
                agregarElemento(conjuntoA, universo, conjuntoB, "A");
                cout << endl << endl << "Presiona enter para continuar" << endl;
                cin.get();
                break;
            case 2:
                // Agregar elemento a B
                agregarElemento(conjuntoB, universo, conjuntoA, "B");
                cout << endl << endl << "Presiona enter para continuar" << endl;
                cin.get();
                break;
            case 3:
                // Mostrar conjunto A
                mostrarConjunto(conjuntoA, "A");
                cout << endl << endl << "Presiona enter para continuar" << endl;
                esperar();
                break;
            case 4:
                // Mostrar conjunto B
                mostrarConjunto(conjuntoB, "B");
                cout << endl << endl << "Presiona enter para continuar" << endl;
                esperar();
                break;
            case 5:
                // Editar elemento de A
                editarElemento(conjuntoA, universo, "A");
                saltoGrande();
                break;
            case 6:
                // Editar elemento de B
                editarElemento(conjuntoB, universo, "B");
                saltoGrande();
                break;
            case 7:
                // Borrar elemento de A
                borrarElemento(conjuntoA, "A");
                saltoGrande();
                break;
            case 8:
                // Borrar elemento de B
                borrarElemento(conjuntoB, "B");
                saltoGrande();
                break;
            case 9:
                // Vaciar conjunto A
                vaciarConjunto(conjuntoA, "A");
                break;
            case 10:
                // Vaciar conjunto B
                vaciarConjunto(conjuntoB, "B");
                break;
            case 11:
                // Realizar Unión
                unionConjuntos(conjuntoA, conjuntoB);
                break;
            case 12:
                // Realizar Intersección
                interseccionConjuntos(conjuntoA, conjuntoB);
                break;
            case 13:
                // Realizar Diferencia
                diferenciaConjuntos(conjuntoA, conjuntoB);
                break;
            case 14: {
                // Realizar Complemento
                cout << "Elige el conjunto para calcular el complemento:" << endl;
                cout << "1. Complemento de A" << endl;
                cout << "2. Complemento de B" << endl;
                cout << "Selecciona una opcion: ";
                int opcionComp = obtenerNumero();
                if (opcionComp == 1) {
                    complementoConjunto(conjuntoA, universo, "A");
                } else if (opcionComp == 2) {
                    complementoConjunto(conjuntoB, universo, "B");
                } else {
                    cout << "Opcion no valida." << endl;
                }
                break;
            }
            case 15:
                // Salir del programa
                ejecucion = false;
                break;
            default:
                cout << "Opcion no válida. Intentalo de nuevo." << endl;
                break;
        }

        // Actualizar el universo después de cada operación para mantenerlo sincronizado
        actualizarUniverso(universo, conjuntoA, conjuntoB);

        cout << endl;

    } while (ejecucion);
}
