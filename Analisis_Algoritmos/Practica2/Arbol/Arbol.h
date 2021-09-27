// #ifndef Arbol
// #define Arbol
// typedef struct nodo{
// 	int valor;
// 	struct nodo* derecho;
// 	struct nodo* izquierdo;
// }Nodo;

// typedef Nodo* arbol;
// typedef Nodo* pos;

// void Iniciar(arbol* a);
// int Vacio(arbol* a);
// void NuevoNodo(arbol* a, int valor);
// Nodo * CreaNodo(int valor);
// void RellenaInorden(arbol* a, int * arreglo);
// void BuscaValor(arbol* a, int valor, int *encontrado);

// #endif

//// Arbol Mio
#ifndef Arbol
#define Arbol
#define TRUE 1
#define FALSE 0

// Definiendo estructura del arbol
typedef struct nodo
{
	struct nodo *izq, *der;
	int dato;
}nodo;

typedef nodo* arbolBinario;

// *A = Arreglo de lista de numeros 
// n Longitud del arreglo
// DatoRecibido = Numeros de la lista obtenidos mediante el for

// Funcion devuelve un antero (Recibe un Arreglo, Recibe un dato numerico)
int * InsertarABB(int *A, int n,int valorABuscar,int *aviso);
// Inserta elementos en el arbol (Recibe un Arbol binario, Recibe un dato numerico)
void Insertar(arbolBinario **Raiz,int DatoRecibido);
// Cuando el arbol se encuentra vacio inicializa uno nuevo (Recibe un dato numerico)
arbolBinario * InicializarArbol (int numDato);
// Colocara en orden los elementos del arreglo (Recibe un arbol binario,arreglo de numeros)
int * Inorden (arbolBinario *Raiz, int *numeros);
int BusquedaArbol (arbolBinario *Raiz, int valor, int *aviso);
void Iniciar(arbolBinario* a);
void NuevoNodo(arbol* a, int valor);

#endif