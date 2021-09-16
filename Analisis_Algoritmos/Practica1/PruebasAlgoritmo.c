#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./MediciondeTiempos/tiempo.h"
// Para Linux debe ser solo con un punto
#include "./MediciondeTiempos/tiempo.c" 
#include "./Funciones/Funciones.c"
#include "./Funciones/Funciones.h"
// numeros = Arreglo leido
// n = tamaño del arreglo

int main(int argc, char const *argv[])
{
    int *Arreglo;
    int i, n,opc;
    printf("Realizaste la seleccion de: ");
    opc=atoi(argv[1]);
    n=atoi(argv[2]);
    Arreglo = (int *)malloc(n * sizeof(int));
    LeerArchivo(Arreglo, n);
    MenuSeleccion(Arreglo, n,opc);

    return 0;
}

