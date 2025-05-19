
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