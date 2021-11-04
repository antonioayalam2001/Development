/**
******************************************************************************
* @file	Main.c
* @author 	Mora Ayala Jose Antonio
* @version  2.0
* @date  October 29 2020
* @brief Archivo que contiene la seccion principal del programa de Algoritmo de Huffman
******************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./FuncionesD.c"


int main(int argc, char const *argv[])
{
    	//Variable de la lista enlazada que tendra las letras y frecuencias
	Listaenlazada lista = NULL;

	//Variable que tendra la lista enlzada con las letras y frecuencias
	//en el orden correcto
	Listaenlazada listaInvertida = NULL;

	//Obtenemos los nombres de los archivos que fueron dados en la
	//ejecucion del programa
	if(argc!=3){

        printf("Ingresa el nombre del archivo %s\n",argv[0]);
        exit(0);    
    }else{

    	//Guardamos los nombres de los archivos de codificacion
    	//y de frecuencias en 2 variables globales
    	nombreArchivoFrecuencia = argv[1];
    	nombreArchivoCodificacion = argv[2];
    }

    if(fillList(&lista) == -1) exit(0);

    invertList(&lista ,&listaInvertida);

    printList(listaInvertida);

    copyList(listaInvertida);

    huffmanTree();

    Listaenlazada arbolImp = arbol[0];

    if (crearDecodificacion(arbolImp) == -1) exit(0);    

    return 0;
}

