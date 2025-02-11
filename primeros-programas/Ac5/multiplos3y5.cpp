//
// Created by Alonso on 10/02/2025.
//

#include<iostream>
using namespace std;
//declaracion de variables
int num, i, sumaMult3, contMult3, contMult5, sumaMult5;
bool esMultiplo;

int main() //inicio del main
{
    // El usuario ingresa su numero
    cout << "Ingresa un numero entero entre 0 y 1000:";
    cin >> num;

    // Comprobar que el valor es valido
    if (num < 0 || num > 1000)
    {
        cout << "El numero debe estar entre 0 y 1000";
        return 1; // Termina el codigo si el valor es invalido
    }
    sumaMult3 = sumaMult5 = contMult3 = contMult5 = 0; //asigno 0 a todos los contadores


    //Si el numero es valido, continua la ejecucon del codigo
    cout << "Multiplos de 3 y 5 hasta " << num << ":" << endl;
    cout << "3\t5" << endl; // Se agrega una tabulacion para simular una tabla

    for (i = 1; i <= num; i++) //inicia bucle for para buscar los multiplos de 3 y 5
    {
        esMultiplo = false; //se reinicia el valor para evitar falsos positivos

        //verificar los multipos de 3:
        if (i % 3 == 0)
        {
            cout << "\r" << i; //imprime el numero que se esta comprobando actualmente
            sumaMult3 += i; // agrega el valor actual a la suma total de los multiplos de 3
            contMult3++; // aumenta en uno el numero de multiplos de 3
            esMultiplo = true;
        }
        else
        {
            cout << "\r "; //para mantener la alineacion
        }

        cout << "\t"; //para separar columnas

        //verificar los multiplos de 5:
        if (i % 5 == 0)
        {
            cout << i;
            sumaMult5 += i;
            contMult5++;
            esMultiplo = true;
        }

        if (esMultiplo)
        {
            cout << endl; //nueva linea solo si la variable esMultiplo llego a ser verdadera
        }

    } // termina bucle for

    //mostrar resultados finales de la suma y el total de multiplos
    cout << "Total de multiplos de 3:" << contMult3 << endl;
    cout << "Suma de los multiplos de 3" << sumaMult3 << endl;

    cout << "Total de multiplos de 5:" << contMult5 << endl;
    cout << "Suma de los multiplos de 5" << sumaMult5 << endl;

    return 0;
}// final del main