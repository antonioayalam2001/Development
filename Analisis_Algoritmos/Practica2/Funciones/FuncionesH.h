#ifndef FuncionesH
#define FuncionesH

// void BusquedaLinealHilos(int * arreglo, int valorABuscar, int inicio, int final, int * encontrado);
void MenuSeleccion(int *A, int n, int elem ,int opc);
int *LeerArchivo(int *A, int n);
// void BusquedaLineal(int * arreglo, int valorABuscar, int inicio, int final, int * encontrado);

// // Mis hilos
// //          Busqueda Lineal Hilos           // //
// //Recibe: Arreglo, tamaño del arreglo, elemento a buscar, (bandera para saber cuando el emeento haya sido encontrado)
// //Devuelve: un entero con el aviso
// //Funcion: 
// //Uso:
// //
void BusquedaLineal(int *A, int inicio ,int final, int elemn, int *aviso);
void BusquedaLinealHilos(int * A, int valorABuscar, int inicio, int final, int * aviso);
void BusquedaBinaria(int *A,int inicio, int final,int elem,int *aviso);
void BusquedaBinariaHilos(int * A, int valorABuscar, int inicio, int final, int * aviso);

#endif