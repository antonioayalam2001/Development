#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "FuncionesD.h"
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
int fillList(Listaenlazada *lista)
{
	//Declaramos la variable para abrir el archivo de frecuencias.txt
	FILE *frecuenciasTXT = NULL;

	//variable que escaneara los elementos para la lista enlazada
	//una vez que tengamos los datos tanto del nombre como los bits
	char escaneados[20];

	//Abrimos el archivo en modo lectura normal
	frecuenciasTXT = fopen(nombreArchivoFrecuencia, "r");

	//Verificamos que el archivo se haya abierto de manera correcta
	if (frecuenciasTXT == NULL){

		printf("Error en Frecuencias.txt\n"); 
		return -1;
	}

	//Les damos un tamano a las varaibles de 100 bytes cada uno
	cadenaPrueba = malloc(sizeof(char)*100);
	cadenaValor = malloc(sizeof(char)*100);

	//Procedemos a escanear el archivo, primero escaneamos la primera
	//linea que tendra el encabezado
	fgets(cadenaPrueba,100,frecuenciasTXT);

	//Esnaemoas inmediatamente despues, de esta manera obtenemos
	//el nombre del archivo sin decodificar con su tipo de archivo
	fgets(cadenaPrueba,100,frecuenciasTXT);

	//El siguiente escaneo correspondera al numero de bits que escribimos
	//esta variable nos dira que tantos bits deberemos decodificar
	fgets(cadenaValor,100,frecuenciasTXT);
	
	//Convertimos la variable de tipo caracter a tipo entero
	valorBits = atoi(cadenaValor);

	//Comenzamos a escanear los valores hasta terminar con el archivo
	do{

		//Si el archivo llega al final rompemos el ciclo
		if (feof(frecuenciasTXT) == 1) break;

		//En el caso de que la lista no haya sido creada aun con un nodo
		//la inicializamos con la primera letra del archivo y su frecuencia
		if (*lista == NULL){

			//asignamos memoria para ese nodo
			*lista = (Nodolista *)malloc(sizeof(Nodolista));

			//escaneamos la letra del archivo de frecuencias y la almacenamos
			//en nuestra varaible letra de la struct
			fgets(escaneados,5,frecuenciasTXT);
			(*lista)->inf.c = escaneados[0];

			//escanemos el valor numerico que corresponde a la frecuencia
			//como estamos escaneando texto procedemos a convertir la cadena
			//a entero mediante atoi
			fgets(escaneados,10,frecuenciasTXT);
			(*lista)->inf.frec = atoi(escaneados);

			//Declaramos la posicion siguiente a NULL
			(*lista)->sig = NULL;

			//Aunmentamos en 1 el tamano de la lista para usar la varaible en futuras
			//funciones que lo requieran
			tamanoLista++;
		}
		else{

			//En caso de que la lista ya tenga nodos creados lo que procedemos a hacer
			//es crear un nuevo nodo que contendra los datos de la lista
			Listaenlazada nuevoNodo;
			nuevoNodo = (Nodolista *)malloc(sizeof(Nodolista));

			//Escaneamos la letra siguiente del archivo de frecuencias y la almacenamos
			//dentro del la variable letra
			fgets(escaneados,5,frecuenciasTXT);
			nuevoNodo->inf.c = escaneados[0];

			//Posteriormente escaneamos la frecuencia de la letra y de igual manera
			//mediante atoi convertimos la cadena escaneada en enteros
			fgets(escaneados,10,frecuenciasTXT);
			nuevoNodo->inf.frec = atoi(escaneados);

			//actualizamos la cabeza de la lista enlazada
			nuevoNodo->sig = *lista;
			*lista = nuevoNodo;

			//Aunmentamos en 1 el tamano de la lista para usar la varaible en futuras
			//funciones que lo requieran
			tamanoLista++;
		}
	}while(!feof(frecuenciasTXT));

	//Una vez terminado el ciclo lo que procederemos a hacer es eliminar el primer 
	//elemento de la lista enlazada, debido a que como el archivo detecta a los 
	//saltos de linea como caracteres el ultimo elemento sera un salto de linea y
	//una frecuencia anterior por ello eliminamos este ultimo nodo agregado
	*lista = (*lista)->sig;

	//Restamos en 1 el tamano de la lista debido a esta situacion
	tamanoLista--;

	//Cerramos el archivo de frecuencias que ya no nos sera util a partir de ahora
	fclose(frecuenciasTXT);
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
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function printList>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PARAMETROS
-> Listaenlazada: Recibe una listaEnlazada al momento de ser invocada 
->       
~DESCRIPCION: Funcion que nos ayuda a realizar la impresion de la lista 
USO: printList(lista)         
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function printList>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
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
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Function invertList>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
PARAMETROS
-> Listaenlazada Recibe una listaEnlazada al momento de ser invocada 
->       
~DESCRIPCION: Funcion para realizar la inversion de una lista que se le haya mandado 
USO:         preorder (Listaenlazada arbolImpresion);
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Struct invertList>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|
-------------------------------------------------------------------------------------------|
*/

void invertList(Listaenlazada *lista, Listaenlazada *listaInvertida)
{
	//Creamos un auxiliar para dezplazarnos en la lista original
	Listaenlazada listaAuxiliar = *lista;
	
	//Haremos este procedimiento hasta haber concluido con los elementos de la lista
	while(listaAuxiliar != NULL){

		//En caso de que la lista que tendra los datos invertidos (al derecho) no haya
		//sido inicializada lo que haremos es iniciarla con los valores del nodo cabeza
		//de la lista original
		if (*listaInvertida == NULL){

			//Asignamos memoria para este nodo cabeaa
			*listaInvertida = (Nodolista *)malloc(sizeof(Nodolista));

			//guardamos los valores de la lista original en la nueva
			(*listaInvertida)->inf.c = listaAuxiliar->inf.c;
			(*listaInvertida)->inf.frec = listaAuxiliar->inf.frec;
			//Declaramos la siguiente posicion igual a NULL
			(*listaInvertida)->sig = NULL;
			//Nos dezplazamos en una posicion en la lista auxiliar
			listaAuxiliar = listaAuxiliar->sig;
		}
		else{
			//En caso de que la lista ya haya sido iniciada haremos el mismo procedimiento
			//anterior usando un nuevo nodo esta vez
			Listaenlazada nuevoNodo;
			
			//Asignamos memoria para este nodo cabeaa
			nuevoNodo = (Nodolista *)malloc(sizeof(Nodolista));

			//guardamos los valores de la lista original en la nueva
			nuevoNodo->inf.c = listaAuxiliar->inf.c;
			nuevoNodo->inf.frec = listaAuxiliar->inf.frec;

			//actualizamos la cabeza de la lista enlazada
			nuevoNodo->sig = *listaInvertida;
			*listaInvertida = nuevoNodo;

			//Nos dezplazamos en una posicion en la lista original
			listaAuxiliar = listaAuxiliar->sig;
		}
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
        if (j != k){
            return 0;
        }
    }
    //En caso de que se complete el ciclo sin encontrar bits
    //diferentes devolveremos 1 o true
    return 1;
}

// Generacioncodigodat
int crearDecodificacion(Listaenlazada arbolDeHuffman){
	//Creamos una variable para leer el archivo con la codificacion
	FILE *codificado = NULL;

	//Creamos una varaible para escribir el archivo decode
	FILE *decode = NULL;

	//Declaramos una variable auxiliar de tipo arbol que nos ayudara
	//para recorrer el arbol en el orden en que se presentan los bits
	Listaenlazada arbolAuxiliar = arbolDeHuffman;
	//Variable para almacenar el byte escaneado
	unsigned char caracterEscaneado;
	//Variable que nos determinar en que posicion estamos en los bits
	int posicionBit = 7;
	//Posicion que nos determina en que posicion del byte de codificado estamos
	int posicionByte = 0;
	//variable que tendra el valor escaneado del byte que se haya escaneado 
	//mediante fgetc
	int valorBinario;
    bool cambiarByte;
    //Abrimos el archivo codificado en modo lectura binaria
	codificado = fopen(nombreArchivoCodificacion, "rb");
	//Abrimos el archivo decode en modo escritura normal	
	decode = fopen("decodificacion.txt", "w");

    //Comprobamos que el archivo codificado se haya abierto correctamente
	if(codificado == NULL){

		printf("Error en Codificacion\n"); 
		return -1;
	}

	//comprobamos que el archivo decode se haya abierto correctamente
	if(decode == NULL){

		printf("Error en Decodificacion\n"); 
		return -1;
	}

	do{

		//Escaneamos el primer caracter dentro de codificado
		caracterEscaneado = fgetc(codificado);

		//Escanea el End Of File, si se llega a este valor
		//se rompera el ciclo
		if (feof(codificado) == 1) {
			fputc(arbolAuxiliar->inf.c, decode);
			break;
		}

		//Iniciamos en el nodo raiz del arbol
        cambiarByte = false;

        //Escaneamos el primer bit del caracter escaneado
		do{

			if ((arbolAuxiliar->izq == NULL) && (arbolAuxiliar->der == NULL)){

                fputc(arbolAuxiliar->inf.c, decode);
                arbolAuxiliar = arbolDeHuffman;
            }
			else{
                valorBinario = CONSULTARBIT(caracterEscaneado, posicionBit);
                if (valorBinario == 0){
                    arbolAuxiliar = arbolAuxiliar->izq;
                    
                }else{
                    arbolAuxiliar = arbolAuxiliar->der;
                }
                    posicionBit--;
                    if (posicionBit == -1){
                        posicionBit = 7;
                        cambiarByte = true;
                    }
                    
            }
		}while(cambiarByte != true);
	}while(!feof(codificado));
}