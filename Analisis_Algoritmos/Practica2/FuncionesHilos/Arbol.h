#ifndef Funciones
#define Funciones


typedef struct nodo{
	int valor;
	struct nodo* derecho;
	struct nodo* izquierdo;
}Nodo;

typedef Nodo* arbol;
typedef Nodo* pos;

void Iniciar(arbol* a);
int Vacio(arbol* a);
void NuevoNodo(arbol* a, int valor);
Nodo * CreaNodo(int valor);
void RellenaInorden(arbol* a, int * arreglo);
void BuscaValor(arbol* a, int valor, int *encontrado);



#endif