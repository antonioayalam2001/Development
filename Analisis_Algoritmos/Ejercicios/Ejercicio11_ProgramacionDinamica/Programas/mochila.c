
#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

void printknapSack(int pesom, int peso[], int ben[], int n)
{
    int i, w;
    int K[n + 1][pesom + 1];

    // construyendo tabla de forma dinamica
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= pesom; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (peso[i - 1] <= w)
                K[i][w] = max(ben[i - 1] + K[i - 1][w - peso[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    // Ultimo posicion de la tabla esquina inferior derecha, por lo cual podemos acceder
    // al valor almacenado para su impresion
    int res = K[n][pesom];
    printf("%d\n", res);
}
int main()
{
    int elementos;
    int pesom;
    scanf("%d %d", &pesom, &elementos);
    // valor de cada elemento
    int ben[elementos];
    // Peso del elemento
    int peso[elementos];
    for (int i = 0; i < elementos; i++)
    {
        scanf("%d %d", &peso[i], &ben[i]);
    }
    printknapSack(pesom, peso, ben, elementos);

    return 0;
}

// #include <stdio.h>

// int max(int a, int b) { return (a > b) ? a : b; }

// // Returns the maximum value that can be
// // put in a knapsack of capacity W
// int knapSack(int W, int wt[], int val[], int n)
// {
//     // Base Case
//     if (n == 0 || W == 0)
//         return 0;

//     // If weight of the nth item is more than
//     // Knapsack capacity W, then this item cannot
//     // be included in the optimal solution
//     if (wt[n - 1] > W)
//         return knapSack(W, wt, val, n - 1);
//     // Return the maximum of two cases:
//     // (1) nth item included
//     // (2) not included
//     else
//         return max(
//             val[n - 1]
//             + knapSack(W - wt[n - 1],wt, val, n - 1),
//             knapSack(W, wt, val, n - 1));
// }

// // Driver program to test above function
// int main()
// {
//     int val[] = { 60, 100, 120 };
//     int wt[] = { 10, 20, 30 };
//     int W = 50;
//     int n = sizeof(val) / sizeof(val[0]);
//     printf("%d", knapSack(W, wt, val, n));
//     return 0;
// }

