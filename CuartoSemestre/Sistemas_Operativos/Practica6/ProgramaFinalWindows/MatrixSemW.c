//Program that uses process inter communication to process two matrices with semaphores
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

#define SIZE 10
#define MEM_SIZE 5000 

bool inverse(int A[SIZE][SIZE], float inverse[SIZE][SIZE]);
void adjoint(int A[SIZE][SIZE], int adj[SIZE][SIZE]);
void getCofactor(int A[SIZE][SIZE], int temp[SIZE][SIZE], int p, int q, int n);
int determinant(int A[SIZE][SIZE], int n);
int Imprime(int *a);
void LlenaMatriz(int **matriz);
void MatrizSM(int **matriz, int *b);


int main(void)
{
	int i, j, k;
	int *buffer, *shm;
	int **matrix1, **matrix2, result_matrix[SIZE][SIZE];
	float inv[SIZE][SIZE];
	FILE *write_fp;
	char *shmid = "SharedMemory";
	HANDLE hMapFile;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	HANDLE hSem1, hSem2;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	srand((unsigned) time(NULL));

	//Asigancion de espacio de memoria a las matrices
	matrix1 = malloc(SIZE * sizeof(int *));
	matrix2 = malloc(SIZE * sizeof(int *));
	for(i = 0; i < SIZE; i++)
	{
		matrix1[i] = malloc(SIZE * sizeof(int));
		matrix2[i] = malloc(SIZE * sizeof(int));
	}

	//Llenando  matrices con valores aleatorios
	LlenaMatriz(matrix1);
	LlenaMatriz(matrix2);
	//Map shared memory
	if((hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, MEM_SIZE, shmid)) == NULL)
	{
		printf("Failed to map shared memory: (%i)\n", GetLastError());
		exit(EXIT_FAILURE);
	}
	//Create shared memory
	if((shm = (int *)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, MEM_SIZE)) == NULL)
	{
		printf("Failed to create shared memory: (%i)\n", GetLastError());
		CloseHandle(hMapFile);
		exit(EXIT_FAILURE); 
	}
	//MCreando un apuntador a la memoria compartida llamada Buffer
	buffer = shm;

	//Escribiendo matrices en la memoria compartida
	MatrizSM(matrix1,buffer);
	MatrizSM(matrix2,buffer);

	//Creando el primer semaforo
	if((hSem1 = CreateSemaphore(NULL, 1, 1, "Semaphore1")) == NULL)
	{
		printf("Failed to invoke CreateSemaphore: %d\n", GetLastError());
		return -1;
	}
	//Creando Semaforo 2
	if((hSem2 = CreateSemaphore(NULL, 1, 1, "Semaphore2")) == NULL)
	{
		printf("Failed to invoke CreateSemaphore: %d\n", GetLastError());
		return -1;
	}	

	//creando Proceso Hijo
	if(!CreateProcess(NULL, "MatrixSemWChild", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		printf("Failed to invoke CreateProcess: %d\n", GetLastError());
		return -1;
	}
	else //PADRE
	{	
		//Halt in order to leave the Child take the control of both semaphores
		Sleep(1000);

		//Prueba del semáforo
		WaitForSingleObject(hSem1, INFINITE);

		//Imprimiendo las matrices en consola
		Imprime(buffer);

		//PADRE VUELVE A TOMAR CONTROL
		//leyendo la matriz resultante de la multiplicacion, la cual se encuentra almacenada en la memoria compartida
		//Por lo que almacenamos dichos valores en "result_matrix"
		k = 2 * SIZE * SIZE;
		for(i = 0; i < SIZE; i++)
			for(j = 0; j < SIZE; j++)
				result_matrix[i][j] = buffer[k++];

		//Calculando la inversa de la multiplicacion y escribiendola en archivo.
		write_fp = fopen("MultInverse.txt", "w");
		printf("Escribiendo la Inversa en un archivo\n");
		if(inverse(result_matrix, inv))
		{
			for(i = 0; i < SIZE; i++)
			{
				for(j = 0; j < SIZE; j++)
					fprintf(write_fp, "%6.2f ", inv[i][j]);
				fprintf(write_fp, "\n");
			}
		}
		fclose(write_fp);

		//Metiendo en "result_matrix" los valores obtenidos de la suma los cuales estan en la memoria compartida
		k = 3 * SIZE * SIZE;
		for(i = 0; i < SIZE; i++)
			for(j = 0; j < SIZE; j++)
				result_matrix[i][j] = buffer[k++];

		//Calculando la inversa y Escribiendola en el archivo correspondiente
		write_fp = fopen("SumaInverse.txt", "w");	
		printf("Enviando la Inversa de la Suma al archivo\n");
		if(inverse(result_matrix, inv))
		{
			for(i = 0; i < SIZE; i++)
			{
				for(j = 0; j < SIZE; j++)
					fprintf(write_fp, "%6.2f ", inv[i][j]);
				fprintf(write_fp, "\n");
			}
		}
		fclose(write_fp);	
	}

	//Terminación controlada del proceso e hilo asociado de ejecución
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	UnmapViewOfFile(shm);
	CloseHandle(hMapFile);
}
//Funcion para calcular y almacenar la inversa, regresa valor falso en caso de que
//se trate de una matriz singular
bool inverse(int A[SIZE][SIZE], float inverse[SIZE][SIZE])
{
    // Encontrando el Determinante de A[][]
    int det = determinant(A, SIZE);
    if (det == 0)
    {
        printf("Matriz singular, no posee inversa\n");
        return false;
    }
 
    // Buscando la Adjunta
    int adj[SIZE][SIZE];
    adjoint(A, adj);
 
    // Inversa de la matriz = "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<SIZE; i++)
        for (int j=0; j<SIZE; j++)
            inverse[i][j] = adj[i][j]/(float) det;
 
    return true;
}
// Funcion para obtener la ADJUNTA de A[N][N] en adj[N][N]. 
void adjoint(int A[SIZE][SIZE], int adj[SIZE][SIZE])
{
    if (SIZE == 1)
    {
        adj[0][0] = 1;
        return;
    }
 
    // temp almacena los cofactores de A[][]
    int sign = 1, temp[SIZE][SIZE];
 
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            // Obteniendo cofactor de A[i][j]
            getCofactor(A, temp, i, j, SIZE);
 
            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;
 
            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj[j][i] = (sign)*(determinant(temp, SIZE-1));
        }
    }
}

// Function to get cofactor of A[p][q] in temp[][]. n is current
// dimension of A[][]
void getCofactor(int A[SIZE][SIZE], int temp[SIZE][SIZE], int p, int q, int n)
{
    int i = 0, j = 0;
 
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
 
                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
  //Funcion Recursiva que encuentra el determinnte de la matriz
  //n es el tamaño actual de A[][] 
  
int determinant(int A[SIZE][SIZE], int n)
{
    int D = 0; // Dando valor inicial   
 
    //  Base case : Si la matriz contiene un solo elemento
    if (n == 1)
        return A[0][0];
 
    int temp[SIZE][SIZE]; // Para almacenar cofatores
 
    int sign = 1;  // To store sign multiplier
 
     // Iteracion para cada elemento de la primera fila
    for (int f = 0; f < n; f++)
    {
        // Obteniendo Cofactor A[0][f]
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);
 
        // terms are to be added with alternate sign
        sign = -sign;
    }
 
    return D;
}


//Funcion que permite realizar la Impresion de las matrices escritas en memoria

int Imprime(int *a){
	int i;
	printf("\nMatriz numero 1\n\n");
	for(i = 0; i < SIZE * SIZE; i++)
		{
			if(i % 10 == 0 && i != 0)
				printf("\n");	
			printf("%d ", a[i]);
		}
		printf("\n");


	printf("\nMatriz numero 2\n");
	
		for(; i < 2 * SIZE * SIZE; i++)
		{
			if(i % 10 == 0 && i != 0)
				printf("\n");	
			printf("%d ", a[i]);
		}
		printf("\n");

	printf("\nMatriz Resultante de Multiplicacion\n");

		for(; i < 3 * SIZE * SIZE; i++)
		{
			if(i % 10 == 0 && i != 0)
				printf("\n");	
			printf("%d ", a[i]);
		}
		printf("\n");

	printf("\nMatriz Resultante de Suma\n");

		for(; i < 4 * SIZE * SIZE; i++)
		{
			if(i % 10 == 0 && i != 0)
				printf("\n");	
			printf("%d ", a[i]);
		}
		printf("\n");
}

//Funcion para llenar de valores aleatorios la matriz

void LlenaMatriz(int **matriz){
	int i,j;
	for(i = 0; i < SIZE; i++)
		for(j = 0; j < SIZE; j++)
		{
			matriz[i][j] = rand() % 5;
		}	


}
// Funcion para escribir los valores en la memoria compartida

void MatrizSM(int **matriz, int *b){
	
		int i,j,k;
		k = 0;
	for(i = 0; i < SIZE; i++)
		for(j = 0; j < SIZE; j++)
			b[k++] = matriz[i][j];

	for(i = 0; i < SIZE; i++)
		for(j = 0; j < SIZE; j++)
			b[k++] = matriz[i][j];
}