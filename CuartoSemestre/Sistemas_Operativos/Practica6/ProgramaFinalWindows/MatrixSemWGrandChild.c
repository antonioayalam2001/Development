//Program that uses process inter communication to process two matrices
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

#define SIZE 10
#define MEM_SIZE 400 

int main(void)
{
	int matrix1[SIZE][SIZE], matrix2[SIZE][SIZE], result_matrix[SIZE][SIZE], i, j, k;		
	int *buffer, *shm;
	char *shmid = "SharedMemory";
	HANDLE hMapFile, hSem2;
	
	//Abre Semaforo 2
	if((hSem2 = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "Semaphore2")) == NULL)
	{
		printf("Failed to invoke OpenSemaphore2: %d\n", GetLastError());
		return -1;
	}
	//Open file mapping
	if((hMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, shmid)) == NULL)
	{
		printf("Failed to open file of mapping from shared memory: (%i)\n", GetLastError());
		exit(EXIT_FAILURE);
	}
	//Access/Attach to shared memory
	if((shm = (int *)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, MEM_SIZE)) == NULL)
	{
		printf("Failed to access to shared memory: (%i)\n", GetLastError());
		CloseHandle(hMapFile);
		exit(EXIT_FAILURE); 
	}
	//Apuntador a Memoria Compartida
	buffer = shm;

	//Copiando en las matries los valores almacenados en la mm¿emoria compartida
	k = 0;
	for(i = 0; i < SIZE; i++)
		for(j = 0; j < SIZE; j++)
			matrix1[i][j] = buffer[k++];

	for(i = 0; i < SIZE; i++)
		for(j = 0; j < SIZE; j++)
			matrix2[i][j] = buffer[k++];

	//Realizando la suma
	for(i = 0; i < SIZE; i++)
		for(j = 0; j < SIZE; j++)
			result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];

	//Detenido hasta que la multiplicacion esta hecha
	Sleep(1000);

	//Test control of semaphore 2
	WaitForSingleObject(hSem2, INFINITE);
	//Escribiendo la suma dentro de la memoria compartida
	k = 3 * SIZE * SIZE;
	for(i = 0; i < SIZE; i++)
		for(j = 0; j < SIZE; j++)
			buffer[k++] = result_matrix[i][j];			
	
	//FLiberando al Semaforo 2
	if(!ReleaseSemaphore(hSem2, 1, NULL))
	{
		printf("Falla al invocar ReleaseSemaphore: %d\n", GetLastError());
	}
	UnmapViewOfFile(shm);
	CloseHandle(hMapFile);

	return 0;
}