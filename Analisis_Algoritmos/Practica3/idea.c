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
#include <string.h>
#include <stdbool.h>

/* Definiciones que nos sirven para pdoer realizar el manejo de bits conforme sea requerido
    Mediante los "bitwise Operators" o bien Operadores binarios.
    Recurso proporcionado por:
    @Autor : Edgardo Adrian Franco Martinez
 */

#define PESOBIT(bpos) 1 << bpos
#define CONSULTARBIT(var, bpos) (*(unsigned *)&var & PESOBIT(bpos)) ? 1 : 0
#define PONE_1(var, bpos) *(unsigned *)&var |= PESOBIT(bpos)
#define PONE_0(var, bpos) *(unsigned *)&var &= ~(PESOBIT(bpos))
#define CAMBIA(var, bpos) *(unsigned *)&var ^= PESOBIT(bpos)

/* 
-------------------------------------------------------------------------------------------
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Struct Nodoinfo>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
DATATYPE
->int                    frec va alamacenando la frecuencia de repeticion del caracter            
->unsigned char          va almacenando el carcter en cuestion para cada uno de los nodos            
~Description   Estructura que nos proporciona la capacidad de ir alamcenando la frecuencia
                del carcater conforme esta va incrementando, así como poder almacenar el  
                caracter cuando sea necesario para cada uno de los nodos (en caso de que
                tratemos con un nodo hoja tendra un caracter, pues es el proposito del arbol
                huffman, en caso contrario se le asignara el caracter vacio) 
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Struct Nodoinfo>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------|
   */
typedef struct informacion
{
    unsigned char c;
    int frec;
    int binario[16];
} Nodoinfo;

/* 
   -------------------------------------------------------------------------------------------
   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Struct NodoLista>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
   DATATYPE
   ->Nodoinfo       Posee dentro una estructura como la descrita anteriormente para que cada
                    uno de los nodos pueda tener esos elementos dentro de su estructura                        
   ->struct Lista   Definicion de una lista de su mismo tipo para poder ir haciendo el 
                    ligamiento, aqui mismo declaramos las partes de izquierda y derecha pora
                    cada nodo de la lista y asi poder formar el arbol         
   ->DESCRIPCION: Estructura que nos proporciona la capacidad de ir alamcenando la frecuencia
                del carcater conforme esta va incrementando, así como poder almacenar el  
                caracter cuando sea necesario para cada uno de los nodos (en caso de que
                tratemos con un nodo hoja tendra un caracter, pues es el proposito del arbol
                huffman, en caso contrario se le asignara el caracter vacio) 

   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Struct Nodoinfo>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
   -------------------------------------------------------------------------------------------|
    */

typedef struct Lista
{
    Nodoinfo inf;
    struct Lista *sig, *izq, *der;
} Nodolista;

typedef Nodolista *Listaenlazada;
//Sin el typedef
// Nodolista *lista
Nodolista **arbol;
int tam;

// *arbol -> Estructura lista SegundoApuntador **-> (Parte dinamica para la memoria)
//ListaEnlazada **arbol = ***arbol

//Variable con el tamanno total de la lista enlazada
int tamanoLista;

//Variable con el tamano total de bytes del archivo de entrada
int totalDeBytes;

void fillList(Listaenlazada *lista, char c);
void printList(Listaenlazada lista);
void orderList(Listaenlazada *lista);
void huffmanTree();
void copyList(Listaenlazada Lista);
int crearFrecuenciastxt(Listaenlazada lista);
void binaryRoute(Listaenlazada *arbolImpresion, int pos, int bit, int izq, int der);
void createBinaryList(Listaenlazada arbolImpresion, Listaenlazada *listaBinaria);
int crearCodificacionDAT(Listaenlazada listaBinaria, FILE *archivo);
int cmpchar(char cadena1, char cadena2);
int crearCodificacionDAT(Listaenlazada listaBinaria, FILE *archivo);

int main(int argc, char const *argv[])
{
    FILE *archivo;
    Listaenlazada lista = NULL;
    Listaenlazada BinaryList = NULL;
    char listaCaracteres[1024];
    int readBytes;
    char c;

    if (argc != 2)
    {
        printf("Ingresa el nombre del archivo\n", argv[0]);
        exit(0);
    }
    else
    {
        archivo = fopen(argv[1], "rb");
    }

    do
    {
        //Guardamos en bytes leidos el tamano de bytes escaneados
        readBytes = fread(listaCaracteres, sizeof(char), 1024, archivo);

        //Guardamos el total de bytes leido cada vez para obtener el total
        totalDeBytes = totalDeBytes + readBytes;
        //Haremos esto hasta que lleguemos al final del archivo
    } while (!feof(archivo));

    printf("El total de bytes que se encontraron en el archivo son %d\n", totalDeBytes);

    // es necesario hacer uso de la funcion rewind incluida en el manejo de archivos, dado que recorrimos todo el archivo y devemos volver
    // al principio para poder comenzar nuevamente con nuestro procedimiento
    rewind(archivo);

    //  * lista -> Nodolista;

    /* 
    Realizando la obtencion de cada uno de los caracetres que nos encontramos dentro del archivo,
    situacion que sucede hasta que hayamos llegado al final del archivo
    IMPORTANTE. se debe consiedrar que la funcion fgetc al final agrega un salto de linea por lo cual
    es sumamente necesaria la consideracion de poner que el caracter debe ser distinto de menos 1, ya 
    que de no ser asi modificara el resultado de nuestro arbol de huffman y por lo tanto las ocurrencias
     */
    while (!feof(archivo))
    {
        c = fgetc(archivo);
        if (c != -1)
        {
            fillList(&lista, c);
        }
    }

    printf("Nombre del archivo: %s - Tamanno en bytes: %d\n", argv[1], totalDeBytes);
    orderList(&lista); //Ya que hemos llenando la lista procedemos a ordenarla
    printList(lista);  //Realizmamos la impresion de la lista para asegurarnos que todo esta saliendo como deberia

    if (crearFrecuenciastxt(lista) == -1)
    {
        return -1;
    } //Creamos el archivo frecuencias.txt
    printf("Copiando Lista\n");
    copyList(lista); //Copiamos la lista dentro del arbol de Huffman el cual fue declarado de forma global
    printf("Lista Copiada\n");
    printList(lista);

    huffmanTree(); //Procedemos a la cracion del arbol de Huffman
    Listaenlazada arbolimp = arbol[0];
    binaryRoute(&arbolimp, -1, 0, 0, 0); //Realizacion de un recorrido en postorden con respecto al arbol para poder realizar la obtencion de cada codigo

    createBinaryList(arbolimp, &BinaryList); //Guardamos en nuestra lista de valores binarios

    crearCodificacionDAT(BinaryList, archivo); //Realizamos la creacion de la codificacion

    fclose(archivo);

    //Liberamos la memoria de la cabeza de la lista enlazada
    free(lista);

    //liberamos la memoria de el arbol de huffman

    //liberamos la memoria de nuestro arbol de huffman de impresion
    free(arbolimp);

    //Liberamos la memoria para nuestra lista enlzada con nuestros
    //datos en binario
    free(BinaryList);

    //Imprimios este mensaje para saber que el programa se haya
    //ejecutado u terminado sin ningun problema
    printf("Programa terminado con exito\n");

    printf("Acabo\n");
    return 0;
}

/* 
-------------------------------------------------------------------------------------------------
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function fillList>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PARAMETROS
-> Listaenlazada: Recibe una listaEnlazada al momento de ser invocada 
-> char c         
~DESCRIPCION: Funcion que realiza la creacion de una lista enlazada asi como la inicialización 
correspondiente de cada uno de los aputadores que nos ayudar para hacer el arbol de huffman
posteriormente
USO: fillList (&lista) debemos pasar como referencia, dado que estamos trabajando con memoria 
dinamica y el valor de retorno será void / en caso contrario se deberia cambiar el valor de
retorno y asignarlo a una variable de tipo listaEnlazada         
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function fillList>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------------|
*/
void fillList(Listaenlazada *lista, char c)
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

/* 
-------------------------------------------------------------------------------------------------
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function copyList>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PARAMETROS
-> Listaenlazada: Recibe una listaEnlazada al momento de ser invocada (la lista no debe estar
vacia) para poder realizar 

~DESCRIPCION: La funcion realiza la asignacion de valores de forma correcta al arbol de Huffman
Recordemos que el arbol de huffman fue declarado de forma global para poder realizar la 
manipulacion de apuntadores de una forma mas sencilla
USO: copyList (lista)
//No mandamos por referencia dado que no nocesitamos modificar ninguno de los valores que 
se encuentran dentro de nuestra lista ya ordenada         
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function copyList>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------------|
*/

void copyList(Listaenlazada lista)
{
    int pos;

    if (lista == NULL)
    {
        printf("La lista se encuentra vacia\n");
        exit;
    }
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
/* 
-------------------------------------------------------------------------------------------------
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function ordenarLista>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PARAMETROS
-> Listaenlazada: Recibe una listaEnlazada al momento de ser invocada 
->       
~DESCRIPCION: 
USO:         
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function ordenarLista>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------------|
*/

void printList(Listaenlazada lista)
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
-------------------------------------------------------------------------------------------
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function ordenarLista>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PARAMETROS
-> Listaenlazada Recibe una listaEnlazada al momento de ser invocada 
->       
~DESCRIPCION: Funcion que realiza el recorrido de un arbol en preorden (Comienza el 
              recorrido desde la raiz) y  va bajando continuamente por el lado izquierdo, 
              posteriormente cuando ya no hay mas izquierda va a la derecha  Vamos 
              obteinendo los valores que hay existentes en cada hoja, asi como la frecuencia 
              que poseen
USO:         preorder (Listaenlazada arbolImpresion);
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Struct Nodoinfo>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------|
*/

void orderList(Listaenlazada *lista)
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
   USO:         huffmanTree();
   RETURN:      Vacio ya que estamos utilizando memoria dinamica dentro del programa
   ---------------------------------------------------------------------------------------
    */

void huffmanTree()
{
    Nodolista *temp;
    while (arbol[1] != NULL)
    {
        Nodolista *aux;
        aux = (Nodolista *)malloc(sizeof(Nodolista));
        aux->inf.frec = arbol[0]->inf.frec + arbol[1]->inf.frec;
        aux->inf.c = '\0';
        aux->izq = arbol[0];
        aux->der = arbol[1];
        for (int i = 0; i < tam - 1; i++)
        {
            arbol[i] = arbol[i + 1];
        }
        arbol[tam - 1] = NULL;
        arbol[0] = aux;
        for (int i = 0; i < tam - 2; i++)
        {
            if (arbol[i]->inf.frec >= arbol[i + 1]->inf.frec)
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
-------------------------------------------------------------------------------------------------
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function binaryRoute>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PARAMETROS
-> Listaenlazada Recibe una listaEnlazada al momento de ser invocada (debe ser por referencia &)
->int pos : Nos proprociona la posicion en donde se iran insertando los bits correspondientes 
dentro del arreglo
->int bit Variable que nos dice si a la izquierda sera manejado como 0 o como 1 hacia la derecha
valor que depende de como sea mandado al momento de invocar la funcion.
En el caso de como funciona el algoritmo de Huffman debemos manejar izq = 0
der =1
->int izq : Nos sirve para poder ir realizando la obtencion de la cantidad de bit obtenidos
conforme se fue moviendo 
->int der:  Nos sirve para poder ir realizando la obtencion de la cantidad de bit obtenidos
conforme se fue moviendo
~DESCRIPCION: Funcion que realiza el recorrido de un arbol en preorden (Comienza el recorrido 
            desde la raiz) y va bajando continuamente por el lado izquierdo, posteriormente cuando 
            ya no hay mas izquierda va a la derecha Vamos obteinendo los valores que hay 
            existentes en cada hoja, asi como la frecuencia que poseen
USO:        binaryRoute binaryRoute(Listaenlazada *arbolImpresion, int pos, int bit, int izq, int der);
RETURN:     Vacio ya que estamos utilizando memoria dinamica dentro del programa      
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function binaryRoute>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------------|
*/

void binaryRoute(Listaenlazada *arbolImpresion, int pos, int bit, int izq, int der)
{

    //Obtendremos el binario usando como base el recorrido en preorder de un arbol
    if (*arbolImpresion != NULL)
    {
        //Arreglo para ir almacenando cada uno de los binarios
        int auxBin[8];

        //Iremos insertando el valor del bit dependiendo si nos vamos por izquierda con valor 0
        //o si vamos por la derecha con 1, en la primera llamada en el main como no hemos
        //recorrido ninguna pos dentro del arbol por eso tendremos el valor de -1 donde no
        //guardaremos ningun valor dentro del arreglo
        if (pos != -1)
        {
            auxBin[pos] = bit;
        }

        //Si nos encontramos en un nodo hoja donde tenemos la frecuencia y la letra haremos
        //las siguientes operaciones, en caso de que no seguiremos recorriendo el arbol
        if ((*arbolImpresion)->izq == NULL && (*arbolImpresion)->der == NULL)
        {

            //Haremos un ciclo que dependiendo de las veces que nos hayamos dezplazado en la
            //izquierda o la derecha insertaremos los valores guardados en nuestro arreglo
            //auxiliar en nuestra variable dentro de la estructura
            for (int i = 0; i < (izq + der); i++)
            {

                //igualamos los datos dentro de nuestro auxilair con nuestro valor dentro
                //de la estructura
                (*arbolImpresion)->inf.binario[i] = auxBin[i];
            }

            //Como en este punto la frecuencia de las letras ya no nos es util lo remplazaremos
            //con el numero de bites que se registraron, aun que el arreglo tiene los 8 bits,
            //cuando escribamos en el archivo .dat esto nos sera de ayuda para
            //insertar los valores dentro del arreglo
            (*arbolImpresion)->inf.frec = izq + der;
        }
        else
        {
            //Dependiendo hacia donde nos dezplasemos sumaremos en 1 la pos para insertar en
            //el arreglo, ademas de que llevaremos el conteno de los  dezplacamiento hacia la
            //izquierda o hacia la derecha
            binaryRoute(&(*arbolImpresion)->izq, pos + 1, 0, izq + 1, der);
            binaryRoute(&(*arbolImpresion)->der, pos + 1, 1, izq, der + 1);
        }
    }
}

/* 
-------------------------------------------------------------------------------------------------
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function createBinaryList>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PARAMETROS
-> Listaenlazada: Recibe una listaEnlazada al momento de ser invocada 
-> Lista enlazada por referencia: En este caso si necesitamo una por referencia dado a que vamos 
a realizar la insersion de valores dentro de una lista que pretendemos usar depsues

~DESCRIPCION: 
USO:         
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function createBinaryList>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------------|
*/

void createBinaryList(Listaenlazada arbolImpresion, Listaenlazada *binaryList)
{

    //Haremos este proceso mientras el valor no sea NULL, apoyandonos en el
    //recorrido en preorden de la funcion
    if (arbolImpresion != NULL)
    {

        //Si estamos en un nodo hoja haremos lo siguiente, caso de que no sea un
        //nodo hoja nos dezplazaremos a la izquierda o derecha
        if (arbolImpresion->izq == NULL && arbolImpresion->der == NULL)
        {

            //en caso de que la lista binaria sea NULL, crearemos un nuevo nodo con el
            //primer valor encontrado en el nodo hoja del arbol a este primer nodo
            //de la lista que tendra nuestras frecuencias, letra y binario
            if (*binaryList == NULL)
            {

                *binaryList = (Nodolista *)malloc(sizeof(Nodolista));
                (*binaryList)->inf.c = arbolImpresion->inf.c;
                (*binaryList)->inf.frec = arbolImpresion->inf.frec;

                //Insertamos el numero binario de la letra segun el arbol de huffman
                for (int i = 0; i < arbolImpresion->inf.frec; i++)
                    (*binaryList)->inf.binario[i] = arbolImpresion->inf.binario[i];

                (*binaryList)->sig = NULL;
            }
            else
            {

                //En caso de que no sea el primer nodo lo que haremos es de igual forma
                //crear un nuevo nodo que insertaremos dentro de la lista con los datos
                //del siguiente nodo hoja encontrado en el arbol
                Listaenlazada nuevoNodo;
                nuevoNodo = (Nodolista *)malloc(sizeof(Nodolista));
                nuevoNodo->inf.c = arbolImpresion->inf.c;
                nuevoNodo->inf.frec = arbolImpresion->inf.frec;

                //Insertamos el valor binario del arbol en la lista para esta letra
                for (int i = 0; i < arbolImpresion->inf.frec; i++)
                    nuevoNodo->inf.binario[i] = arbolImpresion->inf.binario[i];

                //actualizamos la cabeza de la lista enlazada
                nuevoNodo->sig = *binaryList;
                *binaryList = nuevoNodo;
            }
        }
        else
        {

            //En caso de que no estemos en un nodo hoja nos seguiremos
            //dezplasando dentro del arbol
            createBinaryList(arbolImpresion->izq, &(*binaryList));
            createBinaryList(arbolImpresion->der, &(*binaryList));
        }
    }
}
// Frecuencias mandar numero;

/* 
-------------------------------------------------------------------------------------------------
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function ordenarLista>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PARAMETROS
-> Listaenlazada: Recibe una listaEnlazada al momento de ser invocada no es necesario que sea por
referencia dado que solo queremos acceder a la infromacion que esta almacena

~DESCRIPCION: Funcion que nos permite realizar la creacion de nuestro documento de frecuencias 
USO:         
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function crearFrecuencias>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------------|
*/

int crearFrecuenciastxt(Listaenlazada lista)
{
    char cadena[] = "FRECUENCIAS DE CADA CARACTER EN ORDEN DE APARICION\n MORA AYALA JOSE ANTONIO \n"; //Encabezado para el archivo 
    FILE *frecuencydoc = NULL;

    frecuencydoc = fopen("Frecuencias.txt", "w"); //En caso de que el archivo no exista se crea automaticamente 
    if (frecuencydoc == NULL)
    {
        printf("Error\n");
        return -1;
    }
    fputs(cadena, frecuencydoc); //Insercion de Encabezado
    while (lista != NULL){  //iremos iterando en toda nuestra lista, mientras el siguiente nodo no este vacio quiere decri que aun tenemos informacion que debemos imprimir en el archivo
        //Imprimimos la letra y la frecuencia de la lista usando fprintf
        fprintf(frecuencydoc, "|%c ->>>>>> %d|\n", lista->inf.c, lista->inf.frec);
        lista = lista->sig;
    }
    fclose(frecuencydoc);
}

/* 
-------------------------------------------------------------------------------------------------
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function ordenarLista>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PARAMETROS
-> Listaenlazada: Recibe una listaEnlazada al momento de ser invocada 
->       
~DESCRIPCION: 
USO:         
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function ordenarLista>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------------|
*/
int crearCodificacionDAT(Listaenlazada listaBinaria, FILE *archivo)
{

    //Declaramos un variable para escribir el archivo de salida
    FILE *codificacion = NULL;

    //Declaramos una listaEnlazada auxiliar para dezplazarnos
    //en la lista sin perder el origen o cabeza
    Listaenlazada listaAuxiliar = listaBinaria;

    //Declaramos la variable donde guardaremos el caracter
    //escaneado del archivo original
    char caracterEscaneado;

    //Variable auxiliar que tendra el caracter de la lista que coincida
    //con el escaneado (Necesitado para usar el strcmp())
    char caracterLista;

    // Dar mas espacio al arreglo

    int posicionBit = 7;

    int posicionByte = 0;
    int bt = 0;
    int queryValue;

    int random;

    //Inicializamos una arreglo con 1024 posiciones
    unsigned char arreglo[1024];

    //Procedemos a llenar el arreglo con datos cualquiera
    //en este caso lo llenaremos de 0
    for (int i = 0; i < 1024; i++)
        arreglo[i] = 0;

    //Abrimos o creamos el archivo donde tendremos la codificacion
    //em modo escritura binaria
    codificacion = fopen("codificacion.dat", "wb");

    //Verificamos que el archivo se haya abierto de manera correcta
    if (codificacion == NULL)
    {

        printf("Error al crear/abrir codificacion.dat \n");
        return -1;
    }

    //Rebobinamos hasta el inicio del archivo donde tenemos nuestros
    //datos originales
    rewind(archivo);

    //Mientras no lleguemos al final del archivo haremos lo siguiente
    do
    {

        //Escaneamos el caracter del archivo
        caracterEscaneado = fgetc(archivo);

        //Escanea el End Of File, si se llega a este valor
        //se rompera el ciclo

        if (feof(archivo) == 16) //Igualar a 1 en ejecucion de Linux
            break;

        //Volvemos a la cabeza de la lista enlazada
        listaAuxiliar = listaBinaria;

        //Lo buscamos en la lista enlazada
        for (listaAuxiliar; listaAuxiliar != NULL; listaAuxiliar = listaAuxiliar->sig)
        {

            //Igualamos el caracter de la lista a la variable de apoyo
            caracterLista = listaAuxiliar->inf.c;

            //Si encontramos la letra rompemos el ciclo
            if (cmpchar(caracterLista, caracterEscaneado))
            {
                break;
            }
        }

        for (int j = 0; j < listaAuxiliar->inf.frec; j++)
        {

            queryValue = CONSULTARBIT(arreglo[posicionByte], posicionBit);
            random = listaAuxiliar->inf.binario[j];

            if (queryValue != random)
            {
                CAMBIA(arreglo[posicionByte], posicionBit);
            }

            posicionBit--;
            bt++;

            if (posicionBit == -1)
            {

                posicionBit = 7;
                posicionByte++;
            }

            if (posicionByte == 1024)
            {

                fwrite(arreglo, sizeof(unsigned char), 1024, codificacion);
                posicionByte = 0;
            }
        }
    } while (!feof(archivo));

    if (posicionByte < 1024)
    {
        if (posicionBit == 7)
        {
            fwrite(arreglo, sizeof(unsigned char), posicionByte, codificacion);
        }
        else
        {
            fwrite(arreglo, sizeof(unsigned char), posicionByte + 1, codificacion);
        }
    }
    fclose(codificacion);
}

/* 
-------------------------------------------------------------------------------------------------
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function ordenarLista>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PARAMETROS
-> Listaenlazada: Recibe una listaEnlazada al momento de ser invocada 
->       
~DESCRIPCION: 
USO:         
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function ordenarLista>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------------|
*/

int cmpchar(char cadena1, char cadena2)
{

    //Declaramos 2 variables auxiliares para guardar los bits
    //resultantes
    int j, k;

    //Iniciamos el ciclo para analizar los 8 bits
    for (int i = 0; i < 8; i++)
    {

        //Guardamos el bit de cada cadena en la posicion de
        //i para analizarlos
        j = CONSULTARBIT(cadena1, i);
        k = CONSULTARBIT(cadena2, i);

        //Si algun bit es diferente en cualquier posicion los
        //caracteres no seran iguales y retornamos 0 o false
        if (j != k)
        {
            return 0;
        }
    }

    //En caso de que se complete el ciclo sin encontrar bits
    //diferentes devolveremos 1 o true
    return 1;
}

// Generacioncodigodat