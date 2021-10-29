#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void evaluaT(unsigned char T[]);

int main(int argc, char const *argv[])
{
    unsigned char T[] = {0x45, 0x00, 0x01, 0xe2, 0xd7, 0xdb, 0x40, 0x00, 0x80, 0x06, 0x00, 0x00, 0xc0, 0xa8, 0x01, 0x43, 0x94, 0xcc, 0x3a, 0xdd};
    unsigned char A[] = {0x45, 0x00, 0x01, 0x9c, 0xd7, 0xde, 0x40, 0x00, 0x80, 0x06, 0x88, 0x9d, 0xc0, 0xa8, 0x01, 0x43, 0x94, 0xcc, 0x3a, 0xdd};
    unsigned char J[] = {0x45, 0x00, 0x00, 0x42, 0x00, 0xe2, 0x00, 0x50, 0x80, 0x06, 0x9b, 0xbc, 0x94, 0xcc, 0x3a, 0x11, 0x94, 0xcc, 0x3a, 0x1e};
    printf("Trama lado Alicia:\n");
    evaluaT(T);
    printf("Trama lado Beto:\n");
    evaluaT(A);
    printf("Trama ejemplo:\n");
    evaluaT(J);
}

void evaluaT(unsigned char T[])
{
    unsigned int suma = 0x00, acarreo = 0x00;
    unsigned char i, tam;

    i = 0x00;
    tam = 0x14;
    // Agarrando valores pares
    while (tam > 1)
    {
        acarreo = (((T[i] << 8) & 0xFF00) | ((T[i + 1]) & 0xFF));
        suma += acarreo;
        if ((suma & 0xFFFF0000) > 0)
        {
            suma = suma & 0xFFFF;
            suma += 1;
        }
        i += 2;
        tam -= 2;
    }
    suma = ~suma;
    suma = suma & 0xFFFF;
    if (suma == 0)
    {
        printf("El checksum es correcto\n");
    }
    else if (T[10] == 0 && T[11] == 0)
    {
        printf("El checksum correcto es: 0x%.4x\n", suma);
    }
    else
    {
        suma = 0x00, acarreo = 0x00;
        i = 0x00;
        tam = 0x14;
        T[10] = 0;
        T[11] = 0;
        while (tam > 1)
        {
            acarreo = (((T[i] << 8) & 0xFF00) | ((T[i + 1]) & 0xFF));
            suma += acarreo;
            if ((suma & 0xFFFF0000) > 0)
            {
                suma = suma & 0xFFFF;
                suma += 1;
            }
            i += 2;
            tam -= 2;
        }
        printf("La suma es: 0x%.4x\n", suma);
        suma = ~suma;
        suma = suma & 0xFFFF;
        printf("El checksum correcto es: 0x%.4x\n", suma);
    }
}
