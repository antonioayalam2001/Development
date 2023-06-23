#include <stdio.h> 
#include <stdlib.h>
int numCasos, i;
int tamLinea, numlineas, resultado, posActual, avance;
int lineas[100005][2], lineasResultado[100005][2];
void merge(int l, int m, int r);
void mergeSort(int l, int r);
int max(int a, int b);
int main()
{
    scanf("%d", &numCasos);
    while (numCasos--)
    {
        numlineas = 0;
        resultado = 0;
        posActual = 0;
        scanf("%d", &tamLinea);
        while (scanf("%d %d", &lineas[numlineas][0], &lineas[numlineas][1]) && (lineas[numlineas][0] || lineas[numlineas][1]))
        {
            numlineas++;
        }
        mergeSort(0, numlineas - 1);
        for (i = 0; i < numlineas && posActual < tamLinea; i++)
        {
            if (lineas[i][0] > posActual)
                break;
            lineasResultado[resultado][0] = lineas[i][0];
            lineasResultado[resultado][1] = lineas[i][1];
            resultado++;
            avance = lineas[i][1];
            while (i + 1 < numlineas && lineas[i + 1][0] <= posActual)
            {
                if (max(lineas[++i][1], avance))
                {
                    avance = lineas[i][1];
                    lineasResultado[resultado - 1][0] = lineas[i][0];
                    lineasResultado[resultado - 1][1] = lineas[i][1];
                }
            }
            posActual = avance;
        }
        if (posActual < tamLinea)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", resultado);
            for (i = 0; i < resultado; i++)
                printf("%d %d\n", lineasResultado[i][0], lineasResultado[i][1]);
        }
        if (numCasos)
            printf("\n");
    }
    return 0;
}
void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1][2], R[n2][2];
    for (i = 0; i < n1; i++)
    {
        L[i][0] = lineas[l + i][0];
        L[i][1] = lineas[l + i][1];
    }
    for (j = 0; j < n2; j++)
    {
        R[j][0] = lineas[m + 1 + j][0];
        R[j][1] = lineas[m + 1 + j][1];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i][0] <= R[j][0])
        {
            lineas[k][0] = L[i][0];
            lineas[k][1] = L[i][1];
            i++;
        }
        else
        {
            lineas[k][0] = R[j][0];
            lineas[k][1] = R[j][1];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        lineas[k][0] = L[i][0];
        lineas[k][1] = L[i][1];
        i++;
        k++;
    }
    while (j < n2)
    {
        lineas[k][0] = R[j][0];
        lineas[k][1] = R[j][1];
        j++;
        k++;
    }
}
void mergeSort(int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}
int max(int a, int b)
{
    return (a > b) ? 1 : 0;
}