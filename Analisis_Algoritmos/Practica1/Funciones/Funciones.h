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



void Insercion(int *A, int n);
    // Realiza el ordenamiento de tipo Insercion 
    // Uso: Insercion(A,n);
    // A: Arreglo de numeros no vacio (Obligatorio)
    // n: Cantidad de elementos del arreglo (Obligatorio)

void Shell(int *A, int n);

void imprimirArreglo(int *A,int n);
    // Imprime el arreglo ordenado
    // Uso: imprimeArreglo (A,n);
    // A: Arreglo de elementos no vacío (Obligatorio)
    // n: longitud del arreglo 



void Selection(int *A, int n);
int Pivote(int *A,int p, int n );
void Intercambiar(int *A, int i, int j);
void QuickSort(int *A, int p, int r);
void Quicksort2(int *A, int i, int n);
void Merge(int *A, int p, int q, int r);
void MergeSort(int *A, int p, int r);
int parteEntera(double n);
void ArbolBinario (int *A,int n);
void ImprimirTiempos(double utime0, double stime0, double wtime0, double utime1, double stime1, double wtime1);
    // Imprime los tiempos que tomo en ser ejecutado el programa de forma  decimal y de forma exponencial
    // Uso: ImprimirTiempos(utime0, stime0, wtime0, utime1, stime1, wtime1)
    // utime0,stime0,wtime0 : Vairables del tiempo inicial (deberia ser 0)
    // utime1, stime1, wtime1: Variables de tiempo final
#endif //Funciones