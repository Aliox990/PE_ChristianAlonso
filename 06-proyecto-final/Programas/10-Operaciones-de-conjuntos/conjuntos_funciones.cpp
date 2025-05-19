

// Función: actualizarUniverso
// ---------------------------
// Actualiza el conjunto universo asegurándose de que contenga todos los elementos
// presentes en los conjuntos A y B.
//
// Parámetros:
//   - universo: referencia al vector<string> que representa el conjunto universo.
//   - A: referencia constante al vector<string> del conjunto A.
//   - B: referencia constante al vector<string> del conjunto B.
//
// No retorna valores.
void actualizarUniverso(vector<string>& universo, const vector<string>& A, const vector<string>& B) {
    universo.clear();
    // Agregar elementos de A al universo
    for (const string& elem : A) {
        if (find(universo.begin(), universo.end(), elem) == universo.end()) {
            universo.push_back(elem);
        }
    }
    // Agregar elementos de B al universo
    for (const string& elem : B) {
        if (find(universo.begin(), universo.end(), elem) == universo.end()) {
            universo.push_back(elem);
        }
    }
}


// Función: mostrarConjunto
// ------------------------
// Muestra en pantalla los elementos de un conjunto dado.
//
// Parámetros:
//   - conjunto: referencia constante al vector<string> que representa el conjunto a mostrar.
//   - nombre: referencia constante al string con el nombre del conjunto.
//
// No retorna valores.
void mostrarConjunto(const vector<string>& conjunto, const string& nombre) {
    if (conjunto.empty()) {
        cout << "El conjunto " << nombre << " esta vacio." << endl;
        return;
    }
    cout << "Conjunto " << nombre << ": { ";
    for (const string& elem : conjunto) {
        cout << elem << " ";
    }
    cout << "}" << endl;
}


// Función: agregarElemento
// ------------------------
// Agrega un elemento al conjunto especificado, evitando duplicados y actualizando el universo.
//
// Parámetros:
// - conjunto: referencia al vector<string> del conjunto al que se agregará el elemento.
// - universo: referencia al vector<string> del conjunto universo.
// - otroConjunto: referencia constante al vector<string> del otro conjunto (A o B).
// - nombre: referencia constante al string con el nombre del conjunto (A o B).
//
// No retorna valores.
void agregarElemento(vector<string>& conjunto, vector<string>& universo, const vector<string>& otroConjunto, const string& nombre) {
    string val;
    cout << "Ingrese un elemento para " << nombre << ": ";
    cin.ignore();
    getline(cin, val);

    // Verificar si el elemento ya existe en el conjunto
    if (find(conjunto.begin(), conjunto.end(), val) != conjunto.end()) {
        cout << "El elemento '" << val << "' ya existe en el conjunto " << nombre << "." << endl;
        return;
    }

    conjunto.push_back(val);
    cout << "Elemento '" << val << "' agregado correctamente a " << nombre << "." << endl;

    // Actualizar el universo si el elemento no está presente
    if (find(universo.begin(), universo.end(), val) == universo.end()) {
        universo.push_back(val);
    }
}

//
// Función: editarElemento
// -----------------------
// Permite editar un elemento existente en el conjunto, actualizando el universo si es necesario.
//
// Parámetros:
// - conjunto: referencia al vector<string> del conjunto donde se editará el elemento.
// - universo: referencia al vector<string> del conjunto universo.
// - nombre: referencia constante al string con el nombre del conjunto (A o B).
//
// No retorna valores.
void editarElemento(vector<string>& conjunto, vector<string>& universo, const string& nombre) {
    if (conjunto.empty()) {
        cout << "El conjunto " << nombre << " esta vacio." << endl;
        return;
    }
    mostrarConjunto(conjunto, nombre);
    cout << "Ingrese el elemento a modificar: ";
    string viejo;
    cin.ignore();
    getline(cin, viejo);
    auto it = find(conjunto.begin(), conjunto.end(), viejo);
    if (it != conjunto.end()) {
        cout << "Ingrese el nuevo valor: ";
        string nuevo;
        getline(cin, nuevo);

        // Verificar si el nuevo elemento ya existe en el conjunto
        if (find(conjunto.begin(), conjunto.end(), nuevo) != conjunto.end()) {
            cout << "El elemento '" << nuevo << "' ya existe en el conjunto " << nombre << "." << endl;
            return;
        }

        // Actualizar el universo si el nuevo elemento no está presente
        if (find(universo.begin(), universo.end(), nuevo) == universo.end()) {
            universo.push_back(nuevo);
        }

        *it = nuevo;
        cout << "Elemento actualizado correctamente." << endl;
    } else {
        cout << "El elemento no se encuentra en el conjunto." << endl;
    }
}

//
// Función: borrarElemento
// -----------------------
// Elimina un elemento del conjunto especificado. El elemento permanecerá en el universo.
//
// Parámetros:
// - conjunto: referencia al vector<string> del conjunto del cual se borrará el elemento.
// - nombre: referencia constante al string con el nombre del conjunto (A o B).
//
// No retorna valores.
void borrarElemento(vector<string>& conjunto, const string& nombre) {
    if (conjunto.empty()) {
        cout << "El conjunto " << nombre << " esta vacio." << endl;
        return;
    }
    mostrarConjunto(conjunto, nombre);
    cout << "Ingrese el elemento a borrar: ";
    string valor;
    cin.ignore();
    getline(cin, valor);
    auto it = remove(conjunto.begin(), conjunto.end(), valor);
    if (it != conjunto.end()) {
        conjunto.erase(it, conjunto.end());
        cout << "Elemento eliminado correctamente de " << nombre << "." << endl;
    } else {
        cout << "El elemento no se encuentra en el conjunto." << endl;
    }
    // Nota: El elemento permanece en el universo
}

//
// Función: vaciarConjunto
// -----------------------
// Elimina todos los elementos del conjunto especificado. Los elementos permanecerán en el universo.
//
// Parámetros:
// - conjunto: referencia al vector<string> del conjunto que se vaciará.
// - nombre: referencia constante al string con el nombre del conjunto (A o B).
//
// No retorna valores.
void vaciarConjunto(vector<string>& conjunto, const string& nombre) {
    if (conjunto.empty()) {
        cout << "El conjunto " << nombre << " ya esta vacio." << endl;
        return;
    }
    conjunto.clear();
    cout << "El conjunto " << nombre << " ha sido vaciado." << endl;
    cout << endl << endl << "Presiona enter para continuar" << endl;
    esperar();
}

//
// Función: unionConjuntos
// -----------------------
// Realiza la unión de dos conjuntos y muestra el resultado.
//
// Parámetros:
// - A: referencia constante al vector<string> del conjunto A.
// - B: referencia constante al vector<string> del conjunto B.
//
// Retorna:
// - Un vector<string> que contiene la unión de A y B.
vector<string> unionConjuntos(const vector<string>& A, const vector<string>& B) {
    vector<string> resultado = A;
    for (const string& elem : B) {
        if (find(resultado.begin(), resultado.end(), elem) == resultado.end()) {
            resultado.push_back(elem);
        }
    }
    cout << "La union de los conjuntos es: ";
    mostrarConjunto(resultado, "A unida a B");
    cout << endl << endl << "Presiona enter para continuar" << endl;
    esperar();
    return resultado;
}


// Función: interseccionConjuntos
// ------------------------------
// Realiza la intersección de dos conjuntos y muestra el resultado.
//
// Parámetros:
// - A: referencia constante al vector<string> del conjunto A.
// - B: referencia constante al vector<string> del conjunto B.
//
// Retorna:
// - Un vector<string> que contiene la intersección de A y B.
vector<string> interseccionConjuntos(const vector<string>& A, const vector<string>& B) {
    vector<string> resultado;
    for (const string& elem : A) {
        if (find(B.begin(), B.end(), elem) != B.end()) {
            resultado.push_back(elem);
        }
    }
    cout << "La interseccion de los conjuntos es: ";
    mostrarConjunto(resultado, "interseccion de A con B");
    cout << endl << endl << "Presiona enter para continuar" << endl;
    esperar();
    return resultado;
}


// Función: diferenciaConjuntos
// ----------------------------
// Realiza la diferencia de dos conjuntos en el orden especificado por el usuario y muestra el resultado.
//
// Parámetros:
// - A: referencia constante al vector<string> del conjunto A.
// - B: referencia constante al vector<string> del conjunto B.
//
// Retorna:
// - Un vector<string> que contiene la diferencia según el orden elegido.
vector<string> diferenciaConjuntos(const vector<string>& A, const vector<string>& B) {
    cout << "Elige el orden de la diferencia:" << endl;
    cout << "1. A - B" << endl;
    cout << "2. B - A" << endl;
    cout << "Selecciona una opcion: ";
    int opcion = obtenerNumero();

    vector<string> resultado;
    if (opcion == 1) {
        for (const string& elem : A) {
            if (find(B.begin(), B.end(), elem) == B.end()) {
                resultado.push_back(elem);
            }
        }
        cout << "La diferencia A - B es: ";
        mostrarConjunto(resultado, "A - B");
    } else if (opcion == 2) {
        for (const string& elem : B) {
            if (find(A.begin(), A.end(), elem) == A.end()) {
                resultado.push_back(elem);
            }
        }
        cout << "La diferencia B - A es: ";
        mostrarConjunto(resultado, "B - A");
    } else {
        cout << "Opcion no valida." << endl;
    }
    cout << endl << endl << "Presiona enter para continuar" << endl;
    esperar();
    return resultado;
}


// Función: complementoConjunto
// ----------------------------
// Calcula el complemento de un conjunto respecto al universo y muestra el resultado.
//
// Parámetros:
// - conjunto: referencia constante al vector<string> del conjunto del cual se calculará el complemento.
// - universo: referencia constante al vector<string> del conjunto universo.
// - nombreConjunto: referencia constante al string con el nombre del conjunto (A o B).
//
// Retorna:
// - Un vector<string> que contiene el complemento del conjunto especificado.
vector<string> complementoConjunto(const vector<string>& conjunto, const vector<string>& universo, const string& nombreConjunto) {
    vector<string> resultado;
    for (const string& elem : universo) {
        if (find(conjunto.begin(), conjunto.end(), elem) == conjunto.end()) {
            resultado.push_back(elem);
        }
    }
    cout << "El complemento de " << nombreConjunto << " es: ";
    mostrarConjunto(resultado, "Complemento de " + nombreConjunto);
    cout << endl << endl << "Presiona enter para continuar" << endl;
    esperar();
    return resultado;
}
