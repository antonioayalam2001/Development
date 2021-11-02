#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PESOBIT(bpos) 1<<bpos
#define CONSULTARBIT(var,bpos) (*(unsigned*)&var & PESOBIT(bpos))?1:0
#define PONE_1(var,bpos) *(unsigned*)&var |= PESOBIT(bpos)
#define PONE_0(var,bpos) *(unsigned*)&var &= ~(PESOBIT(bpos))
#define CAMBIA(var,bpos) *(unsigned*)&var ^= PESOBIT(bpos)

//Estructura que creara el nodo con el caracter y su frecuencia
typedef struct datos{
	char letra;
	int frecuencia;
	int binario[8];
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

//Variable con el tamanno total de la lista enlazada
int tamanoLista;

//Variable con el tamano total de bytes del archivo de entrada
int totalDeBytes;

//Variable global que nos ayudara a la obtencion de datos en
//binario de cada letra
int auxiliarBinario[8];

/*
Prototipo de la funcion que inicializara nuestra lista enlazada

RECIBE:
lista 			Lista donde tendremos los caracteres ordenados
caracteres[] 	arreglo de caracteres escaneados del archivo
bytes 			numero total de bytes escaneados del archivo

DEVUELVE
Nada
*/
void crearLista(ListaEnlazada *lista, char caracteres[], int bytes);

/*
Prototipo de la funcion que creara la lista enlazada

RECIBE:
lista 		Lista donde tendremos los caracteres ordenados
caracter 	caracter que se almacenara en la lista enlazada	

DEVUELVE
Nada
*/
void completarlista(ListaEnlazada *lista, char caracter);

/*
Prototipo de la funcion que ordenara la lista enlazada

RECIBE:
lista 		Lista donde tendremos los caracteres ordenados

DEVUELVE
Nada
*/
void ordenarLista(ListaEnlazada *lista);

/*
Prototipo de la funcion que imprimira la lista enlaza DEBUG

RECIBE:
lista 		Lista donde tendremos los caracteres ordenados

DEVUELVE
Nada
*/
void imprimirLista(ListaEnlazada lista);

/*
Prototipo de la funcion que imprime el archivo frecuenas.txt

RECIBE
lista 		lista enlazada con los valores de frecuancia y letra

DEVUELVE
-1 si el archivo no se pudo abrir
*/
int crearFrecuenciastxt(ListaEnlazada lista);

/*
Prototipo de la funcion que copiara datos de la lista
enalazada a la del arbol de huffman

RECIBE:
lista 		Lista donde tendremos los caracteres ordenados
arbol 		Estructura para el arbol de huffman

DEVUELVE
Nada
*/
void copiarLista(ListaEnlazada lista);

/*
Prototipo de la funcion que creara el arbol de huffman

RECIBE
Nada

DEVUELVE
Nada
*/
void crearArbolHuffman();

/*
Prototipo de la funcion que obtendra el valor binario de 
cada caracter segun el arbol de huffman

RECIBE
arbolImpresion	arbol de huffman
posicion 		valor de la posicion donde se insertara el bit
bit 			valor del bit 0 o 1
izquierda 		contador que nos dira el numero de veces que fuimos a la izquierda
derecha 		contador que nos dira el numero de veces que fuimos a la derecha

DEVUELVE
Nada
*/
void obtenerBinario(arbolHUFFMAN *arbolImpresion, int posicion, int bit, int izquierda, int derecha);

/*
Prototipo de la funcion que imprime el arbol de Huffman
en preorden

RECIBE
arbolImpresion	arbol de huffman creado listo para ser
imprimido en pantalla

DEVUELVE
Nada
*/
void guardarEnLista(arbolHUFFMAN arbolImpresion, ListaEnlazada *listaBinaria);

/*


RECIBE


DEVUELVE
Nada
*/
int crearCodificacionDAT(ListaEnlazada listaBinaria, FILE *archivo);

/*


RECIBE


DEVUELVE
Nada
*/
int cmpchar(char cadena1, char cadena2);

int main(int argc, char const *argv[]){

	//Variable auxiliar con los caracteres escaneados
	//de tamano de 1024 caracteres o bytes
	char listaDeCaracteres[1024];

	//Numero de bytes leidos por la llamada al archivo
	int bytesLeidos;

	//Inicializacion de la variable archivo para operar el 
	//archivo que se escaneara
	FILE *archivo = NULL;

	//Inicializacion de la cabeza de la lista enlazada sin
	//datos por el momento
	ListaEnlazada lista = NULL;

	//inicilizacion de una lista enlazada que contiene los
	//valores binarios de cada letra
	ListaEnlazada listaBinaria = NULL;

	if(argc!=2){

        printf("Ingresa el nombre del archivo\n",argv[0]);
        exit(0);    
    }

    //abrimos el archivo en modo solo lectura
    else archivo = fopen(argv[1], "rb");
    
	//Comprobamos si el archivo fue abierto correctamente
	if (archivo == NULL){

		printf("Error\n"); 
		return -1;
	}
 
	do{

		//Guardamos en bytes leidos el tamano de bytes escaneados
		bytesLeidos = fread(listaDeCaracteres, sizeof(char), 1024, archivo);

		//Guardamos el total de bytes leido cada vez para obtener el total
		totalDeBytes = totalDeBytes + bytesLeidos;

		//mandamos a llamar a crear lista donde mandamos el arreglo
		//de caracteres y el numero de bytes leidos
		crearLista(&lista, listaDeCaracteres, bytesLeidos);

	//Haremos esto hasta que lleguemos al final del archivo
	}while(!feof(archivo));

	//Imprimimos los datos del archivo de entrada
	printf("Nombre del archivo: %s - Tamanno en bytes: %d\n", argv[1], totalDeBytes);

	//Mandamos a ordenar la lista por el tamano de frecuencia
	ordenarLista(&lista);

	//Imprimimos la lista para comprobar que todo esta correcto
	//tambien nos ayudara a obtener el tamanno de la lista enlazada
	imprimirLista(lista);

	//Creamos el archivo frecuencias.txt
	if (crearFrecuenciastxt(lista) == -1) return -1;

	//Copiamos los valores de la lista enlazada en el arbol de huffman
	copiarLista(lista);

	//Ahora procedemos a crear nuestro arbol de huffman para la 
	//codificicacion futura
	crearArbolHuffman();

	//Creacion de un nodo arbol para la impresion y manipulacion ordenada
	arbolHUFFMAN arbolImpresion = arbol[0];

	//Funcion que recorre el arbol y obtiene el binario de un caracter
	obtenerBinario(&arbolImpresion, -1, 0, 0, 0);
	
	//guardamos los datos en binario en una nueva lista enlazada para
	//mas comodidad
	guardarEnLista(arbolImpresion, &listaBinaria);

	//Imprimimos la lista para saber que todo los datos se hayan
	//registrado de manera correcta - DEBUGG
	//imprimirLista(listaBinaria);

	//funcion para crear el archivo codificado
	crearCodificacionDAT(listaBinaria, archivo);

	//Cerramos el archivo una vez que terminemos de escanearlo
	fclose(archivo);

	//Liberamos la memoria de la cabeza de la lista enlazada
	free(lista);

	//liberamos la memoria de el arbol de huffman
	free(arbol);

	//liberamos la memoria de nuestro arbol de huffman de impresion
	free(arbolImpresion);

	//Liberamos la memoria para nuestra lista enlzada con nuestros
	//datos en binario
	free(listaBinaria);

	//Imprimios este mensaje para saber que el programa se haya
	//ejecutado u terminado sin ningun problema
	printf("Programa terminado con exito\n");
}

void crearLista(ListaEnlazada *lista, char caracteres[], int bytes){

	//Si nuestra lista no tiene elementos, procedemos a crear el 
	//primer elemento de la lista enlazada
	if (*lista == NULL){

		*lista = (NodoLista *)malloc(sizeof(NodoLista));
		(*lista)->data.letra = caracteres[0];
		(*lista)->data.frecuencia = 1;
		(*lista)->siguiente = NULL;	
	}

	//Continuamos con la creacion de la lista enlazada insertando
	//los caracteres siguientes
	for (int i = 1; i < bytes; i++){

		completarlista(&(*lista), caracteres[i]);
	}
}

void completarlista(ListaEnlazada *lista, char caracter){
	//bandera que nos determina si es necesario crear un
	//nuevo nodo y agregarlo a la lista enlazada
	bool banderaNuevoNodo = false;

	//Lista auxiliar para no perder la cabeza de la lista
	ListaEnlazada listaAuxiliar = *lista;

	//Haremos un ciclo que durara hasta que se llegue al 
	//final de la lista, este ciclo busca actualizar la 
	//frecuencia del caracter ingresado o insertar un 
	//nuevo nodo en caso de que no se encuentre
	do{

		//comparamos si el caracter ya esta en la lista
		if (listaAuxiliar->data.letra == caracter){

			//Si ya existe marcamos false nuestra bandera
			banderaNuevoNodo = false;

			//aumentamos en 1 la frecuencia de la letra
			listaAuxiliar->data.frecuencia++;

			//cerramos el ciclo para evitar hacer mas
			//comparaciones innecesarias
			return;
		}
		//Si no se encontro el caracter, igualamos 
		//nuestra bandera a true indicando que necesitamos
		//crear un nuevo nodo para la lista
		else banderaNuevoNodo = true;

		//Nos movemos a la posicion siguiente de la lista
		listaAuxiliar = listaAuxiliar->siguiente;

	}while(listaAuxiliar != NULL);

	//Comprobacion de que requerimos un nuevo nodo
	if (banderaNuevoNodo){

		//creamos un nuevo nodo con los datos del caracter
		ListaEnlazada nuevoNodo;
		nuevoNodo = (NodoLista *)malloc(sizeof(NodoLista));
		nuevoNodo->data.letra = caracter;
		nuevoNodo->data.frecuencia = 1;
		//actualizamos la cabeza de la lista enlazada
		nuevoNodo->siguiente = *lista;
		*lista = nuevoNodo;
	}
}

void ordenarLista(ListaEnlazada *lista){

	//Ordenamiento para la lista enlazada (Metodo Burbuja)

	//variables auxiliares para la manipulcacion de la listas
	ListaEnlazada listaActual, listaSiguiente;

	//variables auxiliares para guardar los valores de los
	//nodos de la lista a intercambiar
	int frecuenciaAux;
	char caracterAux;

	//Igualamos la cabeza de la lista a nuestro auxiliar
	listaActual = *lista;

	//Ciclo que recorrera la lista hasta que la posicion
	//siguiente sea NULL
	while(listaActual->siguiente != NULL){

		//asignamos la posicion de siguiente a listasiguiente
		listaSiguiente = listaActual->siguiente;

		//ciclo que se ejecutara mientras la lista sea diferente
		//de NULL (hasta que lleguemos al final)
		while(listaSiguiente != NULL){

			//Si la frecuencia de actual es mayor a la frecuencia de siguiente
			//procederemos a intercambiar los valores de los nodos de la lista
			if (listaActual->data.frecuencia >= listaSiguiente->data.frecuencia){

				//Metodo de simple intercambio entre 2 posiciones

				//guardamos la frecuencia y la letra de nuestro nodo siguiente
				frecuenciaAux = listaSiguiente->data.frecuencia;
				caracterAux = listaSiguiente->data.letra;

				//Movemos los datos de actual a la posicion siguiente
				listaSiguiente->data.frecuencia = listaActual->data.frecuencia;
				listaSiguiente->data.letra = listaActual->data.letra;
				
				//Nuestros valores guardados los movemos a la posicion actual
				listaActual->data.frecuencia = frecuenciaAux;
				listaActual->data.letra = caracterAux;					
			}

			//Nos desplazamos en la lista de siguiente una posicion
			//Moveremos a los datos de actual hasta que ya no sean mayores 
			//a la posicion de siguiente
			listaSiguiente = listaSiguiente->siguiente;
		}

		//Nos desplasamos en uno en cada lista, los nodos anteriores de la lista
		//ya estan ordenados, es decir son numeros menores
		listaActual = listaActual->siguiente;
		listaSiguiente = listaActual->siguiente;
	}

	//printf("Ordenamiento completado con exito\n");
}

void imprimirLista(ListaEnlazada lista){
	
	//Para saber el tamano de la lista sumaremos en 1
	//cada iteracion del ciclo, inicializamos la cuenta
	tamanoLista = 0;

	//Imprimimos la lista enlazada para comprobar que
	//todo se haya ejecutado correctamente
	while(lista != NULL){
	/*	
		//DEBUGG
		//Mandamos a imprimir los datos dentro de la lista enlazada
		//en este caso imprimimos la letra y la frecuncia
		printf("%c", lista->data.letra);
		printf(" %d\n", lista->data.frecuencia);

		//En caso de que ya se haya obtenido los bits con base en el arbol
		//de Huffman imprimiremos los bits de cada letra
		//Si aun no se crea el arbol de huffman entonces el valor en las
		//posiciones de la varaible binario estaran vacios, en caso contrario
		//tendran valores ya sea 0 o 1, de esta manera si comprobamos la primera
		//posicion con 0 o 1 sabremos que esta la lista ya tiene los datos del
		//arbol de Huffman
		if ((lista->data.binario[0] == 1) || (lista->data.binario[0] == 0)){
       		for (int i = 0; i < lista->data.frecuencia; i++)
       			printf("%d ", lista->data.binario[i]);

       		printf("\n");	
		}
   	*/	
   		//Avanzamos en uno la posicion y sumamos en el tamanno de la lista
		lista = lista->siguiente;
		tamanoLista++;
	}
}

int crearFrecuenciastxt(ListaEnlazada lista){

	//Declaramos una cadena que tendra nuestro encabezado para el
	//el archivo de frecuencias
	char cadena[] = "Tabla de frecuencias\n";

	//Declaramos una nueva variable para abrir el archivo
	FILE *frecuenciasTXT = NULL;

	//Abrimos el archivo frecuencias.txt, en caso de que no exista
	//se genera el archiv automaticamente
	frecuenciasTXT = fopen("frecuencias.txt", "w");

	//Verificamos que el archivo se haya abierto de manera correcta
	if (frecuenciasTXT == NULL){

		printf("Error\n"); 
		return -1;
	}

	//Insertamos el encabezado dentro de nuestro archivo con fputs
	fputs(cadena, frecuenciasTXT);

	//Mientras nuesta lista de frecuencias no sea NULL, insertaremos los datos
	//dentro de la lista como la letra y la frecuencia en el archivo
	while(lista != NULL){

		//Imprimimos la letra y la frecuencia de la lista usando fprintf
		fprintf(frecuenciasTXT, "%c - %d\n", lista->data.letra, lista->data.frecuencia);
		lista = lista->siguiente;
	}

	//Una vez acabado de ingresar todo dentro de nuestro archivo procedemos
	//ah cerrar el archivo
	fclose(frecuenciasTXT);
}

void copiarLista(ListaEnlazada lista){

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
	for (lista, i = 0; lista != NULL ; i++, lista = lista->siguiente){

		arbol[i]->data.frecuencia = lista->data.frecuencia;
		arbol[i]->data.letra = lista->data.letra;		
	}
}

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

void obtenerBinario(arbolHUFFMAN *arbolImpresion, int posicion, int bit, int izquierda, int derecha){

 	//Obtendremos el binario usando como base el recorrido en preorder de un arbol
    if (*arbolImpresion != NULL) {

    	//Iremos insertando el valor del bit dependiendo si nos vamos por izquierda con valor 0
    	//o si vamos por la derecha con 1, en la primera llamada en el main como no hemos 
    	//recorrido ninguna posicion dentro del arbol por eso tendremos el valor de -1 donde no
    	//guardaremos ningun valor dentro del arreglo
    	if (posicion != -1){
    		auxiliarBinario[posicion] = bit;
    	}

    	//Si nos encontramos en un nodo hoja donde tenemos la frecuencia y la letra haremos
    	//las siguientes operaciones, en caso de que no seguiremos recorriendo el arbol
    	if ((*arbolImpresion)->izquierda == NULL && (*arbolImpresion)->derecha == NULL){

    		//Haremos un ciclo que dependiendo de las veces que nos hayamos dezplazado en la
    		//izquierda o la derecha insertaremos los valores guardados en nuestro arreglo
    		//auxiliar en nuestra variable dentro de la estructura
    		for (int i = 0; i < (izquierda + derecha); i++){

    			//igualamos los datos dentro de nuestro auxilair con nuestro valor dentro
    			//de la estructura
    			(*arbolImpresion)->data.binario[i] = auxiliarBinario[i];	
    		}

    		//Como en este punto la frecuencia de las letras ya no nos es util lo remplazaremos
    		//con el numero de bites que se registraron, aun que el arreglo tiene los 8 bits,
    		//cuando escribamos en el archivo .dat esto nos sera de ayuda para 
    		//insertar los valores dentro del arreglo
    		(*arbolImpresion)->data.frecuencia = izquierda + derecha;
    	}
    	else{
    		//Dependiendo hacia donde nos dezplasemos sumaremos en 1 la posicion para insertar en
    		//el arreglo, ademas de que llevaremos el conteno de los  dezplacamiento hacia la 
    		//izquierda o hacia la derecha
    		obtenerBinario(&(*arbolImpresion)->izquierda, posicion+1, 0, izquierda+1, derecha);
       		obtenerBinario(&(*arbolImpresion)->derecha, posicion+1, 1, izquierda, derecha+1);
    	}
    }
}

void guardarEnLista(arbolHUFFMAN arbolImpresion, ListaEnlazada *listaBinaria) {

	//Haremos este proceso mientras el valor no sea NULL, apoyandonos en el
	//recorrido en preorden de la funcion
    if (arbolImpresion != NULL) {

    	//Si estamos en un nodo hoja haremos lo siguiente, caso de que no sea un
    	//nodo hoja nos dezplazaremos a la izquierda o derecha
        if (arbolImpresion->izquierda == NULL && arbolImpresion->derecha == NULL){

        	//en caso de que la lista binaria sea NULL, crearemos un nuevo nodo con el
        	//primer valor encontrado en el nodo hoja del arbol a este primer nodo
        	//de la lista que tendra nuestras frecuencias, letra y binario
        	if (*listaBinaria == NULL){

				*listaBinaria = (NodoLista *)malloc(sizeof(NodoLista));
				(*listaBinaria)->data.letra = arbolImpresion->data.letra;
				(*listaBinaria)->data.frecuencia = arbolImpresion->data.frecuencia;

				//Insertamos el numero binario de la letra segun el arbol de huffman
				for (int i = 0; i < arbolImpresion->data.frecuencia; i++)
					(*listaBinaria)->data.binario[i] = arbolImpresion->data.binario[i];

				(*listaBinaria)->siguiente = NULL;	
			}
			else{

				//En caso de que no sea el primer nodo lo que haremos es de igual forma
				//crear un nuevo nodo que insertaremos dentro de la lista con los datos
				//del siguiente nodo hoja encontrado en el arbol
				ListaEnlazada nuevoNodo;
				nuevoNodo = (NodoLista *)malloc(sizeof(NodoLista));
				nuevoNodo->data.letra = arbolImpresion->data.letra;
				nuevoNodo->data.frecuencia = arbolImpresion->data.frecuencia;

				//Insertamos el valor binario del arbol en la lista para esta letra
				for (int i = 0; i < arbolImpresion->data.frecuencia; i++)
					nuevoNodo->data.binario[i] = arbolImpresion->data.binario[i];

				//actualizamos la cabeza de la lista enlazada
				nuevoNodo->siguiente = *listaBinaria;
				*listaBinaria = nuevoNodo;
			}
        }
        else {

        	//En caso de que no estemos en un nodo hoja nos seguiremos
        	//dezplasando dentro del arbol
	        guardarEnLista(arbolImpresion->izquierda, &(*listaBinaria));
	        guardarEnLista(arbolImpresion->derecha, &(*listaBinaria));
    	}
    }
}

int crearCodificacionDAT(ListaEnlazada listaBinaria, FILE *archivo){

	//Declaramos un variable para escribir el archivo de salida
	FILE *codificacion = NULL;

	//Declaramos una listaEnlazada auxiliar para dezplazarnos
	//en la lista sin perder el origen o cabeza
	ListaEnlazada listaAuxiliar = listaBinaria;

	//Declaramos la variable donde guardaremos el caracter
	//escaneado del archivo original
	char caracterEscaneado;

	//Variable auxiliar que tendra el caracter de la lista que coincida
	//con el escaneado (Necesitado para usar el strcmp())
	char caracterLista;

	int posicionBit = 7;

	int posicionByte = 0;

	int queryValue;

	int random;

	//Inicializamos una arreglo con 1024 posiciones
	unsigned char arreglo[1024];

	//Procedemos a llenar el arreglo con datos cualquiera
	//en este caso lo llenaremos de 0
	for(int i = 0; i < 1024; i++)
		arreglo[i] = 0;

	//Abrimos o creamos el archivo donde tendremos la codificacion
	//em modo escritura binaria
	codificacion = fopen("codificacion.dat", "wb");

	//Verificamos que el archivo se haya abierto de manera correcta
	if (codificacion == NULL){

		printf("Error al crear/abrir codificacion.dat \n");
		return -1;
	}

	//Rebobinamos hasta el inicio del archivo donde tenemos nuestros
	//datos originales
	rewind(archivo);

	//Mientras no lleguemos al final del archivo haremos lo siguiente
	do{

		//Escaneamos el caracter del archivo
		caracterEscaneado = fgetc(archivo);

		//Escanea el End Of File, si se llega a este valor
		//se rompera el ciclo
		if (feof(archivo) == 16) break;

		//Volvemos a la cabeza de la lista enlazada
		listaAuxiliar = listaBinaria;

		//Lo buscamos en la lista enlazada
		for (listaAuxiliar; listaAuxiliar != NULL; listaAuxiliar = listaAuxiliar->siguiente){

			//Igualamos el caracter de la lista a la variable de apoyo
			caracterLista = listaAuxiliar->data.letra;

			//Si encontramos la letra rompemos el ciclo
			if(cmpchar(caracterLista, caracterEscaneado)){
				break;
			}
		}

		for (int j = 0; j < listaAuxiliar->data.frecuencia; j++){

			queryValue = CONSULTARBIT(arreglo[posicionByte],posicionBit);
			random = listaAuxiliar->data.binario[j];

			if (queryValue != random){
				CAMBIA(arreglo[posicionByte],posicionBit);
			}

			posicionBit--;

			if (posicionBit == -1){

				posicionBit = 7;
				posicionByte++;
			}

			if (posicionByte == 1024){

				fwrite(arreglo, sizeof(unsigned char), 1024, codificacion);
				posicionByte = 0;
			}
		}
	}while(!feof(archivo));

	if (posicionByte < 1024){
		if (posicionBit == 7)
		{
			fwrite(arreglo, sizeof(unsigned char), posicionByte, codificacion);
		}else{
			fwrite(arreglo, sizeof(unsigned char), posicionByte+1, codificacion);
		}
		
	}

	// for (int m = 0; m < 4; m++)
	// {
	// 	for (int k = 7; k >= 0; k--)
	// 	{
	// 		printf("%d ", CONSULTARBIT(arreglo[m],k));
	// 	}
	// 	printf("\n");
	// }

	// //if((posicionByte < 1024) && (posicionByte != 0))
	// 	fwrite(arreglo, sizeof(unsigned char), 4, codificacion);

	fclose(codificacion);
}

int cmpchar(char cadena1, char cadena2){

	//Declaramos 2 variables auxiliares para guardar los bits
	//resultantes
	int j, k;

	//Iniciamos el ciclo para analizar los 8 bits
	for(int i = 0; i < 8; i++){

		//Guardamos el bit de cada cadena en la posicion de
		//i para analizarlos
		j = CONSULTARBIT(cadena1,i);
		k = CONSULTARBIT(cadena2,i);

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