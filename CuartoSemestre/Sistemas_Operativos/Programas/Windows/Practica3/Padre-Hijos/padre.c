#include <stdio.h>
#include <windows.h>

int main(int argc,char *argv[])

{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
     int i;
     ZeroMemory(&si,sizeof(si));
	 si.cb = sizeof(si);
	 ZeroMemory(&pi,sizeof(pi));

        if ( !CreateProcess(NULL, argv[1] ,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi) )
		{
		  printf("Fallo al invocar CreateProcess(%d)\n",GetLastError() );
	  	return 1;
	    }

       printf("\n\t\t **ARBOL DE PROCESOS**\n");
	    printf("\n\n ->Soy el Padre,  PID:  %d\n", GetCurrentProcessId());
	    WaitForSingleObject(pi.hProcess,INFINITE);
        CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
 return 0;
}
