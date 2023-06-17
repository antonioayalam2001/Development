#include<windows.h>
#include<stdio.h>

int main(){
    HANDLE hStdin = GetStdHandle (STD_INPUT_HANDLE);
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int szBuffer[10][20];
    DWORD dwBufferSize = sizeof(szBuffer);        
    DWORD dwNoBytesRead;
    DWORD dwNoBytesWrite;
    BOOL bReadFile;
    bReadFile = ReadFile(hStdin,szBuffer,dwBufferSize,&dwNoBytesRead,NULL);
    CloseHandle(hStdin);


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


    printf("Suma: \n");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            szBuffer[i+10][j+10]=a[i][j]+b[i][j];
            printf("%f",szBuffer[i+10][j+10]);
        }
        printf("\n");
        
    }

    BOOL bWriteFile=WriteFile(hStdout,szBuffer,dwBufferSize,&dwNoBytesWrite,NULL);
    CloseHandle(hStdout);
    
    return 0;
}