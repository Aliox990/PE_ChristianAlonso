/*
Nombre:     Christian Alonso Arevalos Gonzalez
Edad:       19
Recidencia: Tepatitlan
Fecha:      13/03/2025
Carrera:    Ingenieria en Computacion
Semestre:   Segundo
Código:     Puntero
*/

#include <iostream>
using namespace std;

int main(){
  int numero = 5;
  int* puntero = &numero;

  cout << "direccion de memoria de numero: " << &numero << endl;
  cout << "Direccion almacenada en puntero: " << puntero << endl;
  cout << "valor de numero a traves del puntero: " << *puntero << endl;

  *puntero = 10;
  cout << "nuevo valor de numero a traves del puntero: " << numero << endl;
  cout << "Direccion almacenada en puntero: " << puntero << endl;

  return 0;
}


