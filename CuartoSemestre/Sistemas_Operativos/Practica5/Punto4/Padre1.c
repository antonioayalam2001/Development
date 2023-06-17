/*Programa Padre*/
#include "windows.h"
#include "stdio.h"
#include "string.h"
char mensaje[] = "8,5,6,4,1,8,2,7,3,3,";
char matriz12[] = "7,5,5,3,3,2,3,1,2,9,";
char matriz13[] = "3,5,4,2,2,1,4,7,6,7,";
char matriz14[] = "2,4,5,8,7,1,2,6,5,4,";
char matriz15[] = "8,8,1,2,7,5,1,5,5,1,";
char matriz16[] = "5,6,7,5,6,4,2,4,9,5,";
char matriz17[] = "6,4,9,8,6,2,5,6,5,3,";
char matriz18[] = "3,5,6,2,8,4,3,4,8,1,";
char matriz19[] = "1,7,2,4,8,4,9,5,6,3,";
char matriz110[] = "6,1,4,5,8,8,8,5,7,4,";
char matriz21[] = "6,4,2,5,6,3,2,6,5,7,";
char matriz22[] = "2,3,6,1,4,2,1,4,2,5,";
char matriz23[] = "4,8,7,4,3,7,2,6,3,3,";
char matriz24[] = "8,6,7,6,4,7,8,4,1,2,";
char matriz25[] = "1,3,9,4,6,8,8,8,6,9,";
char matriz26[] = "7,4,8,5,3,8,6,9,4,5,";
char matriz27[] = "8,7,5,7,4,8,2,2,9,8,";
char matriz28[] = "1,2,6,8,8,2,4,6,2,8,";
char matriz29[] = "9,2,6,1,3,7,2,3,4,1,";
char matriz210[] = "5,3,5,3,4,2,4,8,2,5";
int main()
{
    //char mensaje[]="1,2,3,4,5,6,7,8";
    strcat(mensaje, matriz12);
    strcat(mensaje, matriz13);
    strcat(mensaje, matriz14);
    strcat(mensaje, matriz15);
    strcat(mensaje, matriz16);
    strcat(mensaje, matriz17);
    strcat(mensaje, matriz18);
    strcat(mensaje, matriz19);
    strcat(mensaje, matriz110);
    strcat(mensaje, matriz21);
    strcat(mensaje, matriz22);
    strcat(mensaje, matriz23);
    strcat(mensaje, matriz24);
    strcat(mensaje, matriz25);
    strcat(mensaje, matriz26);
    strcat(mensaje, matriz27);
    strcat(mensaje, matriz28);
    strcat(mensaje, matriz29);
    strcat(mensaje, matriz210);
    DWORD escritos;
    HANDLE hLecturaPipe, hEscrituraPipe;
    PROCESS_INFORMATION piHijo;
    STARTUPINFO siHijo;
    SECURITY_ATTRIBUTES pipeSeg = {sizeof(SECURITY_ATTRIBUTES), NULL, TRUE};

    /*Obtencion de informacion para la inacializacion del proceso hijo*/
    GetStartupInfo(&siHijo);
    /*Creacion de la tuberia sin nombre*/
    CreatePipe(&hLecturaPipe, &hEscrituraPipe, &pipeSeg, 0);
    /*Escritura en la tuberia sin nombre*/
    WriteFile(hEscrituraPipe, mensaje, strlen(mensaje) + 1, &escritos, NULL);
    siHijo.hStdInput = hLecturaPipe;
    siHijo.hStdError = GetStdHandle(STD_ERROR_HANDLE);
    siHijo.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    siHijo.dwFlags = STARTF_USESTDHANDLES;
    CreateProcess(NULL, "Hijo1", NULL, NULL, TRUE, 0, NULL, NULL, &siHijo, &piHijo);
    WaitForSingleObject(piHijo.hProcess, INFINITE);
printf("Mensaje recibido en el proceso hijo, termina el proceso padre\n");
CloseHandle(hLecturaPipe);
CloseHandle(hEscrituraPipe);
CloseHandle(piHijo.hThread);
CloseHandle(piHijo.hProcess);
return 0;
}