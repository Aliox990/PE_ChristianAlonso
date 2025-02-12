/*
Nombre:     Christian Alonso Arevalos Gonzalez
Edad:       19
Recidencia: Tepatitlan
Fecha:      11/02/2025
Carrera:    INgenieria en Computacion
Semestre:   Segundo
Codigo:     Secuencia de numeros
*/

#include<iostream>
#include<limits>
using namespace std;

//declaracion de variables
unsigned long int suma;
int num, i; //El numero no se coloca como long por que sera limitado en el codigo
char ejecucion;


//Inicio del main
int main()
{
     cout << "Quieres ejecutar el codigo? (s/n):";
     cin >> ejecucion;

     while(ejecucion == 's' || ejecucion == 'S') //Inicio del bucle principal, el usuario decide si se vuelve a ejecutar
     {
          cout << "Ingrese un numero:"; // valor maximo funcional: 4008
          if (!(cin >> num))
          {
               cin.clear(); // Limpia el error de cin
               cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignora el resto de la línea
               cout << "ERROR: El valor debe ser numerico" << endl;
          }
          else if ( num <= 0 || num > 4009 )
          {
               cout << "ERROR: Valor invalido, el numero debe ser mayor que 0 y menor que 4009" << endl;
          }
          else
          {
               suma = 0; //se reinicia el valor de la suma por si se ejecuta el programa mas de una ves
               /*
                *En este bucle se imprime la sucesion de valores que se van a sumar
                *El limite es el numero dado por el usuario anteriormente
                *El if sirve para imprimir el ultimo valor de la sucecion elevado al cuadrado y el resultado
               */
               for(i = 1; i <= num; i++)
               {
                    suma += (i * i);

                    //Aqui se muestran todos los valores que se van a sumar
                    if(i == num)
                    {
                         cout << i*i << " = " << suma << endl;
                    }
                    else
                    {
                         cout << i*i << " + ";
                    }
               } // fin del for

          }
          cout << "Quieres probar con otro valor? (s/n):";
          cin >> ejecucion;

     } // fin del bucle principal
     return 0;
}// fin del main



