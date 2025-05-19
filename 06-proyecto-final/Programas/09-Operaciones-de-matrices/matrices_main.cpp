
#include "matrices_funciones.cpp"


void operacionesMatrices() {
    // declaracion de variables
    int opcion, tamano=2;
    vector<vector<int>> matriz1, matriz2, resultado;
    bool ejecucion = true;


    do { // inicio del do-while
        mostrarMenus(9);
        opcion = obtenerNumero();

        switch (opcion) { //inicio del switch
            case 1: // Definir tamaño de la matriz
                tamano=obtenerTamano();
                break;

            case 2: // Llenar matrices manualmente
            {
                while (ejecucion)
                {
                    cout << "A que matriz le quieres agregar valores?\n";
                    cout << "1. Matriz 1\n2. Matriz 2\n3. Salir\n";
                    opcion = obtenerNumero();

                    switch (opcion)
                    {
                    case 1:
                        agregarValores(matriz1, tamano);
                        break;
                    case 2:
                        agregarValores(matriz2, tamano);
                        break;
                    case 3:
                        cout << "Saliendo del llenado manual...\n";
                        ejecucion = false;
                        break;
                    default:
                        cout << "Opcion invalida. Por favor, intentalo de nuevo.\n";
                        break;
                    }
                } // fin del while
                saltoGrande();
                ejecucion = true;
                break;
            }// fin del caso 2

            case 3: // Llenar matrices aleatoriamente
            {
                while (ejecucion)
                {
                    cout << "A que matriz le quieres agregar valores aleatorios?\n";
                    cout << "1. Matriz 1\n2. Matriz 2\n3. Salir\n";
                    opcion = obtenerNumero();

                    switch (opcion)
                    {
                        case 1:
                            agregarAleatorio(matriz1, tamano);
                            break;
                        case 2:
                            agregarAleatorio(matriz2, tamano);
                            break;
                        case 3:
                            cout << "Saliendo del llenado aleatorio...\n";
                            ejecucion = false;
                            break;
                        default:
                            cout << "Opcion invalida. Por favor, intentalo de nuevo.\n";
                            break;
                    }// fin del switch
                } // fin del while
                saltoGrande();
                ejecucion = true;
                break;
            }// fin del caso 3

            case 4: // Mostrar matrices
            {
                while (ejecucion)
                {
                    cout << "Que matriz te gustaria ver?\n";
                    cout << "1. Matriz 1\n2. Matriz 2\n3. Salir\n";
                    opcion = obtenerNumero();

                    switch (opcion)
                    {
                        case 1:
                            mostrarMatriz(matriz1, tamano);
                            cout << endl << endl << "Presiona enter para continuar" << endl;
                            esperar();
                            break;
                        case 2:
                            mostrarMatriz(matriz2, tamano);
                            cout << endl << endl << "Presiona enter para continuar" << endl;
                            esperar();
                            break;
                        case 3:
                            cout << "Saliendo de la visualizacion de matrices...\n";
                            ejecucion = false;
                            break;
                        default:
                            cout << "Opcion invalida. Por favor, intentalo de nuevo.\n";
                            break;
                    }//fin del switch
                } //fin del while
                saltoGrande();
                ejecucion = true;
                break;
            }// fin del caso 4


            case 5: // Sumar matrices
                sumarMatrices(matriz1, matriz2, tamano);
                break;

            case 6: // Restar matrices
            {
                cout << "Matriz 1:" << endl;
                mostrarMatriz(matriz1, tamano);
                cout << "Matriz 2:" << endl;
                mostrarMatriz(matriz2, tamano);

                cout << "Que matriz te gustaria ver?\n";
                cout << "1. Matriz 1 - Matriz 2\n2. Matriz 2 - Matriz 1\n";
                opcion = obtenerNumero();


                switch (opcion)
                {
                    case 1:
                        restarMatrices(matriz1, matriz2, tamano);
                        break;
                    case 2:
                        restarMatrices(matriz2, matriz1, tamano);
                        break;
                    default:
                        cout << "Opcion invalida. Por favor, intentalo de nuevo.\n";
                        break;
                }//fin del switch
                break;
            }
            case 7: // Multiplicar matrices
            {
                cout << "Matriz 1:" << endl;
                mostrarMatriz(matriz1, tamano);
                cout << "Matriz 2:" << endl;
                mostrarMatriz(matriz2, tamano);

                cout << "Que matriz te gustaria ver?\n";
                cout << "1. Matriz 1 x Matriz 2\n2. Matriz 2 x Matriz 1\n";
                opcion = obtenerNumero();


                switch (opcion)
                {
                    case 1:
                        multMatrices(matriz1, matriz2, tamano);
                        break;
                    case 2:
                        multMatrices(matriz2, matriz1, tamano);
                        break;
                    default:
                        cout << "Opcion invalida. Por favor, intentalo de nuevo.\n";
                        break;
                }//fin del switch
                break;
            }


            case 8: // Editar valor
            {
                while (ejecucion)
                {
                    cout << "Que matriz te gustaria modificar?\n";
                    cout << "1. Matriz 1\n2. Matriz 2\n3. Salir\n";
                    opcion = obtenerNumero();

                    switch (opcion)
                    {
                        case 1:
                            editarValor(matriz1, tamano);
                            break;
                        case 2:
                            editarValor(matriz2, tamano);
                            break;
                        case 3:
                            cout << "Saliendo de la modificacion de matrices...\n";
                            ejecucion = false;
                            break;
                        default:
                            cout << "Opcion invalida. Por favor, intentalo de nuevo.\n";
                            break;
                    }//fin del switch
                } //fin del while
                ejecucion = true;
                break;
            }

            case 9: // Vaciar matrices
            {
                cout << "Estas seguro de querer borrar las matrices?\n";
                cout << "1. Si\n2. No\n";
                opcion = obtenerNumero();

                switch (opcion)
                {
                    case 1:
                        vaciarMatrices(matriz1,matriz2,tamano);
                        break;
                    case 2:
                        break;
                    default:
                        cout << "Opcion invalida.\n";
                }
                break;
            }

            case 10: // Salir
                ejecucion=false;
                break;

            default:
                cout << "ERROR: Opcion Invalida. \nPresione Enter para continuar" << endl;
                cin.ignore();
                cin.get();
                break;
        }// fin del switch
    } while (ejecucion); // fin del do-while
}
