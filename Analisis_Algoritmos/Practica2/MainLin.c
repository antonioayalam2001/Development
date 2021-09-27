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
    int i,l,m,j;                                           //Variables para loops
    // int *Arreglo;
    int n =60, opc, *A;
    //- int *Arreglo; 
    // . Arreglo Pruebas;
    // int Arreglo[4] = {197, 236, 3035, 902};
    // .Arreglo Solicitado;
    // int Arreglo[20] = {322486,14700764,3128036,6337399,61396,10393545,214744564,1295390003,450057883,187645041,1980098116,152503,4000,1493283650,214826,1843349527,136083,2109248666,2147470852,0};
    // Bandera que nos servira de apoyo para saber cuando un elemento ya haya sido encontrado
    // En todos los casos cuando bandera>0 el elemento habra sido encontrado
    int aviso = -1;

    // Asignacion de memoria del arreglo con respecto al tamaño de problema solicitado
    A = (int *)malloc(n * sizeof(int));
    // Lectura y asignacion de valores al arreglo en cuestion
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
        for (h = 0; h < 4; h++)
    {
        uswtime(&utime0, &stime0, &wtime0);
        BusquedaBinariaHilos(A,Arreglo[h],0,n, &aviso);
        uswtime(&utime1, &stime1, &wtime1);

        if (aviso > 0)
        {
            printf("BH %d\n",h);
            printf("\n");
            printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
            printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
            printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
            printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
            printf("\n");
        }

        aviso = -1;
    }


    return 0;
}
