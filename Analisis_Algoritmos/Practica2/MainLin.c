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

int main(int argc, char const *argv[])
{
    double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medición de tiempos
    int i, l, m, j;                                        //Variables para loops
    int n, opc, *A,hilos;                                        //Variables de : (tamaño de problema), (opcion), (Arreglo dinamico) respectivamente
    int Arreglo[20] = {322486, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644, 1295390003, 450057883, 187645041, 1980098116, 152503, 5000, 7500, 214826, 1843349527, 1321906174, 2109248666, 2147470852, 0};
    // Aviso que nos servira de apoyo para saber cuando un elemento ya haya sido encontrado
    // En todos los casos cuando aviso>0 el elemento habra sido encontrado
    int aviso = -1;
    // Tomando los valores de los argumentos de ejecucion
    if (argv[1]==NULL || argv[2]==NULL || argv[3]==NULL)
    {
        printf("Debes ingresar un valor para n, un numero para eleccion de algoritmo y una cantidad de hilos:\n");
        printf("./MainLin (n) (Algoritmo) (Hilos)\n");
        printf("Si eliges la opcion 2 o 4 ingresa una cantidad distinta a 0 en el tercer argumento\n");
    }else{

        n = atoi(argv[1]);
        // numero=atoi(argv[2]);
        opc = atoi(argv[2]);
        hilos = atoi(argv[3]);
        // Asignacion de memoria del arreglo con respecto al tamaño de problema solicitado
        A = (int *)malloc(n * sizeof(int));
        // Lectura y asignacion de valores al arreglo en cuestion
        LeerArchivo(A, n);
        //Implementacion de un Algoritmo de Ordenamiento para ir evaluando la busqueda del arreglo de forma ordenada y facilitar recoleccion de datos
        Quicksort2(Arreglo, 0, 20);
    }

    // Ciclo para poder proporcionar un menu de opcion y seleccionar el algoritmo deseado
    // Durante el ciclo de acuerdo a la opcion seleccionada proporcionara los resultados en caso de que el valor del
    // aviso haya cambiado
    do
    {
        printf("///////////////Valor de n %d////////////////////\n\n", n);
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
                    printf("Busqueda Lineal numero: %d\n", Arreglo[m]);
                    printf("real:%.10e s\n", wtime1 - wtime0);
                    printf("\n");
                }
                else
                {
                    printf("NoE: %d\n", Arreglo[m]);
                    printf("real  %.10e s\n", wtime1 - wtime0);
                    printf("\n");
                }

                aviso = -1;
            }

            break;
        case 2:
        printf("BusquedaLinealHilos\n");
        printf("La cantidad de hilos es: %d\n",hilos);
            for (j = 0; j < 20; j++)
            {
                uswtime(&utime0, &stime0, &wtime0);
                BusquedaLinealHilos(A, Arreglo[j], 0, n, &aviso,hilos);
                uswtime(&utime1, &stime1, &wtime1);

                if (aviso > 0)
                {
                    printf("Lineal Hilos %d\n", Arreglo[j]);
                    printf("real %.10e s\n", wtime1 - wtime0);
                    printf("\n");
                }
                else
                {
                    printf("NoE: %d\n", Arreglo[j]);
                    printf("real %.10e s\n", wtime1 - wtime0);
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
                    printf("Binaria%d\n", Arreglo[m]);
                    printf("real %.10e s\n", wtime1 - wtime0);
                    printf("\n");
                }
                else
                {
                    printf("NoE: %d\n", Arreglo[m]);
                    printf("real %.10e s\n", wtime1 - wtime0);
                    printf("\n");
                }

                aviso = -1;
            }
            break;
        case 4:
            printf("Metodo de Busqueda Binaria Hilos\n");
            printf("La cantidad de hilos es: %d\n",hilos);
            int h;
            h = 0;
            for (h = 0; h < 20; h++)
            {
                uswtime(&utime0, &stime0, &wtime0);
                BusquedaBinariaHilos(A, Arreglo[h], 0, n, &aviso,hilos);
                uswtime(&utime1, &stime1, &wtime1);

                if (aviso > 0)
                {
                    printf("BH: %d\n", Arreglo[h]);
                    printf("real %.10e s\n", wtime1 - wtime0);
                    printf("\n");
                }
                else
                {
                    printf("NoE: %d\n", Arreglo[h]);
                    printf("real %.10e s\n", wtime1 - wtime0);
                    printf("\n");
                }

                aviso = -1;
            }
            break;
        case 5:
            printf("Metodo de Fibo\n");
            for (m = 0; m < 20; m++)
            {
                uswtime(&utime0, &stime0, &wtime0);
                aviso = fibMonaccianSearch(A, Arreglo[m], n);
                uswtime(&utime1, &stime1, &wtime1);

                if (aviso > 0)
                {
                    printf("Busqueda Fibo %d\n", Arreglo[m]);
                    printf("real %.10e s\n", wtime1 - wtime0);
                    printf("\n");
                }
                else
                {
                    printf("NoE: %d\n", Arreglo[m]);
                    printf("real  %.10e s\n", wtime1 - wtime0);
                    printf("\n");
                }

                aviso = -1;
            }
            // BusquedaEnArbol(A, n, elem,&encontrado);
            break;

        case 6:
            printf("Metodo de Arbol \n");
            for (m = 0; m < 20; m++)
            {
                uswtime(&utime0, &stime0, &wtime0);
                BusquedaEnArbol(A, n, Arreglo[m], &aviso);
                uswtime(&utime1, &stime1, &wtime1);

                if (aviso > 0)
                {
                    printf("Busqueda Arbol elemento : %d\n", Arreglo[m]);
                    printf("real %.10e s\n", wtime1 - wtime0);
                    printf("\n");
                }
                else
                {
                    printf("NoE: %d\n", Arreglo[m]);
                    printf("real %.10e s\n", wtime1 - wtime0);
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
                    printf("Busqueda Arbol Hilos elemento: %d\n", Arreglo[m]);
                    printf("real %.10e s\n", wtime1 - wtime0);
                    printf("\n");
                }
                else
                {
                    printf("NoE: %d\n", Arreglo[m]);
                    printf("real %.10e s\n", wtime1 - wtime0);
                    printf("\n");
                }

                aviso = -1;
            }
            break;
        case 8:
            for (m = 0; m < 20; m++)
            {
                uswtime(&utime0, &stime0, &wtime0);
                BusquedaExponencial(A, n, Arreglo[m], &aviso);
                uswtime(&utime1, &stime1, &wtime1);

                if (aviso > 0)
                {
                    printf("Busqueda Exponencial: %d ", Arreglo[m]);
                    printf("real %.10e s\n", wtime1 - wtime0);
                    printf("\n");
                }
                else
                {
                    printf("NoE: %d ", Arreglo[m]);
                    printf("real %.10e s\n", wtime1 - wtime0);
                    printf("\n");
                }

                aviso = -1;
            }
            break;

        default:
            break;
        }
        opc = 0;
    } while (opc != 0);

    return 0;
}
