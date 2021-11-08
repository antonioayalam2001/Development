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
    // Vairable de una lista con estructura listaenlazada como la que hemos manejado para la parte
    // de deodificacion la cual tendra en si las letras y las frecuencias en el orden 
    // que habiamos manejado
	Listaenlazada lista = NULL;

	/* Dado que hemos manejado la creaciond e la lista mediante la actualizacion de la czabeza es necesario que 
    la lista se someta a un proceso de inversion, pues basicamente la forma en que accedemos a los elemntos sera
    lo ultimo en haber sido insertado es lo primero a lo cual tendremos acceso  */
	Listaenlazada listaInvertida = NULL;

	/* Para la ejecucion del programa es necesario recibir dos argumentos como maxicmo los cuales tiene  que ver con un archivo codificado
    asi como la lista de frecuancias que le fue generada ára poder proceder a la realizacion de este progragrama de decodificacion */
	if(argc!=3){

        printf("Debes ingresar los nombres de los archivos primero el de Frecuencias.txt y posteriormente el archivo a decodificar %s\n",argv[0]);
        exit(0);    
    }else{
    	nombreArchivoFrecuencia = argv[1];
    	nombreArchivoCodificacion = argv[2];
    }

    // Procedemos a llenar la lista
    if(fillList(&lista) == -1) exit(0);

    invertList(&lista ,&listaInvertida); // Dado que tenemos una llista ya llena pasamos como parametro esa ista y la segunda lisat en la cual alamcenaremos 
    // los datos en el orden en el cual nos interesa obtenerlos para poder realizar la insercion de los bits de la forma correcta conforme vayamos leyendo
    // los bits del archivo codifcado
    printf("Lista normal\n");
    printList(lista);
    printf("Liste invertida\n");
    printList(listaInvertida); 

    copyList(listaInvertida); //Realizamos la copia de los valores de la lista que tenemos en orden logico para nosotros conforme deseamos obtener 
    // los caracteres asi como su codificacion en el arbol de Huffman
    huffmanTree(); //Creamos el arbol de Huffman
    Listaenlazada arbolImp = arbol[0]; //Asignamos el arbol en la posicion 0 a una variable de tipo listaenlzada, ya que esta posee en su estructura tambien la 
    // de la estructura de un arbol Binario
    if (crearDecodificacion(arbolImp) == -1) exit(0);    /* Ya que hemos realizado todo el procedimiento podemos proceder a realizar la creacion del archivo de 
    texto en cuestion */
    return 0;
}

