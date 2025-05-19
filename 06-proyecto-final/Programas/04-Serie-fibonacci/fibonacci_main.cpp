
#include "fibonacci_funciones.cpp"

void serieFibonacci() { //inicio del main
    int num, antFibonacci = 0, fibonacci = 1, bucle, comprobacion = 0;
    bool ejecucion=true;

    do { //bucle principal, al final se le pregunta al usuario si quiere repetir este bucle

    mostrarMenus(4);
    bucle=obtenerNumero();

        switch (bucle) { //inicio del switch
            case 1: //primer caso
                // Usar bucle For
                cout << "Ingresa un valor:";
                num = obtenerNumero();
                antFibonacci = 0;
                fibonacci = 1;
                cout << antFibonacci << endl;
                if (num == 0)//paro no imprimir numeros de mas
                {
                    break;
                }
                cout << fibonacci << endl;

                for (comprobacion = 0; comprobacion < 1; ) {

                    comprobacion = comparar(num, fibonacci, antFibonacci);
                    fibonacci = fibonacci + antFibonacci;  // se consigue nuevo valor para fibonacci y se recalcula el anterior valor
                    antFibonacci = fibonacci - antFibonacci;
                    if (comprobacion == 0)  // para que se detenga antes de que el número de Fibonacci sea mayor al del usuario
                        cout << fibonacci << endl;
                }
                cout << "Pulse enter para continuar" << endl;
                esperar();
                break;//fin del primer caso

            case 2: //segundo caso
                // Usar bucle While
                comprobacion = 0;
                cout << "Ingresa un valor:";
                num = obtenerNumero();
                antFibonacci = 0;
                fibonacci = 1;
                cout << antFibonacci << endl;
                if (num == 0)//paro no imprimir numeros de mas
                {
                    break;
                }
                cout << fibonacci << endl;
                while (comprobacion == 0) {
                    comprobacion = comparar(num, fibonacci, antFibonacci);
                    fibonacci = fibonacci + antFibonacci;  // se consigue nuevo valor para fibonacci y se recalcula el anterior valor
                    antFibonacci = fibonacci - antFibonacci;
                    if (comprobacion == 0)  // para que se detenga antes de que el número de Fibonacci sea mayor al del usuario
                        cout << fibonacci << endl;
                }
                cout << "Pulse enter para continuar" << endl;
                esperar();
                break;//fin del segundo caso

            case 3://tercer caso
                // Usar bucle Do-While
                cout << "Ingresa un valor:";
                num = obtenerNumero();
                antFibonacci = 0;
                fibonacci = 1;
                cout << antFibonacci << endl;
                if (num == 0)//paro no imprimir numeros de mas
                {
                    break;
                }
                cout << fibonacci << endl;
                do {
                    comprobacion = comparar(num, fibonacci, antFibonacci);
                    fibonacci = fibonacci + antFibonacci;  // se consigue nuevo valor para fibonacci y se recalcula el anterior valor
                    antFibonacci = fibonacci - antFibonacci;
                    if (comprobacion == 0)  // para que se detenga antes de que el número de Fibonacci sea mayor al del usuario
                        cout << fibonacci << endl;
                } while (comprobacion == 0);
                cout << "Pulse enter para continuar" << endl;
                esperar();
                break;//fin del tercer caso
            case 4:
                {
                    ejecucion = false;
                }

            default:// por si no se selecciono un numero valido
                cout << "Seleccion invalida" << endl;
            }// fin del switch
    } while (ejecucion); // fin del do while
}