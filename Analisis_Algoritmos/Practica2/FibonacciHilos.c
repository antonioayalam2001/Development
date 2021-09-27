//Librerias incluidas
// 3CM12
// Analisis de Algoritmos
// Autores: Mora Ayala Jose, Antonio, Lopez Lopez Oscar Manual
// Jeon Jeong Paola, Lemus Ruiz Mariana ELizabeth
// Algoritmo de Busqueda por Fibonacci con la implementacion de hilos 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// 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
#include "./Tiempo/tiempo.c"

int *LeerArchivo(int *A, int n);
struct argumentos {
	int *arr;
	int fib2;
	int fib1;
	int n;
	int target;	
};

int min(int x, int y) { return (x<=y)? x : y; }

/*
    Funcion: fibonacci
    Esta realiza una busqueda Fibonacci en el intervalo dado
    Lo que se recibe: (Struct) args que contienen los numeros Fibonacci donde inicia la busqueda, 
    el numero a buscar y el arreglo donde buscar.
    Imprime si ha encontrado el numero 
*/
void *fibonacci(void *ags){
    double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medición de tiempos
	struct argumentos *args = (struct argumentos*) ags;
	int status = 0, offset = 0;
	// Inizializa numeros fibonacci  
    int fibMMm2 = args->fib2; // (m-2)No. Fibonacci  
    int fibMMm1 = args->fib1; // (m-1)No. Fibonacci  
    int fibM = fibMMm2 + fibMMm1; // m Fibonacci 
    int n = args->n;
    int x = args->target;
    uswtime(&utime0, &stime0, &wtime0);
	while (fibM > 1) 
        { 
            // Revisa si fibMm2 esta en una locacion valida 
            int i = min(offset+fibMMm2, n-1); 
            // Si x es maqyor que el valor de index fibMn2, corta el subarray 
            
            if ((args->arr[i]) < x) 
            { 
                fibM = fibMMm1; 
                fibMMm1 = fibMMm2; 
                fibMMm2 = fibM - fibMMm1; 
                offset = i; 
            } 
  
            // Si x es menor que el valor index fibMm2, corta el subarray despues de i+1 
            else if ((args->arr[i]) > x) 
            { 
                fibM = fibMMm2; 
                fibMMm1 = fibMMm1 - fibMMm2; 
                fibMMm2 = fibM - fibMMm1; 
            } 
  
            // Elemento encontrado retorna S
            else
            {
        uswtime(&utime1, &stime1, &wtime1);
            	printf("Encontrado\n");
                printf("\n");
                printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
                printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
                printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
                printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
                printf("\n");
            	pthread_exit((void*)&status);

            } 
        } 
  
        // compara el ultimo elemento con x 
        if(fibMMm1 == 1 && (args->arr[offset+1]) == x) 
            printf("Encontrado\n");

	pthread_exit((void*)&status);
}

/*
    main
    Recibe: Tamaño de problema (argv[1]), Numero a buscar (argv[2]).
    Entonces realiza la busqueda Fibonacci utilizando dos hilos.
    Y finalmente devuelve el tiempo que tarda en ejecutarse el algoritmo.
    Nota: argv[1] DEBE SER MAYOR A 0.
*/
void main(int argc, char *argv[]){
	struct argumentos *margs = NULL;
	pthread_t id1 = 0,id2 = 0;
	int n = 0, target = 0, *numeros, i = 0;
	int eid1 = -1, eid2 = -1;

	int fibMMm2 = 0; // (m-2)No. Fibonacci
    int fibMMm1 = 1; // (m-1)No. Fibonacci 
    int fibM = fibMMm2 + fibMMm1; // m Fibonacci 
	
	n = atoi(argv[1]);
	target = atoi(argv[2]);

	numeros = malloc(sizeof(int)*n);
	margs = malloc(sizeof(struct argumentos));

	margs -> n = n;
	margs -> target = target;
	
	LeerArchivo(numeros,n);

    margs-> arr = numeros;
	/*Generamos los numeros fibonacci, para el tamaño de problema
	el índice máximo alcanzado en la serie fibonacci será el 36
	por lo tanto, se propone la creacion de dos hilos, uno busca
	en índice < 18 y otro en índice > 18*/
	i = 0;
	// fibM va a guardar el mas pequeño
    while (fibM < n) 
    { 
        fibMMm2 = fibMMm1; 
        fibMMm1 = fibM; 
        fibM = fibMMm2 + fibMMm1; 
        i++;
        if(i==18){
        	//Lanzamos un hilo que busque aqui
        	margs -> fib2 = fibMMm2;
        	margs -> fib1 = fibMMm1;
        	pthread_create(&id1,NULL,fibonacci,(void*)margs);
        }
    } 
    //Alcanzo los ultimos numeros, lanzamos otro hilo para que busque por alla
    margs -> fib2 = fibMMm2;
	margs -> fib1 = fibMMm1;
	pthread_create(&id2,NULL,fibonacci,(void*)margs);
	pthread_join(id1,(void*)&eid1);
  	pthread_join(id2,(void*)&eid2);

    printf("\n");
    printf("n=%i\n",n);
    printf("x=%i\n",target);
	return;
}


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