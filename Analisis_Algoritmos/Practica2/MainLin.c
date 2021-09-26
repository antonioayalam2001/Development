// Programa Principal para ser ejecutado en Windows
// 3CM12
// Analisis de Algoritmos
// Autores: Mora Ayala Jose, Antonio, Lopez Lopez Oscar Manual
// Jeon Jeong Paola, Lemus Ruiz Mariana ELizabeth

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./Funciones/FuncionesH.c"
#include "./Tiempo/tiempo.c"
// numeros = Arreglo leido
// n = tamaño del arreglo

// Tomara los argumentos que se coloquen al momento de ejecutar, en caso de ejecutar sin argumentos
// pedira que ingreses una opcion del 1 al 9 y los elementos a ordenar por defecto sera de 100 numeros

// - Activar comentarios y ya funcionara correctamente con el archivo

int main(int argc, char const *argv[])
{
    double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medición de tiempos
    int i,l,m;                                                 //Variables para loops
    // int *Arreglo;
    int n =60, opc, *A;
    //- int *Arreglo;
    int Arreglo[4] = {197, 236, 3035, 902};
    int aviso = -1;

    int j;
    A = (int *)malloc(n * sizeof(int));

    LeerArchivo(A, n);

    //- Ya funcionan lineal
    // for (m = 0; m < 4; m++)
    // {
    //     uswtime(&utime0, &stime0, &wtime0);
    //     BusquedaLineal(A,0,n, Arreglo[m], &aviso);
    //     uswtime(&utime1, &stime1, &wtime1);

    //     if (aviso > 0)
    //     {
    //         printf("Lineal %d\n",m);
    //         printf("\n");
    //         printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
    //         printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
    //         printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
    //         printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    //         printf("\n");
    //     }

    //     aviso = -1;
    // }
    // for (j = 0; j < 4; j++)
    // {
    //     uswtime(&utime0, &stime0, &wtime0);
    //     BusquedaLinealHilos(A, Arreglo[j], 0, n, &aviso);
    //     uswtime(&utime1, &stime1, &wtime1);

    //     if (aviso > 0)
    //     {
    //         printf("Lineal Hilos %d\n",j);
    //         printf("\n");
    //         printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
    //         printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
    //         printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
    //         printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    //         printf("\n");
    //     }

    //     aviso = -1;
    // }

    //!Prueba Binaria
        for (m = 0; m < 4; m++)
    {
        uswtime(&utime0, &stime0, &wtime0);
        BusquedaBinaria(A,0,n, Arreglo[m], &aviso);
        uswtime(&utime1, &stime1, &wtime1);

        if (aviso > 0)
        {
            printf("Lineal %d\n",m);
            printf("\n");
            printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
            printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
            printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
            printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
            printf("\n");
        }

        aviso = -1;
    }
    int h;
    h=0;
    //     for (h = 0; h < 4; h++)
    // {
    //     uswtime(&utime0, &stime0, &wtime0);
        BusquedaBinariaHilos(A,0,n, 3035, &aviso);
    //     uswtime(&utime1, &stime1, &wtime1);

    //     if (aviso > 0)
    //     {
    //         printf("BH %d\n",h);
    //         printf("\n");
    //         printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
    //         printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
    //         printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
    //         printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    //         printf("\n");
    //     }

    //     aviso = -1;
    // }


    return 0;
}
