/*TAD Arbol binario
ESTRUCTURAS DE DATOS 1CM7
ABRIL 2017
*/

// ComentarioDesdePc con gitHub
// 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
//Tercer Prueba con Pc


#include <stdlib.h>
#include "Arbol.h"

// *A = Arreglo de lista de numeros 
// n Longitud del arreglo
// DatoRecibido = Numeros de la lista obtenidos mediante el for

int * InsertarABB (int * A, int n)
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
	A = Inorden(Raiz,A);
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

Efecto: Recibe un arbol binario A y una posicion P, realiza el recorrido izquierdo -> raiz -> derecho a partir de la posicion P.
Requerimientos: El arbol binario A es no vacio y la posicion P es una posicion valida.
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

//PruebaComentario
//Segundo comentario
//Tercer comentario
//Cuarto Comentario
//Quinto comentario
//Sexto comentario