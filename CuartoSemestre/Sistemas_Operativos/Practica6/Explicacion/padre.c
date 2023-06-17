// Codigo pal Tunas pa que vea como esta el pedo.c

#include <stdio.h>
#include <string.h>
#include <windows.h>

#define TAM_MEM 600

//Aqui estan las variables que usamos para crear la memoria y todo pedo

HANDLE hArchMapeoAB;
char *idMemCompartidaAB = "MATRIZAB";	//notese que este apuntador tiene un identificador que es MATRIZAB
char *apDatosAB, *apTrabajoAB;			//con ese identificador podemos crear y acceder a la memoria

int matrizA[10][10] = {					//Matriz bien vergas

	{1, 3, 5, 2, 4, 1, 2, 4, 5, 3},
	{1, 3, 2, 4, 5, 1, 2, 3, 4, 1},
	{3, 2, 1, 1, 3, 3, 1, 4, 2, 4},
	{1, 1, 2, 4, 2, 5, 2, 1, 2, 4},
	{5, 5, 1, 1, 3, 1, 2, 4, 2, 3},
	{1, 4, 2, 3, 4, 1, 3, 1, 5, 2},
	{1, 2, 5, 5, 2, 4, 1, 3, 3, 2},
	{5, 4, 1, 4, 1, 4, 1, 3, 2, 5},
	{1, 5, 3, 5, 1, 2, 1, 3, 1, 1},
	{5, 1, 3, 1, 4, 2, 2, 4, 3, 1},
};

int aux1 = 0, aux2 = 0, i, j, a;

int main(void){
// Estos 2 IF crean el espacio en memoria con el tamaño que especificamos arriba y el identificador

	if((hArchMapeoAB=CreateFileMapping( INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0,
									   TAM_MEM, idMemCompartidaAB)) == NULL){
 
 		printf("No se mapeo la memoria compartida: (%i)\n", GetLastError());
 		exit(-1);
 	}

 	if((apDatosAB=(char *)MapViewOfFile(hArchMapeoAB, FILE_MAP_ALL_ACCESS, 0, 0,
 									   TAM_MEM)) == NULL){
 
		printf("No se creo la memoria compartida: (%i)\n", GetLastError());
		CloseHandle(hArchMapeoAB);
		exit(-1);
	}

// Aqui enlazamos la variable que va a guardar los datos de la matriz a la variable que esta en memoria
// osea apTrabajo tendra los datos de la matriz y como son apuntadores si uno se actualiza el otro tambien
// entonces mientras guardamos la matriz en trabajo, a la vez datos esta guardando los valores en el espacio de
// memoria, el segundo if vemos como enlazamos la variable datos al espacio de memoria

	apTrabajoAB = apDatosAB;

	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++)
			*apTrabajoAB++ = matrizA[i][j];
		}
		
	*apTrabajoAB = '\0';	//Esta madre indica el fin de la variable, por ello si tienes un 0 en la matriz crea un
							//fin, por ello es recomendable no tener 0 en la matriz

	while (*apDatosAB != '*'){	//Esta madre espera hasta que el otro archivo acceda a la memoria para cerrarse
		sleep(1);
	}
	
	UnmapViewOfFile(apDatosAB); //con esta wea se borra el espacio en memoria
	CloseHandle(hArchMapeoAB);

} 
