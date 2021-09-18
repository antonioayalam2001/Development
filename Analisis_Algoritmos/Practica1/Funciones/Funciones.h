#ifndef Funciones
#define Funciones
// Documentar Funciones
int *LeerArchivo(int *A, int n);
    // Realiza la lectura del archivo de 10 millones de numeros 
    // Uso: LeerArchivo(int *A,int n);
    // A: Arreglo de numeros no vacio (Obligatorio)
    // n: Cantidad de elementos que queremos tomar (Obligatorio)

void MenuSeleccion(int *A, int n,int opc);
//Declaracion cabecera de Funciones
void Burbuja(int *numeros, int n);
    // Realiza el ordenamiento de tipo burbuja
    // Uso: Burbuja(int *A,int n);
    //A: Arreglo de numeros no vacio (Obligatorio)
    // n: Cantidad de elementos del arreglo (Obligatorio)
void BurbujaOptimizada(int *A, int n);
    // Realiza el ordenamiento de tipo burbuja Optimizada 1
    // Uso: BurbujaOptimizada(int *A,int n);
    // A: Arreglo de numeros no vacio (Obligatorio)
    // n: Cantidad de elementos del arreglo (Obligatorio)
void Burbuja2(int *A, int n);
    // Imprime el arreglo ordenado
    // Uso: imprimeArreglo (A,n);
    // A: Arreglo de elementos no vacío (Obligatorio)
    // n: longitud del arreglo 

void Insercion(int *A, int n);
    // Realiza el ordenamiento de tipo Insercion 
    // Uso: Insercion(A,n);
    // A: Arreglo de numeros no vacio (Obligatorio)
    // n: Cantidad de elementos del arreglo (Obligatorio)

void Shell(int *A, int n);
    // Realiza el ordenamiento de Tipo Shell
    // Uso: Shell(A,n);
    // A: Arreglo de elementos no vacío (Obligatorio)
    // n: longitud del arreglo 

void imprimirArreglo(int *A,int n);
    // Imprime el arreglo ordenado
    // Uso: imprimeArreglo (A,n);
    // A: Arreglo de elementos no vacío (Obligatorio)
    // n: longitud del arreglo 

void Selection(int *A, int n);
    // Realiza el ordenamiento de la forma de Seleccion
    // Uso: Selection(A,n)
    // A: Arreglo de numeros no vacio (Obligatorio)
    // n: Cantidad de elementos del arreglo (Obligatorio)

void Quicksort2(int *A, int i, int n);
    // Realiza el ordenamiento mediante QuickSort, el cual funciona de manera recursiva, recibe un arreglo
    // no vacio, asi como la cantidad de elementos que contiene -1 (debido a que buscamos obtener la
    // utlima posicion)
    // A: Arreglo de elementos no vacio
    // i  (primer elemento) con respecto al cual queremos realizar el ordenamiento (en este caso 0)
    // n -1 : Tamaño del arreglo - 1
    // Uso: QuickSort2(A,0,n-1) 

void MergeSort(int *A, int p, int r);
    // Realiza el ordenamiento de elementos de forma recursiva 
    // Uso: MergeSort(A,0,n-1)
    // A: Arreglo de elementos no vacio
    // p : Primera posicion 
    // r = n-1 (tamaño del arreglo menos una posicion, por la forma en que se indexa) 

void Merge(int *A, int p, int q, int r);

    // A: Arreglo de elementos no vacio
    // p: posicion del primer elemento
    // q: Parte entera obtenida a partir de la division de p/r realizada en la implementacion de la funcion
    // r: ultima posicion 

int parteEntera(double n);
    // Recibe un numero y lo manda a piso (redondeo hacia abajo) para obtener un valor de tipo entero

void ArbolBinario (int *A,int n);
    // Recibe un arreglo y tamaño del arreglo
void ImprimirTiempos(double utime0, double stime0, double wtime0, double utime1, double stime1, double wtime1);
    // Imprime los tiempos que tomo en ser ejecutado el programa de forma  decimal y de forma exponencial
    // Uso: ImprimirTiempos(utime0, stime0, wtime0, utime1, stime1, wtime1)
    // utime0,stime0,wtime0 : Vairables del tiempo inicial (deberia ser 0)
    // utime1, stime1, wtime1: Variables de tiempo final
#endif //Funciones