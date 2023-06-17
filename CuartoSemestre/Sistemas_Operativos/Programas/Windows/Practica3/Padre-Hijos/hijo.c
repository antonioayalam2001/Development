#include <windows.h>
#include <stdio.h>

int main(void)
       {
     	STARTUPINFO si;
	    PROCESS_INFORMATION pi;
		int i;
		int j;
	   	 printf("\n\t Nivel 2");
         printf("\n\t --->Soy el hijo,  PID:  %d\n", GetCurrentProcessId());
 	     for ( j = 0 ; j < 5 ; j++ )
		  {

		    	ZeroMemory(&si,sizeof(si));
				si.cb = sizeof(si);
				ZeroMemory(&pi,sizeof(pi));

 	 	if ( !CreateProcess(NULL, "dos",NULL,NULL,FALSE,0,NULL,NULL,&si,&pi) )
		   {
 	 	     	printf("Fallo al invocar CreateProcess(%d)\n",GetLastError() );
 	 	 	    return 1;
 	 	   }

 	 	WaitForSingleObject(pi.hProcess,INFINITE);
 	 	CloseHandle(pi.hProcess);
 	 	CloseHandle(pi.hThread);
 	}

   	return 0;
  }
