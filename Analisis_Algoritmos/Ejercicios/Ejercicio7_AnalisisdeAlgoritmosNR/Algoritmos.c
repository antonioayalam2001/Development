#include<stdio.h>
#include<math.h>
int SumaCuadratica3Mayores(A, n)
{
    if (A[1] > A[2] && A[1] > A[3])
    {
        m1 = A[1];
        if (A[2] > A[3])
        {
            m2 = A[2];
            m3 = A[3];
        }
        else
        {
            m2 = A[3];
            m3 = A[2];
        }
    }
    else if (A[2] > A[1] && A[2] > A[3])
    {
        m1 = A[2];
        if (A[1] > A[3]){
            m2 = A[1];
            m3 = A[3];}
        else{
            m2 = A[3];
            m3 = A[1];}
    }
    else
    {
        m1 = A[3];
        if (a[1 > A[2]])
{
            m2 = A[1];
            m3 = A[2];
        }
        else
        {
            m2 = A[2];
            m3 = A[1];
        }
    }
    i = 4;
    while (i <= n)
    {
        if (A[i] > m1)
        {
            m3 = m2;
            m2 = m1;
            m1 = A[i];
        }
        else if (A[i] > m1)
        {
            m3 = m2;
            m2 = A[i];
        }
        else if (A[i] > m3)
        {
            m3 = A[i];
        }
        i = i + 1;
    }
    return = pow(m1 + m2 + m3, 2);
}

// void Burbuja(int *A, int n)
// {
//     int i, j, aux;
//     for (i = 0; i < (n - 1); i++)
//     {
//         for (j = i+1; j < (n ); j++)
//         {
//             if (A[j] < A[i])
//             {
//                 aux = A[i];
//                 A[i] = A[j];
//                 A[j] = aux;
//             }
//         }
//     }
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



// void Burbuja2(int *A, int n)
// {
//     bool cambio = true;
//     int i = 1;
//     int j, aux;
//     while (i <= (n - 1) && cambio != false)
//     {
//         cambio = false;
//         for (j = 0; j <= ((n - 1) - i); j++)
//         {
//             if (A[j + 1] < A[j])
//             {
//                 aux = A[j];
//                 A[j] = A[j + 1];
//                 A[j + 1] = aux;
//                 cambio = true;
//             }
//         }
//         i = i + 1;
//     }
//     imprimirArreglo(A, n);
// }


void Burbuja(int *A, int n)
{
    int i, j, aux;
    for (i = 0; i < (n - 1); i++)
    {
        for (j = 0; j < (n - 1); j++)
        {
            if (A[j] > A[j + 1])
            {
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
            }
        }
    }
    imprimirArreglo(A, n);
}


// void ValidaPrima(){
//     int i,n,divisores;
//     printf("Ingresa:");
//     scanf("%d",&i);
//     if (n>0)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             if (n%i==0)
//             {
//                 divisores=divisores+1;
//             }
            
//         }
        
//     }
//     if (divisores == 2)
//     {
//         printf("S");
//     }else{
//         printf("N");
//     }
    
// }
// void FrecuenciaMinNumeros(){
//     int n,i,j,num,f,ftemp,ntemp;
//     int A[n];
//     scanf("%d",&n);
//     while (i<=n)
//     {
//         scanf("d",&A[i]);
//         i=i+1;
//     }
//     f=0;
//     i=1;
//     while (i<=n)
//     {
//         ntemp=A[i];
//         j=1;
//         ftemp=0;
//         while (j<=n)
//         {
//             if (ntemp=A[j])
//             {
//                 ftemp=ftemp+1;  
//             }
//             j=j+1;            
//         }
//         if (f<ftemp)
//         {
//             f=ftemp;
//             num=ntemp;
//         }
//         i=i+1;        
//     }   
//     printf("Numero: %d", num);
// }





// void search(char *pat, char*txt){
//     int M = strlen(pat);
//     int N= strlen(txt);
//     for (int i = 0; i <= N-M; i++)
//     {
//         int j;
//         for (j = 0; j < M; j++)
//         {
//             if (txt[i+j]!=pat[j])
//             {
//                 break;
//             }
            
//         }if (j==M)
//         {
//             printf("Pattern Found at: %D \n ", i);
//         }
//     }
    
// }

// Codigo 10
// stack<int> sortStack(stack<int> &input)
// {
//     stack<int> tmpStack;
 
//     while (!input.empty())
//     {
//         // pop out the first element
//         int tmp = input.top();
//         input.pop();
 
//         // while temporary stack is not empty and top
//         // of stack is greater than temp
//         while (!tmpStack.empty() && tmpStack.top() > tmp)
//         {
//             // pop from temporary stack and push
//             // it to the input stack
//             input.push(tmpStack.top());
//             tmpStack.pop();
//         }
 
//         // push temp in temporary of stack
//         tmpStack.push(tmp);
//     }
 
//     return tmpStack;
// }