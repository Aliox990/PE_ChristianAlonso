//
// Created by Alonso on 09/02/2025.
//

#include <iostream>
using namespace std;
//declaracion de varables
int num, fibonacci, antFibonacci, comprobacion, bucle;
char continuar;

// Función para comprobar si el número del usuario es igual o cercano al número de Fibonacci
int comparar(int num, int fibonacci, int antFibonacci) {
    if (num == fibonacci || num < fibonacci + antFibonacci || num == antFibonacci)
        return 1;
    else
        return 0;
}

int main() { //inicio del main

    do { //bucle principal, al final se le pregunta al usuario si quiere repetir este bucle
        cout << "Ingresa un valor: ";
        cin >> num;  // el usuario ingresa su número
        comprobacion = 0;

        if (num == 0) {  // por si el usuario ingresa el número 0, que el código no imprima el 1
            cout << 0 << endl;
        } else {
            cout << "Con que bucle quieres hacer el procedimiento? 1:for   2:while   3:do-while: ";
            cin >> bucle;  // el usuario elige el bucle que usará

            antFibonacci = 0;
            fibonacci = 1;
            cout << antFibonacci << endl;
            cout << fibonacci << endl;

            switch (bucle) { //inicio del switch
                case 1: //primer caso
                    // Usar bucle For
                    for (comprobacion = 0; comprobacion < 1; ) {
                        comprobacion = comparar(num, fibonacci, antFibonacci);
                        fibonacci = fibonacci + antFibonacci;  // se consigue nuevo valor para fibonacci y se recalcula el anterior valor
                        antFibonacci = fibonacci - antFibonacci;
                        if (comprobacion == 0)  // para que se detenga antes de que el número de Fibonacci sea mayor al del usuario
                            cout << fibonacci << endl;
                    }
                    break;//fin del primer caso

                case 2: //segundo caso
                    // Usar bucle While
                    while (comprobacion == 0) {
                        comprobacion = comparar(num, fibonacci, antFibonacci);
                        fibonacci = fibonacci + antFibonacci;  // se consigue nuevo valor para fibonacci y se recalcula el anterior valor
                        antFibonacci = fibonacci - antFibonacci;
                        if (comprobacion == 0)  // para que se detenga antes de que el número de Fibonacci sea mayor al del usuario
                            cout << fibonacci << endl;
                    }
                    break;//fin del segundo caso

                case 3://tercer caso
                    // Usar bucle Do-While
                    do {
                        comprobacion = comparar(num, fibonacci, antFibonacci);
                        fibonacci = fibonacci + antFibonacci;  // se consigue nuevo valor para fibonacci y se recalcula el anterior valor
                        antFibonacci = fibonacci - antFibonacci;
                        if (comprobacion == 0)  // para que se detenga antes de que el número de Fibonacci sea mayor al del usuario
                            cout << fibonacci << endl;
                    } while (comprobacion == 0);
                    break;//fin del tercer caso

                default:// por si no se selecciono un numero valido
                    cout << "Seleccion invalida" << endl;
            }// fin del switch
        }

        cout << "Quieres continuar con otro numero? (S/N): ";  // pregunta al usuario si quiere ejecutar el código de nuevo, si es 'n' el código dejará de ejecutarse
        cin >> continuar;
    } while (continuar != 'N' && continuar != 'n'); // fin del do while

    return 0;
}// fin del main
