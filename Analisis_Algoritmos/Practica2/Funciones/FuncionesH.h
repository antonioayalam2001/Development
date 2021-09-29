// 3CM12
// Analisis de Algoritmos
// Autores: Mora Ayala Jose, Antonio, Lopez Lopez Oscar Manual
// Jeon Jeong Paola, Lemus Ruiz Mariana ELizabeth
// Cabeceras de funciones 
#ifndef FuncionesH
#define FuncionesH

// void BusquedaLinealHilos(int * arreglo, int valorABuscar, int inicio, int final, int * encontrado);
// void BusquedaLineal(int * arreglo, int valorABuscar, int inicio, int final, int * encontrado);

// // Mis hilos
// //          Busqueda Lineal Hilos           // //
// //Recibe: Arreglo, tamaño del arreglo, elemento a buscar, (bandera para saber cuando el emeento haya sido encontrado)
// //Devuelve: vacio
// //Funcion: Realizar la busqueda de un elemento dado mediante la opcion de Hilos
// //Uso: BusquedaLineal(A,0,n,valor,*aviso)
// //
void BusquedaLineal(int *A, int inicio ,int final, int elemn, int *aviso);
void BusquedaLinealHilos(int * A, int valorABuscar, int inicio, int final, int * aviso);
// // Busqueda Binaria
//Recibimos un arreglo que contiene los numeros del archivo 10 millones
// inicio : Inicio del arreglo
//Un entero "final" para especificar el tamaño del arreglo
//Un entero llamado elemento el cual tiene el número que deseamos encontrar,
//dentro del arreglo
// *aviso: Bandera que nos ayudara a determianr si el elemento ya fue encontrado o no
void BusquedaBinaria(int *A,int inicio, int final,int elem,int *aviso);

// // Busqueda Binaria
//Recibimos un arreglo que contiene los numeros del archivo 10 millones
// inicio : Inicio del arreglo
//Un entero "final" para especificar el tamaño del arreglo
//Un entero llamado elemento el cual tiene el número que deseamos encontrar,
//dentro del arreglo
// *aviso: Bandera que nos ayudara a determianr si el elemento ya fue encontrado o no
void BusquedaBinariaHilos(int * A, int valorABuscar, int inicio, int final, int * aviso);

// BusquedaExponencial //
//Recibimos un arreglo que contiene los numeros del archivo 10 millones
// inicio : Inicio del arreglo
//Un entero "final" para especificar el tamaño del arreglo
//Un entero llamado elemento el cual tiene el número que deseamos encontrar,
//dentro del arreglo
// *aviso: Bandera que nos ayudara a determianr si el elemento ya fue encontrado o no

// BusquedaArbol //
//Recibimos un arreglo que contiene los numeros del archivo 10 millones
// inicio : Inicio del arreglo
//Un entero "final" para especificar el tamaño del arreglo
//Un entero llamado elemento el cual tiene el número que deseamos encontrar,
//dentro del arreglo
// *aviso: Bandera que nos ayudara a determianr si el elemento ya fue encontrado o no
void BusquedaEnArbol(int * arreglo, int n, int valorABuscar, int * aviso);
void BusquedaEnArbolHilos(int * arreglo, int n, int valorABuscar, int * aviso);
// Funcion para devolver el minimo de dos numeros
int min(int x, int y); 

// Recibe arreglo, valor a buscar y tamaño del arreglo
int fibMonaccianSearch(int *A, int x, int n);
int BusquedaExponencial(int *A, int n, int elem, int *aviso);

// Prototipos para afcilitar ejecucion de Hilos
void * lanzarBusquedaLineal(void* busqueda);
void * lanzarBusquedaBinaria(void* busqueda);
void * procesarBusquedaArbol(void* busqueda);

// Funcion para leer el archivo 10millones ordenados
// Recibe : Arreglo de elementos con memoria suficiente para alojar la n cantidad de elementos 
// n: Cantidad de elementos que seran asignados al arreglo
int *LeerArchivo(int *A, int n);
int* Quicksort2(int *A, int primero, int ultimo);
#endif