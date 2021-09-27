// Archivo de cabecera de las funciones
// 3CM12
// Analisis de Algoritmos
// Autores: Mora Ayala Jose, Antonio, Lopez Lopez Oscar Manual
// Jeon Jeong Paola, Lemus Ruiz Mariana ELizabeth 
#include "Funciones.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<math.h>
#include "../Arbol/Arbol.c"
// //          Busqueda Lineal           // //
// //Recibe:
// //Devuelve:
// //Funcion:
// //Uso:
// //
int BusquedaLineal(int *A, int n, int elem){
    //- Variables para el ciclo
    int i;
    for (i = 0; i < n; i++)
    {
        if(A[i]==elem){
            printf("El elemento fue encontrado en la posicion numero: %d ", i);
        };
    }    
}
// //          Busqueda Binaria           // //
// //
// //
// //
// //
// //
int BusquedaBinaria(int *A,int n,int elem){
    // -Variables para algoritmo de busqueda
    int inicio,final,mitad;
    inicio=0;
    final=n-1;    
    while (inicio<=final)
    {
        mitad=(inicio + final)/2;
        if (A[mitad]==elem)
        {
            printf("Enontraste el emento en la posicion: %d",mitad);
            return mitad;
        }
        if (A[mitad]<elem)
            {inicio=mitad;}
        else{final=mitad;}        
        
    }    
}

// //          Busqueda Exponencial           // //
// //
// //
// //
// //
// //
int BusquedaExponencial(int *A, int n, int elem){
        // -Variables para algoritmo de busqueda
    int inicio,final,mitad,i;

    inicio=i;
    final=n-1;    
    while (i<final && A[i]!=elem)
    {
        i=i*2;
    }
    printf("%d",i);
        mitad=((i/2) + final)/2;
        if (A[mitad]==elem)
        {
            printf("Enontraste el elemento en la posicion: %d",mitad);
            return mitad;
        }
        if (A[mitad]<elem)
            {inicio=mitad;}
        else{final=mitad;}  
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
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
 
    //Nos marca el rango de la izquierda donde no se encuentra el elemento deseado
    int offset = -1;
 

    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);
 
        //Si el elemento es mayor al valor del índice, 
        //Lo valores se irán recorriendo y el "offset" 
        //se cambiará al valor del índice,
        if (A[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
 
        //Si el elemento es mayor a la posición del arreglo en la posiciónde fibMm2
        //el arreglo se dividirá después de la posición i+1
        else if (A[i] > x) {
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
 
// //          Busqueda Meadiante Arbol ABB           // //
// //
// //
// //
// //
// //
// void BusquedaEnArbol(int * arreglo, int n, int valorABuscar, int * bandera)
// {
// 	// Variable para "almacenar" el árbol
// 	arbol t;
// 	// Creamos nuestro árbols
// 	Iniciar(&t);
// 	// Rellenamos el arbol
// 	int ix;
// 	for(ix=0;ix < n; ix++)
// 	{
// 		NuevoNodo(&t,arreglo[ix]);
// 	}
// 	// Lanzamos la búsqueda sin hilos
// 	BuscaValor(&t, valorABuscar, bandera);
// }





// . Menu de seleccion
void MenuSeleccion(int *A, int n, int elem ,int opc)
{
    int encontrado=-1;
    switch (opc)
    {
    case 1:
        puts("Metodo de Lineal");
        BusquedaLineal(A, n, elem);
        break;
    case 2:
        puts("Metodo de Busqueda Binaria");
        BusquedaBinaria(A, n, elem);
        break;
    case 3:
        puts("Metodo de Busqueda Exponencial");
        BusquedaBinaria(A, n, elem);
        break;
    case 4:
        puts("Metodo de Busqueda Fibbonacci");
        int res=fibMonaccianSearch(A, elem, n);
        printf("%d",res);
        break;
    case 5:
        puts("Metodo de Busqueda Arbol");
        // BusquedaEnArbol(A, n, elem,&encontrado);
        A=InsertarABB(A,n);
        break;

    default:
        break;
    }
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