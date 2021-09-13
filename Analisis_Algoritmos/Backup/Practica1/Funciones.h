#ifndef Funciones
#define Funciones
// Documentar Funciones

//Declaracion cabecera de Funciones


void Burbuja(int *numeros, int n);
void BurbujaOptimizada(int *A, int n);
void Insercion(int *A, int n);
void Shell(int *A, int n);
int *LeerArchivo(int *A, int n);
void MenuSeleccion(int *A, int n,int opc);
void imprimirArreglo(int *A,int n);
void Selection(int *A, int n);

int Pivote(int *A,int p, int n );
void Intercambiar(int *A, int i, int j);
void QuickSort(int *A, int p, int r);
// void ImprimirTiempos(double utime0, double stime0, double wtime0, double utime1, double stime1, double wtime1);
void Quicksort2(int *A, int i, int n);
void Merge(int *A, int p, int q, int r);
void MergeSort(int *A, int p, int r);
int parteEntera(double n);
void Burbuja2(int *A, int n);

void ArbolBinario (int *A,int n);
#endif //Funciones