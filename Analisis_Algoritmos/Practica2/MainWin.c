// Programa Principal para ser ejecutado en Windows
// 3CM12
// Analisis de Algoritmos
// Autores: Mora Ayala Jose, Antonio, Lopez Lopez Oscar Manual
// Jeon Jeong Paola, Lemus Ruiz Mariana ELizabeth

// #include "./Funciones/Funciones.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define min
// numeros = Arreglo leido
// n = tamaño del arreglo
int *Quicksort2(int *A, int primero, int ultimo);
int BusquedaExponencial(int *A, int n, int elem, int *aviso);
int *LeerArchivo(int *A, int n);
int binarySearch(int arr[], int, int, int);
int exponentialSearch(int arr[], int n, int x);
// Tomara los argumentos que se coloquen al momento de ejecutar, en caso de ejecutar sin argumentos
// pedira que ingreses una opcion del 1 al 9 y los elementos a ordenar por defecto sera de 100 numeros

// - Activar comentarios y ya funcionara correctamente con el archivo

int main(int argc, char const *argv[])
{

    // .Arreglo Solicitado;
    int Arreglo[20] = {322486, 14700764, 3128036, 6337399, 61396, 10393545, 214744564, 1295390003, 450057883, 187645041, 1980098116, 152503, 5000, 1493283650, 214826, 1843349527, 1360839364, 2109248666, 2147470852, 0};

    int aviso = -1;

    // Lectura y asignacion de valores al arreglo en cuestion
    Quicksort2(Arreglo, 0, 20);

    for (int i = 0; i < 20; i++)
    {
        printf("%d\n", Arreglo[i]);
    }

    int mitad = exponentialSearch(Arreglo, 20, 1493283650);
    BusquedaExponencial(Arreglo, 20, 3128036, &aviso);

    printf("El valor del aviso es %d \n", mitad);
    printf("El valor del mio es %d", aviso);

    if (aviso>0)
    {
    printf("Hola");
        /* code */
    }
    

    return 0;
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

// Returns position of first occurrence of
// x in array
int exponentialSearch(int arr[], int n, int x)
{
    // If x is present at first location itself
    if (arr[0] == x)
        return 0;

    // Find range for binary search by
    // repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i * 2;

    //  Call binary search for the found range.
    return binarySearch(arr, i / 2,
                        min(i, n - 1), x);
}

// A recursive binary search function. It returns
// location of x in  given array arr[l..r] is
// present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then it
        // can only be present n left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not present
    // in array
    return -1;
}