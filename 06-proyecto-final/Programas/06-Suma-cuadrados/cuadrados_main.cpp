


//Inicio del main
void sumaCuadrados()
{
     unsigned long int suma;
     int num, i, opcion; //El numero no se coloca como long por que sera limitado en el codigo
     bool ejecucion = true;

     while(ejecucion) //Inicio del bucle principal, el usuario decide si se vuelve a ejecutar
     {
          mostrarMenus(6);
          opcion = obtenerNumero();
          switch (opcion)
          {
          case 1:
               {
                    cout << "Ingrese un numero menor o igual a 4008:"; // valor maximo funcional: 4008
                    num = obtenerNumero();
                    if (num > 4008)
                    {
                         cout << "ERROR: El numero ingresado es mayor a 4008" << endl;
                         break;
                    }
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
                              cout << i*i << " = " << endl << suma << endl;
                         }
                         else
                         {
                              cout << i*i << " + ";
                         }
                    } // fin del for
                    cout << "Presiona enter para continuar" << endl;
                    esperar();
                    break;
               }
          case 2:
               {
                    ejecucion = false;
                    break;
               }
          default:
               {
                    cout << "Opcion invalida" << endl;
               }

          }
     } // fin del while

}// fin del main




