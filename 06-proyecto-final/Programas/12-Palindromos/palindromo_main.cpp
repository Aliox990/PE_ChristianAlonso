
#include "palindromo_funciones.cpp"

//Declaracion de variables


void Palindromos()
{
    bool ejecucion = true;
    int opcion;
    string palabra;

    while(ejecucion){
        mostrarMenus(12);
        opcion = obtenerNumero();
        switch (opcion)
        {
        case 1:
            {
                cout << "Ingresa una palabra:";
                palabra = obtenerFrase();
                esPalindromo(palabra);
                contarCaracteres(palabra);
                break;
            }
        case 2:
            {
                cout << "Saliendo del programa..." << endl;
                ejecucion = false;
                break;
            }
        default:
            {
                cout << "Opcion no valida." << endl;
                break;
            }
        }//Fin del switch

    }

} // fin del main