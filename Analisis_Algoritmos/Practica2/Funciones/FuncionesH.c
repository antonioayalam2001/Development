#include "FuncionesH.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Estructura auxiliar para la búsqueda
// lineal
typedef struct auxiliarBusquedaLineal{
	int * arrelgo;
	int valorABuscar;
	int inicio;
	int final;
	int * encontrado;
}AuxiliarLineal;
typedef struct auxiliarBusquedaBinaria{
	int * arrelgo;
	int valorABuscar;
	int inicio;
	int final;
	int * encontrado;
}AuxiliarBinaria;

void * lanzarBusquedaLineal(void* busqueda);
void * lanzarBusquedaBinaria(void* busqueda);
//  * Función que busca en un arreglo mediante el uso
//  * del algoritmo de búsqueda secuencial
//  * Parámetros:
//  *	arreglo - el arreglo en el que se desea buscar
//  *	elem - el valor a buscar dentro del arreglo
//  * 	inicio - el punto inicial del segmento dentro del arreglo para buscar
//  * 	final - el punto final del segmento dentro del arreglo para buscar
//  *	aviso - nos indicará si el valor fue encontrado
//  *
//  * */	
// // Busqueda Lienal Hilos
void BusquedaLineal(int *A, int inicio ,int final, int elem, int *aviso){
    //- Variables para el ciclo
    int n;
    for (n = inicio; n < final; n++)
    {
    	if (*aviso>=0)
    	{
    		break;
    	}
        if(A[n]==elem){
            printf("El elemento fue encontrado en la posicion numero: %d ", n);
			*aviso=elem;
        }
    }    
}
// // Busqueda Lineal Hilos
void BusquedaLinealHilos(int * A, int valorABuscar, int inicio, int final, int * aviso){
	
	// - Variables para el manejo del algoritmo
	int puntomedio = (final-inicio)/2;
	if (puntomedio >0)
	{
		//- Creacion de los hilos que contendran partes del arreglo en cuestion:
		pthread_t *hilo;
		hilo= malloc (2*sizeof(pthread_t));
		//- Repartiendo el arreglo mediante el uso de las estructuras que creamos
		AuxiliarLineal *der= (AuxiliarLineal *)malloc(sizeof(AuxiliarLineal));
			der->arrelgo=A;
			der->valorABuscar= valorABuscar;
			der->inicio=puntomedio+1;
			der->final=final;
			der->encontrado=aviso;
		AuxiliarLineal *izq= (AuxiliarLineal *)malloc(sizeof(AuxiliarLineal));
			izq->arrelgo=A;
			izq->valorABuscar= valorABuscar;
			izq->inicio=inicio;
			izq->final=puntomedio;
			izq->encontrado=aviso;

		// -Creando los Hilos
		//- La funcion naturalmente devuelve 0 en caso de que el hilo se haya creado de forma exitosa, de lo contrario devolvera otro valor
		if (pthread_create(&hilo[0],NULL,lanzarBusquedaLineal,(void*)izq)!=0)
		{
			perror("El hilo nos e pudo crear");
			exit(-1);
		}
		if (pthread_create(&hilo[1],NULL,lanzarBusquedaLineal,(void*)der)!=0)
		{
			perror("El hilo nos e pudo crear");
			exit(-1);
		}
		// - Variables manejo de ciclo for
		int i;
		// - Hace que los hilos terminen y posteriormente se vuelvan a unir al programa principal (Hasta que los hilos acaben acaba todo)
		// -Si el main termina primero tendra que mantenerse en espera
		for (i=0; i<2; i++) pthread_join (hilo[i], NULL);
		free(hilo);

	}
	
}

// // Busqueda Binaria 

void BusquedaBinaria(int *A,int inicio, int final,int elem,int *aviso){
    // -Variables para algoritmo de busqueda
	int mitad;
    while (inicio<=final)
    {
        mitad=(inicio + final)/2;
        if (A[mitad]<elem)
            {inicio=mitad+1;}
        else{final=mitad-1;}        
        
        if (A[mitad]==elem)
        {
			*aviso=elem;			
            printf("Enontraste el emento en la posicion: %d\n",mitad);
			break;
        }
    }    
}

// // Busqueda Binaria Hilos // //

void BusquedaBinariaHilos(int * A, int valorABuscar, int inicio, int final, int * aviso){
	
	// - Variables para el manejo del algoritmo
	int puntomedio = (final-inicio)/2;
	if (puntomedio >0)
	{
		//- Creacion de los hilos que contendran partes del arreglo en cuestion:
		pthread_t *hilo;
		hilo= malloc (2*sizeof(pthread_t));
		//- Repartiendo el arreglo mediante el uso de las estructuras que creamos
		AuxiliarBinaria *der= (AuxiliarBinaria *)malloc(sizeof(AuxiliarBinaria));
			der->arrelgo=A;
			der->valorABuscar= valorABuscar;
			der->inicio=puntomedio+1;
			der->final=final;
			der->encontrado=aviso;
		AuxiliarBinaria *izq= (AuxiliarBinaria *)malloc(sizeof(AuxiliarBinaria));
			izq->arrelgo=A;
			izq->valorABuscar= valorABuscar;
			izq->inicio=inicio;
			izq->final=puntomedio;
			izq->encontrado=aviso;

		// -Creando los Hilos
		//- La funcion naturalmente devuelve 0 en caso de que el hilo se haya creado de forma exitosa, de lo contrario devolvera otro valor
		if (pthread_create(&hilo[0],NULL,lanzarBusquedaBinaria,(void*)izq)!=0)
		{
			perror("El hilo nos e pudo crear");
			exit(-1);
		}
		if (pthread_create(&hilo[1],NULL,lanzarBusquedaBinaria,(void*)der)!=0)
		{
			perror("El hilo nos e pudo crear");
			exit(-1);
		}
		// - Variables manejo de ciclo for
		int i;
		// - Hace que los hilos terminen y posteriormente se vuelvan a unir al programa principal (Hasta que los hilos acaben acaba todo)
		// -Si el main termina primero tendra que mantenerse en espera
		for (i=0; i<2; i++) pthread_join (hilo[i], NULL);
		free(hilo);

	}
	
}




// void BusquedaLineal(int * arreglo, int valorABuscar, int inicio, int final, int * encontrado)
// {
// 	int n;
// 	for(n = inicio; n < final; n++)
// 	{
// 		if(*encontrado >= 0)
// 		{
// 			break;
// 		}
// 		if (arreglo[n] == valorABuscar )
// 		{
//             printf("Encontraste el elemento en la posicion %d",n); 
// 			*encontrado=valorABuscar;
//       	}
// 	}
// }


// void BusquedaLinealHilos(int * arreglo, int valorABuscar, int inicio, int final, int * encontrado)
// {
// 	int puntoMedio = (final - inicio) / 2;
// 	if(puntoMedio > 0)
// 	{
// 		// Comenzamos la
// 		// repartición de los subarreglos
// 		pthread_t *thread;
// 		thread = malloc(2*sizeof(pthread_t));
// 		// Creamos los auxiliares 
// 		AuxiliarLineal * izq = (AuxiliarLineal *)malloc(sizeof(AuxiliarLineal));
// 		(*izq).arrelgo = arreglo;
// 		(*izq).valorABuscar = valorABuscar;
// 		(*izq).encontrado = encontrado;
// 		(*izq).inicio = inicio;
// 		(*izq).final = puntoMedio;


// 		AuxiliarLineal * der = (AuxiliarLineal *)malloc(sizeof(AuxiliarLineal));
// 		(*der).arrelgo = arreglo;
// 		(*der).valorABuscar = valorABuscar;
// 		(*der).encontrado = encontrado;
// 		(*der).inicio = puntoMedio + 1;
// 		(*der).final = final;

// 		// Creamos los hilos
// 		if(pthread_create(&thread[0], NULL, procesarBusquedaLineal, (void *)izq) != 0)
// 		{
// 			perror("El thread no  pudo crearse [Lineal]\n");
// 			exit(-1);
// 		}
// 		if(pthread_create(&thread[1], NULL, procesarBusquedaLineal, (void *)der) != 0)
// 		{
// 			perror("El thread no  pudo crearse [Lineal]\n");
// 			exit(-1);
// 		}
// 		// Esperamos a los hilos
// 		int i;
// 		for (i=0; i<2; i++) pthread_join (thread[i], NULL);
// 		free(thread);
// 	}	
// }

// . Menu de seleccion
void MenuSeleccion(int *A, int n, int elem ,int opc)
{
    switch (opc)
    {
    case 1:
        printf("Metodo de Lineal");
        break;
    case 2:
        printf("Metodo de Busqueda Binaria");
        break;
    case 3:
        printf("Metodo de Busqueda Exponencial");
        break;
    case 4:
        printf("Metodo de Busqueda Fibbonacci");
        break;
    case 5:
        printf("Metodo de Busqueda Arbol");
        // BusquedaEnArbol(A, n, elem,&encontrado);
        break;
    case 6:
        printf("Lineal Hilos");
        // BusquedaLinealHilos(A,3,0,8,&encontrado);
    default:
        break;
    }
}

// Nos ayudará a lanzar la búsqueda en árbol por cada hilo
void * lanzarBusquedaLineal(void* busqueda)
{
	AuxiliarLineal * l = (AuxiliarLineal *)busqueda;
	BusquedaLineal(l->arrelgo, l->inicio,l->final, l->valorABuscar, l->encontrado);
}

void * lanzarBusquedaBinaria(void* busqueda){
	AuxiliarBinaria *a = (AuxiliarBinaria *)busqueda;
	BusquedaLineal(a->arrelgo,a->inicio,a->final-1,a->valorABuscar,a->encontrado);
}


// .Lectura del Archivo
int *LeerArchivo(int *A, int n)
{
    int i;
    FILE *numeros;
    numeros = fopen("10millones.txt", "r");
    if (numeros == NULL)
    {
        puts("Error en la apertura del archivo");
    }
    for (i = 0; i < n; i++)
    {
        fscanf(numeros, "%d", &A[i]);
    }
    fclose(numeros);
}