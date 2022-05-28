#include <stdio.h>

// Declarando la estructura del nodo que utilizaremos como base para la creación de la lista, de la misma forma este es el nodo
typedef struct _nodo
{
   int dato;
   struct _nodo *next;
} tipoNodo;


// Indicamos que para hacer un apuntador de tipoNodo usamos la palabra Lista o nodo
typedef tipoNodo *Lista;
typedef tipoNodo *nodo;


int main(int argc, char const *argv[])
{
   Lista lista;
   
}

void insertarInicio(Lista *lista, int dato)
{
   nodo nuevo;
   nuevo = (nodo)malloc(sizeof(tipoNodo));
   nuevo->dato = dato;
   nuevo->next = *lista;
   *lista = nuevo;
}

void insertarFinal(Lista *lista, int dato)
{
   nodo nuevo;
   nuevo = (nodo)malloc(sizeof(tipoNodo));
   nuevo->dato = dato;
   nuevo->next = NULL;
   if(*lista == NULL)
   {
      *lista = nuevo;
   }
   else
   {
      nodo aux = *lista;
      while(aux->next != NULL)
      {
         aux = aux->next;
      }
      aux->next = nuevo;
   }
}
