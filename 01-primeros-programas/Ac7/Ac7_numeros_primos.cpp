/*
Nombre:     Christian Alonso Arevalos Gonzalez
Edad:       19
Recidencia: Tepatitlan
Fecha:      18/02/2025
Carrera:    Ingenieria en Computacion
Semestre:   Segundo
Codigo:     Numeros primos
*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

//declaración de variables
int num, i, j;
char ejecucion;
bool esprimo, valorValido;
unsigned long sum;
vector<int> primos; // vector para almacenar números primos

int main() //inicia el main
{
    cout << "Quieres ejecutar el programa? (s/n):";
    cin >> ejecucion;

    while(ejecucion =='s' || ejecucion =='S') {

        cout << "Ingresa un numero entero menor a 358,000:";
        sum = 0;
        primos.clear(); //reinicia los valores en el vector donde estan los primos

        if (!(cin >> num)) //comprobar que el valor es numerico
        {
            cin.clear(); // Limpia el error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignora el resto de la línea
            cout << "ERROR: El valor debe ser numerico" << endl;
            valorValido = false;
        }
        else if (num > 358000) // comprobar que el valor este dentro del rango
        {
            cout << "ERROR: Valor invalido, el numero debe ser mayor que 0 y menor que 358000" << endl;
            valorValido = false;
        }
        else
        {
            cout << "ERROR: Valor invalido, el numero debe ser mayor que 0 y menor que 4009" << endl;
            valorValido = true;
        }


        if (valorValido)
        {
            for (i = 2; i <= num; i++) //inicio del for para seleccionar numeros
            {
                esprimo = true;
                for (j = 2; j <= i; j++) //inicio del for para comprobar si un numero es primo
                {
                    if ((j != i) && (i % j == 0)) // if para comprobar si un numero es primo
                    {
                        esprimo = false;
                        break;
                    } //fin del if
                } //fin del for para comprobar si un numero es primo

                if (esprimo)
                {
                    primos.push_back(i); // agregar el número primo al vector
                }
            } // fin del for para seleccionar numeros

            // Calcular la suma de los números primos en el vector
            for (int primo : primos) {
                cout << primo << endl;
                sum += primo;
            }

            cout << "La suma de los numeros primos es: " << sum << endl;
        }

        cout << "Quieres volver a ejecutar el programa? (s/n):";
        cin >> ejecucion;

    } //fin del while

    return 0;
}// fin del main
