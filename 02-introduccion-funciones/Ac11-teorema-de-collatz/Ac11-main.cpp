/*
Nombre:     Christian Alonso Arevalos Gonzalez
Edad:       19
Recidencia: Tepatitlan
Fecha:      15/03/2025
Carrera:    Ingenieria en Computacion
Semestre:   Segundo
Código:     Teorema de Collatz
*/

#include <iostream>
using namespace std;
#include "Ac11-funciones.cpp"

//Declaracion de variables
int opcion, cont1=1, cont2=1, valor1=1, valor2=1;
bool ejecucion = true;

int main() { //Inicio del main

  cout << "Bienvenido\nEste programa compara dos sucesiones que siguen el teorema de Collatz\n" << endl;

  do { //Inicio del while
    mostrarMenu();
    opcion = obtenerNumero();

    switch (opcion) {
      case 1:{
        while (ejecucion){
          cout << "Que valor quieres modificar?" << endl;
          cout << "1. Valor 1: " << valor1 << endl;
          cout << "2. Valor 2: " << valor2 << endl;
          cout << "3. Salir" << endl;
          cout << "Seleccione una opcion: " << endl;
          opcion = obtenerNumero();
          switch (opcion) {
            case 1:{
              cout << "Ingrese un valor:";
              valor1 = obtenerNumero();
              break;
            }
            case 2:{
              cout << "Ingrese un valor:";
              valor2 = obtenerNumero();
              break;
            }
            case 3:{
              cout << "Volviendo al menu principal..." << endl;
              ejecucion = false;
            }
            default:{
              cout << "Opcion invalida\n";
            }
          }
        }// fin del while
        ejecucion = true;
        break;
      }

      case 2:{
        cout << "Sucesion del primer valor (" << valor1 << "):" << endl;
        cont1 = secuencia(valor1);
        cout << cont1 << endl << endl;
        cout << "Sucesion del segundo valor (" << valor2 << "):" << endl;
        cont2 = secuencia(valor2);
        cout << cont2 << endl << endl;
        break;
      }

      case 3:{
        ejecucion = false;
        break;
      }

      default:{
        cout << "Opcion invalida" << endl;
        break;
      }

    }
  } while (ejecucion); // Fin del while

  cout << "Gracias por usar el prgrama" << endl;
  return 0;
} //Fin del main
