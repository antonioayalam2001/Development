#define TRUE 1
#define FALSE 0

// Definiendo estructura del arbol
typedef struct nodo
{
	struct nodo *izq, *der;
	int dato;
}nodo;

typedef nodo arbolBinario;

// *A = Arreglo de lista de numeros 
// n Longitud del arreglo
// DatoRecibido = Numeros de la lista obtenidos mediante el for

int * InsertarABB(int *A, int n);
void Insertar(arbolBinario **Raiz,int DatoRecibido);
arbolBinario * InicializarArbol (int numDato);
int * Inorden (arbolBinario *Raiz, int *numeros);