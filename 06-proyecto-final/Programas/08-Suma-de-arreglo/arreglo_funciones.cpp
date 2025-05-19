
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
        cout << "Posicion " << i+1 << ":\t" << arreglo[i] << endl;
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
    cout << endl << "El resultado es: " << suma << endl;
    cout << "Presiona enter para continuar" << endl;
    esperar();
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
    cout << "Ingresa la posicion a cambiar (1 a " << arreglo.size() << "): ";
    posicion = obtenerNumero();
    posicion--;

    if (posicion >= 0 && posicion < arreglo.size())
    {
        arreglo[posicion] = obtenerNumero();
        cout << "Cambio realizado exitosamente" << endl;
    }
    else
    {
        cout << "Posicion invalida" << endl;
    }
    cout << endl << "Presiona enter para continuar" << endl;
    esperar();
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
    cout << "Ingresa la posicion a borrar (1 a " << arreglo.size()  << "): ";
    posicion = obtenerNumero();
    posicion--;

    if (posicion >= 0 && posicion < arreglo.size())
    {
        arreglo.erase(arreglo.begin() + posicion);
        cout << "Valor eliminado." << endl;
    }
    else
    {
        cout << "Posicion invalida." << endl;
    }
    cout << endl << "Presiona enter para continuar" << endl;
    esperar();
}

// Vacía completamente el vector
//
// Parametro:
// - vector: el vector que se quiere vaciar
void vaciarArreglo(vector<int>& arreglo)
{
    arreglo.clear();
    cout << "El arreglo ha sido vaciado." << endl;

    cout << endl << "Presiona enter para continuar" << endl;
    esperar();
}

