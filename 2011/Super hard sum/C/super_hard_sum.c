#include <stdio.h>
#include <string.h>

//Función que consigue el primer número de un String, ej: String: 10 20 30
//Nos devuelve 10 de tipo integer
int get_first_num(char*);


int main(){

	char *linea;
	int resultado;
	char *ptr;
	int acumulador;

	//Bucle infinito
	do{

		resultado = 0; //Cada nueva linea, el resultado se 'vacia'
		//El acumulador tiene dos funciones:
		// - Guarda el valor numerico que nos devuelve la función "get_num" para
		//	 después añadirlo al resultado actual.
		// - Si el acumulador queda a 0, significa que no hay más numeros y por
		//	 lo tanto se ha acabado la operación.
		acumulador = 1; 
		//Conseguimos nuestra entrada por teclado
		fgets(linea, 1024, stdin);
		
		//Conseguimos el resultado y lo almacenamos en un acumulador, para
		//después introducirlo en el resultado final
		while (acumulador = get_first_num(linea)){

			//Chapuza, para avanzar al siguiente numero
			while(*linea != 32 && *linea != '\0' && *linea != 10){
				linea++;
			}
			while ((*linea == 32 || *linea == '\0' || *linea == 10) && *linea != '\000'){
				linea++;
			}

			
			resultado += acumulador;
		}

		//Una vez acabada la operación de la linea, imprimimos el resultado
		printf("%d\n", resultado);

	}while(1);
	return 0;
}


//Tra
int get_first_num(char *linea){
	const char posibles_entradas[] = "0123456789-";
	int resultado = 0;
	int negativo = 0;
	int i;

	
	if (*linea == 10 || *linea == 13 || *linea == 32 || *linea == '\0'){
		return 0;
	}

	//Transformar string a número
	while (*linea != 10 && *linea != 32 && *linea != 13 && *linea != '\0'){
		for(i = 0; posibles_entradas[i] != *linea; i++);
		
		linea++;

		//Posible valor negativo
		if (posibles_entradas[i] == '-'){
			negativo = 1;
		}else{
			
			resultado += i;
			//Si es el último elemento no será multiplicado por 10
			if (*linea != 10 && *linea != 32 && *linea != 13 && *linea != '\0'){
				resultado *= 10;
			}
		
		}
	}

	return negativo ? -resultado : resultado;
}


