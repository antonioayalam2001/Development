#include <stdio.h>
#include <stdlib.h>
// int SumaCuadratica3Mayores(A, n);
// int MaximoComunDivisor(m, n);
// int SumaCuadratica3MayoresV2(A,n);
int Codigo5();
int Codigo4();

int main(int argc, char const *argv[])
{
    // SumaCuadratica3Mayores(A, n)
    // MaximoComunDivisor(m, n);
    // SumaCuadratica3MayoresV2(A,n);
    //  Codigo5();
     Codigo4();
    return 0;
}

// Código 01: *Recomendación: Usar como operaciones básicas: comparación entre elementos del arreglo A y Asignaciones a mayor1, mayor 2 y mayor 3.

// int SumaCuadratica3Mayores(A, n)
// {
//     if (A[1] > A[2] && A[1] > A[3])
//     {
//         m1 = A[1];
//         if (A[2] > A[3])
//         {
//             m2 = A[2];
//             m3 = A[3];
//         }
//         else
//         {
//             m2 = A[3];
//             m3 = A[2];z
//         }
//     }
//     else if (A[2] > A[1] && A[2] > A[3])
//     {
//         m1 = A[2];
//         if (A[1] > A[3])
//         {
//             m2 = A[1];
//             m3 = A[3];
//         }
//         else
//         {
//             m2 = A[3];
//             m3 = A[1];
//         }
//     }
//     else
//     {
//         m1 = A[3];
//         if (a[1 > A[2]])
//         {
//             m2 = A[1];
//             m3 = A[2];
//         }
//         else
//         {
//             m2 = A[2];
//             m3 = A[1];
//         }
//     }
//     i = 4;
//     while (i <= n)
//     {
//         if (A[i] > m1)
//         {
//             m3 = m2;
//             m2 = m1;
//             m1 = A[i];
//         }
//         else if (A[i] > m1)
//         {
//             m3 = m2;
//             m2 = A[i];
//         }
//         else if (A[i] > m3)
//         {
//             m3 = A[i];
//         }
//         i = i + 1;
//     }
//     return = pow(m1 + m2 + m3, 2);
// }

// int MaximoComunDivisor(m, n){
//     a=max(n,m);
//     b=min(n,m);
//     residuo=1;
//     while (residuo>0)
//     {
//         residuo = a%b;
//         a=b;
//         b=residuo;
//     }
//     MaximoComunDivisor=a;
//     return MaximoComunDivisor;    
// }

// int SumaCuadratica3MayoresV2(A,n){
//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < n-1; j++)
//         {
//             if(A[j]>A[j+1]){
//                 aux=A[j];
//                 A[j]=A[j+1];
//                 A[j+1]=aux;
//             }
//         }        
//     }
//     r=A[n-1]+A[n-2]+A[n-3];
//     return pow(r,2);
// }

int Codigo5(){
    int A[11]={1,2,3,4,5,1,2,3,4,5,6};
    int B[0]={};
    int C[3]={1,2,3};
    int *d;
    d= malloc(sizeof(int)*1000);
    int n=1000;
    for (int j = 0; j < 1000; j++)
    {
        d[j]=1;
    }
        
    int z=1,cont=0,i,polinomio=0;
    
    polinomio=0;

    for (i = 0; i <= n; i++)
    {
        polinomio=polinomio*z + d[n-i];
        cont+=1;
    }
    printf("%d",cont);

    
}

int Codigo4(){
    int f=0,i=0,j=0,num=0,ftemp=0,ntemp=0,n;
    int cont=0;
    printf("Ingresa");
    scanf("%d",&n);
    int A[n];
    i=1;
    while (i<=n)
    {
        scanf("%d",A[i]);
        i+=1;
        cont+=1;
    }
    printf("Hola");
    f=0;
    i=1;
    while (i<=n)
    {
        ntemp=A[i];
        j=1;
        ftemp=0;
        cont+=3;
        while (j<=n)
        {
            if (ntemp=A[j])
            {
                ftemp=ftemp+1;
                cont+=1;
            }
            j=j+1;
        }

        if (f<ftemp)
        {
            f=ftemp;
            num=ntemp;
            cont++;
        }
        i=i+1;
    }
    printf("Num: %d",cont);
}
