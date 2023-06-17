#include<windows.h>
#include<stdio.h>

int main(){

    //--Recepción de Datos

    HANDLE hStdin = GetStdHandle (STD_INPUT_HANDLE);
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int szBuffer[10][20];
    DWORD dwBufferSize = sizeof(szBuffer);        
    DWORD dwNoBytesRead;
    DWORD dwNoBytesWrite;
    BOOL bWriteFile;
    BOOL bReadFile;

    printf("Hijo :%f \n", szBuffer [0][0]);
    bReadFile = ReadFile(hStdin,szBuffer,dwBufferSize,&dwNoBytesRead,NULL);
    CloseHandle(hStdin);

    /////

    //Preparacion de Datos
    int i,j;
    float a[10][10],b[10][10];

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if (j<10)
            {
                a[i][j]=szBuffer[i][j];
            }
            else
            {
                b[i][j-10]=szBuffer[i][j];
            }
            
        }
    }

    //MAndando los datos al hijo
    SECURITY_ATTRIBUTES saAttr;
    saAttr.nLength=sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle=TRUE;
    saAttr.lpSecurityDescriptor=NULL;

    HANDLE hRead1, hWrite1, hRead2, hWrite2;

    CreatePipe(&hRead1,&hWrite1,&saAttr,0);
    CreatePipe(&hRead2,&hWrite2,&saAttr,0);

    bWriteFile = WriteFile(hWrite1,szBuffer,dwBufferSize,&dwNoBytesWrite,NULL);

    //Creando hijo (nieto)
    STARTUPINFO si1;
    GetStartupInfo(&si1);
    PROCESS_INFORMATION pi1;
    ZeroMemory (&si1, sizeof(si1));
    ZeroMemory (&pi1, sizeof(pi1));
    si1.cb = sizeof(STARTUPINFO);
    si1.hStdError = GetStdHandle (STD_ERROR_HANDLE);
    si1.hStdOutput = hWrite2;
    si1.hStdInput= hRead1;
    si1.dwFlags = STARTF_USESTDHANDLES;

    BOOL process1 = CreateProcess ("grandson",NULL,NULL,NULL,TRUE,0,NULL,NULL,&si1,&pi1);
    WaitForSingleObject(pi1.hProcess,INFINITE);

    CloseHandle(pi1.hProcess);
    CloseHandle(pi1.hThread);

    //Recibiendo mensaje del hijo (nieto)
    bReadFile = ReadFile(hRead2,szBuffer,dwBufferSize,&dwNoBytesRead,NULL);

    CloseHandle(hRead1);
    CloseHandle(hWrite1);
    CloseHandle(hRead2);
    CloseHandle(hWrite2);


    //Mandando datos al padre
    printf("Multiplicacion: \n");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            szBuffer[i][j]=a[i][j]*b[i][j];
            printf("%f",szBuffer[i][j]);
        }
        printf("\n");
        
    }

    bWriteFile=WriteFile(hStdout,szBuffer,dwBufferSize,&dwNoBytesWrite,NULL);
    CloseHandle(hStdout);
    


    return 0;
}