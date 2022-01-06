#include <stdio.h>
#include <stdlib.h>

int sumaMaximaSubDyV(int a[], int inicio, int final);
int max(int n1, int n2, int n3);
int main(int argc, char const *argv[])
{
    int n, x, a;
    scanf("%d", &n);
    int numeros[n];
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &x);
        numeros[j] = x;
    }
    
    a = sumaMaximaSubDyV(numeros, 0, n-1);
    printf("%d",a);
    return 0;
}

int sumaMaximaSubDyV(int a[],int inicio , int final){
    int mitad, izq, der,suma,i,sumaizq,sumader,sumacentro;
    if (inicio == final)
    {
        return a[inicio];
    }
    mitad = (inicio + (final-1)) / 2;
    izq = (sumaMaximaSubDyV(a, inicio, mitad));
    der = (sumaMaximaSubDyV(a, mitad + 1, final));

    suma = 0;
    sumaizq = a[mitad];
    for( i = mitad; i >= inicio; i--)
    {
        suma += a[i];
        if (suma>sumaizq)
            sumaizq = suma;
    }
    suma = 0;
    sumader = a[mitad+1];
    for( i = mitad+1; i <= final; i++)
    {
        suma += a[i];
        if (suma>sumader)
            sumader = suma;
    }
    sumacentro = sumaizq + sumader;
    return max(izq,der,sumacentro);
}

int max(int n1, int n2,int n3) {
    if ( n1 >= n2 && n1 >= n3 )
        return n1;
    else
        if (n2 > n3)
        return n2;
    else
        return n3; 
}