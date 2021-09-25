#include "FuncionesH.h"
#include <pthread.h>
#include <stdlib.h>
// Estructura auxiliar para la búsqueda
// lineal
typedef struct auxiliarBusquedaLineal{
	int * arrelgo;
	int valorABuscar;
	int inicio;
	int final;
	int * encontrado;
}AuxiliarLineal;
// Prototipos internos
void * procesarBusquedaArbol(void* busqueda);
void * procesarBusquedaBinaria(void* busqueda);
void * procesarBusquedaLineal(void* busqueda);
void BusquedaLinealHilos(int * arreglo, int valorABuscar, int inicio, int final, int * encontrado)
{
	int puntoMedio = (final - inicio) / 2;
	if(puntoMedio > 0)
	{
		// Comenzamos la
		// repartición de los subarreglos
		pthread_t *thread;
		thread = malloc(2*sizeof(pthread_t));
		// Creamos los auxiliares 
		AuxiliarLineal * izq = (AuxiliarLineal *)malloc(sizeof(AuxiliarLineal));
		(*izq).arrelgo = arreglo;
		(*izq).valorABuscar = valorABuscar;
		(*izq).encontrado = encontrado;
		(*izq).inicio = inicio;
		(*izq).final = puntoMedio;


		AuxiliarLineal * der = (AuxiliarLineal *)malloc(sizeof(AuxiliarLineal));
		(*der).arrelgo = arreglo;
		(*der).valorABuscar = valorABuscar;
		(*der).encontrado = encontrado;
		(*der).inicio = puntoMedio + 1;
		(*der).final = final;

		// Creamos los hilos
		if(pthread_create(&thread[0], NULL, procesarBusquedaLineal, (void *)izq) != 0)
		{
			perror("El thread no  pudo crearse [Lineal]\n");
			exit(-1);
		}
		if(pthread_create(&thread[1], NULL, procesarBusquedaLineal, (void *)der) != 0)
		{
			perror("El thread no  pudo crearse [Lineal]\n");
			exit(-1);
		}
		// Esperamos a los hilos
		int i;
		for (i=0; i<2; i++) pthread_join (thread[i], NULL);
		free(thread);
	}	
}

// . Menu de seleccion
void MenuSeleccion(int *A, int n, int elem ,int opc)
{
    int encontrado=-1;
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
        BusquedaLinealHilos(A,elem,0,n-1,&encontrado);
    default:
        break;
    }
}

// Nos ayudará a lanzar la búsqueda en árbol por cada hilo
void * procesarBusquedaLineal(void* busqueda)
{
	AuxiliarLineal * l = (AuxiliarLineal *)busqueda;
	BusquedaLineal((*l).arrelgo, (*l).valorABuscar,(*l).inicio, (*l).final, (*l).encontrado);
}