#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
void merge(int l, int m, int r);
void mergeSort(int l, int r);
double max(double a, double b);
double aspersores[10000][2];
int main()
{
    int numAsper = 0, largo = 0, ancho = 0, posicion = 0, radio = 0;
    int i = 0, resultado = 0;
    double distanciaX = 0, aux = 0, avance = 0;
    while (scanf("%d %d %d", &numAsper, &largo, &ancho) != EOF)
    {
        for (i = 0; i < numAsper; i++)
        {
            scanf("%d %d", &posicion, &radio);
            distanciaX = sqrt((double)radio * radio - (ancho / 2.0) * (ancho / 2.0));
            if (distanciaX == distanciaX)
            {
                aspersores[i][0] = (double)posicion - distanciaX;
                aspersores[i][1] = (double)posicion + distanciaX;
            }
        }
        mergeSort(0, numAsper - 1);
        aux = 0;
        resultado = 0;
        for (i = 0; i < numAsper && aux < largo; i++)
        {
            if (aspersores[i][0] > aux)
                break;
            resultado++;
            avance = aspersores[i][1];
            while (i + 1 < numAsper && aspersores[i + 1][0] <= aux)
            {
                avance = max(aspersores[++i][1], avance);
            }
            aux = avance;
        }
        if (aux < largo)
            resultado = -1;
        printf("%d\n", resultado);
        for (i = 0; i < numAsper; i++)
        {
            aspersores[i][0] = 0;
            aspersores[i][1] = 0;
        }
    }
    return 0;
}
void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    double L[n1][2], R[n2][2];
    for (i = 0; i < n1; i++)
    {
        L[i][0] = aspersores[l + i][0];
        L[i][1] = aspersores[l + i][1];
    }
    for (j = 0; j < n2; j++)
    {
        R[j][0] = aspersores[m + 1 + j][0];
        R[j][1] = aspersores[m + 1 + j][1];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i][0] <= R[j][0])
        {
            aspersores[k][0] = L[i][0];
            aspersores[k][1] = L[i][1];
            i++;
        }
        else
        {
            aspersores[k][0] = R[j][0];
            aspersores[k][1] = R[j][1];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        aspersores[k][0] = L[i][0];
        aspersores[k][1] = L[i][1];
        i++;
        k++;
    }
    while (j < n2)
    {
        aspersores[k][0] = R[j][0];
        aspersores[k][1] = R[j][1];
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
double max(double a, double b)
{
    return (a > b) ? a : b;
}