#include <stdio.h>
#include <string.h>


int get_numero(char*);


int main(){

	char *linea;
	int resultado;
	char *ptr;
	int contador;

	do{

		resultado = 0;
		contador = 1;
		fgets(linea, 1024, stdin);
		
	
		while (contador){
			contador = get_numero(linea);

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

int get_numero(char *linea){
	char numbers[] = "0123456789-";
	int resultado = 0;
	int negativo = 0;

	if (*linea == 10 || *linea == 13 || *linea == 32 || *linea == '\0'){
		return 0;
	}

	while (*linea != 10 && *linea != 32 && *linea != 13 && *linea != '\0'){
		int i;
		for(i = 0; numbers[i] != *linea; i++);
		
		if (i == 10){
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
	//if (negativo) return -resultado;
	//return resultado;
}


