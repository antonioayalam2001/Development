// Programa Principal de implementacion de funciones para ser usadas en Windows
// 3CM12
// Analisis de Algoritmos
// Autores: Mora Ayala Jose, Antonio, Lopez Lopez Oscar Manual
// Jeon Jeong Paola, Lemus Ruiz Mariana ELizabeth 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "../Arbol/Arbol.h"
#include "../Arbol/Arbol.c"
#include <stdbool.h>


// Uso: LeerArchivo(int *A,int n);
// Realiza la lectura del archivo de 10 millones de numeros
// A: Arreglo de numeros no vacio (Obligatorio)
// n: Cantidad de elementos que queremos tomar (Obligatorio)
int *LeerArchivo(int *A, int n)
{
    int i;
    FILE *numeros;
    numeros = fopen("numeros10millones.txt", "r");
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


    // Uso: Burbuja(int *A,int n);
    // Realiza el ordenamiento de tipo burbuja
    //A: Arreglo de numeros no vacio (Obligatorio)
    // n: Cantidad de elementos del arreglo (Obligatorio)
void Burbuja(int *A, int n)
{
    int i, j, aux;
    for (i = 0; i < (n - 1); i++)
    {
        for (j = 0; j < (n - 1); j++)
        {
            if (A[j] > A[j + 1])
            {
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
            }
        }
    }
    imprimirArreglo(A, n);
}
    // Uso: BurbujaOptimizada(int *A,int n);
    // Realiza el ordenamiento de tipo burbuja Optimizada 1
    // A: Arreglo de numeros no vacio (Obligatorio)
    // n: Cantidad de elementos del arreglo (Obligatorio)
void BurbujaOptimizada(int *A, int n)
{
    int i, j, aux;
    for (i = 0; i < (n - 1); i++)
    {
        for (j = 0; j < (n - 1) - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
            }
        }
    }
    imprimirArreglo(A, n);
}
    // Uso: imprimeArreglo (A,n);
    // Imprime el arreglo ordenado
    // A: Arreglo de elementos no vacío (Obligatorio)
    // n: longitud del arreglo 
void Burbuja2(int *A, int n)
{
    bool cambio = true;
    int i = 1;
    int j, aux;
    while (i <= (n - 1) && cambio != false)
    {
        cambio = false;
        for (j = 0; j <= ((n - 1) - i); j++)
        {
            if (A[j + 1] < A[j])
            {
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
                cambio = true;
            }
        }
        i = i + 1;
    }
    imprimirArreglo(A, n);
}
    // Uso: Insercion(A,n);
    // Realiza el ordenamiento de tipo Insercion 
    // A: Arreglo de numeros no vacio (Obligatorio)
    // n: Cantidad de elementos del arreglo (Obligatorio)
void Insercion(int *A, int n)
{
    int i, j, temp;
    for (i = 0; i <= n - 1; i++)
    {
        j = i;
        temp = A[i];
        while ((j > 0) && (temp < A[j - 1]))
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp;
    }
    imprimirArreglo(A, n);
}
    // Uso: Selection(A,n)
    // Realiza el ordenamiento de la forma de Seleccion
    // A: Arreglo de numeros no vacio (Obligatorio)
    // n: Cantidad de elementos del arreglo (Obligatorio)
void Selection(int *A, int n)
{
    int i, k, p, temp;
    for (k = 0; k < (n - 1); k++)
    {
        p = k;
        for (i = k + 1; i < (n); i++)
        {
            if (A[i] < A[p])
                p = i;
        }
        temp = A[p];
        A[p] = A[k];
        A[k] = temp;
    }
    imprimirArreglo(A, n);
}
    // Uso: Shell(A,n);
    // Realiza el ordenamiento de Tipo Shell
    // A: Arreglo de elementos no vacío (Obligatorio)
    // n: longitud del arreglo 
void Shell(int *A, int n)
{
    int i, j, k, b, temp;
    k = ceil(n / 2);
    while (k >= 1)
    {
        b = 1;
        while (b != 0)
        {
            b = 0;
            for (i = k; i <= n - 1; i++)
            {
                if (A[i - k] > A[i])
                {
                    temp = A[i];
                    A[i] = A[i - k];
                    A[i - k] = temp;
                    b = b + 1;
                }
            }
        }
        k = ceil(k / 2);
    }
    imprimirArreglo(A, n);
}

int parteEntera(double n)
{
    double entero = floor(n);
    return (int)entero;
}
    // Uso: MergeSort(A,0,n-1)
    // Realiza el ordenamiento de elementos de forma recursiva 
    // A: Arreglo de elementos no vacio
    // p : Primera posicion 
    // r = n-1 (tamaño del arreglo menos una posicion, por la forma en que se indexa) 
void MergeSort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = parteEntera((p + r) / 2);
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}
    // A: Arreglo de elementos no vacio
    // p: posicion del primer elemento
    // q: Parte entera obtenida a partir de la division de p/r realizada en la implementacion de la funcion
    // r: ultima posicion 
void Merge(int *A, int p, int q, int r)
{
    int l = r - p + 1, i = p, j = q + 1, k, *C;
    C = malloc(sizeof(int *) * l);

    for (k = 0; k <= l; k++)
    {
        if (i <= q && j <= r)
        {
            if (A[i] < A[j])
            {
                C[k] = A[i];
                i++;
            }
            else
            {
                C[k] = A[j];
                j++;
            }
        }
        else if (i <= q)
        {
            C[k] = A[i];
            i++;
        }
        else
        {
            C[k] = A[j];
            j++;
        }
    }
    for (i = p, j = 0; i <= r; i++, j++)
    {
        A[i] = C[j];
    }
    free(C);
}
    // Uso: QuickSort2(A,0,n-1) 
    // Realiza el ordenamiento mediante QuickSort, el cual funciona de manera recursiva, recibe un arreglo
    // no vacio, asi como la cantidad de elementos que contiene -1 (debido a que buscamos obtener la
    // utlima posicion)
    // A: Arreglo de elementos no vacio
    // i  (primer elemento) con respecto al cual queremos realizar el ordenamiento (en este caso 0)
    // n -1 : Tamaño del arreglo - 1
void Quicksort2(int *A, int primero, int ultimo)
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
    // Recibe un arreglo y tamaño del arreglo

void ArbolBinario(int *A, int n)
{
    A = InsertarABB(A, n);
    imprimirArreglo(A, n);
}

// Permite realizar la seleccion de alguno de los algoritmos conforme al parametro que fue 
// seleccionado al momento de ejecutar el programa 
void MenuSeleccion(int *A, int n, int opc)
{
    switch (opc)
    {
    case 1:
        puts("Metodo de Burbuja");
        Burbuja(A, n);
        break;
    case 2:
        puts("Metodo de Burbuja Optimizada 1");
        BurbujaOptimizada(A, n);
        break;
    case 3:
        puts("Metodo de Burbuja Optimizada 2\n");
        Burbuja2(A, n);
        break;
    case 4:
        puts("Metodo de Insercion");
        Insercion(A, n);
        break;
    case 5:
        printf("Metodo de Seleccion\n");
        Selection(A, n);
        break;
    case 6:
        puts("Metodo de Shell");
        Shell(A, n);
        break;
    case 7:
        puts("Ordenamiento basado en ABB");
        ArbolBinario(A, n);
        break;
    case 8:
        puts("Metodo de MergeSort");
        MergeSort(A, 0, n - 1);
        imprimirArreglo(A, n);
        break;
    case 9:
        puts("Metodo de QuickSort");
        Quicksort2(A, 0, n - 1);
        imprimirArreglo(A, n);
        break;
    default:
        break;
    }
}
    // Uso: imprimeArreglo (A,n);
    // Imprime el arreglo ordenado
    // A: Arreglo de elementos no vacío (Obligatorio)
    // n: longitud del arreglo 
void imprimirArreglo(int *A, int n)
{
    int aux = 1;
    for (int i = 0; i < n; i++)
    {
        printf("%d. %d,\n ", aux, A[i]);
        aux++;
    }
}