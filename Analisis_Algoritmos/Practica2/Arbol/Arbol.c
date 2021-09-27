// #include "Arbol.h"
// #include <stdlib.h>
// #include <stdio.h>

// int arrayIndex = 0;

// /*
//  * Función encargada de iniciar el apuntado a arbol
//  *
//  * */
// void Iniciar(arbol* a){
// 	*a = NULL;
// 	return;
// }

// /*
//  * Función que determina si un arbol está vacío
//  * Regresa 1 en caso de que esté vacío y 0 en otro caso
//  *
//  * */
// int Vacio(arbol* a){
// 	if(*a == NULL)
// 	{
// 		return 1;
// 	}
// 	else 
// 	{
// 		return 0;
// 	}
// }

// /*
//  * Función encargada de insertar nuevos nodos
//  * al arbol, recursivamente
//  *
//  * */
// void NuevoNodo(arbol* a, int valor){
// 	// Si el árbol está vacío, crea un nodo en la raíz
// 	if(Vacio(a) == 1)
// 	{
// 		*a = CreaNodo(valor);
// 	}
// 	else
// 	{
// 		// Determinamos hacia donde hay que mover
// 		// la posición
// 		if((*a)->valor < valor)
// 		{
// 			// Llamamos nuevamente a esta función
// 			// pero ahora con la nueva ubicación
// 			NuevoNodo(&((*a)->derecho),valor);
// 		}
// 		else	
// 		{
// 			// Llamamos nuevamente a esta función
// 			// pero ahora con la nueva ubicación
// 			NuevoNodo(&((*a)->izquierdo),valor);
// 		}
// 	}
// 	return;
// }

// /*
//  * Función encargada de crear un nuevo nodo con el valor
//  * enviado en el parámetro
//  *
//  * */
// Nodo * CreaNodo(int valor){
// 	Nodo * aux = (Nodo *)malloc(sizeof(Nodo));
// 	aux->valor = valor;
// 	aux->derecho = NULL;
// 	aux->izquierdo = NULL;
// 	return aux;
// }

// /*
//  * Función encargada de rellenar un arreglo mediante 
//  * la lectura InOrder del arbol
//  *
//  * */
// void RellenaInorden(arbol* a, int * arreglo)
// {
// 	// Comprobamos que no esté vacío
// 	if(Vacio(a) != 1)
// 	{
// 		// Nos movemos a la izquierda y llamamos a la función nuevamente
// 		RellenaInorden(&((*a)->izquierdo),arreglo);
// 		// Aumentamos el índice y almacenamos el valor en el arreglo
// 		arreglo[arrayIndex++] = (*a)->valor;
// 		// Nos movemos a la derecha y llamamos a la función nuevamente
// 		RellenaInorden(&((*a)->derecho),arreglo);		
// 	}
// 	return;
// }

// /*
//  * Función que busca iterativamente un valor dentro
//  * de un árbol dado
//  * Parámetros:
//  *	a - el árbol en el que se desea buscar
//  *	valor - el valor a buscar dentro del árbol
//  *	encontrado - nos indicará si el valor fue encontrado
//  * */
// void BuscaValor(arbol* a, int valor, int *encontrado)
// {
// 	// Empleamos un auxiliar para no perder la raíz
// 	// de nuestro árbol
// 	arbol * sub = a;
// 	int x = 0;
// 	// Mientras existan nodos y no se haya encontrado el valor
// 	while(Vacio(sub) != 1 && *encontrado == -1)
// 	{
// 		// Si el nodo en el que estamos contiene el valor
// 		// significa que fue encontrado
// 		if((*sub)->valor == valor)
// 		{
// 			*encontrado = valor;
//             printf("Si encontramos el valor we en %d",valor);
// 			break;
// 		}
// 		else if((*sub)->valor < valor)
// 		{
// 			// Si el valor que buscamos es mayor
// 			// al del nodo en el que nos encontramos
// 			// nos movemos a la derecha
// 			sub = &((*sub)->derecho);
// 		}		
// 		else if((*sub)->valor > valor)
// 		{
// 			// Si el valor que buscamos es menor
// 			// al del nodo en el que nos encontramos
// 			// nos movemos a la izquierda
// 			sub = &((*sub)->izquierdo);
// 		}	
// 	}
// 	return;
// }

//// Arbol Mio
// Arbol de Busqueda Binaria
// Analisis de Algoritmos
// Autores: Mora Ayala Jose, Antonio, 
// 3CM12
#include <stdlib.h>
#include "Arbol.h"

// *A = Arreglo de lista de numeros 
// n Longitud del arreglo
// DatoRecibido = Numeros de la lista obtenidos mediante el for

void Iniciar(arbolBinario* a){
	*a = NULL;
	return;
}




void NuevoNodo(arbolBinario* a, int valor){
	// Si el árbol está vacío, crea un nodo en la raíz
	if(Vacio(a) == 1)
	{
		*a = CreaNodo(valor);
	}
	else
	{
		// Determinamos hacia donde hay que mover
		// la posición
		if((*a)->valor < valor)
		{
			// Llamamos nuevamente a esta función
			// pero ahora con la nueva ubicación
			NuevoNodo(&((*a)->derecho),valor);
		}
		else	
		{
			// Llamamos nuevamente a esta función
			// pero ahora con la nueva ubicación
			NuevoNodo(&((*a)->izquierdo),valor);
		}
	}
	return;
}




int BusquedaArbol(arbolBinario *Raiz, int valor,int *aviso){
	arbolBinario *aux = Raiz;
	int x=0;
			// printf("Ya fue encontrado");

	while (aux!=NULL)
	{
		if ((aux->dato) == valor)
		{
			*aviso=1;
			break;
		}
		else if ((aux->dato) < valor){
			aux=((aux->der));
		}
		else if ((aux->dato) > valor){
			aux=((aux->izq));
		}
		
	}
	


}


// Inicializa un arbol, reservando memoria y asignando primer elemento a Dato
// 									Recibe un dato
// arbolbinario * IniciarlizarAtblo (int NumDato)
arbolBinario * InicializarArbol (int numDato)
{
	arbolBinario *A = malloc(sizeof(nodo)); 
	// Asignando el DatoRecibido a dato del aebol
	A->dato= numDato;
	//Sin nodo izquierdo
	A->izq=NULL; 
	//Sin nodo derecho 
	A->der=NULL; 
	// Regresamos el Arreglo
	return A;
}