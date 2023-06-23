#include <stdio.h>

int Ciclo(int n);

    int contador, i, j, k;
int main(int argc, char const *argv[])
{
    int n;
    n = atoi(argv[1]);
    Ciclo(n);
    return 0;
}

int Ciclo(int n)
{
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
                // contador+=5;                                     
            // }
        }
        contador++;  //Saliendo del for
    }
    contador++;  //Saliendo del for
   	printf("%d\n", contador);

}
