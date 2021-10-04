// 3CM12
// Analisis de Algoritmos
// Autores: Mora Ayala Jose, Antonio, Lopez Lopez Oscar Manual
// Jeon Jeong Paola, Lemus Ruiz Mariana ELizabeth
//Fecha de Creacion 01/10/21 (Actualizacion de arbol agregando BuscaValor)
// Version 1.3
// Algoritmo de Busqueda por algoritmo exponencial con la implementacion de hilos 
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