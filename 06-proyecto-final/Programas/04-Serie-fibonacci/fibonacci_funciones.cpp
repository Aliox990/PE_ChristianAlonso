//------------------------------------------------------
// Función para comprobar si el número del usuario es igual o cercano al número de Fibonacci
//
// Parametros:
// - num:
// - fibonacci:
// - antFibonacci:
int comparar(int num, int fibonacci, int antFibonacci) {
    if (num == fibonacci || num < fibonacci + antFibonacci || num == antFibonacci)
        return 1;
    else
        return 0;
}


