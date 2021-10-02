//Librerias incluidas
// 3CM12
// Analisis de Algoritmos
// Autores: Mora Ayala Jose, Antonio, Lopez Lopez Oscar Manual
// Jeon Jeong Paola, Lemus Ruiz Mariana ELizabeth
// Algoritmo de Busqueda por Fibonacci con la implementacion de hilos 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "./Tiempo/tiempo.c"

/* Prototipo de la funcion de lectura del archivo de los 10 millones de numeros */
int *LeerArchivo(int *A, int n);
int exponencialBusqueda(int * arreglo, int n, int valorABuscar, int parts);
void *exponencialH(void *args);

// Estructura auxiliar exponencial
typedef struct argumentos {
	int *arr;
	int elemento;	
	int izq;
	int der;
	int *aviso;
}expo;

int min(int x, int y) { return (x<=y)? x : y; }

/*
    Funcion: fibonacci
    Esta realiza una busqueda Fibonacci en el intervalo dado
    Lo que se recibe: (Struct) args que contienen los numeros Fibonacci donde inicia la busqueda, 
    el numero a buscar y el arreglo donde buscar.
    Imprime si ha encontrado el numero 
*/
void *exponencialH(void *args){
    double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medici�n de tiempos
	expo *exponencial=(expo*)args;
    int izq=exponencial->izq;
    int der=exponencial->der;
    int i=izq+1;

    if (exponencial->arr[izq]==exponencial->elemento )
    {
        *exponencial->aviso=exponencial->elemento;
	    pthread_exit(NULL);        
    }
    while (i<=der && exponencial->arr[i] <= exponencial->elemento)
    {
        i=i*2;
    }

    if (i<=der)
    {
        der=i;
    }

    izq=i/2;

    while (izq <= der && *exponencial->aviso==-1)
    {
        //Dividiendo en mitades 
        int mitad = (izq+der)/2;
        //Revisamos si el elemento de encuentra en la posicion del centro actual
        if (exponencial->arr[mitad] == exponencial->elemento)
        {
            *exponencial->aviso=exponencial->elemento;
            pthread_exit(NULL);
        }

        if (exponencial->arr[mitad] < exponencial->elemento)
        {
            izq=mitad+1;
        }else{
            der=mitad-1;
        }
        pthread_exit(NULL);
        
    }
}
    
int exponencialBusqueda(int * arreglo, int n, int valorABuscar, int parts){
    pthread_t ids[parts]; // Número de hilos
	int found = -1;				// Encontró el hilo o no (0 -> false)
	// Variable auxiliar para cálculo de los rangos de los hilos
	int tamT = n / parts;
	// Variable auxiliar para divisibles no exactos
	int mod = n % parts;

	for (int i = 0; i < parts; i++)
	{


		// Creación de memoria para
		expo *d = malloc(sizeof(expo));
		d->arr = arreglo;
		d->elemento = valorABuscar;
		// Variable inicio del rango
		d->izq = i * tamT;
		// Variable fin del rango
		d->der = (d->izq + tamT) - 1;
		// Condicional para ajustar el rango
		if (i == parts - 1)
		{
			// Asignación del valor de rango
			d->der += mod;
		}
		// Comunicación entre hilos
		d->aviso = &found;

		// Lanza los hilos
		pthread_create(&ids[i], NULL, exponencialH, (void *)d);
	}

	for (int i = 0; i < parts; i++)
	{
		// Fin/terminar hilos
		pthread_join(ids[i], NULL);
	}

	return found;


}
    
    
    
int main(int argc, char const *argv[])
{
    printf("Hola\n");
    	/*  Variables para time */

	// Variables para medición de tiempos
	double utime0, stime0, wtime0, utime1, stime1, wtime1;
	int n; // n determina el tamaño del algorito dado por argumento al ejecutar
	int i; // Variables para loops

	// Variables
	int x;				 // India el valor a buscar.
	int found;		 // Indica si encontró el valor.
    // Asignacion de memoria del arreglo con respecto al tamaño de problema solicitado
    int *A;
    A = (int *)malloc(n * sizeof(int));
    n=10000;
    // Lectura y asignacion de valores al arreglo en cuestion
    LeerArchivo(A, n);

	uswtime(&utime0, &stime0, &wtime0);
    found=exponencialBusqueda(A,n,5000,2);
   	uswtime(&utime1, &stime1, &wtime1);

    if (found>0)
    {
        	// Tiempo real
	    printf("%.10f ", wtime1 - wtime0);
	// Tiempo de CPU
	    printf("%.10f ", utime1 - utime0);
	//Tiempo E/S
	    printf(" %.10f", stime1 - stime0);
	// CPU/Wall %
	    printf(" %.10f \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    }
    

    return 0;
}



/* Funcion para leer y almacenar n cantidad de numeros del archivo 10millones dentro de un arreglo (con memoria previamente asignada)
    Recibe:
        *A: Arreglo de elementos vacio con la memoria suficiente para almacenar n cantidad de elementos 
         n: cantidad de elementos que seran leidos del archivo y almacenados en el arreglo
 */
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