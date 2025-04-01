// funciones.cpp (versión corregida y mejorada)
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;

// ---------------------------------------------------------------------
// Muestra el menú principal del juego del ahorcado
//
// No recibe parámetros y no devuelve ningún valor.
void Menu() {
    cout << "\n===== Juego del Ahorcado =====" << endl;
    cout << "1. Jugador contra Jugador" << endl;
    cout << "2. Jugador contra Computadora" << endl;
    cout << "3. Salir" << endl;
    cout << "==============================" << endl;
    cout << "Selecciona una opcion: ";
}

// ---------------------------------------------------------------------
// Obtiene un número entero validado del usuario.
//
// Retorno:
// - Regresa un número entero ingresado por el usuario.
int obtenerNumero() {
    string entrada;
    int num;

    while (true) {
        cin >> entrada;
        bool esEntero = true;

        for (size_t i = 0; i < entrada.length(); i++) {
            if (!isdigit(entrada[i])){
                esEntero = false;
                break;
            }
        }

        if (esEntero) {
            try {
                num = stoi(entrada);
                break;
            } catch (...) {
                esEntero = false;
            }
        }

        cout << "ERROR: Debes ingresar un numero entero valido.\nIngresa otro numero: ";
    }

    return num;
}

// ---------------------------------------------------------------------
// Valida que una cadena contenga únicamente caracteres alfabéticos
//
// Parámetros:
// - palabra: Cadena a validar
//
// Retorno:
// - Verdadero si es válida, falso si contiene caracteres no alfabéticos
bool esPalabraValida(const string& palabra) {
    for (char c : palabra) {
        if (!isalpha(c)) {
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
string obtenerPalabra() {
    string palabra;
    while (true) {
        cin >> palabra;
        if (esPalabraValida(palabra)) {
            // Convertir a minúsculas
            for (char& c : palabra) {
                c = tolower(c);
            }
            return palabra;
        }
        cout << "ERROR: Solo se permiten letras. Ingresa otra palabra: ";
    }
}

// ---------------------------------------------------------------------
// Esta función obtiene una sola letra y evita ingresar valores ya usados.
//
// Parámetros:
// - letrasUsadas: Vector de caracteres que ya han sido usados en la ronda actual.
//
// Retorno:
// - Regresa una letra en minúscula, que no haya sido usada previamente.
char obtenerLetra(vector<char>& letrasUsadas) {
    string entrada;
    char letra;

    while (true) {
        cin >> entrada;
        if (entrada.length() != 1) {
            cout << "ERROR: Solo debes ingresar una letra. Intenta de nuevo: ";
            continue;
        }
        if (!isalpha(entrada[0])) {
            cout << "ERROR: Solo se deben ingresar letras. Intenta de nuevo: ";
            continue;
        }
        letra = tolower(entrada[0]);
        if (find(letrasUsadas.begin(), letrasUsadas.end(), letra) != letrasUsadas.end()) {
            cout << "ERROR: Ya has usado esa letra. Intenta con otra: ";
            continue;
        }
        break;
    }
    return letra;
}

// ---------------------------------------------------------------------
// Muestra gráficamente el estado del ahorcado según los intentos restantes
//
// Parámetros:
// - intentosRestantes: Número de oportunidades que quedan al jugador
//
// No devuelve ningún valor
void mostrarAhorcado(int intentosRestantes) {
    const int maxIntentos = 10;
    int errores = maxIntentos - intentosRestantes;

    // Cada caso representa la cantidad de errores cometidos
    switch (errores) {
        case 0:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 1:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 2:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << "  |   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 3:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 4:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 5:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " /    |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 6:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " / \\  |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 7:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " / \\  |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 8:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " / \\  |" << endl;
            cout << "D:    |" << endl;
            cout << "=========" << endl;
            break;
        default: // Para más de 7 errores
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  X   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " / \\  |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
    }
}

// ---------------------------------------------------------------------
// Retorna una cadena con la visualización de la palabra oculta,
// mostrando las letras adivinadas y '_' para las no descubiertas.
//
// Parámetros:
// - palabra: La palabra que se debe adivinar.
// - letrasUsadas: Vector de letras que ya han sido ingresadas.
//
// Retorno:
// - Una cadena con la visualización actual de la palabra.
string visualizacion(const string& palabra, const vector<char>& letrasUsadas) {
    string salida;
    for (char c : palabra) {
        if (find(letrasUsadas.begin(), letrasUsadas.end(), tolower(c)) != letrasUsadas.end()) {
            salida.push_back(toupper(c)); // Mostrar letras adivinadas en mayúscula
        } else {
            salida.push_back('_');
        }
        salida.push_back(' ');
    }
    return salida;
}

// ---------------------------------------------------------------------
// Gestiona el turno completo del jugador para adivinar la palabra
// incluyendo la visualización del ahorcado y penalizaciones
//
// Parámetros:
// - palabra: La palabra que debe ser adivinada
//
// Retorno:
// - Puntos obtenidos equivalent a los intentos restantes
int turnoJugador(const string& palabra) {
    const int maxIntentos = 10;
    int intentos = maxIntentos;
    vector<char> letrasUsadas;

    while (intentos > 0 && visualizacion(palabra, letrasUsadas).find('_') != string::npos) {
        mostrarAhorcado(intentos);
        cout << "\nPalabra: " << visualizacion(palabra, letrasUsadas) << endl;
        cout << "Intentos restantes: " << intentos << endl;
        cout << "Letras usadas: ";
        for (char c : letrasUsadas) cout << c << " ";
        cout << "\nIngresa una letra: ";
        
        char guess = obtenerLetra(letrasUsadas);
        letrasUsadas.push_back(guess);

        // Penalizar por vocal
        if (guess == 'a' || guess == 'e' || guess == 'i' || guess == 'o' || guess == 'u') {
            intentos--;
            cout << "Penalizacion por vocal (-1 intento)." << endl;
        }

        // Verificar si la letra está en la palabra
        bool acierto = false;
        for (char c : palabra) {
            if (tolower(c) == guess) {
                acierto = true;
                break;
            }
        }
        
        if (!acierto) {
            intentos--;
            cout << "Letra incorrecta (-1 intento)." << endl;
        }
    }

    if (visualizacion(palabra, letrasUsadas).find('_') == string::npos) {
        cout << "\n¡Palabra adivinada: " << palabra << "!" << endl;
        cout << "Puntaje (intentos restantes): " << intentos << endl;
        return intentos;
    } else {
        cout << "\nNo se adivinó la palabra: " << palabra << endl;
        return 0;
    }
}

// ---------------------------------------------------------------------
// Genera una letra para el turno de la computadora usando frecuencia de letras
// en español (Le da prioridad a letras frecuentes)
//
// Parámetros:
// - letrasUsadas: Vector con las letras ya intentadas
//
// Retorno:
// - Letra seleccionada para el siguiente intento
char obtenerLetraComputadora(const vector<char>& letrasUsadas) {
    // Frecuencia de letras en español (ordenadas de más a menos comunes)
    // Esto para que la IA no sea tan simple como solo letras al azar
    const string letrasFrecuentes = "eaosrnidlcumtpbgvyqhfjzñxkw";
    
    // Primero intenta con letras frecuentes que no ha usado
    for (char c : letrasFrecuentes) {
        if (find(letrasUsadas.begin(), letrasUsadas.end(), c) == letrasUsadas.end()) {
            return c;
        }
    }
    
    // Si ya usó todas las frecuentes, elige aleatoriamente
    char guess;
    do {
        guess = 'a' + rand() % 26;
    } while (find(letrasUsadas.begin(), letrasUsadas.end(), guess) != letrasUsadas.end());
    
    return guess;
}

// ---------------------------------------------------------------------
// Gestiona el turno de la computadora para adivinar la palabra
// usando estrategia de letras frecuentes y mostrando progreso gráfico
//
// Parámetros:
// - palabra: La palabra que debe ser adivinada
//
// Retorno:
// - Puntos obtenidos equivalent a los intentos restantes
int turnoComputadora(const string& palabra) {
    const int maxIntentos = 10;
    int intentos = maxIntentos;
    vector<char> letrasUsadas;

    while (intentos > 0 && visualizacion(palabra, letrasUsadas).find('_') != string::npos) {
        mostrarAhorcado(intentos);
        cout << "\nPalabra: " << visualizacion(palabra, letrasUsadas) << endl;
        cout << "Intentos restantes de la computadora: " << intentos << endl;
        
        char guess = obtenerLetraComputadora(letrasUsadas);
        cout << "La computadora adivina: " << guess << endl;
        letrasUsadas.push_back(guess);

        // Penalizar por vocal
        if (guess == 'a' || guess == 'e' || guess == 'i' || guess == 'o' || guess == 'u') {
            intentos--;
            cout << "Penalizacion por vocal (-1 intento)." << endl;
        }

        // Verificar si la letra está en la palabra
        bool acierto = false;
        for (char c : palabra) {
            if (tolower(c) == guess) {
                acierto = true;
                break;
            }
        }
        
        if (!acierto) {
            intentos--;
            cout << "Letra incorrecta (-1 intento)." << endl;
        }
    }

    if (visualizacion(palabra, letrasUsadas).find('_') == string::npos) {
        cout << "\nLa computadora adivinó la palabra: " << palabra << endl;
        cout << "Puntaje de la computadora (intentos restantes): " << intentos << endl;
        return intentos;
    } else {
        cout << "\nLa computadora no adivinó la palabra: " << palabra << endl;
        return 0;
    }
}

// ---------------------------------------------------------------------
// Modo Jugador contra Jugador
void jugarPvP() {
    int puntosJugador1 = 0, puntosJugador2 = 0;
    char opcionRonda;
    string palabra;

    do {
        // Ronda 1: Jugador 1 elige, Jugador 2 adivina
        cout << "\nJugador 1, ingresa una palabra (solo letras): ";
        palabra = obtenerPalabra();
        system("cls"); // Limpiar pantalla para ocultar la palabra
        
        cout << "Turno de Jugador 2 para adivinar." << endl;
        int puntos = turnoJugador(palabra);
        puntosJugador2 += puntos;
        cout << "Jugador 2 obtiene " << puntos << " puntos." << endl;

        // Ronda 2: Jugador 2 elige, Jugador 1 adivina
        cout << "\nJugador 2, ingresa una palabra (solo letras): ";
        palabra = obtenerPalabra();
        system("cls"); // Limpiar pantalla para ocultar la palabra
        
        cout << "Turno de Jugador 1 para adivinar." << endl;
        puntos = turnoJugador(palabra);
        puntosJugador1 += puntos;
        cout << "Jugador 1 obtiene " << puntos << " puntos." << endl;

        // Mostrar puntaje acumulado
        cout << "\nPuntaje acumulado:" << endl;
        cout << "Jugador 1: " << puntosJugador1 << endl;
        cout << "Jugador 2: " << puntosJugador2 << endl;

        cout << "\n¿Desean jugar otra ronda? (s/n): ";
        cin >> opcionRonda;
    } while (opcionRonda == 's' || opcionRonda == 'S');

    // Resultado final
    cout << "\nPuntaje final:" << endl;
    cout << "Jugador 1: " << puntosJugador1 << endl;
    cout << "Jugador 2: " << puntosJugador2 << endl;
    
    if (puntosJugador1 > puntosJugador2) {
        cout << "¡Jugador 1 es el ganador!" << endl;
    } else if (puntosJugador2 > puntosJugador1) {
        cout << "¡Jugador 2 es el ganador!" << endl;
    } else {
        cout << "¡Empate!" << endl;
    }
}

// ---------------------------------------------------------------------
// Modo Jugador contra Computadora
void jugarPvC() {
    vector<string> banco = {
        "programacion", "computadora", "ahorcado", "juego", "codigo",
        "universidad", "desafio", "aprendizaje", "palabra", "puntaje",
        "victoria", "derrota", "aleatorio", "logica", "algoritmo",
        "variable", "funcion", "compilador", "depuracion", "sistema"
    };

    int puntosJugador = 0, puntosComputadora = 0;
    char opcionRonda;
    string palabra;

    do {
        // Turno 1: Computadora elige, jugador adivina
        palabra = banco[rand() % banco.size()];
        cout << "\nLa computadora ha elegido una palabra." << endl;
        
        int puntos = turnoJugador(palabra);
        puntosJugador += puntos;
        cout << "Obtuviste " << puntos << " puntos." << endl;

        // Turno 2: Jugador elige, computadora adivina
        cout << "\nIngresa una palabra para que la computadora la adivine (solo letras): ";
        palabra = obtenerPalabra();
        system("cls"); // Limpiar pantalla para ocultar la palabra
        
        puntos = turnoComputadora(palabra);
        puntosComputadora += puntos;
        cout << "La computadora obtuvo " << puntos << " puntos." << endl;

        // Mostrar puntaje acumulado
        cout << "\nPuntaje acumulado:" << endl;
        cout << "Jugador: " << puntosJugador << endl;
        cout << "Computadora: " << puntosComputadora << endl;

        cout << "\n¿Deseas jugar otra ronda? (s/n): ";
        cin >> opcionRonda;
    } while (opcionRonda == 's' || opcionRonda == 'S');

    // Resultado final
    cout << "\nPuntaje final:" << endl;
    cout << "Jugador: " << puntosJugador << endl;
    cout << "Computadora: " << puntosComputadora << endl;
    
    if (puntosJugador > puntosComputadora) {
        cout << "¡Ganaste!" << endl;
    } else if (puntosComputadora > puntosJugador) {
        cout << "La computadora gana." << endl;
    } else {
        cout << "¡Empate!" << endl;
    }
}