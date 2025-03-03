#include <iostream>
#include <vector>
#include <cstdlib> // Para rand()
#include <ctime>   // Para poder hacer semillas aleatorias co time()
using namespace std;



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


// Esta función muestra un menú con opciones para el usuario.
//
// No recibe parámetros y no devuelve ningún valor.
void mostrarMenu() {
    cout << "\nMenu de opciones:\n";
    cout << "1.  Cambiar tamano de matriz\n";
    cout << "2.  Llenar matrices manualmente\n";
    cout << "3.  Llenado aleatorio\n";
    cout << "4.  Mostrar matrices\n";
    cout << "5.  Sumar matrices\n";
    cout << "6.  Restar matrices\n";
    cout << "7.  Multiplicar matrices\n";
    cout << "8.  Editar valor\n";
    cout << "9.  Vaciar matrices\n";
    cout << "10. Salir\n";
    cout << "Seleccione una opcion: ";
}


//Obtiene el tamano de las matrices
//
//Valor de retorno:
//-Regresa un numero entero entre 2 y 10 dado por el usuario
int obtenerTamano() {
    int tamano;
    bool esEntero = false;
    while (!esEntero)
    {
        cout << "Ingrese el tamano para las matrices (2 a 10): ";
        tamano = obtenerNumero();
        if (tamano >= 2 && tamano <= 10)
        {
            esEntero = true;
            return tamano;
        }
        else
        {
            esEntero = false;
            cout << "Valor invalido.\n";
        }
    }
}


//Permite al usuario llenar las matrices
//
//Parametros:
//-matriz: matriz que se desea modificar
//-tamano: tamano de la matriz
void agregarValores(vector<vector<int>>& matriz, int tamano) {
    matriz.resize(tamano, vector<int>(tamano)); // Asegurarse de que la matriz tiene el tamaño correcto
    cout << "Por favor, ingresa los valores para la matriz: " << endl;

    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            cout << "Elemento [" << i+1 << "][" << j+1 << "]: ";
            matriz[i][j] = obtenerNumero();
        }
    }

    cout << "Matriz llenada correctamente." << endl;
}


//Permite al usuario llenar las matrices aleatoriamente
//
//Parametros:
//-matriz: matriz que se desea modificar
//-tamano: tamano de la matriz
void agregarAleatorio(vector<vector<int>>& matriz, int tamano) {
    srand(time(0)); // Inicializar la semilla de números aleatorios
    matriz.resize(tamano, vector<int>(tamano)); // Asegurarse de que la matriz tiene el tamaño correcto
    cout << endl;

    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            cout << "Elemento [" << i+1 << "][" << j+1 << "]: ";
            matriz[i][j] = rand() % 201-100;
            cout << matriz[i][j] << endl;
        }
    }

    cout << "Matriz llenada correctamente.\n";
}


//Permite al usuario ver las matrices
//
//Parametros:
//-matriz: matriz que se desea mostrar
//-tamano: tamano de la matriz
void mostrarMatriz(vector<vector<int>>& matriz, int tamano) {
    matriz.resize(tamano, vector<int>(tamano)); // Asegurarse de que la matriz tiene el tamaño correcto
    cout << "Estos son los valores de la matriz: " << endl;

    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}


//Suma las dos matrices y muestra el resultado
//
//parametros:
//- matriz1: primer matriz que se va a sumar
//- matriz2: segunda matriz que se va a sumar
//- tamano: tamano de las matrices
void sumarMatrices(vector<vector<int>>& matriz1, vector<vector<int>>& matriz2, int tamano) {
    matriz1.resize(tamano, vector<int>(tamano)); // Asegurarse de que la matriz tiene el tamaño correcto
    matriz2.resize(tamano, vector<int>(tamano));

    cout << "Matriz 1:" << endl;
    mostrarMatriz(matriz1, tamano);
    cout << "Matriz 2:" << endl;
    mostrarMatriz(matriz2, tamano);

    cout << "Resultado de la suma: " << endl;
    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            cout << matriz1[i][j]+matriz2[i][j] << "\t";
        }
        cout << endl;
    }
}


//resta las dos matrices y muestra el resultado
//A la primer matriz se le resta la segunda
//
//parametros:
//- matriz1: primera matriz
//- matriz2: segunda matriz
//- tamano: tamano de las matrices
void restarMatrices(vector<vector<int>>& matriz1, vector<vector<int>>& matriz2, int tamano) {
    matriz1.resize(tamano, vector<int>(tamano)); // Asegurarse de que la matriz tiene el tamaño correcto
    matriz2.resize(tamano, vector<int>(tamano));

    cout << "Resultado de la suma: " << endl;
    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            cout << matriz1[i][j]-matriz2[i][j] << "\t";
        }
        cout << endl;
    }
}


//Realiza la multiplicacion de la primer matriz por la segunda matriz
//
//parametros:
//- matriz1: primer matriz
//- matriz2: segunda matriz
//- tamano: tamano de las matrices
void multMatrices(vector<vector<int>>& matriz1, vector<vector<int>>& matriz2, int tamano) {
    vector<vector<int>> resultado;

    resultado.resize(tamano, vector<int>(tamano)); // Asegurarse de que la matriz tiene el tamaño correcto
    matriz1.resize(tamano, vector<int>(tamano));
    matriz2.resize(tamano, vector<int>(tamano));

    for (int i = 0; i < tamano; ++i) {//filas de primer matriz
        for (int j = 0; j < tamano; ++j) {//columnas de segunda matriz
            for (int k = 0; k < tamano; ++k)// Calcular el producto escalar de la fila de A por la columna de B
            {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }// fin de los ciclos for
    cout << "Resultado de la multiplicacion: " << endl;
    mostrarMatriz(resultado, tamano);
}


// Edita un valor de una matriz en una posición específica
//
// Parámetros:
// - matriz: matriz que se desea modificar
// - tamano: tamaño de la matriz
void editarValor(vector<vector<int>>& matriz, int tamano) {
    int fila, columna, nuevoValor;

    cout << "Ingrese la fila (1-" << tamano << "): ";
    fila = obtenerNumero() - 1;
    cout << "Ingrese la columna (1-" << tamano << "): ";
    columna = obtenerNumero() - 1;

    if (fila >= 0 && fila < tamano && columna >= 0 && columna < tamano) {
        cout << "Valor actual: " << matriz[fila][columna] << endl;
        cout << "Ingrese el nuevo valor: ";
        nuevoValor = obtenerNumero();
        matriz[fila][columna] = nuevoValor;
        cout << "Valor actualizado correctamente.\n";
    } else {
        cout << "ERROR: Posición fuera de rango.\n";
    }
}


// Vacía todas las matrices y las deja en ceros
//
// Parámetros:
// - matriz1: primera matriz a vaciar
// - matriz2: segunda matriz a vaciar
// - tamano: tamaño de las matrices
void vaciarMatrices(vector<vector<int>>& matriz1, vector<vector<int>>& matriz2, int tamano) {
    matriz1.assign(tamano, vector<int>(tamano, 0));
    matriz2.assign(tamano, vector<int>(tamano, 0));
    cout << "Las matrices han sido vaciadas correctamente.\n";
}
