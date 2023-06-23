//Titulo: Producto2Mayores caso Medio
//Descripcion: Obtener de un arreglo de n numeros los 2 numeros mas grandes dentro de el
//con el promedio de operaciones basicas
//Version:1.0
//Autor:Mora Ayala Jose Antonio
// Algoritmo extraido de la plataforma eakdemy.com
//Fecha: 15 de septiembre de 2021
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//////////////////////////////////////////////////////////////////////////
int Producto2Mayores(int *A, int n);
// Uso: Producto2Mayores(A,n);
// Recibe <- Un arreglo (A), cantidad de elementos en el arreglo (n)
// Devuelve -> int (producto de los 2 numeros mayores)
// Errores: No mandar los parametros adecuados, mandar un arreglo vacio
//////////////////////////////////////////////////////////////////////////

void srand(unsigned int semilla);


int main(int argc, char const *argv[])
{
    // Declaracion de arreglo y tamaño del arreglo
    int *Arreglo, n = 2500;
    // Asignacion de memoria al arreglo con el tamaño deseado
    Arreglo = (int *)malloc(n * sizeof(int));
    // Ejecucion del Algoritmo
    Producto2Mayores(Arreglo, n);

    return 0;
}

int Producto2Mayores(int *A, int n)
{
    // Variables de Ciclos
    int i,k,j, repeticiones = 10000;
    // Variables Algoritmo
    int  mayor1, mayor2,aux,promedio = 0;
    srand(time(NULL));
    for (k = 0; k < repeticiones; k++)
    {
        aux = 0;
        for (j = 0; j < n; j++)
        {
            A[j] = 10000 + rand() % (30001 + 10000);
        }
        if (A[1] > A[2])
        {
            mayor1 = A[1];
            mayor2 = A[2];
            aux += 3; //operaciones Comparacion + 2 asignaciones
        }else
        {
            mayor1 = A[2];
            mayor2 = A[1];
            aux += 3; //operaciones Comparacion + 2 asignaciones
        }
        i = 3;
        while (i <= n)
        {
            if (A[i] > mayor1)
            {
                mayor2 = mayor1;
                mayor1 = A[i];
                aux += 3; //operaciones Comparacion + 2 asignaciones
            }
            else if (A[i] > mayor2)
            {
                mayor2 = A[i];
                aux += 2; //2 operaciones Comparacion + 1 asignaciones
            }
            else
            {
                aux += 2; //2 operaciones Comparacion en falso
            }
            i = i + 1;
        }
        promedio += aux; //Llevando la cuenta del contador al termino de cada ideracion en el ciclo
    }
    promedio = promedio / repeticiones;
    printf("%d", promedio);
    return (mayor1 * mayor2);
}