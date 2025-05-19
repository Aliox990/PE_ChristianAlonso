

// ---------------------------------------------------------------------
// Valida que una cadena contenga únicamente caracteres alfabéticos
//
// Parámetros:
// - palabra: Cadena a validar
//
// Retorno:
// - Verdadero si es válida, falso si contiene caracteres no alfabéticos
bool esFraseValida(const string& palabra) {
    for (char c : palabra) {
        if (!isalpha(c) && !isspace(c)) {
            return false;
        }
    }
    return !palabra.empty();
}

// ---------------------------------------------------------------------
// Solicita y valida una palabra alfabética al usuario
// convirtiéndola automáticamente a minúsculas
//
// No recibe parámetros
//
// Retorno:
// - Cadena válida en minúsculas
string obtenerFrase() {
    string palabra;
    cin.ignore(); // Limpiar el buffer antes de getline
    while (true) {
        getline(cin, palabra);
        if (esFraseValida(palabra)) {
            // Convertir a mayúsculas
            for (char& c : palabra) {
                c = toupper(c);
            }
            return palabra;
        }
        cout << "ERROR: Solo se permiten letras y espacios. Ingresa otra palabra: ";
    }
}

// -----------------------------------------------------
// Comprueba si una palabra es palíndromo e imprime el resultado.
//
// Parámetros:
// - palabra: la cadena a comprobar.
//
void esPalindromo(const string& palabraOriginal) {
    string palabra;
    for (char c : palabraOriginal) {
        if (!isspace(c)) {
            palabra += c;
        }
    }
    int n = palabra.size();// Para facilitar la lectura
    bool esPal = true;

    // Solo hace falta comprobar hasta la mitad
    for (int i = 0; i < n/2; ++i) {
        if (palabra[i] != palabra[n - 1 - i]) {
            esPal = false;
            break;  // Salir en cuanto no coincidan para ahorrar iteraciones inecesarias
        }
    }
    cout << "| Palabra:" << palabra << endl;
    cout << "+----------------+---------------+" << endl;
    if (esPal) {
        cout << "| Palindromo     |       Si      |" << endl;
    } else {
        cout << "| Palindromo     |       No      |" << endl;

    }
}


// -----------------------------------------------------
// Cuenta vocales, consonantes y caracteres de una palabra
//
// Parametros:
// - Palabra: la cadena a comprobar.
//
// La funcion no retorna ningun valor, pero si imprime los valores calculados
//
void contarCaracteres(const string& palabra)
{
    int vocales = 0 ,consonantes = 0, caracteres = 0;
    for (char c : palabra)
    {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            vocales++;
        }
        else
        {
            consonantes++;
        }
        caracteres++;

    }

    cout << "+----------------+---------------+" << endl;
    cout << "| Vocales        |       " << vocales << "\t |" << endl;
    cout << "+----------------+---------------+" << endl;
    cout << "| Consonantes    |       " << consonantes << "\t |" << endl;
    cout << "+----------------+---------------+" << endl;
    cout << "| Caracteres     |       " << caracteres << "\t |" << endl;
    cout << "+--------------------------------+" << endl;

    cout << endl << "Enter para continuar ";
    cin.ignore();
    cin.get();
    cout << endl << endl << endl << endl << endl << endl << endl << endl;//esto es por que no se borra la consola de Clion
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
}





