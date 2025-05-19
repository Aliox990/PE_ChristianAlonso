
#include "collatz_funciones.cpp"



void teoremaDeCollatz() { //Inicio del main
    //Declaracion de variables
    int opcion, cont1=1, cont2=1, valor1=1, valor2=1;
    bool ejecucion = true;

    cout << "Bienvenido\nEste programa compara dos sucesiones que siguen el teorema de Collatz\n" << endl;
    do { //Inicio del while
        mostrarMenus(11);
        opcion = obtenerNumero();

        switch (opcion) {
        case 1:{
                while (ejecucion){
                    cout << "Que valor quieres modificar?" << endl;
                    cout << "1. Valor 1: " << valor1 << endl;
                    cout << "2. Valor 2: " << valor2 << endl;
                    cout << "3. Salir" << endl;
                    cout << "Seleccione una opcion: " << endl;
                    opcion = obtenerNumero();
                    switch (opcion) {
                    case 1:{
                            cout << "Ingrese un valor:";
                            valor1 = obtenerNumero();
                            break;
                    }
                    case 2:{
                            cout << "Ingrese un valor:";
                            valor2 = obtenerNumero();
                            break;
                    }
                    case 3:{
                            cout << "Volviendo al menu principal..." << endl;
                            ejecucion = false;
                    }
                    default:{
                            cout << "Opcion invalida\n";
                    }
                    }
                }// fin del while
                ejecucion = true;
                break;
        }

        case 2:{
                cout << "Sucesion del primer valor (" << valor1 << "):" << endl;
                cont1 = secuencia(valor1);
                cout << "Valores de la sucesion" << cont1 << endl << endl;
                cout << "Sucesion del segundo valor (" << valor2 << "):" << endl;
                cont2 = secuencia(valor2);
                cout << "Valorese de la sucesion:" << cont2 << endl << endl;
                break;
        }

        case 3:{
                ejecucion = false;
                break;
        }

        default:{
                cout << "Opcion invalida" << endl;
                break;
        }

        }
    } while (ejecucion); // Fin del while

    cout << "Gracias por usar el prgrama" << endl;
} //Fin del main
