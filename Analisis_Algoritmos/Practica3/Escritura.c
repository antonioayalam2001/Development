#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PESOBIT(bpos) 1<<bpos
#define CONSULTARBIT(var,bpos) (*(unsigned*)&var & PESOBIT(bpos))?1:0
#define PONE_1(var,bpos) *(unsigned*)&var |= PESOBIT(bpos)
#define PONE_0(var,bpos) *(unsigned*)&var &= ~(PESOBIT(bpos))
#define CAMBIA(var,bpos) *(unsigned*)&var ^= PESOBIT(bpos)
int main(int argc, char const *argv[]){

	unsigned char cadena[] = {'h','a','l','a',' ','m','a','n','d','a'};

	int n_bits = 8;

	FILE *salida = NULL;

	salida = fopen("salidaOriginal.dat", "wb");
    
	//Comprobamos si el archivo fue abierto correctamente
	if (salida == NULL){

		printf("Error\n"); 
		return -1;
	}

	fwrite(cadena, sizeof(unsigned char), 10, salida);

	fclose(salida);

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 8; j++){

			PONE_0(cadena[i],j);
		}
	}

	//Para la h
	PONE_1(cadena[0],0);
	PONE_1(cadena[0],3);	
	PONE_1(cadena[0],4);
	//Para la 0
	PONE_1(cadena[1],0);
	PONE_1(cadena[1],1);
	PONE_1(cadena[1],4);
	PONE_1(cadena[1],6);
	PONE_1(cadena[1],7);
	//Para la l
	PONE_1(cadena[2],0);
	PONE_1(cadena[2],2);
	PONE_1(cadena[2],5);
	PONE_1(cadena[2],6);
	PONE_1(cadena[2],7);
	//Para la a
	PONE_1(cadena[3],6);
	PONE_1(cadena[3],7);

	salida = fopen("salida.dat", "wb");
    
	//Comprobamos si el archivo fue abierto correctamente
	if (salida == NULL){

		printf("Error\n"); 
		return -1;
	}

	fwrite(cadena, sizeof(unsigned char), 4, salida);

	fclose(salida);


	return 0;
}