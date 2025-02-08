Proceso IncrementarNumeros
    Definir numero, i, contador, opcion Como Entero
    contador <- 0  // Contador de operaciones realizadas
	
    Repetir
        Escribir "Ingrese un número:"
        Leer numero
		
        // Verifica el rango del número ingresado
        Si (numero > 0) Y (numero < 500) Entonces
            Escribir "Incrementando de 5 en 5, 100 veces:"
            Para i <- 1 Hasta 100 Con Paso 1 Hacer
                numero <- numero + 5
                Escribir "Valor ", i, ": ", numero
            FinPara
            contador <- contador + 1  // Contar la operación realizada
			
        Sino
            Si (numero >= 500) Y (numero <= 1000) Entonces
                Escribir "Incrementando de 10 en 10, 50 veces:"
                Para i <- 1 Hasta 50 Con Paso 1 Hacer
                    numero <- numero + 10
                    Escribir "Valor ", i, ": ", numero
                FinPara
                contador <- contador + 1  // Contar la operación realizada
				
            Sino
                Si numero > 1000 Entonces
                    Escribir "No se puede calcular el valor."
                Sino
                    Escribir "Número inválido. Debe ser mayor que 0."
                FinSi
            FinSi
        FinSi
		
        // Preguntar si desea terminar el programa, si es 1 el programa deja de ejecutarse
        Escribir "¿Desea terminar el programa? (1 = Sí, 0 = No)"
        Leer opcion
		
    Hasta Que opcion = 1
	
    // Mostrar el total de operaciones realizadas
    Escribir "Total de operaciones realizadas: ", contador
FinProceso
