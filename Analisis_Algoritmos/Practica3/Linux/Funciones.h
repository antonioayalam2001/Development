#ifndef Funciones
#define Funciones
#include <stdio.h>
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
    int binario[16];
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

   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Struct Nodoinfo>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
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

// *arbol -> Estructura lista SegundoApuntador **-> (Parte dinamica para la memoria)
//ListaEnlazada **arbol = ***arbol


//Arreglo para ir almacenando cada uno de los binarios
// int auxBin[8];
//Variable con el tamanno total de la lista enlazada
int tamanoLista;

//Variable con el tamano total de bytes del archivo de entrada
int totalDeBytes;
int totalDeBits;

void fillList(Listaenlazada *lista, char c);
void printList(Listaenlazada lista);
void orderList(Listaenlazada *lista);
void huffmanTree();
void copyList(Listaenlazada Lista);
int crearFrecuenciastxt(Listaenlazada lista);
void binaryRoute(Listaenlazada *arbolImpresion, int pos, int bit, int izq, int der, int *auxBin);
void createBinaryList(Listaenlazada arbolImpresion, Listaenlazada *listaBinaria);
int crearCodificacionDAT(Listaenlazada listaBinaria, FILE *archivo);
int cmpchar(char cadena1, char cadena2);
int crearCodificacionDAT(Listaenlazada listaBinaria, FILE *archivo);
void imprimirTiempos(double utime0, double stime0, double wtime0, double utime1, double stime1, double wtime1);

#endif //Funciones.h
