


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
            saltoGrande();
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
            matriz[i][j] = obtenerNumeroNeg();
        }
    }

    cout << "Matriz llenada correctamente." << endl;
    cout << endl << endl << "Presiona enter para continuar" << endl;
    esperar();
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
    cout << endl << endl << "Presiona enter para continuar" << endl;
    esperar();
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
    cout << endl << endl << "Presiona enter para continuar" << endl;
    esperar();
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

    cout << "Resultado de la resta: " << endl;
    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            cout << matriz1[i][j]-matriz2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl << endl << "Presiona enter para continuar" << endl;
    esperar();
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
    cout << endl << endl << "Presiona enter para continuar" << endl;
    esperar();
}


// Edita un valor de una matriz en una posición específica
//
// Parámetros:
// - matriz: matriz que se desea modificar
// - tamano: tamaño de la matriz
void editarValor(vector<vector<int>>& matriz, int tamano) {
    int fila, columna;

    cout << "Ingrese la fila (1-" << tamano << "): ";
    fila = obtenerNumero() - 1;
    cout << "Ingrese la columna (1-" << tamano << "): ";
    columna = obtenerNumero() - 1;

    if (fila >= 0 && fila < tamano && columna >= 0 && columna < tamano) {
        cout << "Valor actual: " << matriz[fila][columna] << endl;
        cout << "Ingrese el nuevo valor: ";
        matriz[fila][columna] = obtenerNumeroNeg();
        cout << "Valor actualizado correctamente.\n";
    } else {
        cout << "ERROR: Posición fuera de rango.\n";
        cout << endl << endl << "Presiona enter para continuar" << endl;
        esperar();
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
