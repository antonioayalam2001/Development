#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

int main()
{
    int n;
    HANDLE hFile;
    BOOL bFile;
    char chBuffer [50];
    DWORD dwNoByteToWrite = strlen(chBuffer);
    DWORD dwNoByteWritten = 0;
    DWORD dwNoByteToRead = strlen(chBuffer);
    DWORD dwNoByteRead = 0;

        printf("escoja que archivo quiere saber info y copiarlo a otro directorio: \n");
        printf("1 para el primero\n");
        printf("2 para el segundo\n");
        printf("3 para el tercero\n");
        scanf("%d", &n);

        if(n==1){
            char chBuffer [] = "Hola a todo el mundo";
            hFile = CreateFile(
                "C:\\Users\\Rodrigo\\Desktop\\pruebas\\text1.txt",
                GENERIC_READ|GENERIC_WRITE,
                FILE_SHARE_READ,
                NULL,
                CREATE_NEW,
                FILE_ATTRIBUTE_NORMAL,
                NULL
            );
            //read file
            bFile = ReadFile(
                hFile,
                chBuffer,
                dwNoByteToRead,
                &dwNoByteRead,
                NULL
            );
            printf("datos del archivo: %s", chBuffer);
            CloseHandle(hFile);

            system("copy C:\\Users\\Rodrigo\\Desktop\\pruebas\\text1.txt C:\\Users\\Rodrigo\\Desktop\\pruebas\\destino");
        }

        if(n==2){
            char chBuffer [] = "Hola a todo el otro mundo";
            hFile = CreateFile(
                "C:\\Users\\Rodrigo\\Desktop\\pruebas\\text2.txt",
                GENERIC_READ|GENERIC_WRITE,
                FILE_SHARE_READ,
                NULL,
                CREATE_NEW,
                FILE_ATTRIBUTE_NORMAL,
                NULL
            );
            //read file
            bFile = ReadFile(
                hFile,
                chBuffer,
                dwNoByteToRead,
                &dwNoByteRead,
                NULL
            );
            printf("datos del archivo: %s", chBuffer);
            CloseHandle(hFile);

            system("copy C:\\Users\\Rodrigo\\Desktop\\pruebas\\text2.txt C:\\Users\\Rodrigo\\Desktop\\pruebas\\destino");
        }

        if(n==3){
            char chBuffer [] = "Hola a todo el ultimo mundo";
            hFile = CreateFile(
                "C:\\Users\\Rodrigo\\Desktop\\pruebas\\text3.txt",
                GENERIC_READ|GENERIC_WRITE,
                FILE_SHARE_READ,
                NULL,
                CREATE_NEW,
                FILE_ATTRIBUTE_NORMAL,
                NULL
            );
            //read file
            bFile = ReadFile(
                hFile,
                chBuffer,
                dwNoByteToRead,
                &dwNoByteRead,
                NULL
            );
            printf("datos del archivo: %s", chBuffer);
            CloseHandle(hFile);

            system("copy C:\\Users\\Rodrigo\\Desktop\\pruebas\\text3.txt C:\\Users\\Rodrigo\\Desktop\\pruebas\\destino");
        }
    return 0;
}