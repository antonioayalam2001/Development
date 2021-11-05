#ifndef Funciones
#define Funciones
#include <stdio.h>

/**
******************************************************************************
* @file	Funciones.h
* @author 	Mora Ayala Jose Antonio
* @version 2.0
* @date October 30 2021
* @brief Archivo de cabeceras de las funciones que competen al programa principal 
******************************************************************************
*/

/* Definiciones que nos sirven para pdoer realizar el manejo de bits conforme sea requerido
    Mediante los "bitwise Operators" o bien Operadores binarios.
    Recurso proporcionado por:
    @Autor : Edgardo Adrian Franco Martinez
 */

#define PESOBIT(bpos) 1 << bpos
#define CONSULTARBIT(var, bpos) (*(unsigned *)&var & PESOBIT(bpos)) ? 1 : 0
#define PONE_1(var, bpos) *(unsigned *)&var |= PESOBIT(bpos)
#define PONE_0(var, bpos) *(unsigned *)&var &= ~(PESOBIT(bpos))
#define CAMBIA(var, bpos) *(unsigned *)&var ^= PESOBIT(bpos)

/* 
-------------------------------------------------------------------------------------------
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Struct Nodoinfo>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
DATATYPE
->int                    frec va alamacenando la frecuencia de repeticion del caracter            
->unsigned char          va almacenando el carcter en cuestion para cada uno de los nodos            
~Description   Estructura que nos proporciona la capacidad de ir alamcenando la frecuencia
                del carcater conforme esta va incrementando, así como poder almacenar el  
                caracter cuando sea necesario para cada uno de los nodos (en caso de que
                tratemos con un nodo hoja tendra un caracter, pues es el proposito del arbol
                huffman, en caso contrario se le asignara el caracter vacio) 
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Struct Nodoinfo>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------|
   */
typedef struct informacion
{
    unsigned char c;
    int frec;
    int binario[24];
} Nodoinfo;
/* 
   -------------------------------------------------------------------------------------------
   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Struct NodoLista>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
   DATATYPE
   ->Nodoinfo       Posee dentro una estructura como la descrita anteriormente para que cada
                    uno de los nodos pueda tener esos elementos dentro de su estructura                        
   ->struct Lista   Definicion de una lista de su mismo tipo para poder ir haciendo el 
                    ligamiento, aqui mismo declaramos las partes de izquierda y derecha pora
                    cada nodo de la lista y asi poder formar el arbol         
   ->DESCRIPCION: Estructura que nos proporciona la capacidad de ir alamcenando la frecuencia
                del carcater conforme esta va incrementando, así como poder almacenar el  
                caracter cuando sea necesario para cada uno de los nodos (en caso de que
                tratemos con un nodo hoja tendra un caracter, pues es el proposito del arbol
                huffman, en caso contrario se le asignara el caracter vacio) 

   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Struct Nodolista>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
   -------------------------------------------------------------------------------------------|
    */
typedef struct Lista
{
    Nodoinfo inf;
    struct Lista *sig, *izq, *der;
} Nodolista;

typedef Nodolista *Listaenlazada;
//Sin el typedef
// Nodolista *lista

Nodolista **arbol;
int tam;
int totalDeBits;

// *arbol -> Estructura lista SegundoApuntador **-> (Parte dinamica para la memoria)
//ListaEnlazada **arbol = ***arbol


//Arreglo para ir almacenando cada uno de los binarios
// int auxBin[8];
//Variable con el tamanno total de la lista enlazada
int tamanoLista;

//Variable con el tamano total de bytes del archivo de entrada
int totalDeBytes;

/* 
////////////////////////////////////////////////Prototipo de funcion fillList////////////////////////////////////////////////
Prototitpo de la función 
->Return Value : Void
->Opera con: Necesita de un lista de tipo Listaenlazada pasada por referencia y un caracter
////////////////////////////////////////////////Prototipo de funcion fillList////////////////////////////////////////////////
 */
void fillList(Listaenlazada *lista, char c);
/* 
////////////////////////////////////////////////Prototipo de funcion printList////////////////////////////////////////////////
Prototipo de la funcion : 
->Return Value : Void
->Opera con: Lista enlazada
////////////////////////////////////////////////Prototipo de funcion printList////////////////////////////////////////////////
 */
void printList(Listaenlazada lista);
/* 
////////////////////////////////////////////////Prototipo de funcion orderList////////////////////////////////////////////////
Prototipo de la funcion : 
->Return Value : Void
->Opera con: Lista enlazada pasa por referencia con el objetivo de poder ordenar los valores que encuentre dentro de esa lista 
y poder seguir siendo usada de esa forma en operaciones posteriores
////////////////////////////////////////////////Prototipo de funcion orderList////////////////////////////////////////////////
 */
void orderList(Listaenlazada *lista);
/* 
/////////////////////////////////////Prototipo de funcion huffmanTree////////////////////////////////////////////////
Prototipo de la funcion : huffmanTree
->Return Value : Void
->Opera con: nada
->Dado que durante el programa nuestro arbol de huffman fue creado de una manera global no es necesairo que reciba
uno de ese tipo y dado que hemos estado trabajando con memoria dinamica no es necesario que mandemos como
parametro alguna lista
/////////////////////////////////////Prototipo de funcion huffmanTree////////////////////////////////////////////////
 */
void huffmanTree();
/* 
////////////////////////////////////////////////Prototipo de funcion copyList////////////////////////////////////////////////
Prototitpo de la función copyList
->Return Value : Void
->Opera con: Lista enlazada
->Dada una lista que no este vacia la funcion se encargara de proceder a copiar los valores que encuentre dentro de esa lista 
en  el arbol de Huffman al cual podemos acceder dado que fue declarado de forma global 
////////////////////////////////////////////////Prototipo de funcion copyList////////////////////////////////////////////////
 */
void copyList(Listaenlazada Lista);
/* 
////////////////////////////////////////////////Prototipo de funcion frecuenciasTXT////////////////////////////////////////////////
Prototitpo de la función frecuenciasTXT
->Return Value : Int (en caso de error debemos retornar un valor)
->Opera con: Lista enlazada
-> Dado que solo nos interesa conocer los valores dentro de la lista y no modificarlos solo se pasa como parametro
////////////////////////////////////////////////Prototipo de funcion frecuenciastxtx////////////////////////////////////////////////
 */
int crearFrecuenciastxt(Listaenlazada lista);
/* 
////////////////////////////////////////////////Prototipo de funcion binaryRoute////////////////////////////////////////////////
Prototitpo de la función Ruta Binaria
->Return Value : Void
->Opera con: Listaenlazada *arbolImpresion, int pos, int bit, int izq, int der, int *auxBin
-> Realiza el recorrido en postorden de nuetro arbol de Huffman para poder ir obteniendo las codificaciones correspondientes asi
como el caracter en cuestion y la frecuencia
////////////////////////////////////////////////Prototipo de funcion binaryRoute////////////////////////////////////////////////
 */
void binaryRoute(Listaenlazada *arbolImpresion, int pos, int bit, int izq, int der, int *auxBin);
/* 
////////////////////////////////////////////////Prototipo de funcion createBinaryList////////////////////////////////////////////////
Prototitpo de la función crear Lista Binaria 
->Return Value : Void
->Opera con: Lista enlazada y una listaenlazada pasada por referencia la cual alamacenara el recorrdio binario 
////////////////////////////////////////////////Prototipo de funcion createBinaryList////////////////////////////////////////////////
 */
void createBinaryList(Listaenlazada arbolImpresion, Listaenlazada *listaBinaria);
/* 
////////////////////////////////////////////////Prototipo de funcion crearCodificacionDAT////////////////////////////////////////////////
Prototitpo de la función 
->Return Value : int 
->Opera con: Lista binaria, archivo
////////////////////////////////////////////////Prototipo de funcion crearCodificacionDAT////////////////////////////////////////////////
 */
int crearCodificacionDAT(Listaenlazada listaBinaria, FILE *archivo);
/* 
////////////////////////////////////////////////Prototipo de funcion cmpchar////////////////////////////////////////////////
Prototitpo de la función 
->Return Value : int
->Opera con: 2 cadenas dadas las cuales quieran ser sometidas a una comparacion en cunato a valores binarios 
////////////////////////////////////////////////Prototipo de funcion cmpchar////////////////////////////////////////////////
 */
int cmpchar(char cadena1, char cadena2);

/* 
////////////////////////////////////////////////Prototipo de funcion imprimirTiempos////////////////////////////////////////////////
Prototitpo de la función 
->Return Value : Void
->Opera con: Lista enlazada
////////////////////////////////////////////////Prototipo de funcion imprimirTiempos////////////////////////////////////////////////
 */
void imprimirTiempos(double utime0, double stime0, double wtime0, double utime1, double stime1, double wtime1);


#endif //Funciones.h
