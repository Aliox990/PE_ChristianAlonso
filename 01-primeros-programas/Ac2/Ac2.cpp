//
// Created by Alonso on 06/02/2025.
//

#include <iostream>
using namespace std;

int main()
{
    std::cout << "El \\\\ sirve para mostrar en consola el caracter \\" << std::endl;
    std::cout << "El \\n sirve para dar un salto de linea, algo asi: Hola,\ncomo\nestas" << std::endl;
    std::cout << "El \\a da una alarma cuando se ejecuta \a" << std::endl;
    std::cout << "El \\t da una tabulacion, algo \t asi" << std::endl;
    std::cout << "El \\\" sirve para imprimir \" en consola" << std::endl;
    std::cout << ",algo asi \r El \\r regresa al principio de la linea" << std::endl;

    printf ("Para imprimir enteros: %d\n", 3);
    printf ("Para imprimir un numero en octal: %o\n", 15);
    printf ("Para imprimir un numero en hexadecimal: %x\n", 15);
    printf ("Para imprimir un caracter: %c\n", 'a');
    printf ("Para imprimir una cadena: %s\n", "Cadena");
    printf ("Para imprimir un real con punto decimal con signo: %f", -123.456);

    return 0;
}


