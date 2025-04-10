#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// ---------------------------------------------------------------------
// Muestra la pantalla de inicio estilo videojuego
//
// No recibe parámetros y no devuelve valor.
void pantallaInicio() {
    cout << "================================================" << endl;
    cout << "    .---.  .----. .----. .----. .----. .----." << endl;
    cout << "   {_   _}/  {}  \\| {}  }| {}  }| {_  { {__  " << endl;
    cout << "     | |  \\      /| .-. \\| .-. \\| {__ .-._} }" << endl;
    cout << "     `-'   `----' `-' `-'`-' `-'`----'`----' " << endl;
    cout << "                  .----. .----.              " << endl;
    cout << "                  | {}  \\| {_                " << endl;
    cout << "                  |     /| {__               " << endl;
    cout << "                  `----' `----'              " << endl;
    cout << "        .-. .-.  .--.  .-. .-. .----. .-.   " << endl;
    cout << "        | {_} | / {} \\ |  `| |/  {}  \\| |   " << endl;
    cout << "        | { } |/  /\\  \\| |\\  |\\      /| |   " << endl;
    cout << "        "
            "`-' `-'`-'  `-'`-' `-' `----' `-'    " << endl;
    cout << "================================================" << endl;
    cout << "          Presiona Enter para continuar   " << endl;
    cin.get();
    cout << endl << endl << endl << endl << endl;

}

// ---------------------------------------------------------------------
// Muestra el menú principal del juego de Torres de Hanoi
void mostrarMenu() {
    cout << "+------------------------------+" << endl;
    cout << "|         TORRES DE HANOI      |" << endl;
    cout << "+------------------------------+" << endl;
    cout << "| 1. Jugar                     |" << endl;
    cout << "| 2. Salir                     |" << endl;
    cout << "+------------------------------+" << endl;
    cout << "Selecciona una opcion: ";
}

// ---------------------------------------------------------------------
// Obtiene un número entero validado del usuario.
int obtenerNumero() {
    string entrada;
    int num;
    while (true) {
        cin >> entrada;
        bool esEntero = true;
        for (char c : entrada) {
            if (!isdigit(c) && !(c=='-' && &c==&entrada[0])) { esEntero=false; break; }
        }
        if (esEntero) {
            try { num = stoi(entrada); break; }
            catch(...) {}
        }
        cout << "ERROR: Ingresa un numero entero valido: ";
    }
    return num;
}

// ---------------------------------------------------------------------
// Inicializa las tres torres para n discos.
// Torre 0 (origen) recibe discos de tamaño n..1, torres 1 y 2 quedan vacías.
void inicializarTorres(int n, vector<vector<int>>& torres) {
    torres.assign(3, vector<int>());
    for (int d = n; d >= 1; --d) torres[0].push_back(d);
}

// ---------------------------------------------------------------------
// Dibuja las tres torres horizontalmente en ASCII.
// Cada torre ocupa un ancho fijo de (2*n - 1) caracteres.
void mostrarTorres(const vector<vector<int>>& torres, int n) {
    int width = 2*n - 1;
    // Dibujar niveles de arriba hacia abajo
    for (int level = n - 1; level >= 0; --level) {
        for (int t = 0; t < 3; ++t) {
            if (level < (int)torres[t].size()) {
                int disc = torres[t][level];
                int discW = 2*disc - 1;
                int padL = (width - discW) / 2;
                int padR = width - discW - padL;
                cout << string(padL, ' ') << string(discW, '=') << string(padR, ' ');
            } else {
                int padL = (width - 1) / 2;
                int padR = width - 1 - padL;
                cout << string(padL, ' ') << '|' << string(padR, ' ');
            }
            cout << ' '; // separación entre torres
        }
        cout << '\n';
    }
    // Base de las torres
    for (int t = 0; t < 3; ++t) {
        cout << string(width, '-') << ' ';
    }
    cout << '\n';
}
// ---------------------------------------------------------------------
// Intenta mover un disco de torre 'origen' a 'destino'.
// Solo es legal si origen no está vacío y disco superior <= destino superior.
bool moverDisco(vector<vector<int>>& torres, int origen, int destino) {
    if (torres[origen].empty()) return false;
    int d = torres[origen].back();
    if (!torres[destino].empty() && torres[destino].back() < d) return false;
    torres[origen].pop_back();
    torres[destino].push_back(d);
    return true;
}


// ---------------------------------------------------------------------
// Calcula la puntuación en estrellas (1-5) según movimientos realizados.
// Parámetros:
// - movimientos: movimientos realizados por el usuario.
// - optimo: número mínimo de movimientos (2^n - 1).
// Retorno:
// - Estrellas entre 1 y 5.
int calcularEstrellas(int movimientos, int optimo) {
    double ratio = (double)optimo / movimientos;
    int estrellas = (int)round(ratio * 5.0);
    if (estrellas < 1) estrellas = 1;
    if (estrellas > 5) estrellas = 5;
    return estrellas;
}

// ---------------------------------------------------------------------
// Muestra gráficamente las estrellas en ASCII.
// Parámetros:
// - estrellas: número de estrellas llenas (1-5).
void mostrarEstrellas(int estrellas) {
    cout << "Puntuación: ";
    for (int i = 0; i < estrellas; ++i) cout << '*';
    for (int i = estrellas; i < 5; ++i) cout << ' ';
    cout << " (" << estrellas << "/5)\n";
}


// ---------------------------------------------------------------------
// Ejecuta la partida interactiva de Torres de Hanoi.
// Permite al usuario mover discos manualmente.
void jugarHanoi() {
    cout << "\nIngresa el numero de discos (1-10): ";
    int n;
    do {
        n = obtenerNumero();
        if (n < 1 || n > 10)
            cout << "Valor invalido. Ingresa entre 1 y 10: ";
    } while (n < 1 || n > 10);

    vector<vector<int>> torres;
    inicializarTorres(n, torres);

    int movimientos = 0;
    int optimo = (1 << n) - 1; // 2^n - 1

    // Mientras la torre destino (índice 2) no tenga todos los discos
    while (((int)torres[2].size() != n) && ((int)torres[1].size() != n)) {
        cout << "\nEstado actual:\n";
        mostrarTorres(torres, n);

        cout << "Movimiento #" << (movimientos+1) << "\n";
        cout << "Torre origen (1-3): ";
        int o = obtenerNumero();
        cout << "Torre destino (1-3): ";
        int d = obtenerNumero();

        if (o<1||o>3||d<1||d>3) {
            cout << "Torres invalidas. Usa numeros entre 1 y 3.\n";
            continue;
        }
        if (moverDisco(torres, o-1, d-1)) {
            movimientos++;
        } else {
            cout << "Movimiento ilegal. Intenta de nuevo.\n";
        }
    }

    // Juego completado
    cout << "\n¡Felicidades! Completaste las Torres de Hanoi.\n";
    mostrarTorres(torres, n);
    cout << "Movimientos realizados: " << movimientos << "\n";
    cout << "Movimientos minimos (optimos): " << optimo << "\n";
    if (movimientos == optimo)
        cout << "¡Lo lograste en el minimo de movimientos!\n";
    else
        cout << "Podrias resolverlo en menos movimientos.\n";

    int estrellas = calcularEstrellas(movimientos, optimo);
    mostrarEstrellas(estrellas);
}
