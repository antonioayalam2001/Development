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
    int n=100,opc,*A;
    //- int *Arreglo;
    int Arreglo[10]={1,2,3,4,5,6,7,8,9,10};
    int aviso= -1;

    // !Tratando de leer el archivo
    A=(int*)malloc(n*sizeof(int));

    LeerArchivo(A, 100);
    BusquedaLinealHilos(A,11560,0,n,&aviso);


    // !

    // - Pruebas normales funcionando 
    // BusquedaLinealHilos(Arreglo,7,0,n,&aviso);
    // if (aviso>0)
    // {
    //         printf("Si lo encontre");
    // }
    //         printf("Si lo encontre %d",aviso);
    


    

    return 0;
}
