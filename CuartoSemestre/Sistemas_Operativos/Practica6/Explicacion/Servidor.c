#include<stdio.h>
#include<math.h>
#include<windows.h>
#define TAM_MEM 400

int main(void){

    HANDLE hArchMapeo;
    char *idMemCompartida = "MemoriaCompartida";
    int *apDatos, *apTrabajo, c;
    if ((hArchMapeo = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        TAM_MEM,
        idMemCompartida)
    ) == NULL)
    {
        printf("No se mapeo la memoria compartida: (%i)\n",GetLastError());
        exit(-1);
    }

    if ((apDatos = (int *)MapViewOfFile(hArchMapeo,
                                        FILE_MAP_ALL_ACCESS,
                                        0,
                                        0,
                                        TAM_MEM))==NULL)
    {
        printf("No se creo la memoria compartida: (%i)\n",GetLastError());
        CloseHandle(hArchMapeo);
        exit(-1);
    }

    int **matriz1;
    int **matriz2;
    int **matriz3;
    int **matriz4;
    apTrabajo=apDatos;
    int fin_intervalo=10;

    for (c = 0; c < 200; c++)
    {
        *apTrabajo++=rand()%fin_intervalo;
    }
    *apDatos=0;

    //Semaforo//
    HANDLE hSemaforo;
    //CrandoSemaforo
    if ((hSemaforo=CreateSemaphore(NULL,1,1,"Semaforo"))== NULL)
    {
        printf("Fallo al invocar CreateSemaphore: (%d)\n",GetLastError());
        return -1;
    }

    /////////////////////
    /////////////////////
     STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory (&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory (&pi, sizeof(pi));

    if(!CreateProcess(NULL, "ProcesoH.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
     {
     printf( "Fallo al invocar CreateProcess (%d)\n", GetLastError() );
     return 0;
     } 
    
    WaitForSingleObject(hSemaforo,INFINITE);

    //Seccion Critica
    printf("Padre Entrando al Semaforo");
    Sleep(5000);

    //Liberacion del Semaforo
    if (!ReleaseSemaphore(hSemaforo,1,NULL))
    {
        printf( "Fallo al invocar ReleaseS (%d)\n", GetLastError() );
   
    }
    
    printf("Padre Liberando al Semaforo");
    Sleep(5000);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    
    
    
    
}