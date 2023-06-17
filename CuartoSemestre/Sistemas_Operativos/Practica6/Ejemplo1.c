#include <windows.h>

#include <stdio.h>

 

int main(void)

{

STARTUPINFO si;

PROCESS_INFORMATION pi;

ZeroMemory(&si, sizeof(si));

si.cb = sizeof(si);

ZeroMemory(&pi, sizeof(pi));


// Start the child process. If not OK...

if(!CreateProcess("Ejecutable.exe", // module name.
NULL, 
NULL, 
NULL, 
FALSE, 
0,
NULL, 
NULL, 
&si, 
&pi) 
)


// Then, give some prompt...

printf("\nSorry! CreateProcess() failed.\n\n");

// else, give some prompt...


// Wait until child process exits after 5000 ms.

printf("Soy el padre\n"); 
WaitForSingleObject(pi.hProcess, INFINITE);

printf("\n");

 

// Close process and thread handles. If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.

// To get extended error information, call GetLastError().

if(CloseHandle(pi.hProcess) !=0){
printf("The process handle has been closed successfully\n");}
else{
    printf("something went wrong");
}

if(CloseHandle(pi.hThread) != 0)

printf("The thread handle has been closed successfully\n");

return 0;

}