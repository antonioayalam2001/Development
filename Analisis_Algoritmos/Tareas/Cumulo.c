#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
double MinimaDistancia = 1e10; // Mínima distancia.

// A structure to represent a Point in 2D plane
typedef struct Point
{
    float x, y;
} Point;

// La función de comparación tiene tres valores de retorno, 1, 0 y -1. Pero debe dividirse en tres tipos: <0,> 0, 0. El valor de retorno de la función es de tipo int, y ambos parámetros son const void * (const es de solo lectura, es decir, no se puede modificar. Void puede ser de cualquier tipo, y a y b se nombran arbitrariamente). El nombre de la función cmp se puede personalizar con cualquier nombre, pero el nombre pasado en qsort () debe ser el que desea definir.
int compareX(const void *a, const void *b)
{
    return (((*(Point *)a).x < (*(Point *)b).x) ? -1 : 1); //Manera en que se comparan los puntos x
}

float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// A Brute Force method to return the smallest distance between two points
// // in P[] of size n
// float bruteForce(Point P[], int n)
// {
//     float min = FLT_MAX;
//     for (int i = 0; i < n; ++i)
//         for (int j = i + 1; j < n; ++j)
//             if (dist(P[i], P[j]) < min)
//                 min = dist(P[i], P[j]);
//     return min;
// }

void Busca(struct Point *p, int n)
{
    double d;
    int i, j, a, b;
    if (n <= 1) // Si no hay pares de puntos:
        return; // salir.

    //    Parámetro
    // Como se puede ver en la declaración, esta función no tiene valor de retorno y necesita cuatro parámetros. El cuarto parámetro es el puntero de función, y el concepto del puntero de función no se explicará aquí. Aquellos que estén interesados ​​deben entenderlo.
    // 1. base: un puntero al primer elemento de la matriz que se va a ordenar.
    // 2. nitems: el número de elementos en la matriz a los que apunta la base.
    // 3. size - el tamaño de cada elemento en la matriz, en bytes.
    // 4. compar - una función utilizada para comparar dos elementos.
    qsort(p, n, sizeof(struct Point), compareX); // Ordenar los puntos por la coordenada x.

    Busca(p, n / 2); // Mirar en el subconjunto de la izquierda.

    Busca(p + n / 2, (n + 1) / 2); // Mirar en el subconjunto de la derecha.

    //Busca del lado derecho e izquiero los puntos mas cercanos
    for (i = n / 2; (i > 0) && (p[n / 2].x - p[i].x < MinimaDistancia); i--)
        ; // Hallar los límites del conjunto central.

    for (j = n / 2; j < n - 1 && p[j].x - p[n / 2].x < MinimaDistancia; j++)
        ;

    // Búsqueda en el conjunto central.
    for (a = i; a <= j; a++)
        for (b = a + 1; b <= j; b++)
            if ((d = dist(p[a], p[b])) < MinimaDistancia) //Si encuentras una distancia mínima actualizala
            {
                MinimaDistancia = d;
            }
}

int main()
{
    int n;
    double x, y;
    scanf("%d", &n);
    Point P[n];
    int aux;
    if (n>=2 && n<=50000)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf  %lf", &x,&y);
            P[j].x = x;
            P[j].y = y;
        }
        Busca(P, n); //Busca la minima distancia
        printf("%.3lf\n", MinimaDistancia);

    }else{
        return 0;
    }
    
    return 0;
}