





void numerosPrimos() //inicia el main
{
    //declaración de variables
    int num, i, j, opcion;
    bool esprimo, valorValido, ejecucion = true;
    unsigned long sum;
    vector<int> primos; // vector para almacenar números primos

    while(ejecucion) {

        mostrarMenus(7);
        opcion = obtenerNumero();
        switch (opcion)
        {
            case 1:
                sum = 0;
                valorValido = true;
                primos.clear(); //reinicia los valores en el vector donde estan los primos
                cout << "Ingresa un numero entero menor a 358,000:";
                num = obtenerNumero();
                if (num > 358000)
                {
                    cout << "El numero debe ser menor a 358,000:";
                    valorValido = false;
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
                    cout << "Presiona enter para continuar" << endl;
                    esperar();
                }
                break;
            case 2:
                ejecucion = false;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    } //fin del while
}
