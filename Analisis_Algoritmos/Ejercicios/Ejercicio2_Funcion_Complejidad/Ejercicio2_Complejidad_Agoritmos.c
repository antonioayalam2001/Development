#include<stdio.h>

int main(int argc, char const *argv[])
{
    // int n= -1,contador=1;
    // int n= 0,contador=1;
    // int n= 1,contador=1; 
    // int n= 2,contador=1; 
    // int n= 3,contador=1; 
    int n= 8,contador=0; 
    // int n= 15,contador=1; 
    // int n= 20,contador=1; 
    // int n= 100,contador=1; 
    // int n= 409,contador=1; 
    // int n= 500,contador=1; 
    // int n= 593,contador=1; 
    // int n= 1000,contador=1; 
    // int n= 1471,contador=1; 
    // int n= 1500,contador=1; 
    // int n= 2801,contador=1; 
    // int n= 3000,contador=1; 
    // int n= 5000,contador=1; 
    // int n= 10000,contador=1; 
    // int n= 20000,contador=1;

    // CICLO NUMERO 1
    int i,j,k;
    // int cont=0;
    // int temp;
    // int A[]={0};
    // for (i = 1, cont++; i < n;cont++, i++)
    // {
    //     cont++;
    //     for (j = n,cont++;j > 1;cont++, j/=2 )
    //     {
    //         cont++;
    //         temp = A[j];
    //         cont++;
    //         A[j]=A[j+1];
    //         cont+=2;
    //         A[j+1]=temp;
    //         cont+=2;
    //         cont++;
    //     }
    //     cont++;  
    // }
    // cont++;

    // printf("%d",cont);

    // // Ciclo NUMERO 2
    // int polinomio=0;
    // int z;
    // for (int i = 0; i < =n; i++)
    // {
    //     polinomio = polinomio * z + A[n-i]; 
    // }


    // // CICLO 3
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         C[i, j] = 0;
    //         for (int k = 0; k <= n; k++)
    //         {
    //             C[i][j] = C[i][j] + A[i][k] * B[k][j];
    //         }
    //     }
    // }

    // // CICLO 4
    // int anterior =1, actual=1,aux; 
    // contador+=2;        //2 asignaciones
    // while (n>2)
    // {
    //     contador++;     //Entrando al while
    //     aux=anterior+actual; //Asignacion + Aritmetica
    //     anterior=actual;     //Asignacion
    //     actual=aux;          //Asignacion
    //     n=n-1;               //Asignacion+Aritmetica
    //     contador+=6;
    // }

    // // CICLO 5
    // for (i = n - 1, j = 0, contador+=2; i >= 0; i--, j++, contador+=2)
    // {
    //     contador++; //Ingresando al for
    //     s2[j]=s[i];
    //     contador++; //Asignacion
    // }
    // contador++; //saliendo for

    // for (k = 0, contador++;	k < n; k++, contador++){
    //     contador++; //Entrando al for
    //     s[i]=s2[j];
    //     contador++; //Asignacion
    // }    
    // contador++; //Saliendo for
   	// printf("%d\n", contador);
    
    // // CICLO 6
    // int l,a=0,b=0,r;
    // l=(a<b)?a:b;
    // contador+=3; //2 Comparaciones + 1 asignacion
    // r=1;
    // contador++; //Asignacion
    // for (i = 2, contador++; i <= n; i++,contador++)
    // {
    //     contador++; //Entrando al Bucle
    //     if (a%i==0 && b%i==0)
    //     {
    //         contador+=5; //2 aritmeticas, 1 asignacion,3 comparaciones
    //         r=i;
    //         contador++; //1 asignacion
    //     }        
    // }
    // contador++; //Saliendo del for 
   	// printf("%d\n", contador);

    // CICLO 7
    for (i = 1,contador++; i < n;contador++, i++){
    contador++;                          //Entrando al for
        for (j = 0,contador++; j < n-1;contador++, j++)
        {
            contador++;             //Entrando al for j
            // if (lista[j]>lista[j+1])
            // {
                contador+=2;      //1 comparacion + 1 aritmetica
                // temp=lista[j];  //Asignacion 
                // lista[j]=lista[j+1]; //1 asigancion+1aritmetica
                // lista[j+1]=temp;  //1 Aritmetica + 1 asignacion
                contador+=5;                                     
            // }
        }
        contador++;  //Saliendo del for
    }
    contador++;  //Saliendo del for
   	printf("%d\n", contador);
    
    


    return 0;
}
