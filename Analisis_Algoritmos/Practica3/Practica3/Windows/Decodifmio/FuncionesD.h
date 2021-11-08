#ifndef FuncionesD
#define FuncionesD

#define PESOBIT(bpos) 1 << bpos
#define CONSULTARBIT(var, bpos) (*(unsigned *)&var & PESOBIT(bpos)) ? 1 : 0
#define PONE_1(var, bpos) *(unsigned *)&var |= PESOBIT(bpos)
#define PONE_0(var, bpos) *(unsigned *)&var &= ~(PESOBIT(bpos))
#define CAMBIA(var, bpos) *(unsigned *)&var ^= PESOBIT(bpos)

typedef struct informacion
{
    unsigned char c;
    int frec;
    int binario[16];
} Nodoinfo;


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

char *nombreArchivoFrecuencia;

//Variable que tendra el nombre del archivo de codificacion
char *nombreArchivoCodificacion;

//Declaramos variables que almacenaran el tipo de archivo y el nombre
//que tendra el archivo decode
char *cadenaPrueba;

//Declaramos la variable que tendra el valor escaneado en modo texto
char *cadenaValor;

//Variable que tendra el valor del numero de bits de tipo entero
int valorBits;

//Declaramos variable para el tamano de la lista enlazada
int tamanoLista;


int fillList(Listaenlazada *lista);

/* 
-------------------------------------------------------------------------------------------------
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function printList>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PARAMETROS
-> Listaenlazada: Recibe una listaEnlazada al momento de ser invocada 
->       
~DESCRIPCION: Funcion que nos ayuda a realizar la impresion de la lista 
USO: printList(lista)         
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function printList>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------------|
*/
void printList(Listaenlazada lista);

/* 
-------------------------------------------------------------------------------------------
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function invertList>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PARAMETROS
-> Listaenlazada Recibe una listaEnlazada al momento de ser invocada 
->       
~DESCRIPCION: Funcion para realizar la inversion de una lista que se le haya mandado 
USO:         preorder (Listaenlazada arbolImpresion);
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Struct invertList>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------|
*/

void invertList(Listaenlazada *lista,Listaenlazada *listainvertida);

/* 
   ---------------------------------------------------------------------------------------
   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function HuffmanTree>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
   PARAMETROS
   ->  
   ~DESCRIPCION: Funcion que realiza la creacion de un arbol huffman asignano frecuencias y las hojas
                conforme la lista de frecuencias que previmante ya tuvo que haber sido sometida a un ordenamiento
                previo.
   USO:         huffmanTree();
   RETURN:      Vacio ya que estamos utilizando memoria dinamica dentro del programa
   ---------------------------------------------------------------------------------------
    */

void huffmanTree();

/* 
-------------------------------------------------------------------------------------------------
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function copyList>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PARAMETROS
-> Listaenlazada: Recibe una listaEnlazada al momento de ser invocada (la lista no debe estar
vacia) para poder realizar 

~DESCRIPCION: La funcion realiza la asignacion de valores de forma correcta al arbol de Huffman
Recordemos que el arbol de huffman fue declarado de forma global para poder realizar la 
manipulacion de apuntadores de una forma mas sencilla
USO: copyList (lista)
//No mandamos por referencia dado que no nocesitamos modificar ninguno de los valores que 
se encuentran dentro de nuestra lista ya ordenada         
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function copyList>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------------|
*/

void copyList(Listaenlazada Lista);

/* 
-------------------------------------------------------------------------------------------------
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function ordenarLista>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PARAMETROS
-> Listaenlazada: Recibe una listaEnlazada al momento de ser invocada 
->       
~DESCRIPCION: 
USO:         
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function ordenarLista>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------------|
*/
int cmpchar(char cadena1, char cadena2);

/* 
-------------------------------------------------------------------------------------------------
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function crearDecodificacion>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PARAMETROS
-> Listaenlazada: Arbol de Fuffman
->       
~DESCRIPCION: Funcion que realiza la decodificacion del archivo en cuestion
al cual se accede ya que esta almacenado en una variable declarada globarlemnete,
el procedimiento se hace mediante la evaluacion de los bits recibidos
y la consulta de los códigocs obtenidos gracias a las listas que creamos
USO:         
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function crearDecodificacion (Listaenlazada arbolDeHuffman)>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------------|
*/
int crearDecodificacion(Listaenlazada arbolDeHuffman);
#endif 

