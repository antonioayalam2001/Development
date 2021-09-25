// Programa Principal para ser ejecutado en Windows
// 3CM12
// Analisis de Algoritmos
// Autores: Mora Ayala Jose, Antonio, Lopez Lopez Oscar Manual
// Jeon Jeong Paola, Lemus Ruiz Mariana ELizabeth 

#include "./Funciones/Funciones.c"
#include "./Funciones/FuncionesH.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// numeros = Arreglo leido
// n = tamaño del arreglo

// Tomara los argumentos que se coloquen al momento de ejecutar, en caso de ejecutar sin argumentos 
// pedira que ingreses una opcion del 1 al 9 y los elementos a ordenar por defecto sera de 100 numeros

// - Activar comentarios y ya funcionara correctamente con el archivo


int main(int argc, char const *argv[])
{
    // int *Arreglo;
    int n=10,opc;
    //- int *Arreglo;
    int Arreglo[8]={1,2,3,4,5,6,7,8};
    if ((atoi(argv[1]))==0)
    {
        printf("Te faltan argumentos\n");
        printf("Ingresa una opcion: (Solo del 1 al 5)\n");
        printf("1.Busqueda Lineal\n2.Busqueda Binaria\n3.Exponencial\n4.Fibbonacci\n5.Arbol\n");
        scanf("%d",&opc);
    }
    else{
    opc=atoi(argv[1]);
    n=atoi(argv[2]);
    } 
    //- Arreglo = (int *)malloc(n * sizeof(int));
    //- LeerArchivo(Arreglo, n);
    // -MenuSeleccion(Arreglo,n,902,opc);
    MenuSeleccion(Arreglo,n,2,opc);

    

    return 0;
}
