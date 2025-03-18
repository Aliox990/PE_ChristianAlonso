/*
Nombre:     Christian Alonso Arevalos Gonzalez
Edad:       19
Recidencia: Tepatitlan
Fecha:      13/03/2025
Carrera:    Ingenieria en Computacion
Semestre:   Segundo
Código:     Puntero
*/

#include "iostream"
using namespace std;
int arreglo[10];

int main() {

  int* puntero = arreglo;

  for (int i = 0; i < 10; i++) {
    cout << "Numeros " << i+1 << ": " << endl;
    cin >> *(puntero+i);
  }

  cout << "Numeros ingresados:" << endl;
  for (int i = 0; i < 10; i++) {
    cout << *(puntero+i) << " en " << puntero+i << endl;
  }

  cout << "Lista de numeros inversa" << endl;
  for (int i = 9; i >= 0; i--) {
    cout << *(puntero+i) << " en " << puntero+i << endl;
  }
  return 0;
}


