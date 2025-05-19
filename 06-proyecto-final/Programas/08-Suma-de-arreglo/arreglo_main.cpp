
#include "arreglo_funciones.cpp"




void sumaDeArreglo()
{
    // Declaración de variables
    int opcion;
    vector<int> arreglo;
    bool ejecucion = true;

    while (ejecucion) // Inicio del do-while
    {
        mostrarMenus(8); // Muestra las opciones
        opcion = obtenerNumero();

        switch (opcion)
        {
        case 1: // Agregar valor
            if (arreglo.size() < 10)
            {
                cout << "Ingresa un valor para la posicion " << arreglo.size()+1 << ":" << endl;
                arreglo.push_back(obtenerNumero());//agrega el nuevo elemento al final
                saltoGrande();
            }
            else
            {
                cout << "El arreglo ya esta lleno" << endl;
                cout << endl << "Presiona enter para continuar" << endl;
                esperar();
            }
            break;

        case 2: // Mostrar valores
            mostrarArreglo(arreglo);
            cout << endl << "Presiona enter para continuar" << endl;
            esperar();
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
    } // Fin del while
}
