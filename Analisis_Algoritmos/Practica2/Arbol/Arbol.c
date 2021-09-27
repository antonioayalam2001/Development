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

int * InsertarABB (int * A, int n,int valorABuscar,int *aviso)
{
	// Declarando raiz del arbol
	arbolBinario *Raiz;
	//Reservando memoria
	Raiz = (arbolBinario *) malloc (sizeof(arbolBinario));
	// Estableciendo la raiz como vacia 
	Raiz = NULL;
	for (int i = 0; i < n; ++i)
	// Recorriendo la lista para ir insertando cada numero en el arbol
		Insertar(&Raiz,A[i]);
		
	// A = Inorden(Raiz,A);
	//- BusquedaArbol(Raiz,902);
	// BusquedaArbol(Raiz,valorABuscar,aviso);
}

void Insertar(arbolBinario **Raiz,int DatoRecibido)
{
	//Se crea un nodo auxiliar
	arbolBinario **Auxiliar = NULL; 
	 //Se iguala el auxiliar numeros la raiz
	Auxiliar = Raiz;
	// Si no hay dato se crea un nodo nuevo
	if (*Raiz == NULL) 
		*Raiz = InicializarArbol(DatoRecibido);
	else
	{
		
		// Bucle para buscar un nodo que este vacio y poder proceder a una
		// nueva insercion de dato
		while(*Auxiliar != NULL) 
		{
			// Si el numero a ingresar es menor en Auxiliar
			if (DatoRecibido < (*Auxiliar)->dato)
			// Se va al nodo izquierdo 
				Auxiliar = &((*Auxiliar)->izq); 
				//Si el numero a ingresar es mayor en Auxiliar
			else if (DatoRecibido > (*Auxiliar)->dato) 
				Auxiliar = &((*Auxiliar)->der); //Se va al nodo derecho
		}
		// Ya se llego a la posicion adecuada, agrega el nuevo nodo
		// Cuando llegamos a la posicion donde no había dato podemos agregar 
		// el nodo nuevo (Auxiliar ya sabe si debe ir a la izquierda o derecha)
		// Gracias al if que pusimos
		*Auxiliar = InicializarArbol (DatoRecibido);
	}
}


/*

Funcion: Recibe un arbol binario Raiz y una posicion A, realiza el recorrido izquierdo -> raiz -> derecho a partir de la posicion A.
Requerimientos: El arbol binario A es no vacio y la posicion A es una posicion valida.
*/
int * Inorden (arbolBinario * Raiz, int *A)
{
	int i = 0;
	arbolBinario *Auxiliar,*Recorrido;
	Auxiliar = Raiz;
	while (Auxiliar !=NULL)
	{
		if (Auxiliar->izq == NULL)
		{
			A[i] = Auxiliar->dato;
			Auxiliar = Auxiliar->der;
			i++;
		}
		else
		{
			Recorrido = Auxiliar->izq;
			while(Recorrido->der !=NULL && Recorrido->der != Auxiliar)
				Recorrido = Recorrido->der;
			if(Recorrido->der == NULL)
			{
				Recorrido->der = Auxiliar;
				Auxiliar = Auxiliar->izq;
			}
			else
			{
				Recorrido->der = NULL;
				A[i] = Auxiliar->dato;
				Auxiliar = Auxiliar->der;
				i++;
			}
		}
	}
	return A;
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