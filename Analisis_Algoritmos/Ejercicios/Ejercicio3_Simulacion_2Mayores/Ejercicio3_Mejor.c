//Titulo: Producto2Mayores Mejor caso
//Descripcion: Obtener de un arreglo de n numeros los 2 numeros mas grandes dentro de el
//con el promedio de operaciones basicas
//Version:1.0
//Autor:Mora Ayala Jose Antonio
//Algoritmo extraido de la plataforma eakdemy.com
//Fecha: 15 de septiembre de 2021
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Funciones que Facilitan la compresion del codigo

//////////////////////////////////////////////////////////////////////////
int Producto2Mayores(int *A, int n);
// Uso: Producto2Mayores(A,n);
// Recibe <- Un arreglo (A), cantidad de elementos en el arreglo (n)
// Devuelve -> int (producto de los 2 numeros mayores)
// Errores: No mandar los parametros adecuados, mandar un arreglo vacio
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

int *LeerArchivo(int *A, int n);
// Uso: *LeerArchivo(A,n);
// Recibe <- Un arreglo (A), Tamaño del arreglo (n)
// Devuelve -> apuntador int (Arreglo de numeros)
// Errores: No mandar los parametros adecuados, mandar un arreglo vacio

//////////////////////////////////////////////////////////////////////////
void imprimirArreglo(int *A, int n);
// Uso: Producto2Mayores(A,n);
// Recibe <- Un arreglo (A), Tamaño del arreglo (n)
// Devuelve -> Impresion de los elementos del arreglo ordenado
// Errores: No mandar los parametros adecuados, mandar un arreglo vacio
//////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
    // Declaracion de arreglo y tamaño del arreglo
    int *Arreglo, n = 4;
    // Asignacion de memoria al arreglo con el tamaño deseado
    Arreglo = (int *)malloc(n * sizeof(int));
    // Lectura del archivo con os numeros del mejor caso
    LeerArchivo(Arreglo, n);
    // Ejecucion del Algoritmo
    Producto2Mayores(Arreglo, n);

    return 0;
}

int Producto2Mayores(int *A, int n)
{
    // Variables del ciclo
    int j = 0, k = 0, i = 0;
    // Variables Algoritmo
    int repeticiones = 1000, aux = 0, promedio = 0, mayor1 = 0, mayor2 = 0;

    // Algoritmo Producto2Mayores
    for (k = 0; k < repeticiones; k++)
    {

        aux = 0;

        if (A[1] > A[2])
        {

            aux++;

            mayor1 = A[1];
            aux++;
            mayor2 = A[2];
            aux++;
        }
        else
        {

            aux++;

            mayor1 = A[2];
            aux++;
            mayor2 = A[1];
            aux++;
        }

        i = 3;

        while (i <= n)
        {

            if (mayor1 < A[i])
            {

                aux++;

                mayor2 = mayor1;
                aux++;
                mayor1 = A[i];
                aux++;
            }
            else if (A[i] > mayor2)
            {

                aux++;

                mayor2 = A[i];
                aux++;
            }

            i++;

            aux += 2;
        }

        promedio += aux;
    }

    promedio = promedio / repeticiones;

    printf("Promedio mejor caso en %d numeros: %d\n", n, promedio);
    return (mayor1 * mayor2);
}

int *LeerArchivo(int *A, int n)
{
    int i;
    FILE *numeros;
    numeros = fopen("numeros.txt", "r");
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

void imprimirArreglo(int *A, int n)
{
    int aux = 1;
    for (int i = 0; i < n; i++)
    {
        printf("%d. %d,\n ", aux, A[i]);
        aux++;
    }
}