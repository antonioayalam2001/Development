#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//Funciones que usaremos para obtener/cambiar y deplazarnos en los bits
//de las variables

//Nos permite hacer un corrimiento a la izquierda en la variable dada
#define PESOBIT(bpos) 1<<bpos

//Nos permite consultar el bit de una variable en la posicion dada
#define CONSULTARBIT(var,bpos) ((unsigned)&var & PESOBIT(bpos))?1:0

//Nos permite vambiar el bit mediante negacion de la variable en una posicion
#define CAMBIA(var,bpos) (unsigned)&var ^= PESOBIT(bpos)

//Estructura que creara el nodo con el caracter y su frecuencia
typedef struct datos{
	char letra;
	int frecuencia;
}NodoDatos;

//Estructura que creara la lista enlazada con los datos
//escaneados del archivo
typedef struct lista{
	NodoDatos data;
	struct lista *siguiente;
}NodoLista;

//Definicion del nodo para la lista enlazada, evitando usar
//dobles apuntadores
typedef NodoLista *ListaEnlazada;

//estrucutra que creara la lista con los datos para el
//arbol de huffman
typedef struct arbol{
	NodoDatos data;
	struct arbol *izquierda;
	struct arbol *derecha;	
}NodoArbol;

//Creacion del arbol de manera global para evitar problemas 
//apuntadores a memoria
NodoArbol **arbol;

//Definicion del tipo de dato para la estrucutra del arbol
//de HUffman
typedef NodoArbol *arbolHUFFMAN;

//Variable que tendra el nombre del archivo de frecuencia
char *nombreArchivoFrecuencia;

//Variable que tendra el nombre del archivo de codificacion
char *nombreArchivoCodificacion;

//Declaramos variables que almacenaran el tipo de archivo y el nombre
//que tendra el archivo decodificado
char *cadenaPrueba;

//Declaramos la variable que tendra el valor escaneado en modo texto
char *cadenaValor;

//Variable que tendra el valor del numero de bits de tipo entero
int valorBits;

//Declaramos variable para el tamano de la lista enlazada
int tamanoLista;

/*
Prototipo de la funcion que creara la lista con los datos del archivo
de frecuencias.txt

RECIBE
lista 		lista enlazada donde pondremos los valores del archivo

DEVUELVE
Nada
*/
int crearListaEnlazada(ListaEnlazada *lista);

/*
Prototipo de la funcion invertira la lista ya creada con el fin de tener
los datos en el mismo orden que el archivo de codificacion

RECIBE
lista 			lista enlazada donde pondremos los valores del archivo
listaInvertida	lista donde tendra los valores invertidos en el orden correcto

DEVUELVE
Nada
*/
void invertirLista(ListaEnlazada *lista, ListaEnlazada *listaInvertida);

/*
Prototipo de la funcion que imprimira la lista enlaza invertida en orden
Funcion de DEBUGG o de prueba, no es necesaria para el funcionamiento

RECIBE
listaInvertida		lista enlazada donde pondremos las letras y frecuencias

DEVUELVE
Nada
*/
void imprimirLista(ListaEnlazada lista);

/*
Prototipo de la funcion que copiara datos de la lista
enalazada a la del arbol de huffman

RECIBE:
listaInvertida 		Lista donde tendremos los caracteres ordenados

DEVUELVE
Nada
*/
void copiarLista(ListaEnlazada listaInvertida);

/*
Prototipo de la funcion que creara el arbol de huffman

RECIBE
Nada

DEVUELVE
Nada
*/
void crearArbolHuffman();

/*
Prototipo de la funcion que imprimira el arbol de huffman en preorden

RECIBE
arbolDeHuffman 		arbol donde tendremos el arbol de huffman ya creado

DEVUELVE
-1 si el archivo no se puedo abrir
*/
void preorden(arbolHUFFMAN arbolDeHuffman);

int crearDecodificacion(arbolHUFFMAN arbolDeHuffman);


int main (int argc, char* argv[]){

	//Variable de la lista enlazada que tendra las letras y frecuencias
	ListaEnlazada lista = NULL;

	//Variable que tendra la lista enlzada con las letras y frecuencias
	//en el orden correcto
	ListaEnlazada listaInvertida = NULL;

	//Obtenemos los nombres de los archivos que fueron dados en la
	//ejecucion del programa
	if(argc!=3){

        printf("Ingresa el nombre del archivo %s\n",argv[0]);
        exit(0);    
    }else{

    	//Guardamos los nombres de los archivos de codificacion
    	//y de frecuencias en 2 variables globales
    	nombreArchivoFrecuencia = argv[1];
    	nombreArchivoCodificacion = argv[2];
    }

    //Mandamos a llamar la funcion que creara la lista enlazada a partir
    //del archivo de frecuencias.txt, si el archivo no se abre terminamos
    //el programa
    if(crearListaEnlazada(&lista) == -1) exit(0);
    
    //Mandamos a llamar a la funcion de invertir lista para tener los datos
    //en el orden en que fueron escaneados en el archivo de codificacion
    invertirLista(&lista ,&listaInvertida);

    //En caso de que queramos ver como se creo la lista enlazada usamos la siguiente
    //funcion, esta funcion solo es de consulta no es necesaria para el programa
    imprimirLista(listaInvertida);

    //Copiamos la lista invertida en el arreglo donde tedremos los nodos para el
    //arbol de huffman
    copiarLista(listaInvertida);

    //Mandamos a llamar a la funcion que creara el arbol de huffman
    crearArbolHuffman();

    //Creamos una nueva struct que tendra el arbol de huffman, esto para un manejo
    //mas sencillo para posteriores funciones
    arbolHUFFMAN arbolDeHuffman = arbol[0];

    //funcion que imprime el arbol de huffman en preorden, no es necesaria para
    //el funcionamiento del programa, solo es de consulta
    //preorden(arbolDeHuffman);

    if (crearDecodificacion(arbolDeHuffman) == -1) exit(0);    

    //Liberamos la memoria de la lista original
    free(lista);

    //Liberamos la memoria para la lista invertida
    free(listaInvertida);

    //liberamos la memoria donde tenemos el arbol de huffman
    free(arbolDeHuffman);

    printf("PROGRAMA TERMINADO\n");
}

/*
funcion que creara la lista con los datos del archivo de frecuencias.txt

RECIBE
lista 		lista enlazada donde pondremos los valores del archivo

DEVUELVE
-1 si el archivo no se pudo abrir
*/
int crearListaEnlazada(ListaEnlazada *lista){

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
			*lista = (NodoLista *)malloc(sizeof(NodoLista));

			//escaneamos la letra del archivo de frecuencias y la almacenamos
			//en nuestra varaible letra de la struct
			fgets(escaneados,5,frecuenciasTXT);
			(*lista)->data.letra = escaneados[0];

			//escanemos el valor numerico que corresponde a la frecuencia
			//como estamos escaneando texto procedemos a convertir la cadena
			//a entero mediante atoi
			fgets(escaneados,10,frecuenciasTXT);
			(*lista)->data.frecuencia = atoi(escaneados);

			//Declaramos la posicion siguiente a NULL
			(*lista)->siguiente = NULL;

			//Aunmentamos en 1 el tamano de la lista para usar la varaible en futuras
			//funciones que lo requieran
			tamanoLista++;
		}
		else{

			//En caso de que la lista ya tenga nodos creados lo que procedemos a hacer
			//es crear un nuevo nodo que contendra los datos de la lista
			ListaEnlazada nuevoNodo;
			nuevoNodo = (NodoLista *)malloc(sizeof(NodoLista));

			//Escaneamos la letra siguiente del archivo de frecuencias y la almacenamos
			//dentro del la variable letra
			fgets(escaneados,5,frecuenciasTXT);
			nuevoNodo->data.letra = escaneados[0];

			//Posteriormente escaneamos la frecuencia de la letra y de igual manera
			//mediante atoi convertimos la cadena escaneada en enteros
			fgets(escaneados,10,frecuenciasTXT);
			nuevoNodo->data.frecuencia = atoi(escaneados);

			//actualizamos la cabeza de la lista enlazada
			nuevoNodo->siguiente = *lista;
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
	*lista = (*lista)->siguiente;

	//Restamos en 1 el tamano de la lista debido a esta situacion
	tamanoLista--;

	//Cerramos el archivo de frecuencias que ya no nos sera util a partir de ahora
	fclose(frecuenciasTXT);
}

/*
funcion invertira la lista ya creada con el fin de tener
los datos en el mismo orden que el archivo de codificacion

RECIBE
lista 			lista enlazada donde pondremos los valores del archivo
listaInvertida	lista donde tendra los valores invertidos en el orden correcto

DEVUELVE
Nada
*/
void invertirLista(ListaEnlazada *lista, ListaEnlazada *listaInvertida){

	//Creamos un auxiliar para dezplazarnos en la lista original
	ListaEnlazada listaAuxiliar = *lista;

	//Haremos este procedimiento hasta haber concluido con los elementos de la lista
	while(listaAuxiliar != NULL){

		//En caso de que la lista que tendra los datos invertidos (al derecho) no haya
		//sido inicializada lo que haremos es iniciarla con los valores del nodo cabeza
		//de la lista original
		if (*listaInvertida == NULL){

			//Asignamos memoria para este nodo cabeaa
			*listaInvertida = (NodoLista *)malloc(sizeof(NodoLista));

			//guardamos los valores de la lista original en la nueva
			(*listaInvertida)->data.letra = listaAuxiliar->data.letra;
			(*listaInvertida)->data.frecuencia = listaAuxiliar->data.frecuencia;

			//Declaramos la siguiente posicion igual a NULL
			(*listaInvertida)->siguiente = NULL;

			//Nos dezplazamos en una posicion en la lista auxiliar
			listaAuxiliar = listaAuxiliar->siguiente;
		}
		else{

			//En caso de que la lista ya haya sido iniciada haremos el mismo procedimiento
			//anterior usando un nuevo nodo esta vez
			ListaEnlazada nuevoNodo;
			
			//Asignamos memoria para este nodo cabeaa
			nuevoNodo = (NodoLista *)malloc(sizeof(NodoLista));

			//guardamos los valores de la lista original en la nueva
			nuevoNodo->data.letra = listaAuxiliar->data.letra;
			nuevoNodo->data.frecuencia = listaAuxiliar->data.frecuencia;

			//actualizamos la cabeza de la lista enlazada
			nuevoNodo->siguiente = *listaInvertida;
			*listaInvertida = nuevoNodo;

			//Nos dezplazamos en una posicion en la lista original
			listaAuxiliar = listaAuxiliar->siguiente;
		}
	}
}

/*
funcion que imprimira la lista enlaza invertida en orden
Funcion de DEBUGG o de prueba, no es necesaria para el funcionamiento

RECIBE
listaInvertida		lista enlazada donde pondremos las letras y frecuencias

DEVUELVE
Nada
*/
void imprimirLista(ListaEnlazada lista){

	//Imprimimos la lista enlazada para comprobar que
	//todo se haya ejecutado correctamente
	while(lista != NULL){
		
		//Mandamos a imprimir los datos dentro de la lista enlazada
		//en este caso imprimimos la letra y la frecuncia
		printf("%c", lista->data.letra);
		printf(" %d\n", lista->data.frecuencia);
   		
   		//Avanzamos en uno la posicion y sumamos en el tamanno de la lista
		lista = lista->siguiente;
	}
}

/*
funcion que copiara datos de la lista enlazada a la del arbol de huffman

RECIBE:
listaInvertida 		Lista donde tendremos los caracteres ordenados

DEVUELVE
Nada
*/
void copiarLista(ListaEnlazada listaInvertida){

	//Variable para los ciclos que manejaremos
	int i;

	//Declaramos el arreglo de estructuras del tamano total de elementos
	//de la lista enlazada
	arbol = (NodoArbol **)malloc(tamanoLista*sizeof(NodoArbol *));

	//creamos un total de tamanolista nodos con valores vacios para
	//para posteriormente llenarlos con los datos de la lista
	for (i = 0; i < tamanoLista; i++){

		//Creamos un nuevo nodo vacio por cada espacio dentro del arreglo
		NodoArbol *nuevaHoja;
		nuevaHoja = (NodoArbol *)malloc(sizeof(NodoArbol));
		nuevaHoja->data.frecuencia = 0;
		nuevaHoja->data.letra = '\0';
		nuevaHoja->izquierda = NULL;
		nuevaHoja->derecha = NULL;

		arbol[i] = nuevaHoja;
	}

	//Ya que tenemos el arreglo lleno con los nodos vacios procedemos a
	//llenarlos con los datos de la lista enlazada
	for (listaInvertida, i = 0; listaInvertida != NULL ; i++, listaInvertida = listaInvertida->siguiente){

		arbol[i]->data.frecuencia = listaInvertida->data.frecuencia;
		arbol[i]->data.letra = listaInvertida->data.letra;		
	}
}

/*
funcion que creara el arbol de huffman

RECIBE
Nada

DEVUELVE
Nada
*/
void crearArbolHuffman(){

	//Crearemos un nodo de tipo arbol temporal con el fin de ayudarnos
	//en el ordenamiento posterior a la creacion de un arbol
	NodoArbol *temporal;

	//Haremos un ciclo que se terminara hasta que solamente tengamos
	//un unico nodo en la posicion 0 donde sabremos que es donde estara
	//el arbol de huffman
	while(arbol[1] != NULL ){

		//Creamos el nodo arbol que juntara 2 caracteres con sus frecuencias
		//o 2 nodos si se tienen arboles en arreglo ya creados
		NodoArbol *auxiliar;
		auxiliar = (NodoArbol *)malloc(sizeof(NodoArbol));
		auxiliar->data.frecuencia = arbol[0]->data.frecuencia + arbol[1]->data.frecuencia;
		auxiliar->data.letra = '\0';
		auxiliar->izquierda = arbol[0];
		auxiliar->derecha = arbol[1];

		//Una vez que ya se tenga un arbol creado recorremos una
		//posicion el arreglo hacia atras con el fin de eliminar los
		//nodos enlazados en el nuevo nodo anterior
		for (int i = 0; i < tamanoLista-1; i++){

			arbol[i] = arbol[i+1];
		}

		//Una vez terminando de dezplazar los datos eliminarmos el ultimo nodo
		//ya que este estara repetido
		arbol[tamanoLista-1] = NULL;

		//Insertamos el arbol creado en la posicion 0 de nuestro arreglo
		arbol[0] = auxiliar;

		//Una vez que ya tenemos insertado el arbol procederemos a su ordenamiento
		//dentro del arreglo
		for (int i = 0; i < tamanoLista-2; i++){

			//Haremos un ciclo de simple intercambio, un metodo de burbuja a la mitad
			if (arbol[i]->data.frecuencia >= arbol[i+1]->data.frecuencia){

				temporal = arbol[i+1];
				arbol[i+1] = arbol[i];
				arbol[i] = temporal;
			}
		}
		
		//Iremos reduciendo en 1 nuestro tamano de la lista por cada nueva pareja
		//de nodos enlazada a un arbol
		tamanoLista--;
	}
}

/*
funcion que imprimira el arbol de huffman en preorden

RECIBE
arbolDeHuffman 		arbol donde tendremos el arbol de huffman ya creado

DEVUELVE
Nada
*/
void preorden (arbolHUFFMAN arbolDeHuffman){

	//Primeramente nos sercioramos de que nuestro arbol no sea NULL
	if (arbolDeHuffman != NULL){

		//Imprimimos la letra y su frecuencia dentro del nodo del arbol
		printf("%c ", arbolDeHuffman->data.letra);
		printf("%d\n", arbolDeHuffman->data.frecuencia);

		//usamos la recursion para desplazarnos primero a la izquierda y 
		//luego a la derecha del arbol
		preorden(arbolDeHuffman->izquierda);
		preorden(arbolDeHuffman->derecha);
	}
}

int crearDecodificacion(arbolHUFFMAN arbolDeHuffman){

	//Creamos una variable para leer el archivo con la codificacion
	FILE *codificado = NULL;

	//Creamos una varaible para escribir el archivo decodificado
	FILE *decodificado = NULL;

	//Declaramos una variable auxiliar de tipo arbol que nos ayudara
	//para recorrer el arbol en el orden en que se presentan los bits
	arbolHUFFMAN arbolAuxiliar = arbolDeHuffman;

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

	//Abrimos el archivo decodificado en modo escritura normal	
	// decodificado = fopen(cadenaPrueba, "w");
    printf("%s", cadenaPrueba);

    //Comprobamos que el archivo codificado se haya abierto correctamente
	if(codificado == NULL){

		printf("Error en Codificacion\n"); 
		return -1;
	}

	//comprobamos que el archivo decodificado se haya abierto correctamente
	// if(decodificado == NULL){

	// 	printf("Error en Decodificacion\n"); 
	// 	return -1;
	// }

	do{

		//Escaneamos el primer caracter dentro de codificado
		caracterEscaneado = fgetc(codificado);

		//Escanea el End Of File, si se llega a este valor
		//se rompera el ciclo
		//if (feof(codificado) == 1) break;

		//Iniciamos en el nodo raiz del arbol
        cambiarByte = FALSE;

        //Escaneamos el primer bit del caracter escaneado
		do{

			if ((arbolAuxiliar->izquierda == NULL) && (arbolAuxiliar->derecha == NULL)){

                fputc(arbolAuxiliar->data.letra, decodificado);
                arbolAuxiliar = arbolDeHuffman;
            }
			else{
                valorBinario = CONSULTARBIT(caracterEscaneado, posicionBit);
                if (valorBinario == 0){
                    arbolAuxiliar = arbolAuxiliar->izquierda;
                    
                }else{
                    arbolAuxiliar = arbolAuxiliar->derecha;
                }
                    posicionBit--;
                    if (posicionBit == -1){
                        posicionBit = 7;
                        cambiarByte = TRUE;
                        fputc(arbolAuxiliar->data.letra, decodificado);
                        arbolAuxiliar = arbolDeHuffman;
                    }
                    
            }

		}while(cambiarByte != TRUE);

	}while(!feof(codificado));



}