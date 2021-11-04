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
void printList(Listaenlazada lista);
void invertList(Listaenlazada *lista,Listaenlazada *listainvertida);
void huffmanTree();
void copyList(Listaenlazada Lista);
int crearFrecuenciastxt(Listaenlazada lista);
void binaryRoute(Listaenlazada *arbolImpresion, int pos, int bit, int izq, int der, int *auxBin);
void createBinaryList(Listaenlazada arbolImpresion, Listaenlazada *listaBinaria);
int crearCodificacionDAT(Listaenlazada listaBinaria, FILE *archivo);
int cmpchar(char cadena1, char cadena2);
int crearCodificacionDAT(Listaenlazada listaBinaria, FILE *archivo);
int crearDecodificacion(Listaenlazada arbolDeHuffman);
#endif 

