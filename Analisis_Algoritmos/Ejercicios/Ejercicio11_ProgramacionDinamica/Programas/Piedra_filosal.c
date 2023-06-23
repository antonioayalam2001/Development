// PHILOSOPHERS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int matriz[101][101];
int x = 0, y = 0;
int max(int a, int b, int c);
int numPiedras();
int main()
{
    int numeroEjecuciones;
    scanf("%d", &numeroEjecuciones);
    while (numeroEjecuciones--)
    {
        scanf("%d %d", &x, &y);
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                scanf("%d", &matriz[i][j]);
        printf("%d\n", numPiedras());
    }
    return 0;
}
int numPiedras()
{
    int piedrasTotales = 0;
    int aux1 = 0, aux2 = 0;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (i > 0)
            {
                if (j > 0)
                    aux1 = matriz[i - 1][j - 1];
                if (j < y - 1)
                    aux2 = matriz[i - 1][j + 1];
                matriz[i][j] = matriz[i][j] + max(matriz[i - 1][j], aux1, aux2);
            }
            piedrasTotales = max(piedrasTotales, matriz[i][j], -1);
        }
    }
    return piedrasTotales;
}
int max(int a, int b, int c)
{

    int numMax = 0;
    numMax = (numMax > a) ? numMax : a;
    numMax = (numMax > b) ? numMax : b;
    numMax = (numMax > c) ? numMax : c;
    return numMax;
}

