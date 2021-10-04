// 3CM12
// Analisis de Algoritmos
// Autores: Mora Ayala Jose, Antonio, Lopez Lopez Oscar Manual
// Jeon Jeong Paola, Lemus Ruiz Mariana ELizabeth
// Implementacion de funciones
#include "FuncionesH.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../FuncionesHilos/Arbol.c"

//  //Estrucutras auxiliares para la ejecucion de los códigos
//  //Nos ofrecen la alternativa de almacenar los valores dependiento de cada uno de los hilos
//  //De tal forma que podremos ALMACENAR LOS PARAMETROS MANDADOS A LAS UNCIONES CON HILOS 
typedef struct auxiliarBusquedaLineal
{
	int *arrelgo;
	int valorABuscar;
	int inicio;
	int final;
	int *encontrado;
} AuxiliarLineal;
typedef struct auxiliarBusquedaBinaria
{
	int *arrelgo;
	int valorABuscar;
	int inicio;
	int final;
	int *encontrado;
} AuxiliarBinaria;

typedef struct auxiliarBusquedaEnArbol{
	arbol t;
	int valorABuscar;
	int * encontrado;
}AuxiliarArbol;


// // Busqueda Lienal
//Recibimos un arreglo que contiene los numeros del archivo 10 millones
// inicio : Inicio del arreglo
//Un entero "final" para especificar el tamaño del arreglo
//Un entero llamado elemento el cual tiene el número que deseamos encontrar,
//dentro del arreglo
// *aviso: Bandera que nos ayudara a determianr si el elemento ya fue encontrado o no
void BusquedaLineal(int *A, int inicio, int final, int elem, int *aviso)
{
	//- Variables para el ciclo
	int n;
	for (n = inicio; n < final; n++)
	{
		// Cuando aviso haya cambiado de valor terminara este algoritmo de busqueda
		if (*aviso >= 0)
		{
			break;
		}
		//Nos ayuda a comparar las posiciones que se encuentran en el arreglo
		//con la posición del elemento que se desea encontrar
		if (A[n] == elem)
		{
			// printf("El elemento fue encontrado en la posicion numero: %d \n", n);
			*aviso = elem;
		}
	}
}
// // Busqueda Lineal Hilos
//Recibimos un arreglo que contiene los numeros del archivo 10 millones
// inicio : Inicio del arreglo
//Un entero "final" para especificar el tamaño del arreglo
//Un entero llamado elemento el cual tiene el número que deseamos encontrar,
//dentro del arreglo
// *aviso: Bandera que nos ayudara a determianr si el elemento ya fue encontrado o no
// void BusquedaLinealHilos(int *A, int valorABuscar, int inicio, int final, int *aviso)
// {

void BusquedaLinealHilos(int *A, int valorABuscar, int inicio, int final, int *aviso,int hilos){
	int parts = hilos;
	pthread_t hilo[parts];
	int medio = final/parts;
	for (int i = 0; i < parts; i++)
	{
		AuxiliarBinaria *f = (AuxiliarBinaria *)malloc(sizeof(AuxiliarBinaria));
		f->arrelgo=A;
		f->valorABuscar=valorABuscar;
		f->inicio=i*medio;
		f->final=((f->inicio)+medio)-1;
		f->encontrado=aviso;
		pthread_create(&hilo[i],NULL,lanzarBusquedaLineal,(void*)f);
	}

	for (int i = 0; i < parts; ++i)
	{
		pthread_join(hilo[i],NULL);
	}

}
// // Busqueda Binaria
//Recibimos un arreglo que contiene los numeros del archivo 10 millones
// inicio : Inicio del arreglo
//Un entero "final" para especificar el tamaño del arreglo
//Un entero llamado elemento el cual tiene el número que deseamos encontrar,
//dentro del arreglo
// *aviso: Bandera que nos ayudara a determianr si el elemento ya fue encontrado o no

void BusquedaBinaria(int *A, int inicio, int final, int elem, int *aviso)
{
	// -Variables para algoritmo de busqueda
	int mitad;
	while (inicio <= final)
	{
		mitad = (inicio + final) / 2;
		if (A[mitad] < elem)
		{
			inicio = mitad + 1;
		}
		
		else
		{
			final = mitad - 1;
		}

		if (A[mitad] == elem)
		{
			*aviso = 1;
			// printf("Enontraste el emento en la posicion: %d\n", mitad);
			break;
		}
	}
}





// ///////////////////////////////ya sirve//////////////////////////////////////////////////////////////
// // Busqueda Binaria Hilos // //
// // Busqueda Binaria
//Recibimos un arreglo que contiene los numeros del archivo 10 millones
// inicio : Inicio del arreglo
//Un entero "final" para especificar el tamaño del arreglo
//Un entero llamado elemento el cual tiene el número que deseamos encontrar,
//dentro del arreglo
// *aviso: Bandera que nos ayudara a determianr si el elemento ya fue encontrado o no

void BusquedaBinariaHilos(int *A, int valorABuscar, int inicio, int final, int *aviso,int hilos){
	int parts = hilos;
	pthread_t hilo[parts];
	int medio = final/parts;
	for (int i = 0; i < parts; i++)
	{
		AuxiliarBinaria *f = (AuxiliarBinaria *)malloc(sizeof(AuxiliarBinaria));
		f->arrelgo=A;
		f->valorABuscar=valorABuscar;
		f->inicio=i*medio;
		f->final=((f->inicio)+medio)-1;
		f->encontrado=aviso;
		pthread_create(&hilo[i],NULL,lanzarBusquedaBinaria,(void*)f);
	}

	for (int i = 0; i < parts; ++i)
	{
		pthread_join(hilo[i],NULL);
	}

}

// //          Busqueda con Serie de Fibbonacci           // //
//Función para encontrar el mínimo de dos números
int min(int x, int y) { return (x <= y) ? x : y; }

//Regresa "i" si el elemento se encuentra en el arreglo
//Si el elemento no se encuentra, regresa un -1

//Declaramos un arreglo
//Un entero "n" para especificar el tamaño del arreglo
//Un entero llamado n el cual tiene el número que deseamos encontrar,
//dentro del arreglo
int fibMonaccianSearch(int *A, int x, int n)
{
	//Inicializamos los primeros dos números de la serie
	//Estos números siempre son continuos
	int fibMMm2 = 0;
	int fibMMm1 = 1;

	//La suma de los números anteriores dan el número que sigue en la serie
	int fibM = fibMMm2 + fibMMm1;

	//Mientras fibM es menor al tamaño del arreglo,
	//Los valores se irán "recorriendo" de variable
	//Y la suma de los números anteriores,
	//serán el valor de fibM
	while (fibM < n)
	{
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	//Nos marca el rango de la izquierda donde no se encuentra el elemento deseado
	int offset = -1;

	while (fibM > 1)
	{
		int i = min(offset + fibMMm2, n - 1);

		//Si el elemento es mayor al valor del índice,
		//Lo valores se irán recorriendo y el "offset"
		//se cambiará al valor del índice,
		if (A[i] < x)
		{
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		}

		//Si el elemento es mayor a la posición del arreglo en la posiciónde fibMm2
		//el arreglo se dividirá después de la posición i+1
		else if (A[i] > x)
		{
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}

		//Si el elemento es encontrado, devolvemos "i"
		else
			return i;
	}

	//Comparamos el último valor del arreglo con el elemento
	if (fibMMm1 && A[offset + 1] == x)
		return offset + 1;

	//Si el elemento no es encontrado, devolvemos un -1
	return -1;
}


//Busqueda en Arbol
void BusquedaEnArbol(int * arreglo, int n, int valorABuscar, int * aviso)
{
	// Variable para "almacenar" el árbol
	arbol t;
	// Inicializando arbol
	Iniciar(&t);
	// Rellenamos el arbol
	int i;
	// Variable para poder controlar el ciclo
	for(i=0;i < n; i++)
	{
		NuevoNodo(&t,arreglo[i]);
	}
	// Lanzamos la búsqueda sin hilos
	BuscaValor(&t, valorABuscar, aviso);
}

void BusquedaEnArbolHilos(int * arreglo, int n, int valorABuscar, int * aviso)
{
	// Variable para "almacenar" el árbol
	arbol t;
	// Creamos nuestro árbol
	Iniciar(&t);
	// Rellenamos el arbol
	int i;
	for(i=0;i < n; i++)
	{
		NuevoNodo(&t,arreglo[i]);
	}
	/* Parte de hilos */
	// Comprobamos si nuestro valor a buscar
	// no está en la raíz:
	if((*t).valor == valorABuscar) 
	{
		*aviso = (*t).valor;
	}
	else
	{
		// Si no está, comenzamos la
		// repartición de los subarboles
		pthread_t *thread;
		thread = malloc(2*sizeof(pthread_t));
		// Creamos los auxiliares 
		AuxiliarArbol * izq = (AuxiliarArbol *)malloc(sizeof(AuxiliarArbol));
		izq->t = (*t).izquierdo;
		izq->valorABuscar = valorABuscar;
		izq->encontrado = aviso;

		
		AuxiliarArbol * der = (AuxiliarArbol *)malloc(sizeof(AuxiliarArbol));
		der->t = (*t).derecho;
		der->valorABuscar = valorABuscar;
		der->encontrado = aviso;

		// Creamos los hilos
		if(pthread_create(&thread[0], NULL, procesarBusquedaArbol, (void *)izq) != 0)
		{
			perror("El thread no  pudo crearse [Arbol]\n");
			exit(-1);
		}
		if(pthread_create(&thread[1], NULL, procesarBusquedaArbol, (void *)der) != 0)
		{
			perror("El thread no  pudo crearse [Arbol]\n");
			exit(-1);
		}
		// Esperamos a los hilos
		int i;
		for (i=0; i<2; i++) pthread_join (thread[i], NULL);
		free(thread);
	}
}

int BusquedaExponencial(int *A, int n, int elem, int *aviso)
{
    // -Variables para algoritmo de busqueda
    int inicio, final, mitad, i;
    i = 1;
    final = n;
    while (i < final && A[i] <= elem)
    {
        i = i * 2;
    }

    inicio = (i / 2);
    final = (n - 1);

    while (inicio <= final)
    {
        mitad = (inicio + final) / 2;
        if (A[mitad] == elem)
        {
            *aviso = mitad;
            return mitad;
        }
        if (A[mitad] > elem)
        {
            final = mitad - 1;
        }
        else
        {
            inicio = mitad + 1;
        }
    }
	*aviso=-1;
	return -1;
}






// Nos ayudará a lanzar la búsqueda en árbol por cada hilo
void *lanzarBusquedaLineal(void *busqueda)
{
	AuxiliarLineal *l = (AuxiliarLineal *)busqueda;
	BusquedaLineal(l->arrelgo, l->inicio, l->final, l->valorABuscar, l->encontrado);
}

// void *lanzarBusquedaBinaria(void *busqueda)
// {
// 	AuxiliarBinaria *a = (AuxiliarBinaria *)busqueda;
// 	BusquedaBinaria(a->arrelgo, a->inicio, a->final - 1, a->valorABuscar, a->encontrado);
// }
void *lanzarBusquedaBinaria(void *busqueda)
{
	AuxiliarBinaria *a = (AuxiliarBinaria *)busqueda;
	BusquedaBinaria(a->arrelgo, a->inicio, a->final, a->valorABuscar, a->encontrado);
}


void * procesarBusquedaArbol(void* busqueda)
{
	AuxiliarArbol * b = (AuxiliarArbol *)busqueda;
	BuscaValor(&((*b).t), (*b).valorABuscar, (*b).encontrado);
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

int *Quicksort2(int *A, int primero, int ultimo)
{
    int piv, i, j, central, aux;
    central = (primero + ultimo) / 2;
    piv = A[central], i = primero, j = ultimo;
    do
    {
        while (A[i] < piv)
        {
            i++;
        }
        while (A[j] > piv)
        {
            j--;
        }
        if (i <= j)
        {
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);
    if (primero < j)
    {
        Quicksort2(A, primero, j);
    }
    if (primero < ultimo)
    {
        Quicksort2(A, i, ultimo);
    }
}



