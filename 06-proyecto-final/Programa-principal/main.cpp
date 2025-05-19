/*
Nombre:     Christian Alonso Arevalos Gonzalez
Edad:       20
Recidencia: Tepatitlan
Fecha:      1/05/2025
Carrera:    Ingenieria en Computacion
Semestre:   Segundo
Codigo:     Proyecto final
*/

#include "librerias.h"
using namespace std;


//Declaracion de variables
int opcion;
bool ejecucion=true;

int main()
{
    while(ejecucion)
    {
        mostrarMenus(0);
        opcion = obtenerNumero();
        saltoGrande();
        switch(opcion)
        {
        case 1:
            presentacion();
            break;
        case 2:
            charEscYCadenas();
            break;
        case 3:
            agregarValor();
            break;
        case 4:
            serieFibonacci();
            break;
        case 5:
            multiplos3y5();
            break;
        case 6:
            sumaCuadrados();
            break;
        case 7:
            numerosPrimos();
            break;
        case 8:
            sumaDeArreglo();
            break;
        case 9:
            operacionesMatrices();
            break;
        case 10:
            operacionesConjuntos();
            break;
        case 11:
            teoremaDeCollatz();
            break;
        case 12:
            Palindromos();
            break;
        case 13:
            Ahorcado();
            break;
        case 14:
            torresDeHanoi();
            break;
        case 15:
            ejecucion=false;
            cout << "Saliendo del programa" << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    }//fin del while
}//fin del main

