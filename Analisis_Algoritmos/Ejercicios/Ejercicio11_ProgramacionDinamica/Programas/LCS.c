#include <stdio.h>
#include <string.h>

int max(int a, int b);
// Funcion Longest Common subsequence
// X ->  Cadena numero 1
// Y   -> Cadena numero 2
// m  -> longitud de cadena numero 1
// n  -> longitud de cadena numero 2
int lcs(char *cad1, char *cad2, int m, int n)
{
    // creacion de una tabla dinamica
    // esta varía de acuerdo a los parametros dados, los cuales estan definidos
    // por las longitudes de cada una de las cadenas respectivamente
    // la primer cadena determina filas
    // segunda cadena determina columnas
    int L[m + 1][n + 1];
    // Indices para el manejo de los ciclos for
    int i, j;

    // Primer ciclo que va iterando sobre filas
    for (i = 0; i <= m; i++)
    {
        // Ciclo que va iterando sobre las columnas
        for (j = 0; j <= n; j++)
        {
            // Llenando primer fila y columna de puros 0
            if (i == 0 || j == 0)
                L[i][j] = 0;
            // Cuando hay una coincidencia debemos de realizar el incremento en 1 a el valor
            // que se encuentra en su esquina superior izquierda
            else if (cad1[i - 1] == cad2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                // En caso contrario debemos colocar el maximo de la casilla anterior o la superior
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // Nos devuelve el valor que fue almacenado en la ultima posiciond e la tabla con respecto a filas y columnas
    // tal como en la programacion dinamica
    return L[m][n];
}

// Funcion de la cual nos auxiliamos para poder obtener el maximo de dos numeros dados
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    // char cad1[] = "AGCT";
    // char cad2[] = "AMGXTP";
    char cad1[100000];
    char cad2[100000];
    scanf("%s", &cad1);
    scanf("%s", &cad2);

    int m = strlen(cad1);
    int n = strlen(cad2);

    printf("%d", lcs(cad1, cad2, m, n));
    return 0;
}