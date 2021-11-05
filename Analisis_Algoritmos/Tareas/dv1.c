#include <stdio.h>
#include <stdlib.h>

int sumaMaximaSubDyV(int a[], int inicio, int final);
int max(int n1, int n2, int n3);
int main(int argc, char const *argv[])
{
    int n;
    printf("Ingresa la cantidad de numeros:\n");
    scanf("%d", &n);
    int numeros[8] = {-2,-3,4,-1,-2,1,5,-3};
    int a;
    a = sumaMaximaSubDyV(numeros, 0, 7);
    printf("%d",a);

    // for (int j = 0; j < n;j++)
    // {
    //     printf("numero %d\n",numeros[j]);
    // }
    
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