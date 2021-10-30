/**
******************************************************************************
* @file	Main.c
* @author 	Mora Ayala Jose Antonio
* @version  2.0
* @date  October 29 2020
* @brief Archivo que contiene la seccion principal del programa de Algoritmo de Huffman
******************************************************************************
*/
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
Nodolista **arbol;
int tam;

void llenarlista(Listaenlazada *lista, char c);
void imprimirLista(Listaenlazada lista);
void ordenarlista(Listaenlazada *lista);
void crearArbolHuf();
void copiarLista(Listaenlazada Lista);
void preorden(Listaenlazada arbolImpresion);

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
    char c;
    Listaenlazada lista = NULL;
    while (!feof(archivo))
    {
        c = fgetc(archivo);
        if (c != -1)
        {
        llenarlista(&lista, c);
        }
        
    }
    // imprimirLista(lista);
    ordenarlista(&lista);
    // printf("Ahora ya esta en orden esta madre\n");
    imprimirLista(lista);

    printf("Copiar Lista\n");
    copiarLista(lista);
    printf("Copiar Lista\n");
    imprimirLista(lista);
    crearArbolHuf();

    Listaenlazada arbolimp = arbol[0];
    preorden(arbolimp);

    // printf("Letra %.2x\n",arbol[0]->inf.c);
    // printf("frec %d\n",arbol[0]->inf.frec);
    printf("Acabo\n");
    return 0;
}

    /* 
    Funcion LlenarLista

 */
    void llenarlista(Listaenlazada * lista, char c)
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

    void copiarLista(Listaenlazada lista)
    {
        int pos;
        arbol = (Nodolista **)malloc(tam * sizeof(Nodolista *));
        for (pos = 0; pos < tam; pos++)
        {
            Nodolista *hoja;
            hoja = (Nodolista *)malloc(sizeof(Nodolista));
            hoja->inf.frec = 0;
            hoja->inf.c = '\n';
            hoja->izq = NULL;
            hoja->der = NULL;
            hoja->sig = NULL;
            arbol[pos] = hoja;
        }

        for (lista, pos = 0; lista != NULL; pos++, lista = lista->sig)
        {
            arbol[pos]->inf.frec = lista->inf.frec;
            arbol[pos]->inf.c = lista->inf.c;
        }
    }

    void imprimirLista(Listaenlazada lista)
    {
        tam = 0;
        do
        {
            tam++;
            printf(" %.c con %d\n", lista->inf.c, lista->inf.frec);
            lista = lista->sig;
        } while (lista != NULL);
    }
   /* 
   ---------------------------------------------------------------------------------------
   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function ordernarlista>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
   PARAMETROS
   -> Listaenlazada Recibe una listaEnlazada al momento de ser invocada 
   ->
   ~DESCRIPCION: Funcion que realiza el recorrido de un arbol en preorden (Comienza el recorrido desde la raiz) y 
                va bajando continuamente por el lado izquierdo, posteriormente cuando ya no hay mas izquierda va a la derecha
                Vamos obteinendo los valores que hay existentes en cada hoja, asi como la frecuencia que poseen
   USO:         preorder (Listaenlazada arbolImpresion);
   RETURN:      Vacio ya que estamos utilizando memoria dinamica dentro del programa
   ---------------------------------------------------------------------------------------
    */
    void ordenarlista(Listaenlazada * lista)
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
   /* 
   ---------------------------------------------------------------------------------------
   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function HuffmanTree>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
   PARAMETROS
   ->  
   ~DESCRIPCION: Funcion que realiza la creacion de un arbol huffman asignano frecuencias y las hojas
                conforme la lista de frecuencias que previmante ya tuvo que haber sido sometida a un ordenamiento
                previo.
   USO:         crearArbolHuf();
   RETURN:      Vacio ya que estamos utilizando memoria dinamica dentro del programa
   ---------------------------------------------------------------------------------------
    */
    void crearArbolHuf()
    {
        Nodolista *temp;
        while (arbol[1] != NULL)
        {
            Nodolista *aux;
            aux= (Nodolista *)malloc(sizeof(Nodolista));
            aux->inf.frec = arbol[0]->inf.frec + arbol[1]->inf.frec;
            aux->inf.c = '\0';
            aux->izq = arbol[0];
            aux->der = arbol[1];
            for (int i = 0; i < tam - 1; i++)
            {
                arbol[i] = arbol[i+1];
            }
            arbol[tam - 1] = NULL;
            arbol[0] = aux;
            for (int i = 0; i < tam - 2; i++)
            {
                if (arbol[i]->inf.frec >= arbol[i+1]->inf.frec)
                {
                    temp = arbol[i + 1];
                    arbol[i + 1] = arbol[i];
                    arbol[i] = temp;
                }
            }
            tam--;
        }
    }

   /* 
   ---------------------------------------------------------------------------------------
   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function Preorden>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
   PARAMETROS
   -> Listaenlazada Recibe una listaEnlazada al momento de ser invocada 
   ->
   ~DESCRIPCION: Funcion que realiza el recorrido de un arbol en preorden (Comienza el recorrido desde la raiz) y 
                va bajando continuamente por el lado izquierdo, posteriormente cuando ya no hay mas izquierda va a la derecha
                Vamos obteinendo los valores que hay existentes en cada hoja, asi como la frecuencia que poseen
   USO:         preorder (Listaenlazada arbolImpresion);
   RETURN:      Vacio ya que estamos utilizando memoria dinamica dentro del programa
   ---------------------------------------------------------------------------------------
    */
   
    void preorden(Listaenlazada arbolImpresion)
    {

        if (arbolImpresion != NULL)
        {
            printf("%c - %d\n", arbolImpresion->inf.c, arbolImpresion->inf.frec);
            preorden(arbolImpresion->izq);
            preorden(arbolImpresion->der);
        }
    }

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