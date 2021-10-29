#include<stdio.h>
#include<string.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    // Prueba 1. En esta trama los valores del Checksum estan en 0000 ya que apenas se va a calcular (ALICIA)
    unsigned char T[]={0x45, 0x00, 0x01, 0xe2, 0xd7, 0xdb, 0x40, 0x00, 0x80,
    0x06, 0x00, 0x00, 0xc0, 0xa8, 0x01, 0x43, 0x94, 0xcc, 0x3a, 0xdd};
    // unsigned char H[10];
    // char acarreo;
    // H[0]=T[1]+T[3]+T[5];
    // acarreo = (T[1]+T[3])/16;
    // printf("%.2x",H[0]);
    // printf("%.1x",acarreo);
    // unsigned char a[4]= {1,1,1,1};
    // // printf("%.1x",a);
    // // printf("%d",a);
    // char b= 0x4;
    // char c[4]={};
    // // for (char i = 3; i >=0; i--)
    // // {
    // //     c[i]=a+b;
    // //     printf("%.1x\n",c[i]);
    // // }

    // // if ((c[1] & b) == 1)
    // // {
    // //     printf("Accareo aumenta");
    // // }

    // T[1]<<3;
    // printf("%d",T[1]);
    
    printf("%d\n",T[3]);
    printf("%x\n",T[3]);
    // printf("%s",T[1]);
    // printf("%c",T[3]);
    if (T[3]== 'E' && T[3]=='2')
    {
        printf("Hola");
    }
    
    unsigned char prueba;
    prueba = T[0]+T[3];
    printf("%x",prueba);
    printf("%d",prueba);

                
    
    
    
    
    
    // printf("0x%.2x",(T[1]+T[2]));
// Prueba 2: Para esta trama ya se tiene el valor del checksum (es la que recibió BETITO) verificar si el checksum
// es correcto y en caso de no serlo mostrar el correcto.


    return 0;
}
