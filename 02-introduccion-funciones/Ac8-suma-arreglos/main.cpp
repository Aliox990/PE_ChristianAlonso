/*
Nombre:     Christian Alonso Arevalos Gonzalez
Edad:       19
Recidencia: Tepatitlan
Fecha:      19/02/2025
Carrera:    Ingenieria en Computacion
Semestre:   Segundo
Codigo:     Suma de un arreglo
*/

#include <iostream>
#include <vector>
using namespace std;
#include "funciones.cpp"

// Declaración de variables
int opcion;
vector<int> arreglo;
bool ejecucion = true;

// Inicia el main
int main()
{
    cout << "Bienvenido, este programa suma los elementos de un arreglo" << endl;
    do // Inicio del do-while
    {
        mostrarMenu(); // Muestra las opciones
        cin >> opcion;

        switch (opcion)
        {
            case 1: // Agregar valor
                if (arreglo.size() < 10)
                {
                    arreglo.push_back(obtenerNumero());//agrega el nuevo elemento al final
                }
                else
                {
                    cout << "El arreglo ya esta lleno" << endl;
                }
                break;

            case 2: // Mostrar valores
                mostrarArreglo(arreglo);
                break;

            case 3: // Mostrar sumatoria
                sum(arreglo);
                break;

            case 4: // Cambiar valor
                cambiarValor(arreglo);
                break;

            case 5: // Borrar valor
                borrarValor(arreglo);
                break;

            case 6: // Vaciar arreglo
                vaciarArreglo(arreglo);
                break;

            case 7: // Salir
                ejecucion = false;
                break;

            default: // Opción no válida
                cout << "Opcion no valida. Intentalo de nuevo." << endl;
                break;
        }
    } while (ejecucion); // Fin del do-while

    return 0;
}
