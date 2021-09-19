// Programa Principal para ser ejecutado en Linux
// Si este archivo es visualizado desde Windows marcara un error con el include 
// de la medicion de tiempos, pues estamos ocupando funciones exclusivas de 
// Linux (Por favor pasa a mainWin)
// 3CM12
// Analisis de Algoritmos
// Autores: Mora Ayala Jose, Antonio, Lopez Lopez Oscar Manual
// Jeon Jeong Paola, Lemus Ruiz Mariana ELizabeth 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./MediciondeTiempos/tiempo.h"
// Para Linux debe ser solo con un punto
#include "./MediciondeTiempos/tiempo.c" 
#include "./Funciones/Funciones.c"
#include "./Funciones/Funciones.h"

// Tomara los argumentos que se coloquen al momento de ejecutar, en caso de ejecutar sin argumentos 
// pedira que ingreses una opcion del 1 al 9 y los elementos a ordenar por defecto sera de 100 numeros

int main(int argc, char const *argv[])
{
    int *Arreglo;
    int n,opc;
    if ((atoi(argv[1]))==0)
    {
        printf("Te faltan argumentos\n");
        printf("Ingresa una opcion: (Solo del 1 al 9)\n");
        printf("1.Burbuja\n2.BurbujaOpt\n3.BurbujaOpt2\n4.Insercion\n5.Seleccion\n6.Shell\n7.Arbol\n8.Merge\n9.Quick\n");
        scanf("%d",&opc);
        n=100;
    }
    else{
    opc=atoi(argv[1]);
    n=atoi(argv[2]);
    } 
    Arreglo = (int *)malloc(n * sizeof(int));
    LeerArchivo(Arreglo, n);
    MenuSeleccion(Arreglo, n,opc);

    return 0;
}
