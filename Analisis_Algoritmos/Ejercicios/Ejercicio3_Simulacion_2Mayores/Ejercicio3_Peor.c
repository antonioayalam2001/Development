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
    int *Arreglo, n = 10;
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
    int aux=0;
    int mayor1,mayor2,i;
    if (A[1] > A[2])
    {
        mayor1 = A[1];
        mayor2 = A[2];
        aux+=3; 
    }else
    {
        mayor1 = A[2];
        mayor2 = A[1];
        aux+=3;
    }
    i = 3;
    while (i <= n)
    {
    
        if (A[i] > mayor1)
        {
            mayor2 = mayor1;
            mayor1 = A[i];
            aux+=3;
        }
        else if (A[i] > mayor2)
        {
            mayor2 = A[i];
            aux+=2;
        }else{
            aux+=2;            
        }
        i = i + 1;
    }

    printf("%d",aux);
    return (mayor1 * mayor2);
}

int *LeerArchivo(int *A, int n)
{
    int i;
    FILE *numeros;
    numeros = fopen("peorcaso.txt", "r");
    if (numeros == NULL)
    {
        puts("Error en la apertura del archivo");
    }
    for (i = 0; i < n; i++){
        fscanf(numeros, "%d", &A[i]); }

    fclose(numeros);
}