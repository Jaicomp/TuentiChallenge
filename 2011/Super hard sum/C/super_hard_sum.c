#include <stdio.h>
#include <string.h>


int get_num(char*);


int main(){

	char *linea;
	int resultado;
	char *ptr;
	int contador;

	do{

		resultado = 0;
		contador = 1;
		fgets(linea, 1024, stdin);
		
	
		while (contador = get_num(linea)){

			while(*linea != 32 && *linea != '\0' && *linea != 10){
				linea++;
			}
			while ((*linea == 32 || *linea == '\0' || *linea == 10) && *linea != '\000'){
				linea++;
			}


			resultado += contador;
		}
		printf("%d\n", resultado);

	}while(1);
	return 0;
}

int get_num(char *linea){
	const char posibles_entradas[] = "0123456789-";
	int resultado = 0;
	int negativo = 0;
	int i;

	if (*linea == 10 || *linea == 13 || *linea == 32 || *linea == '\0'){
		return 0;
	}

	while (*linea != 10 && *linea != 32 && *linea != 13 && *linea != '\0'){
		for(i = 0; posibles_entradas[i] != *linea; i++);
		
		if (posibles_entradas[i] == '-'){
			negativo = 1;
		}else{
			
			resultado += i;
			resultado *= 10;
		}
		linea++;
	}
	//Último elemento 
	resultado /= 10;
	

	return negativo ? -resultado : resultado;
}


