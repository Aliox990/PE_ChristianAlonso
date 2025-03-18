
#include <iostream>
using namespace std;



// Esta función muestra un menú con opciones para el usuario.
//
// No recibe parámetros y no devuelve ningún valor.
void mostrarMenu() {
    cout << "\nMenu de opciones:\n";
    cout << "1.  Cambiar valor\n";
    cout << "2.  Comparar secuencias\n";
    cout << "3.  Salir\n";
    cout << "Seleccione una opcion: ";
}


// Esta función obtiene un número y evita errores por ingresar caracteres no válidos
//
// Valor de retorno:
// - Regresa un número entero, puede ser negativo o positivo.
// - No regresa ningún valor hasta que se ingrese un número válido.
int obtenerNumero() {
    string entrada; // Variable para almacenar la entrada del usuario
    int num; // Variable donde se almacenará el número convertido

    while (true) { // Se repite hasta obtener un número válido
        cin >> entrada;

        // Verificar si la entrada es un número entero válido
        bool esEntero = true; // Bandera para validar la entrada
        for (size_t i = 0; i < entrada.length(); i++) { // Se recorre cada caracter de la entrada
            if (!isdigit(entrada[i]) && !(entrada[i] == '-' && i == 0)) {
                // Permitir solo dígitos y el '-' al inicio (para números negativos)
                esEntero = false;
                break; // Salir del ciclo si encuentra un carácter no válido
            }
        } // Fin del for

        if (esEntero) { // Si es un número entero válido
            try {
                num = stoi(entrada); // Convierte la cadena a entero
                break; // Si la conversión es exitosa, salir del bucle
            } catch (...) { // Captura cualquier error de conversión
                esEntero = false;
            }
        }

        cout << "ERROR: Debes ingresar un numero entero valido.\n"; // Mensaje de error
        cout << "Ingresa otro numero: ";
    } // Fin del while

    return num; // Retorna el número validado
}


// Esta funcion muestra la sucesion de numeros y comprueba cuantos numeros tiene en total
//
// Parametros:
// - valor: el numero con el que comenzara la sucesion
//
// Valor de retorno:
// - Regresa la cantidad de numeros que tiene la sucesion
int secuencia(int valor) {
    int contador = 1;
    bool ejecucion = true;

    while (ejecucion)
    {
        cout << valor << ", ";
        if (valor == 1)
        {
            cout << "el valor debe ser mayor a 1" << endl;
            ejecucion = false;
        }
        else if (valor % 2 == 0)
        {
            valor /= 2;
            contador++;
            if (valor == 1)
            {
                ejecucion = false;
                cout << valor << "." << endl;
            }
        }
        else if (valor % 2 != 0)
        {
            valor *= 3;
            valor += 1;
            contador++;
        }
    }// fin del while

    return contador;
}