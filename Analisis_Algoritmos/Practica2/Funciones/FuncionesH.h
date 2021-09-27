#ifndef FuncionesH
#define FuncionesH

// void BusquedaLinealHilos(int * arreglo, int valorABuscar, int inicio, int final, int * encontrado);
int *LeerArchivo(int *A, int n);
// void BusquedaLineal(int * arreglo, int valorABuscar, int inicio, int final, int * encontrado);

// // Mis hilos
// //          Busqueda Lineal Hilos           // //
// //Recibe: Arreglo, tamaño del arreglo, elemento a buscar, (bandera para saber cuando el emeento haya sido encontrado)
// //Devuelve: vacio
// //Funcion: Realizar la busqueda de un elemento dado mediante la opcion de Hilos
// //Uso: BusquedaLineal(A,0,n,valor,*aviso)
// //
void * lanzarBusquedaLineal(void* busqueda);
void * lanzarBusquedaBinaria(void* busqueda);
void BusquedaLineal(int *A, int inicio ,int final, int elemn, int *aviso);
void BusquedaLinealHilos(int * A, int valorABuscar, int inicio, int final, int * aviso);
void BusquedaBinaria(int *A,int inicio, int final,int elem,int *aviso);
void BusquedaBinariaHilos(int * A, int valorABuscar, int inicio, int final, int * aviso);
void BusquedaExponencial(int *A,int inicio, int final,int elem,int *aviso);
void BusquedaEnArbol(int * arreglo, int n, int valorABuscar, int * aviso);
void BusquedaEnArbolHilos(int * arreglo, int n, int valorABuscar, int * aviso);
void * procesarBusquedaArbol(void* busqueda);
int min(int x, int y); 
int fibMonaccianSearch(int *A, int x, int n);
#endif