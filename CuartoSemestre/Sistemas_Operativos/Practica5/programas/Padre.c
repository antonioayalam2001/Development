#include<stdio.h>
#include<math.h>
#include<windows.h>

float determinant(float a[10][10],float k){
    float s=1, det=0,b[10][10];
    int i,j,m,n,c;
    if(k==1){
        return (a[0][0]);
    }
    else
    {
        det=0;
        for(c=0;c<k;c++)
        {
            m=0;
            n=0;
            for (i = 0; i < k; i++)
            {
                for (j = 0; j < k; j++)
                {
                    b[i][j]=0;
                    if (i!=0 && j!=c)   
                    {
                        b[m][n]=a[i][j];
                        if (n<(k-2))
                        {
                            n++;
                        }
                        else{
                            n=0;
                            m++;
                        }   
                    }   
                }         
            }
            det=det+s*(a[0][c]*determinant(b,k-1));
            s= -1*s;
        }
    }
    return (det);
}

void transpose(float num[10][10],float fac[10][10], float r, FILE* archivo){
    int i,j;
    r=10;
    float b[10][10], inverse[10][10],d;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            b[i][j]=fac[j][i];
        }
    }
    d=determinant(num,r);
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            inverse[i][j]=b[i][j]/d;
        }
        
    }

    fprintf(archivo, "La inversa de la matriz es: \n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            fprintf(archivo,"\t%f",inverse[i][j]);
        }
            fprintf(archivo,"\n");
        
    }
    
}


void cofactor(float num[10][10],float f, FILE* archivo){
    float b[10][10],fac[10][10];
    int p,q,m,n,i,j;
    for (q = 0; q < f; q++)
    {
        for (p = 0; p < f; p++)
        {
            /* code */
        m=0;
        n=0;
        for (i = 0; i < f; i++)
        {
            for (j = 0; j < f; j++)
            {
                if (i!= q && j!=0)
                {
                    b[m][n]= num[i][j];
                    if (n<(f-2))
                        n++;
                    else{
                        n=0;
                        m++;
                    }                    
                }   
            }
        }
        fac[q][p] = pow(-1,q+p) * determinant(b,f-1);
        }
    }
    transpose(num, fac, f, archivo);
}

int main (void){
    //creando tuberia
    SECURITY_ATTRIBUTES saAttr;
    saAttr.nLength=sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle=TRUE;
    saAttr.lpSecurityDescriptor=NULL;

    HANDLE hRead1, hWrite1, hRead2, hWrite2;

    CreatePipe(&hRead1,&hWrite1,&saAttr,0);
    CreatePipe(&hRead2,&hWrite2,&saAttr,0);

    //Mandando Mensaje
    int i,j;
    float szBuffer[10][20];
    for (i = 0; i < 10; i++)
        for (j = 0; j < 20; j++)
            szBuffer[i][j]=rand();

    DWORD dwBufferSize = sizeof(szBuffer);        
    DWORD dwNoBytesWrite;

    BOOL bWriteFile = WriteFile(hWrite1,szBuffer,dwBufferSize,&dwNoBytesWrite,NULL);

    //Creando Hijo
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

    printf("Padre : %f\n",szBuffer[0][0]);
    BOOL process1 = CreateProcess("son.exe",NULL, NULL, NULL, TRUE, 0, NULL, NULL, &si1, &pi1);
    if(process1 ==FALSE) printf("NO");


    WaitForSingleObject(pi1.hProcess,INFINITE);

    CloseHandle(pi1.hProcess);
    CloseHandle(pi1.hThread);
    //Recibiendo Mensaje
    DWORD dwNoBytesRead;
    printf("Padre: %f\n",szBuffer[0][0]);
    BOOL bReadFile = ReadFile(hRead2,szBuffer,dwBufferSize,&dwNoBytesRead,NULL);
    printf("Padre: %f\n",szBuffer[0][0]);

    CloseHandle(hRead1);
    CloseHandle(hWrite1);
    CloseHandle(hRead2);
    CloseHandle(hWrite2);
    ////////////

    //Escribiendo Resultados
    float a[10][10], b[10][10];
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if(j<10)
                a[i][j]= szBuffer[i][j];
            else
                b[i][j-10]= szBuffer[i][j];
                
        }
        
    }
    
    FILE* archivo = fopen("salida1.txt","w");
    float d1 = determinant(a,10);

    if (d1!=0)
    {
        cofactor(a,10,archivo);
    }
    else
    {
        fprintf(archivo,"La matriz no tiene inversa");
    }
    fclose(archivo);

    archivo= fopen("salida2.txt","w");
    
    float d2 = determinant(b,10);

    if (d2!=0)
    {
        cofactor(b,10,archivo);
    }
    else
    {
        fprintf(archivo,"La matriz no tiene inversa");
    }
    fclose(archivo);

    return 0;
}