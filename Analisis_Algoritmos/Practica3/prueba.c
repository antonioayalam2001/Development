#include <stdio.h>

void llenaarreglo(int *bin);

int main(int argc, char const *argv[])
{
    int bin[8];
    llenaarreglo(bin);

    for (int i = 0; i < 8; i++)
    {
        printf("el valor es %d\n",bin[i]);
    }
    
    return 0;
}

void llenaarreglo(int *bin){
    for (int i = 0; i < 8; i++)
    {
        printf("Ingresa los valores \n");
        scanf("%d",&bin[i]);
    }
}