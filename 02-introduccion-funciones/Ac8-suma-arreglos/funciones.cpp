#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Esta función muestra el menú de opciones
void mostrarMenu()
{
    cout << "Menu" << endl;
    cout << "1. Agregar valor" << endl;
    cout << "2. Mostrar valores" << endl;
    cout << "3. Mostrar sumatoria" << endl;
    cout << "4. Cambiar valor" << endl;
    cout << "5. Borrar valor" << endl;
    cout << "6. Vaciar arreglo" << endl;
    cout << "7. Salir" << endl;
    cout << "Que quieres hacer? ";
}

// Muestra el contenido del vector
void mostrarArreglo(const vector<int>& arreglo)
{
    if (arreglo.empty())
    {
        cout << "El arreglo esta vacio." << endl;
        return;
    }

    cout << "Lista de valores:" << endl;
    for (int i = 0; i < arreglo.size(); i++)
    {
        cout << "Posicion " << i << ": " << arreglo[i] << endl;
    }
}

// Calcula y muestra la suma de los elementos del vector
void sum(const vector<int>& arreglo)
{
    if (arreglo.empty())
    {
        cout << "El arreglo está vacio. La suma es 0." << endl;
        return;
    }

    unsigned long suma = 0;
    for (int num : arreglo)
    {
        suma += num;
    }
    cout << "El resultado es: " << suma << endl;
}

// Esta función obtiene un número y evita errores por ingresar caracteres no válidos
//
// Valor de retorno:
// - Regresa un numero entero, puede ser negativo o positivo
// - No regresa ningun valor hasta que se ingrese un numero valido
int obtenerNumero() {
    string entrada;
    int num;

    while (true) {
        cout << "Ingresa un numero entero: ";
        cin >> entrada;

        // Verificar si la entrada es un número entero válido
        bool esEntero = true;
        for (char c : entrada) { // se recorre cada caracter de la entrada
            if (!isdigit(c) && !(c == '-' && c == entrada[0])) { // Permitir solo dígitos y el '-' al inicio
                esEntero = false;
                break;
            }
        } // fin del for

        if (esEntero) {
            try {
                num = stoi(entrada); // Convierte la cadena a entero
                break; // Si la conversion sale bien, sale del bucle
            } catch (...) {
                esEntero = false; // Capturar cualquier error de conversión
            }
        }

        cout << "ERROR: Debes ingresar un numero entero valido.\n";
    }

    return num;
}


// Modifica un valor dentro del vector en la posición que el usuario elija
//
// Parametro:
// - vector: vector al que se le quiere modificar un valor
void cambiarValor(vector<int>& arreglo)
{
    if (arreglo.empty())
    {
        cout << "El arreglo está vacio." << endl;
        return;
    }

    int posicion;
    mostrarArreglo(arreglo);
    cout << "Ingresa la posicion a cambiar (0 a " << arreglo.size() - 1 << "): ";
    cin >> posicion;

    if (posicion >= 0 && posicion < arreglo.size())
    {
        arreglo[posicion] = obtenerNumero();
    }
    else
    {
        cout << "Posicion invalida" << endl;
    }
}

// Borra un valor dentro del vector en la posición que el usuario elija
//
// Parametro:
// - Vector: vector en el que se quiere borrar un valor
void borrarValor(vector<int>& arreglo)
{
    if (arreglo.empty())
    {
        cout << "El arreglo esta vacio." << endl;
        return;
    }

    int posicion;
    mostrarArreglo(arreglo);
    cout << "Ingresa la posicion a borrar (0 a " << arreglo.size() - 1 << "): ";
    cin >> posicion;

    if (posicion >= 0 && posicion < arreglo.size())
    {
        arreglo.erase(arreglo.begin() + posicion);
        cout << "Valor eliminado." << endl;
    }
    else
    {
        cout << "Posicion invalida." << endl;
    }
}

// Vacía completamente el vector
//
// Parametro:
// - vector: el vector que se quiere vaciar
void vaciarArreglo(vector<int>& arreglo)
{
    arreglo.clear();
    cout << "El arreglo ha sido vaciado." << endl;
}
