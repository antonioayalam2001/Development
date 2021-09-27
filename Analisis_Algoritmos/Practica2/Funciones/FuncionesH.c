#include "FuncionesH.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// // Estrucutras auxiliares para la ejecucion de los códigos
//  //Nos ofrecen la alternativa de almacenar los valores dependiento de cada uno de los hilos
//  // De tal forma que podremos diviri los elementos 
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

//  //
//  //
//  //


// // Busqueda Lienal
//Recibimos un arreglo que contiene los numeros del archivo 10 millones 
// inicio : Inicio del arreglo
//Un entero "final" para especificar el tamaño del arreglo 
//Un entero llamado elemento el cual tiene el número que deseamos encontrar,
//dentro del arreglo
// *aviso: Bandera que nos ayudara a determianr si el elemento ya fue encontrado o no
void BusquedaLineal(int *A, int inicio ,int final, int elem, int *aviso){
    //- Variables para el ciclo
    int n;
    for (n = inicio; n < final; n++)
    {
		// Cuando aviso haya cambiado de valor terminara este algoritmo de busqueda
    	if (*aviso>=0)
    	{
    		break;
    	}
		//Nos ayuda a comparar las posiciones que se encuentran en el arreglo 
        //con la posición del elemento que se desea encontrar
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


// . Menu de seleccion
void MenuSeleccion(int *A,int inicio, int final,int *Arreglo,int *aviso,int opc)
{
	int m;
    double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medición de tiempos

    switch (opc)
    {
    case 1:
        printf("Metodo de Lineal");
		    for (m = 0; m < 4; m++)
    {
        uswtime(&utime0, &stime0, &wtime0);
        BusquedaLineal(A,0,n, Arreglo[m], &aviso);
        uswtime(&utime1, &stime1, &wtime1);

        if (aviso > 0)
        {
            printf("Lineal %d\n",m);
            printf("\n");
            printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
            printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
            printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
            printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
            printf("\n");
        }

        aviso = -1;
    }
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
	BusquedaBinaria(a->arrelgo,a->inicio,a->final-1,a->valorABuscar,a->encontrado);
}


// .Lectura del Archivo
// .Recibe:  Arreglo con memoria suficiente para almacenar n cantidad de enteros
// .Devuelve: Arreglo con los valores insertados dentro de el


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