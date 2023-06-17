/*Programa Nieto*/
#include "windows.h"
#include "stdio.h"
#include "string.h"
void Sumar(int matriz[10][10], int matriz2[10][10]);
int C[10][10];
/////////////////////////////////////////////////////////////
int const Tam = 100;
void PideDatos(int k, int Dim, float Sist[][Tam]);
void Invierte(int Dim, float Sist[][Tam], float Inv[][Tam]);
void Inversa();
////////////////////////////////////////////////////////////
int main()
{
    char mensaje2[450];
    int matriz[10][10];
    int matriz2[10][10];
    int i, j;
    int k = 0;
    DWORD leidos;
    HANDLE hStdln = GetStdHandle(STD_INPUT_HANDLE);
    SECURITY_ATTRIBUTES pipeSeg = {sizeof(SECURITY_ATTRIBUTES), NULL, TRUE};
    /*Lectura de la tuberia sin nombre*/
    ReadFile(hStdln, mensaje2, sizeof(mensaje2), &leidos, NULL);
    printf("Mensaje recibido del proceso Hijo: %s\n", mensaje2);
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if (i < 10 && j < 10)
            {
                if (k == 0)
                {
                    matriz[i][j] = atoi(strtok(mensaje2, ","));
                    k++;
                }
                else
                    matriz[i][j] =atoi(strtok(NULL,","));
            }
            if (i > 9 && j > 9)
            {
                matriz2[i - 10][j - 10] = atoi(strtok(NULL, ","));
            }
        }
    }
    Sumar(matriz, matriz2);
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

    CloseHandle(hStdln);
    printf("Termina el proceso Nieto, continua el proceso Hijo\n");
    return 0;
}
void Sumar(int matriz[10][10], int matriz2[10][10])
{
    int i,j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            C[i][j] = matriz[i][j] + matriz2[i][j];
        }
    }
}
//Matriz Inversa
void Inversa()
{
    int Dimension = 11, k = 1;
    FILE *fichero;
    int i, j;
    float Sistema[Tam][Tam], Inversa[Tam][Tam];
    PideDatos(k, Dimension, Sistema);
    Invierte(Dimension, Sistema, Inversa);
    fichero = fopen("Resultado1.txt", "a");
    
    fprintf(fichero, "Resultado de la inversa de la Multiplicacion\n");
    for (i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
        {
            fprintf(fichero, "%.4f   ", Inversa[i][j]);
        }
            fprintf(fichero,"\n");
    }
    fclose(fichero);
    printf("El resultado ha sido almacenado en el archivo Resultado\n");
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
            Sist[A][C1] =Sist[Col][C1];
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
                Sist[C2][C1] = Sist[C2][C1] - V1 * Sist[Col][C1];
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