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
int *Quicksort2(int *A, int primero, int ultimo);
// Estructura auxiliar exponencial
typedef struct argumentos {
	int *arr;
	int elemento;	
	int izq;
	int der;
	int *aviso;
}expo;



    
    
int main(int argc, char const *argv[])
{

	// Variables para medición de tiempos
	double utime0, stime0, wtime0, utime1, stime1, wtime1;
	int n; // n determina el tamaño del algorito dado por argumento al ejecutar
	int m; // Variables para loops
    int hilos;
    n=atoi(argv[1]);
    hilos= atoi(argv[2]);
	// Variables
	int x;				 // India el valor a buscar.
	int found;		 // Indica si encontró el valor.
    // Asignacion de memoria del arreglo con respecto al tamaño de problema solicitado
    int *A;
    int Arreglo[20] = {322486,14700764,3128036,6337399,61396,10393545,2147445644,1295390003,450057883,187645041,1980098116,152503,5000,7500,214826,1843349527,1321906174,2109248666,2147470852,0};
    A = (int *)malloc(n* sizeof(int));
    Quicksort2(Arreglo,0,20);
    // Lectura y asignacion de valores al arreglo en cuestion
    LeerArchivo(A, n);


   	for (m = 0; m < 20; m++)
            {
                printf("VALOR DE N: %d: \n", n);
                uswtime(&utime0, &stime0, &wtime0);
    			found=exponencialBusqueda(A,n,Arreglo[m],hilos);
                uswtime(&utime1, &stime1, &wtime1);

                if (found >= 0)
                {
                    printf("Busqueda Exponencial ENCONTRO: %d\n",Arreglo[m]);
                    printf("real:%.10e s\n", wtime1 - wtime0);
                    printf("\n");
                }else{
                    printf("NoE: %d\n",Arreglo[m]);
                    printf("real  %.10e s\n", wtime1 - wtime0);
                    printf("\n");
                }

                found = -1;
            }


    exit (0);
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

/*
    Funcion: fibonacci
    Esta realiza una busqueda Fibonacci en el intervalo dado
    Lo que se recibe: (Struct) args que contienen los numeros Fibonacci donde inicia la busqueda, 
    el numero a buscar y el arreglo donde buscar.
    Imprime si ha encontrado el numero 
*/
void *exponencialH(void *args){
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
            *exponencial->aviso=0;
            pthread_exit(NULL);
        }

        if (exponencial->arr[mitad] < exponencial->elemento)
        {
            izq=mitad+1;
        }else{
            der=mitad-1;
        }
        
    }
        pthread_exit(NULL);
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
