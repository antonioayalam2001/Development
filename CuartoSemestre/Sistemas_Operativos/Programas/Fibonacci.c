#include<stdio.h>
int main(){
    int n,x=0,y=1,z=1;
    printf("Digita el numero de elementos para la serie de Fibonacci: \n");
    scanf("%i",&n);
    printf("%i, ",z);


    for (int i = 0; i < n; i++)
    {
        z= x+y;
        x= y;
        y=z ;
        printf(" %d , ", z );
        
        
    }

    return 0;
}