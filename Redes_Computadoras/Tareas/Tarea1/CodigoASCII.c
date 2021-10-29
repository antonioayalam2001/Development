#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    
    // short int bits=0,i;
    // char c;
    // // int codigo[8];
    // printf("Ingresa un caracter; \n");
    // gets(&c);
    // for (i = 0; i < 8; i++)
    // {
    //     if((c & (1<<i))==0){
    //         // codigo[7-i]=0;
    //         bits+=0;
    //     }else{
    //         // codigo[7-i]=1;
    //         bits+=1;
    //         }
    // }
    // printf("El numero de bits que tiene el caracter introducido: %c es %d \n",c,bits);
    // // for (int i = 0; i < 8; i++)
    // // {
    // //     printf("%d",codigo[i]);
    // // }
    
    unsigned char i=1;
    unsigned char c='R';
    short int contador=0;
    for ( i = 1; i <=128 ; i=i<<1)
    {
    printf("%d",contador);
        
    }



    
    
    return 0;
}
