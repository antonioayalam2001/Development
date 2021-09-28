// 3CM12
// Analisis de Algoritmos
// Autores: Mora Ayala Jose, Antonio, Lopez Lopez Oscar Manual
// Jeon Jeong Paola, Lemus Ruiz Mariana ELizabeth
// Solo falta binaria
// Otro comentario
// Quitando comentarios
// Ultimo comentario hahahaha
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
    int i, l, m, j;                                        //Variables para loops
    // int *Arreglo;
    int n, opc, *A;
    //- int *Arreglo;
    // . Arreglo Pruebas;
    // int Arreglo[4] = {197, 236, 3035, 902};
    // .Arreglo Solicitado;
    int Arreglo[20] = {322486,14700764,3128036,6337399,61396,10393545,2147445644,1295390003,450057883,187645041,1980098116,152503,5000,1493283650,214826,1843349527,1360839354,2109248666,2147470852,0};
    // Aviso que nos servira de apoyo para saber cuando un elemento ya haya sido encontrado
    // En todos los casos cuando aviso>0 el elemento habra sido encontrado
    int aviso = -1;

    // Tomando los valores de los argumentos de ejecucion
    n=atoi(argv[1]);
    // numero=atoi(argv[2]);
    opc=atoi(argv[2]);
 


    // Asignacion de memoria del arreglo con respecto al tamaño de problema solicitado
    A = (int *)malloc(n * sizeof(int));
    // Lectura y asignacion de valores al arreglo en cuestion
    LeerArchivo(A, n);
    // Ciclo para poder proporcionar un menu de opcion y seleccionar el algoritmo deseado
    // Durante el ciclo de acuerdo a la opcion seleccionada proporcionara los resultados en caso de que el valor del
    // aviso haya cambiado 

    do
    {
        printf("Metodos de busqueda:\n");
        printf("1. Metodo de Lineal\n2.LinealHilos\n");
        printf("3. Metodo de Binario\n4.BinarioHilos\n");
        printf("5.Metodo de Exponencial\n6.ExponencialHilos\n");
        printf("7.Metodo Fibo\n8.Metodo Fibo\n");
        printf("9.Metodo de Arbol\n10.Metodo de Arbol Hilos");
        printf("Ingresa opcion:\n");
        // scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            for (m = 0; m < 20; m++)
            {
                uswtime(&utime0, &stime0, &wtime0);
                BusquedaLineal(A, 0, n, Arreglo[m], &aviso);
                uswtime(&utime1, &stime1, &wtime1);

                if (aviso > 0)
                {
                    printf("Busqueda Lineal\n");
                    printf("\n");
                    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
                    printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
                    printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
                    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
                    printf("\n");
                }

                aviso = -1;
            }

            break;
        case 2:
            for (j = 0; j < 20; j++)
            {
                uswtime(&utime0, &stime0, &wtime0);
                BusquedaLinealHilos(A, Arreglo[j], 0, n, &aviso);
                uswtime(&utime1, &stime1, &wtime1);

                if (aviso > 0)
                {
                    printf("Lineal Hilos");
                    printf("\n");
                    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
                    printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
                    printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
                    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
                    printf("\n");
                }

                aviso = -1;
            }
            break;
        case 3:
            printf("Metodo de Busqueda Binaria");
            for (m = 0; m < 20; m++)
            {
                uswtime(&utime0, &stime0, &wtime0);
                BusquedaBinaria(A, 0, n, Arreglo[m], &aviso);
                uswtime(&utime1, &stime1, &wtime1);

                if (aviso > 0)
                {
                    printf("Binaria\n");
                    printf("\n");
                    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
                    printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
                    printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
                    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
                    printf("\n");
                }

                aviso = -1;
            }
            break;
        case 4:
            printf("Metodo de Busqueda Binaria Hilos");
            int h;
            h = 0;
            for (h = 0; h < 20; h++)
            {
                uswtime(&utime0, &stime0, &wtime0);
                BusquedaBinariaHilos(A, Arreglo[h], 0, n, &aviso);
                uswtime(&utime1, &stime1, &wtime1);

                if (aviso > 0)
                {
                    printf("BH");
                    printf("\n");
                    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
                    printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
                    printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
                    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
                    printf("\n");
                }

                aviso = -1;
            }
            break;
        case 5:
            printf("Metodo de Fibo");
            for (m = 0; m < 20; m++)
            {
                uswtime(&utime0, &stime0, &wtime0);
                aviso = fibMonaccianSearch(A, Arreglo[m], n);
                uswtime(&utime1, &stime1, &wtime1);

                if (aviso > 0)
                {
                    printf("Busqueda Fibo\n");
                    printf("\n");
                    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
                    printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
                    printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
                    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
                    printf("\n");
                }

                aviso = -1;
            }
            // BusquedaEnArbol(A, n, elem,&encontrado);
            break;

        case 6:
            printf("Metodo de Arbol\n");
            for (m = 0; m < 20; m++)
            {
                uswtime(&utime0, &stime0, &wtime0);
                BusquedaEnArbol(A, n, Arreglo[m], &aviso);
                uswtime(&utime1, &stime1, &wtime1);

                if (aviso > 0)
                {
                    printf("Busqueda Arbol\n\n");
                    printf("\n");
                    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
                    printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
                    printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
                    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
                    printf("\n");
                }

                aviso = -1;
            }
            break;
            case 7:
                for (m = 0; m < 20; m++)
            {
                uswtime(&utime0, &stime0, &wtime0);
                BusquedaEnArbolHilos(A, n, Arreglo[m], &aviso);
                uswtime(&utime1, &stime1, &wtime1);

                if (aviso > 0)
                {
                    printf("Busqueda Arbol Hilos\n\n");
                    printf("\n");
                    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
                    printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
                    printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
                    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
                    printf("\n");
                }

                aviso = -1;
            }
            break;
        default:
            break;
        }
        /* code */
        opc=0;
    } while (opc != 0);

    return 0;
}
