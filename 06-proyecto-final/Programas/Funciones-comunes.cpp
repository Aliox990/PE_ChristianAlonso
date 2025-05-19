//
// Aqui se encuentran las funciones usadas en mas de un programa y las librerias necesarias
//
#include <iostream>
using namespace std;


// -------------------------------------------------------
//Esta función obtiene un número y evita errores por ingresar caracteres no válidos
//
// Valor de retorno:
// - Regresa un número entero positivo
// - No regresa ningún valor hasta que se ingrese un número válido.
int obtenerNumero() {
    string entrada; // Variable para almacenar la entrada del usuario
    int num; // Variable donde se almacenará el número convertido

    while (true) { // Se repite hasta obtener un número válido
        cin >> entrada;

        // Verificar si la entrada es un número entero válido
        bool esEntero = true; // Bandera para validar la entrada
        for (size_t i = 0; i < entrada.length(); i++) { // Se recorre cada caracter de la entrada
            if (!isdigit(entrada[i])) {
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




// ------------------------------------------------------
//Esta función obtiene un número y evita errores por ingresar caracteres no válidos
//
// Valor de retorno:
// - Regresa un número entero positivo o negativo
// - No regresa ningún valor hasta que se ingrese un número válido.
int obtenerNumeroNeg() {
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


//------------------------------------------------------
//Esta funcion permite mostrar todos los menus de los programas
//
// Parametros:
// - opcion: Es el menu seleccionado segun el numero del programa
void mostrarMenus(int opcion) {
    switch (opcion)
    {
        //Menu Principal
        case 0:{
			cout << "+--------------------------------+" << endl;
            cout << "|         Menu principal         |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "| 1.  Presentacion               |" << endl;
            cout << "| 2.  Caracteres y cadenas       |" << endl;
            cout << "| 3.  Agregar valores            |" << endl;
            cout << "| 4.  Serie fibonacci            |" << endl;
            cout << "| 5.  Multiplos de 3 y 5         |" << endl;
            cout << "| 6.  Suma de cuadrados          |" << endl;
            cout << "| 7.  Numeros primos             |" << endl;
            cout << "| 8.  Suma de arreglo            |" << endl;
            cout << "| 9.  Calculadora de matrices    |" << endl;
            cout << "| 10. Operaciones de conjuntos   |" << endl;
            cout << "| 11. Teorema de Collatz         |" << endl;
            cout << "| 12. Palindromos                |" << endl;
            cout << "| 13. Ahorcado                   |" << endl;
            cout << "| 14. Torres de hanoi            |" << endl;
            cout << "| 15. Salir                      |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "Selecciona una opcion: ";
            break;
        }
        // Agregar valores
        case 3:{
            cout << "+---------------------------------+" << endl;
            cout << "|         Agregar Valores         |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "| 1. Ingresar Numero              |" << endl;
            cout << "| 2. Volver                       |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "Selecciona una opcion: ";
            break;
        }
        // Serie fibonacci
        case 4:{ //1:for   2:while   3:do-while
            cout << "+---------------------------------+" << endl;
            cout << "|         Serie fibonacci         |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "| 1. For                          |" << endl;
            cout << "| 2. While                        |" << endl;
            cout << "| 3. Do-While                     |" << endl;
            cout << "| 4. Volver                       |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "Selecciona una opcion: ";
            break;
        }
        // Multiplos de 3 y 5
        case 5:{
            cout << "+--------------------------------+" << endl;
            cout << "|       Multiplos de 3 y 5       |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "| 1. Ingresar Numero             |" << endl;
            cout << "| 2. Volver                      |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "Selecciona una opcion: ";
            break;
        }
        // Suma de cuadrados
        case 6:{
            cout << "+---------------------------------+" << endl;
            cout << "|        Suma de cuadrados        |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "| 1. Ingresar Numero              |" << endl;
            cout << "| 2. Volver                       |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "Selecciona una opcion: ";
            break;
        }
        // Numeros primos
        case 7:{
            cout << "+--------------------------------+" << endl;
            cout << "|         Numeros primos         |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "| 1. Ingresar Numero             |" << endl;
            cout << "| 2. Volver                      |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "Selecciona una opcion: ";
            break;
        }
        // Suma de un arreglo
        case 8:{
            cout << "+---------------------------------+" << endl;
            cout << "|         Suma de arreglo         |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "| 1. Agregar valor                |" << endl;
            cout << "| 2. Mostrar valores              |" << endl;
            cout << "| 3. Mostrar sumatoria            |" << endl;
            cout << "| 4. Cambiar valor                |" << endl;
            cout << "| 5. Borrar valor                 |" << endl;
            cout << "| 6. Vaciar arreglo               |" << endl;
            cout << "| 7. Volver                       |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "Selecciona una opcion: ";
            break;
        }
        // Operaciones de matrices
        case 9:{
            cout << "+---------------------------------+" << endl;
            cout << "|     Operaciones de matrices     |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "| 1.  Cambiar tamano de matriz    |" << endl;
            cout << "| 2.  Llenar matrices manualmente |" << endl;
            cout << "| 3.  Llenado aleatorio           |" << endl;
            cout << "| 4.  Mostrar matrices            |" << endl;
            cout << "| 5.  Sumar matrices              |" << endl;
            cout << "| 6.  Restar matrices             |" << endl;
            cout << "| 7.  Multiplicar matrices        |" << endl;
            cout << "| 8.  Editar valor                |" << endl;
            cout << "| 9.  Vaciar matrices             |" << endl;
            cout << "| 10. Volver                      |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "Selecciona una opcion: ";
            break;
        }
        // Operaciones de conjuntos
        case 10:{
            cout << "+--------------------------------+" << endl;
            cout << "|    Operaciones de conjuntos    |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "| 1.  Agregar elemento a A       |" << endl;
            cout << "| 2.  Agregar elemento a B       |" << endl;
            cout << "| 3.  Mostrar conjunto A         |" << endl;
            cout << "| 4.  Mostrar conjunto B         |" << endl;
            cout << "| 5.  Editar elemento de A       |" << endl;
            cout << "| 6.  Editar elemento de B       |" << endl;
            cout << "| 7.  Borrar elemento de A       |" << endl;
            cout << "| 8.  Borrar elemento de B       |" << endl;
            cout << "| 9.  Vaciar conjunto A          |" << endl;
            cout << "| 10. Vaciar conjunto B          |" << endl;
            cout << "| 11. Realizar Union             |" << endl;
            cout << "| 12. Realizar Interseccion      |" << endl;
            cout << "| 13. Realizar Diferencia        |" << endl;
            cout << "| 14. Realizar Complemento       |" << endl;
            cout << "| 15. Volver                     |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "Selecciona una opcion: ";
            break;
        }
        // Teorema de Collatz
        case 11:{
            cout << "+--------------------------------+" << endl;
            cout << "|       Teorema de Collatz       |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "| 1. Cambiar valor               |" << endl;
            cout << "| 2. Comparar secuencias         |" << endl;
            cout << "| 3. Volver                      |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "Selecciona una opcion: ";
            break;
        }
        //Palindromos
        case 12:{
            cout << "+--------------------------------+" << endl;
            cout << "|      Detectar palindromos      |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "| 1. Ingresar palabra            |" << endl;
            cout << "| 2. Volver                      |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "Selecciona una opcion: ";
            break;
        }
        // Ahorcado
        case 13:{
            cout << "+--------------------------------+" << endl;
            cout << "|            Ahorcado            |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "| 1. Jugador contra Jugador      |" << endl;
            cout << "| 2. Jugador contra Computadora  |" << endl;
            cout << "| 2. Volver                      |" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "Selecciona una opcion: ";
            break;
        }
        // Torres de hanoi
        case 14:{
            cout << "+---------------------------------+" << endl;
            cout << "|         Torres de hanoi         |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "| 1. Jugar                        |" << endl;
            cout << "| 2. Volver                       |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "Selecciona una opcion: ";
            break;
        }
        default:
        {
          cout << "Error interno: este menu no existe";
        }

    }
}

void saltoGrande()//Por que no me deja usar el cls
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}

void esperar()
{
    cin.ignore();
    cin.get();
    saltoGrande();
}


