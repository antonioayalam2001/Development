/*Programa hijo*/
#include "windows.h"
#include "stdio.h"
#include "string.h"
char mensaje2[] = "6,4,2,5,6,3,2,6,5,7,";
char matriz22[] = "2,3,6,1,4,2,1,4,2,5,";
char matriz23[] = "4,8,7,4,3,7,2,6,3,3,";
char matriz24[] = "8,6,7,6,4,7,8,4,1,2,";
char matriz25[] = "1,3,9,4,6,8,8,8,6,9,";
char matriz26[] = "7,4,8,5,3,8,6,9,4,5,";
char matriz27[] = "8,7,5,7,4,8,2,2,9,8,";
char matriz28[] = "1,2,6,8,8,2,4,6,2,8,";
char matriz29[] = "9,2,6,1,3,7,2,3,4,1,";
char matriz210[] = "5,3,5,3,4,2,4,8,2,5";
char matriz11[] = "8,5,6,4,1,8,2,7,3,3,";
char matriz12[] = "7,5,5,3,3,2,3,1,2,9,";
char matriz13[] = "3,5,4,2,2,1,4,7,6,7,";
char matriz14[] = "2,4,5,8,7,1,2,6,5,4,";
char matriz15[] = "8,8,1,2,7,5,1,5,5,1,";
char matriz16[] = "5,6,7,5,6,4,2,4,9,5,";
char matriz17[] = "6,4,9,8,6,2,5,6,5,3,";
char matriz18[] = "3,5,6,2,8,4,3,4,8,1,";
char matriz19[] = "1,7,2,4,8,4,9,5,6,3,";
char matriz110[] = "6,1,4,5,8,8,8,5,7,4,";
void Multiplicar(int matriz[10][10], int matriz2[10][10]);
int CreandoTuberia(char mensaje[]);
int C[10][10];
/////////////////////////////////////////////////////////////
int const Tam = 100;
void PideDatos(int k, int Dim, float Sist[][Tam]);
void Invierte(int Dim, float Sist[][Tam], float Inv[][Tam]);
void Inversa();
////////////////////////////////////////////////////////////
int main()
{
    char mensaje[450];
    //char mensaje2[] = "9,8,7,6,5,4,3,2";
    strcat(mensaje2, matriz22);
    strcat(mensaje2, matriz23);
    strcat(mensaje2, matriz24);
    strcat(mensaje2, matriz25);
    strcat(mensaje2, matriz26);
    strcat(mensaje2, matriz27);
    strcat(mensaje2, matriz28);
    strcat(mensaje2, matriz29);
    strcat(mensaje2, matriz210);
    strcat(mensaje2, matriz11);
    strcat(mensaje2, matriz12);
    strcat(mensaje2, matriz13);
    strcat(mensaje2, matriz14);
    strcat(mensaje2, matriz15);
    strcat(mensaje2, matriz16);
    strcat(mensaje2, matriz17);

    strcat(mensaje2, matriz18);
    strcat(mensaje2, matriz19);
    strcat(mensaje2, matriz110);
    int matriz[10][10];
    int matriz2[10][10];
    int i, j;
    int k = 0;
    DWORD leidos;
    HANDLE hStdln = GetStdHandle(STD_INPUT_HANDLE);
    SECURITY_ATTRIBUTES pipeSeg = {sizeof(SECURITY_ATTRIBUTES), NULL, TRUE};
    /*Lectura de la tuberia sin nombre*/
    ReadFile(hStdln, mensaje, sizeof(mensaje), &leidos, NULL);
    printf("Mensaje recibido del proceso padre: %s\n", mensaje);
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if (i < 10 && j < 10)
            {
                if (k == 0)
                {
                    matriz[i][j] = atoi(strtok(mensaje, ","));
                    k++;
                }
                else
                    matriz[i][j] = atoi(strtok(NULL, ","));
            }
            if (i > 9 && j > 9)
            {
                matriz2[i - 10][j - 10] = atoi(strtok(NULL, ","));
            }
        }
    }
    Multiplicar(matriz, matriz2);
    printf("\n");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("\t %d", C[i][j]);
        }
        printf("\n");
    }
    Inversa();
    CreandoTuberia(mensaje2);
    CloseHandle(hStdln);
    printf("Termina el proceso Hijo, continua el proceso Padre\n");
    return 0;
}
void Multiplicar(int matriz[10][10], int matriz2[10][10])
{
    int i, j, k;
    //OPERACION DE MULTIPLICACION
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < 10; k++)
            {
                C[i][j] = C[i][j] + matriz[i][k] * matriz2[k][j];
            }
        }
    }
}
int CreandoTuberia(char mensaje[])
{
    DWORD escritos2;
    HANDLE hLecturaPipe2, hEscrituraPipe2;
    PROCESS_INFORMATION piHijo2;
    STARTUPINFO siHijo2;
    SECURITY_ATTRIBUTES pipeSeg2 = {sizeof(SECURITY_ATTRIBUTES), NULL, TRUE};
    /*Obtencion de informacion para la inacializacion del proceso nieto*/
    GetStartupInfo(&siHijo2);
    /*Creacion de la tuberia sin nombre*/
    CreatePipe(&hLecturaPipe2, &hEscrituraPipe2, &pipeSeg2, 0);
    /*Escritura en la tuberia sin nombre*/
    WriteFile(hEscrituraPipe2, mensaje, strlen(mensaje) + 1, &escritos2, NULL);
    siHijo2.hStdInput = hLecturaPipe2;
    siHijo2.hStdError = GetStdHandle(STD_ERROR_HANDLE);
    siHijo2.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    siHijo2.dwFlags = STARTF_USESTDHANDLES;
    CreateProcess(NULL, "Nieto1", NULL, NULL, TRUE, 0, NULL, NULL, &siHijo2, &piHijo2);
    WaitForSingleObject(piHijo2.hProcess, INFINITE);
printf("Mensaje recibido en el proceso Nieto, termina el proceso Hijo\n");
CloseHandle(hLecturaPipe2);
CloseHandle(hEscrituraPipe2);
CloseHandle(piHijo2.hThread);
CloseHandle(piHijo2.hProcess);
return 0;
}
//Matriz Inversa
void Inversa()
{
    int Dimension = 10, k = 1;
    FILE *fichero;
    int i, j;
    float Sistema[Tam][Tam], Inversa[Tam][Tam];
    PideDatos(k, Dimension, Sistema);
    Invierte(Dimension, Sistema, Inversa);
    fichero = fopen("Resultado1.txt", "w");
    fprintf(fichero, "Resultado de la inversa de la Suma\n");

    for (i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
        {
            fprintf(fichero, "%.4f   ", Inversa[i][j]);
        }
            fprintf(fichero, "\n");

    }
    fclose(fichero);
    printf("El resultado ha sido almacenado en el archivo Resultado1\n");
    return;
}
void PideDatos(int k, int Dim, float Sist[][Tam])
{
    int i, j;
    for (i = 1; i <= Dim; i++)
        for (j = 1; j <= Dim; j++)
        {
            Sist[i][j] = C[i - 1][j - 1];
        }
}
void Invierte(int Dim, float Sist[][Tam], float Inv[][Tam])
{
    int NoCero, Col, C1, C2, A;
    float Pivote, V1, V2;
    /*Se inicializa la matriz inversa, como la matriz identidad:*/
    for (C1 = 1; C1 <= Dim; C1++)
        for (C2 = 1; C2 <= Dim; C2++)
            if (C1 == C2)
                Inv[C1][C2] = 1;
            else
                Inv[C1][C2] = 0;
    for (Col = 1; Col <= Dim; Col++)
    {
        NoCero = 0;
        A = Col;
        while (NoCero == 0)
        {
            if ((Sist[A][Col] > 0.0000001) || ((Sist[A][Col] < -0.0000001)))
            {
                NoCero = 1;
            }
            else
                A++;
        }
        Pivote = Sist[A][Col];
        for (C1 = 1; C1 <= Dim; C1++)
        {
            V1 = Sist[A][C1];
            Sist[A][C1] = Sist[Col][C1];
            Sist[Col][C1] = V1 / Pivote;
            V2 = Inv[A][C1];
            Inv[A][C1] = Inv[Col][C1];
            Inv[Col][C1] = V2 / Pivote;
        }
        for (C2 = Col + 1; C2 <= Dim; C2++)
        {
            V1 = Sist[C2][Col];
            for (C1 = 1; C1 <= Dim; C1++)
            {
                Sist
                    [C2][C1] =
                        Sist
                            [C2][C1] -
                        V1 *
                            Sist
                                [Col][C1];
                Inv[C2][C1] = Inv[C2][C1] - V1 * Inv[Col][C1];
            }
        }
    }
    /*Aqui ya esta triangularizada, con 1s en diagonal, ahora se
diagonaliza*/
    for (Col = Dim; Col >= 1; Col--)
        for (C1 = (Col - 1); C1 >= 1; C1--)
        {
            V1 = Sist[C1][Col];
            for (C2 = 1; C2 <= Dim; C2++)
            {
                Sist[C1][C2] = Sist[C1][C2] - V1 * Sist[Col][C2];
                Inv[C1][C2] = Inv[C1][C2] - V1 * Inv[Col][C2];
            }
        }
}
