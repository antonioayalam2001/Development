#include <stdio.h>
#include <windows.h>

#define TAM_MEM 600

// Aqui igual iniciamos las variables, no necesariamente se tienen que llamar igual pero en este caso lo hice asi
//para evitarme confusion

HANDLE hArchMapeoAB;
char *idMemCompartidaAB = "MATRIZAB"; //Lo importante es que esta madre tenga el mismo identificador
char *apDatosAB, *apTrabajoAB;		  //creo que appdatos si se tiene que llamar igual pero no estoy seguro

int matrizA[10][10]; //matriz donde vamos a guardar los datos

// VARIABLES VARIAS que usamos para for o cosas asi

int aux1 = 0, aux2 = 0, i, j, a;

int main(){

// aqui hacemos la conexion con la memoria compartida donde accedemos mediante la id de memoria y el segunfo
	//if lo que haces es igualar los datos en la variable datos del anterior archivo con la de este programa

	if((hArchMapeoAB=OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, idMemCompartidaAB)) == NULL){

		printf("No se hijo archivo de mapeo de la memoria compartida: (%i)\n", GetLastError());
		exit(-1);
	}

	if((apDatosAB=(char *)MapViewOfFile(hArchMapeoAB, FILE_MAP_ALL_ACCESS,0, 0, TAM_MEM)) == NULL){

		printf("No se accedio a la memoria compartida: (%i)\n", GetLastError());
		CloseHandle(hArchMapeoAB);
		exit(-1);
	}

// aqui guardamos la matris con un ciclo for, igualamos trabajo con datos es decir vamos a recorrer la 
//	variable hasta qye nos topemos con el fin de la variable que se denota con \0 

	for (apTrabajoAB = apDatosAB; *apTrabajoAB != '\0'; apTrabajoAB++){

		matrizA[aux1][aux2] = *apTrabajoAB;
		aux2++;

		if (aux2 == 10){
					
			aux2 = 0;
			aux1++;
		}
			
	}

	for (i = 0; i < 10; i++){

		for (j = 0; j < 10; j++){
			
			printf("%d, ", matrizA[i][j]);
		}
		printf("\n");
	}

// una vez que guardamos los datos cerramos el espacio de memoria con las siguientes lineas

	*apDatosAB = '*';
	UnmapViewOfFile(apDatosAB);
	CloseHandle(hArchMapeoAB);

}
