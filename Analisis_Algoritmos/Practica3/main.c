#include <stdio.h>
#include <stdlib.h>

typedef struct informacion
{
    unsigned char c;
    int frec;
} Nodoinfo;

typedef struct Lista
{
    Nodoinfo inf;
    struct Lista *sig, *izq, *der;
} Nodolista;

typedef Nodolista *Listaenlazada;

void llenarlista(Listaenlazada *lista, char c);
void imprimirLista(Listaenlazada lista);
void ordenarlista(Listaenlazada *lista);
void crearArbolHuf(Listaenlazada *lista);

int main(int argc, char const *argv[])
{
    FILE *archivo;

    if (argc != 2)
    {
        printf("Ingresa el nombre del archivo\n", argv[0]);
        exit(0);
    }
    else
    {
    }
    archivo = fopen(argv[1], "rb");

    Listaenlazada lista = NULL;

    while (!feof(archivo))
    {
        llenarlista(&lista, fgetc(archivo));
    }
    // imprimirLista(lista);
    ordenarlista(&lista);
    // printf("Ahora ya esta en orden esta madre\n");
    imprimirLista(lista);
    crearArbolHuf(&lista);
    printf("Huffman\n");
    imprimirLista(lista);
    return 0;
}

/* 
    Funcion LlenarLista

 */
void llenarlista(Listaenlazada *lista, char c)
{
    Listaenlazada laux;
    laux = *lista;
    if (*lista == NULL)
    {
        *lista = (Nodolista *)malloc(sizeof(Nodolista));
        (*lista)->inf.frec = 1;
        (*lista)->inf.c = c;
        (*lista)->sig = NULL;
        (*lista)->izq = NULL;
        (*lista)->der = NULL;
    }
    else
    {
        do
        {
            if ((laux->inf.c) == c)
            {
                laux->inf.frec = laux->inf.frec += 1;
                return;
            }
            laux = laux->sig;
        } while (laux != NULL);
        Listaenlazada nuevo;
        nuevo = (Nodolista *)malloc(sizeof(Nodolista));
        nuevo->inf.frec = 1;
        nuevo->inf.c = c;
        nuevo->sig = *lista;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        *lista = nuevo;
    }
}

void imprimirLista(Listaenlazada lista)
{
    do
    {
        printf(" %.2x con %d\n", lista->inf.c, lista->inf.frec);
        lista = lista->sig;
    } while (lista != NULL);
}

void ordenarlista(Listaenlazada *lista)
{
    Listaenlazada actual, siguiente;
    int t;
    char c;
    actual = *lista;
    while (actual->sig != NULL)
    {
        siguiente = actual->sig;

        while (siguiente != NULL)
        {
            if (actual->inf.frec >= siguiente->inf.frec)
            {
                t = siguiente->inf.frec;
                c = siguiente->inf.c;
                siguiente->inf.frec = actual->inf.frec;
                siguiente->inf.c = actual->inf.c;
                actual->inf.frec = t;
                actual->inf.c = c;
            }
            siguiente = siguiente->sig;
        }
        actual = actual->sig;
        siguiente = actual->sig;
    }
}

void crearArbolHuf(Listaenlazada *lista)
{
//     Listaenlazada aux, aux2;
//     aux = (*lista)->sig;
//     aux->der = (*lista)->sig;
//     aux->izq = *lista;



//     *lista = (*lista)->sig;

//     aux = *lista;
    Listaenlazada aux1 = *lista;
    Listaenlazada aux2 = (*lista)->sig;
    imprimirLista((*lista));
    aux2 = (*lista)->sig;
    do
    {
        aux2->der = aux2;
        aux2->izq = aux1;
        aux2->inf.frec = (*lista)->inf.frec + (*lista)->sig->inf.frec;
        aux2->inf.c = '\0';
        do
        {
            aux2 = aux2->sig;
        } while (aux2->inf.frec >= aux2->sig->inf.frec);

        *lista = (*lista)->sig;
        aux1 = *lista;
        aux2 = aux1->sig;
    } while (*lista !=NULL);
}

/* void crearArbolHuf(Listaenlazada *lista)
{
    Listaenlazada aux;
    int s;
    char c;
    
        Listaenlazada nuevo;
        nuevo = (Nodolista *)malloc(sizeof(Nodolista));
        nuevo->inf.frec = (aux->inf.frec) + (aux->sig->inf.frec);
        nuevo->inf.c = '\0';
        printf("Entro antes del do\n");
        nuevo->izq = aux;
        nuevo->der = aux->sig;

        *lista = (*lista)->sig->sig;
        nuevo->sig = *lista;
        *lista = nuevo;

        aux = *lista;
        do
        {
            Listaenlazada aux2;
            aux2 = (Nodolista *)malloc(sizeof(Nodolista));
            s=aux->sig->inf.frec;
            c=aux->sig->inf.c;
            aux2->izq = aux->sig->izq;
            aux2->der = aux->sig->der;
            aux->sig->inf.frec = aux->inf.frec;
            aux->sig->inf.c = aux->inf.c;
            aux->inf.frec = s;
            aux->inf.c = c;
            aux->izq = aux2->izq;
            aux->der = aux2->der;
            aux = aux->sig;
        } while (aux->inf.frec >= aux->sig->inf.frec);

    
} */

/* 
    Pasitos
    //- 1. Declaración de estructuras 
    //- 2. Abrir Archivo
    //- 3. Empezar lista/terminar
    //- 4. Ordenar Lista
    5. Crear Arbol Huffman
    6. Descubrir como chingados se escribe en binario
    7. Escribir en el archivo (Auxiliandome de los acracteres escaneados en el arreglo (no lista) )
    8. Imprimir / exportar / crear frecuencias.ttx y comprimido.dat
 */