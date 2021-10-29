#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    unsigned char T[]={0x45, 0x00, 0x00, 0x42, 0x00, 0xe2, 0x00, 0x50, 0x80, 0x06, 0x00, 0x00, 0x94, 0xcc, 0x3a, 0x11, 0x94, 0xcc, 0x3a, 0x1e};
	unsigned char A[]={0x45, 0x00, 0x01, 0x9c, 0xd7, 0xde, 0x40, 0x00, 0x80, 0x06, 0x88, 0x9d, 0xc0, 0xa8, 0x01, 0x43, 0x94, 0xcc, 0x3a, 0xdd};
    unsigned int suma,acarreo;
    unsigned char i,tam;
    i=0x00;
    tam=0x14;

        // Agarrando valores pares
        while (tam > 1) {
            acarreo = (((T[i] << 8) & 0xFF00) | ((T[i+1]) & 0xFF));
            suma += acarreo;
            if ((suma & 0xFFFF0000) > 0) {
                suma = suma & 0xFFFF;
                suma += 1;
            }
            i += 2;
            tam -= 2;
        }
        printf("%.4x\n",suma);
        suma =~ suma;
        suma = suma & 0xFFFF;
        printf("%.4x",suma);

        // SOLO IMPAR
    // printf("tamaño %x\n",tam);
    //     if (tam > 0) {
    //         suma += ((T[i] << 8) & 0xFF00);
    //         if ((suma & 0xFFFF0000) > 0) {
    //             suma = suma & 0xFFFF;
    //             suma += 1;
    //         }
    //     }



    // unsigned char T[]={0x45, 0x00, 0x01, 0xe2, 0xd7, 0xdb, 0x40, 0x00, 0x80, 0x06, 0x00, 0x00, 0xc0, 0xa8, 0x01, 0x43, 0x94, 0xcc, 0x3a, 0xdd};
	// unsigned char A[]={0x45, 0x00, 0x01, 0x9c, 0xd7, 0xde, 0x40, 0x00, 0x80, 0x06, 0x88, 0x9d, 0xc0, 0xa8, 0x01, 0x43, 0x94, 0xcc, 0x3a, 0xdd};
    // // unsigned char i,tam;
    // // unsigned char suma,acarreo;
    // // int tam,i;

    // unsigned int suma,acarreo;
    // unsigned char i,tam;
    // // unsigned short suma,acarreo;
    // i=0x00;
    // tam=0x14;

    //     // Agarrando valores pares
    //     while (tam > 1) {
    //         acarreo = (((T[i] << 8) & 0xFF00) | ((T[i+1]) & 0xFF));
    //         suma += acarreo;
    //         if ((suma & 0xFFFF0000) > 0) {
    //             suma = suma & 0xFFFF;
    //             suma += 1;
    //         }

    //         i += 2;
    //         tam -= 2;
    //     }

    //     if (tam > 0) {
    //         suma += ((T[i] << 8) & 0xFF00);
    //         if ((suma & 0xFFFF0000) > 0) {
    //             suma = suma & 0xFFFF;
    //             suma += 1;
    //         }
    //     }
    //     printf("%.4x\n",suma);

    //     suma =~ suma;
    //     suma = suma & 0xFFFF;
    //     printf("%.4x",suma);

    // unsigned char a,b,c,d,e,f;
    // a=0xa9;
    // b=0x39;
    // c=a+b;
    // printf("%x",c);
    // printf("%x\n",(~c&0xff));
    // d=a+b+(~c);
    // printf("%x\n",~d);

    // a=0xb3;
    // b=0xab;
    // c=0x5a;
    // d=0xd5;
    // e=a+b+c+d;
    // printf("%x\n",e);
    // printf("Este es el checksum %x\n",~e);
    
    // e=a+b+c+d+~e;

    // printf("Comprobacion: %x\n",~e);
    unsigned char B[]={0x45, 0x00, 0x01, 0xe2, 0xd7, 0xdb, 0x40, 0x00, 0x80, 0x06, 0x00, 0x00, 0xc0, 0xa8, 0x01, 0x43, 0x94, 0xcc, 0x3a, 0xdd};
    unsigned char s=0x00,c=0x00,res=0x00;
    i=0;
    for (i = 0; i <= 19; i++)
    {
        s=T[i]+s;
    }
    printf("\nChecksum %x\n",(~s+1));
    
    unsigned char C[]={0x45, 0x00, 0x01, 0xe2, 0xd7, 0xdb, 0x40, 0x00, 0x80, 0x06, 0x00, 0x00, 0xc0, 0xa8, 0x01, 0x43, 0x94, 0xcc, 0x3a, 0xdd};
    for (char j = 0; j < 20; j++)
    {
         c=C[j]+c;
    }

    c=c+(0x3d);
    printf("Comprobacion: %x\n",(c));
    c=c&0xff;
    printf("Comprobacion: %x\n",(c));
    

    if (c==0xfe)
    {
        printf("No hay erros");
    }
    

    
    // unsigned int a,b,c,d,e,f;
    // a=0x466f;
    // b=0x726f;
    // c=0x757a;
    // d=0x616e;
    // e=a+b+c+d;
    // printf("%x\n",e);
    // printf("Este es el checksum %x\n",~(e+1));
    
    // e=a+b+c+d+~e;




    return 0;
}
