#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct datos{
	char letra;
	int frecuencia;
}NodoDatos;

typedef struct lista{
	NodoDatos data;
	struct lista *siguiente;
}NodoLista;

typedef NodoLista *ListaEnlazada;

typedef struct arbol{
	NodoDatos data;
	struct arbol *izquierda;
	struct arbol *derecha;	
}NodoArbol;

NodoArbol **arbol;

typedef NodoArbol *arbolHUFFMAN;

int tamanoLista;

void crearLista(ListaEnlazada *lista, char caracteres[], int bytes);

void completarlista(ListaEnlazada *lista, char caracter);

void ordenarLista(ListaEnlazada *lista);

void imprimirLista(ListaEnlazada lista);

void copiarLista(ListaEnlazada lista);

void crearArbolHuffman();

void preorden(arbolHUFFMAN arbolImpresion);

int main(int argc, char const *argv[]){

	char listaDeCaracteres[1024];

	int bytesLeidos;

	FILE *archivo = NULL;

	ListaEnlazada lista = NULL;

	if(argc!=2){

        printf("Ingresa el nombre del archivo\n",argv[0]);
        exit(0);    
    }

    else archivo = fopen(argv[1], "rb");
    
	if (archivo == NULL){

		printf("Error\n"); 
		return -1;
	}
 
	do{

		bytesLeidos = fread(listaDeCaracteres, sizeof(char), 1024, archivo);

		crearLista(&lista, listaDeCaracteres, bytesLeidos);

	}while(!feof(archivo));

	ordenarLista(&lista);

	imprimirLista(lista);

	copiarLista(lista);

	crearArbolHuffman();

	arbolHUFFMAN arbolImpresion = arbol[0];

	preorden(arbolImpresion);

	fclose(archivo);

	free(lista);

	free(arbol);

	printf("Programa terminado con exito\n");
}

void crearLista(ListaEnlazada *lista, char caracteres[], int bytes){

	if (*lista == NULL){

		*lista = (NodoLista *)malloc(sizeof(NodoLista));
		(*lista)->data.letra = caracteres[0];
		(*lista)->data.frecuencia = 1;
		(*lista)->siguiente = NULL;	
	}

	for (int i = 1; i < bytes; i++){

		completarlista(&(*lista), caracteres[i]);
	}
}

void completarlista(ListaEnlazada *lista, char caracter){
	
	bool banderaNuevoNodo = false;

	ListaEnlazada listaAuxiliar = *lista;

	do{

		if (listaAuxiliar->data.letra == caracter){

			banderaNuevoNodo = false;

			listaAuxiliar->data.frecuencia++;

			return;
		}
		else banderaNuevoNodo = true;

		listaAuxiliar = listaAuxiliar->siguiente;

	}while(listaAuxiliar != NULL);

	if (banderaNuevoNodo){

		ListaEnlazada nuevoNodo;
		nuevoNodo = (NodoLista *)malloc(sizeof(NodoLista));
		nuevoNodo->data.letra = caracter;
		nuevoNodo->data.frecuencia = 1;
		nuevoNodo->siguiente = *lista;
		*lista = nuevoNodo;
	}
}

void ordenarLista(ListaEnlazada *lista){

	ListaEnlazada listaActual, listaSiguiente;

	int frecuenciaAux;
	char caracterAux;

	listaActual = *lista;

	while(listaActual->siguiente != NULL){

		listaSiguiente = listaActual->siguiente;

		while(listaSiguiente != NULL){

			if (listaActual->data.frecuencia >= listaSiguiente->data.frecuencia){

				frecuenciaAux = listaSiguiente->data.frecuencia;
				caracterAux = listaSiguiente->data.letra;

				listaSiguiente->data.frecuencia = listaActual->data.frecuencia;
				listaSiguiente->data.letra = listaActual->data.letra;
				
				listaActual->data.frecuencia = frecuenciaAux;
				listaActual->data.letra = caracterAux;					
			}

			listaSiguiente = listaSiguiente->siguiente;
		}

		listaActual = listaActual->siguiente;
		listaSiguiente = listaActual->siguiente;
	}

}

void imprimirLista(ListaEnlazada lista){
	
	tamanoLista = 0;

	while(lista != NULL){
		printf("%c", lista->data.letra);
		printf(" %d\n", lista->data.frecuencia);

		lista = lista->siguiente;
		tamanoLista++;
	}
	printf("\n");
}

void copiarLista(ListaEnlazada lista){

	int i;

	arbol = (NodoArbol **)malloc(tamanoLista*sizeof(NodoArbol *));

	for (i = 0; i < tamanoLista; i++){

		NodoArbol *nuevaHoja;
		nuevaHoja = (NodoArbol *)malloc(sizeof(NodoArbol));
		nuevaHoja->data.frecuencia = 0;
		nuevaHoja->data.letra = '\0';
		nuevaHoja->izquierda = NULL;
		nuevaHoja->derecha = NULL;

		arbol[i] = nuevaHoja;
	}

	for (lista, i = 0; lista != NULL ; i++, lista = lista->siguiente){

		arbol[i]->data.frecuencia = lista->data.frecuencia;
		arbol[i]->data.letra = lista->data.letra;		
	}
}

void crearArbolHuffman(){

	NodoArbol *temporal;

	while(arbol[1] != NULL ){

		NodoArbol *auxiliar;
		auxiliar = (NodoArbol *)malloc(sizeof(NodoArbol));
		auxiliar->data.frecuencia = arbol[0]->data.frecuencia + arbol[1]->data.frecuencia;
		auxiliar->data.letra = '\0';
		auxiliar->izquierda = arbol[0];
		auxiliar->derecha = arbol[1];

		for (int i = 0; i < tamanoLista-1; i++){

			arbol[i] = arbol[i+1];
		}


		arbol[tamanoLista-1] = NULL;

		arbol[0] = auxiliar;


		for (int i = 0; i < tamanoLista-2; i++){

			if (arbol[i]->data.frecuencia >= arbol[i+1]->data.frecuencia){

				temporal = arbol[i+1];
				arbol[i+1] = arbol[i];
				arbol[i] = temporal;
			}
		}

		tamanoLista--;
	}
}

void preorden(arbolHUFFMAN arbolImpresion){

    if (arbolImpresion != NULL) {
        printf("%c - %d\n", arbolImpresion->data.letra ,arbolImpresion->data.frecuencia);
        preorden(arbolImpresion->izquierda);
        preorden(arbolImpresion->derecha);
    }
}