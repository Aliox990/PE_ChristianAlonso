void agregarValor()
{
    int numero, opcion, i, contador = 0;
    bool ejecucion = true;
    do {
        mostrarMenus(3);
        opcion = obtenerNumero();

        switch (opcion)
        {
        case 1:
        {
            cout << "Ingresa un numero menor a 1000:" << endl;
            numero = obtenerNumero();
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
            esperar();
            break;
        }
        case 2:
            {
                cout << "Se realizaron: " << contador << " operaciones" << endl;
                ejecucion = false;
                cout << "Saliendo del programa..." << endl;
            }
        default:
            {
                cout << "Opcion invalida" << endl;
            }
        }



    } while(ejecucion);//fin del do-while

    saltoGrande();
}
