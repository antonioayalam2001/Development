// Programa Principal para ser ejecutado en Windows
// 3CM12
// Analisis de Algoritmos
// Autores: Mora Ayala Jose, Antonio, Lopez Lopez Oscar Manual
// Jeon Jeong Paola, Lemus Ruiz Mariana ELizabeth 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./Funciones/FuncionesH.c"
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
    int encontrado=-1;
    BusquedaLinealHilos(Arreglo,3,0,8,&encontrado);


    

    return 0;
}
