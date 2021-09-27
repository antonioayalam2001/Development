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

// // Estrucutras auxiliares para la ejecucion de los códigos
//  //Nos ofrecen la alternativa de almacenar los valores dependiento de cada uno de los hilos
//  // De tal forma que podremos diviri los elementos
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
			printf("El elemento fue encontrado en la posicion numero: %d ", n);
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
void BusquedaLinealHilos(int *A, int valorABuscar, int inicio, int final, int *aviso)
{

	// - Variables para el manejo del algoritmo
	int puntomedio = (final - inicio) / 2;
	if (puntomedio > 0)
	{
		//- Creacion de los hilos que contendran partes del arreglo en cuestion:
		pthread_t *hilo;
		hilo = malloc(2 * sizeof(pthread_t));
		//- Repartiendo el arreglo mediante el uso de las estructuras que creamos
		AuxiliarLineal *der = (AuxiliarLineal *)malloc(sizeof(AuxiliarLineal));
		der->arrelgo = A;
		der->valorABuscar = valorABuscar;
		der->inicio = puntomedio + 1;
		der->final = final;
		der->encontrado = aviso;
		AuxiliarLineal *izq = (AuxiliarLineal *)malloc(sizeof(AuxiliarLineal));
		izq->arrelgo = A;
		izq->valorABuscar = valorABuscar;
		izq->inicio = inicio;
		izq->final = puntomedio;
		izq->encontrado = aviso;

		// -Creando los Hilos
		//- La funcion naturalmente devuelve 0 en caso de que el hilo se haya creado de forma exitosa, de lo contrario devolvera otro valor
		if (pthread_create(&hilo[0], NULL, lanzarBusquedaLineal, (void *)izq) != 0)
		{
			perror("El hilo nos e pudo crear");
			exit(-1);
		}
		if (pthread_create(&hilo[1], NULL, lanzarBusquedaLineal, (void *)der) != 0)
		{
			perror("El hilo nos e pudo crear");
			exit(-1);
		}
		// - Variables manejo de ciclo for
		int i;
		// - Hace que los hilos terminen y posteriormente se vuelvan a unir al programa principal (Hasta que los hilos acaben acaba todo)
		// -Si el main termina primero tendra que mantenerse en espera
		for (i = 0; i < 2; i++)
			pthread_join(hilo[i], NULL);
		free(hilo);
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
			*aviso = elem;
			printf("Enontraste el emento en la posicion: %d\n", mitad);
			break;
		}
	}
}

// // Busqueda Binaria Hilos // //
// // Busqueda Binaria
//Recibimos un arreglo que contiene los numeros del archivo 10 millones
// inicio : Inicio del arreglo
//Un entero "final" para especificar el tamaño del arreglo
//Un entero llamado elemento el cual tiene el número que deseamos encontrar,
//dentro del arreglo
// *aviso: Bandera que nos ayudara a determianr si el elemento ya fue encontrado o no

void BusquedaBinariaHilos(int *A, int valorABuscar, int inicio, int final, int *aviso)
{

	// - Variables para el manejo del algoritmo
	int puntomedio = (final - inicio) / 2;
	if (puntomedio > 0)
	{
		//- Creacion de los hilos que contendran partes del arreglo en cuestion:
		pthread_t *hilo;
		hilo = malloc(2 * sizeof(pthread_t));
		//- Repartiendo el arreglo mediante el uso de las estructuras que creamos
		AuxiliarBinaria *der = (AuxiliarBinaria *)malloc(sizeof(AuxiliarBinaria));
		der->arrelgo = A;
		der->valorABuscar = valorABuscar;
		der->inicio = puntomedio + 1;
		der->final = final;
		der->encontrado = aviso;
		AuxiliarBinaria *izq = (AuxiliarBinaria *)malloc(sizeof(AuxiliarBinaria));
		izq->arrelgo = A;
		izq->valorABuscar = valorABuscar;
		izq->inicio = inicio;
		izq->final = puntomedio;
		izq->encontrado = aviso;

		// -Creando los Hilos
		//- La funcion naturalmente devuelve 0 en caso de que el hilo se haya creado de forma exitosa, de lo contrario devolvera otro valor
		if (pthread_create(&hilo[0], NULL, lanzarBusquedaBinaria, (void *)izq) != 0)
		{
			perror("El hilo nos e pudo crear");
			exit(-1);
		}
		if (pthread_create(&hilo[1], NULL, lanzarBusquedaBinaria, (void *)der) != 0)
		{
			perror("El hilo nos e pudo crear");
			exit(-1);
		}
		// - Variables manejo de ciclo for
		int i;
		// - Hace que los hilos terminen y posteriormente se vuelvan a unir al programa principal (Hasta que los hilos acaben acaba todo)
		// -Si el main termina primero tendra que mantenerse en espera
		for (i = 0; i < 2; i++)
			pthread_join(hilo[i], NULL);
		free(hilo);
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



// Nos ayudará a lanzar la búsqueda en árbol por cada hilo
void *lanzarBusquedaLineal(void *busqueda)
{
	AuxiliarLineal *l = (AuxiliarLineal *)busqueda;
	BusquedaLineal(l->arrelgo, l->inicio, l->final, l->valorABuscar, l->encontrado);
}

void *lanzarBusquedaBinaria(void *busqueda)
{
	AuxiliarBinaria *a = (AuxiliarBinaria *)busqueda;
	BusquedaBinaria(a->arrelgo, a->inicio, a->final - 1, a->valorABuscar, a->encontrado);
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