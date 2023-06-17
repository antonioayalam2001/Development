#include <windows.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
 STARTUPINFO si; /* Estructura de información inicial para Windows */
 PROCESS_INFORMATION pi; /* Estructura de información del adm. de procesos */
 int i;
 ZeroMemory(&si, sizeof(si));
 si.cb = sizeof(si);
 ZeroMemory(&pi, sizeof(pi));


 if(argc!=2)
 {
 printf("Usar: %s\n", argv[0]);
 strcat(argv[0],"\\Ejecutable.exe");
 printf("Usar: %s\n", argv[0]);

 }
 // Creación proceso hijo
 if(!CreateProcess("C:\\Users\\TONY AYALA\\Google Drive\\Escolar\\College\\CuartoSemestre\\Sistemas_Operativos\\Tarea3\\Programas\\Puntos3_4_5\\Ejecutable.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
 {
 printf( "Fallo al invocar CreateProcess (%d)\n", GetLastError() );
 }
 // Proceso padre
 printf("Soy el padre\n");
 WaitForSingleObject(pi.hProcess, INFINITE);
 printf("Soy el padre otra vez\n");
 // Terminación controlada del proceso e hilo asociado de ejecución

if(CloseHandle(pi.hProcess) !=0){
printf("El manejador del proceso fue cerrado de forma exitosa\n");}
else{
    printf("Algo no sucedio como debia");
}

if(CloseHandle(pi.hThread) != 0)

printf("El manejador de amenazas fue cerrado de forma exitosa\n");


return 0;
} 

