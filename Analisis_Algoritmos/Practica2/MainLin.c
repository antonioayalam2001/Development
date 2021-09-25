//*****************BUSQUEDA SECUENCIAL**************************
// LORETTO ESTRADA GALILEA AMERICA
// PEREZ GARCIA ATZIRI***/

/***********LIBRERIAS********************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/********* VARIABLES GLOBALES **********/
int NumThreads;

/********ESTRUCTURA AUXILIAR PARA LOS ARGUMENTOS********/
typedef struct argumentos{
	int id;
	int dato;
	int *arreglo;
	int n;
} *datos;

/********THREAD BUSQUEDA SECUENCIAL********/
void *sequentialSearch(void *recibido){
	int bandera = '0'; // Para saber si el elemento se encontro.
	int c = 0, inicio = 0, fin = 0;
	int *arregloNuevo = 0;
	
	datos ptr = (datos)recibido;
	
	int *arregloRecibido;
	int datoABuscarRecibido =  ptr -> dato;
	int tamRecibido = ptr -> n;
	int n_Thread = ptr -> id;
	arregloRecibido=(int *)malloc(sizeof(int)*tamRecibido);
	arregloRecibido = ptr -> arreglo;

	inicio=(n_Thread*tamRecibido)/NumThreads;
	if(n_Thread==NumThreads-1)	
		fin=tamRecibido;
	else
		fin=((n_Thread+1)*tamRecibido)/NumThreads-1;

	arregloNuevo = (int *)malloc(sizeof(int)*(fin-inicio));

	for(int i=inicio;i<=fin;i++){
		*(arregloNuevo+c) = *(arregloRecibido+i);
		c++;
	}	
	for(int i=0; i<(fin-inicio); i++){
		if(datoABuscarRecibido == arregloNuevo[i]){
			bandera = '1';
		}
	}
		printf("Hilo %d. %d - %d\t", n_Thread,inicio,fin);
		if(bandera == '1')
			printf("Numero encontrado.\n");
		else
			printf("Numero no encontrado.\n");
}
/******** FUNCION PRINCIPAL ********/
int main (int argc, char *argv[]){
	int *A;
	int datoABuscar, tam, i;
	
	// Conocer el numero de threads
	pthread_t *thread;
	if(argc<2){
		printf("Indique el numero de threads - \n Ejemplo: [user@equipo]$ %s 4\n\n", argv[0]);
		exit(-1);
	}
	NumThreads = atoi(argv[1]);
	thread = malloc(NumThreads*sizeof(pthread_t));
	
	// Tamanio del arreglo;
	if(argc<3){
		printf("\nIndique el tamanio de N - \nEjemplo: [user@equipo]$ %s %s 1000\n",argv[0],argv[1]);
		exit(-1);
	}
	tam=atoi(argv[2]);
	
	// Dato a buscar
	if(argc!=4){
		printf("\nIndique numero a buscar - \nEjemplo: [user@equipo]$ %s %s 1000 %s \n",argv[0],argv[1],argv[2]);
		exit(-1);
	}
	datoABuscar=atoi(argv[3]);
	
	A = (int *)malloc(sizeof(int)*tam);
	
	// Guardando elementos
	for(int i=0; i<tam; i++){
		scanf("%d", A+i);
	}	
	
	struct argumentos args;
	args.id = i;
	args.dato = datoABuscar;
	args.arreglo = A;
	args.n = tam;
	
	for(int i=1; i<=NumThreads; i++){
		struct argumentos args ={i,datoABuscar,A,tam};
		if(pthread_create(&thread[i], NULL, sequentialSearch, (void *)(&args)) != 0){
			perror("El thread no pudo crearse");
			exit(-1);
		}
	}
	
	for(i=1; i<=NumThreads; i++)
		pthread_join(thread[i], NULL);
	
	return 0;
}