//
// Created by Alonso on 08/02/2025.
//

#include <iostream>
using namespace std;
int numero, i, contador=0;
char continuar;

int main() //main
{
     do {
          cout << "Ingrese un numero: ";
          cin >> numero;

          if (numero>0 && numero<=500) // primera opcion
          {
               for (i = 0; i<100; ++i) // Ciclo para realizar 100 veces la suma de 5
               {
                    numero += 5;
                    cout << numero << endl; //muestra el valor actual del numero
                    contador++;
               } // fin del ciclo
          } // fin de la primera opcion
          else if (numero>500 && numero<=1000) //Segunda opcion
          {
               for (i = 0; i<50; ++i) // Ciclo para realizar 50 veces la suma de 10
               {
                    numero += 10;
                    cout << numero << endl; //muestra el valor actual del numero
                    contador++;
               } // fin del ciclo
          } // fin de la segunda opcion
          else // Si las opciones anteriores no aplican
          {
               cout << "No se puede calcular el valor." << endl;
          }

          cout << "Quiere continuar el programa? (s/n)";
          cin >> continuar; //si el usuario escribe s, el programa continua ejecutandose

     } while(continuar == 's' || continuar == 'S');//fin del do-while
     cout << "Se realizaron: " << contador << " operaciones" << endl;

     return 0;
}
// fin del main

