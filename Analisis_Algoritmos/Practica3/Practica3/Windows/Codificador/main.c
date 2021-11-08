/**
******************************************************************************
* @file	Main.c
* @author 	Mora Ayala Jose Antonio
* @version  2.0
* @date  October 29 2021
* @brief Archivo que contiene la seccion principal del programa de Algoritmo de Huffman
******************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./Funciones.c"
#include "../Tiempo/tiempo.h"


int main(int argc, char const *argv[])
{
    double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
    FILE *archivo;                      //Archivo con el cual trabajaremos el algoritmo
    Listaenlazada lista = NULL;         //Lista enlazada para ir alamcenando cada caracter (tambien nos sirve como la estructura del arbol)
    Listaenlazada BinaryList = NULL;    //lista para ir alamcenando los binarios 
    int auxBin[8];                      //Arreglo para ir almacenando los binarios de cada caracter
    char listaCaracteres[1024];         //Arreglo para ir almacenando la cantidad de caracteres que nos enocntramos en el archivo
    int readBytes;                      //Cantidad de bytes leidos
    char c;                             //Caracter para pdoer ir realizando la obtencion y comparacion de cada uno de los caracteres en el archivo

    if (argc != 2){
        printf("Ingresa el nombre del archivo\n", argv[0]);
        exit(0);
    }
    else{
        archivo = fopen(argv[1], "rb");
    }

    do
    {
        //Guardamos en bytes leidos el tamano de bytes escaneados
        readBytes = fread(listaCaracteres, sizeof(char), 1024, archivo);

        //Guardamos el total de bytes leido cada vez para obtener el total
        totalDeBytes = totalDeBytes + readBytes;
        //Haremos esto hasta que lleguemos al final del archivo
    } while (!feof(archivo));

    printf("El total de bytes que se encontraron en el archivo son %d\n", totalDeBytes);

    // es necesario hacer uso de la funcion rewind incluida en el manejo de archivos, dado que recorrimos todo el archivo y devemos volver
    // al principio para poder comenzar nuevamente con nuestro procedimiento
    rewind(archivo);

    //  * lista -> Nodolista;

    /* 
    Realizando la obtencion de cada uno de los caracetres que nos encontramos dentro del archivo,
    situacion que sucede hasta que hayamos llegado al final del archivo
    IMPORTANTE. se debe consiedrar que la funcion fgetc al final agrega un salto de linea por lo cual
    es sumamente necesaria la consideracion de poner que el caracter debe ser distinto de menos 1, ya 
    que de no ser asi modificara el resultado de nuestro arbol de huffman y por lo tanto las ocurrencias
     */
    while (!feof(archivo))
    {
        c = fgetc(archivo);
        if (c != -1)
        {
            fillList(&lista, c);
        }
    }

    printf("Nombre del archivo: %s - Tamanno en bytes: %d\n", argv[1], totalDeBytes);


    orderList(&lista); //Ya que hemos llenando la lista procedemos a ordenarla

   	
    // imprimirTiempos(utime0, stime0, wtime0,utime1, stime1, wtime1);

    printList(lista);  //Realizmamos la impresion de la lista para asegurarnos que todo esta saliendo como deberia
    
    printf("Copiando Lista\n");
    
    copyList(lista); //Copiamos la lista dentro del arbol de Huffman el cual fue declarado de forma global
    
    printf("Lista Copiada\n");
    
    printList(lista);

    uswtime(&utime0, &stime0, &wtime0); //Inicio de contador de ordenamiento de la lista

    huffmanTree(); //Procedemos a la cracion del arbol de Huffman
    
    Listaenlazada arbolimp = arbol[0];
    
    binaryRoute(&arbolimp, -1, 0, 0, 0,auxBin); //Realizacion de un recorrido en postorden con respecto al arbol para poder realizar la obtencion de cada codigo

    createBinaryList(arbolimp, &BinaryList); //Guardamos en nuestra lista de valores binarios

    crearCodificacionDAT(BinaryList, archivo); //Realizamos la creacion de la codificacion
        if (crearFrecuenciastxt(lista) == -1)
    {
        return -1;
    } //Creamos el archivo frecuencias.txt
    uswtime(&utime1, &stime1, &wtime1); //Fin del ordenamientod e la lista
    imprimirTiempos(utime0, stime0, wtime0, utime1, stime1,  wtime1);
    fclose(archivo);

    //Liberamos la memoria de la cabeza de la lista enlazada
    free(lista);

    //liberamos la memoria de nuestro arbol de huffman de impresion
    free(arbolimp);

    //Liberamos la memoria para nuestra lista enlzada con nuestros
    //datos en binario
    free(BinaryList);

    //Imprimios este mensaje para saber que el programa se haya
    //ejecutado u terminado sin ningun problema
    printf("Fin\n");
    return 0;
}

