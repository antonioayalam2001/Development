// Codigo pal Tunas pa que vea como esta el pedo.c

#include <stdio.h>
#include <string.h>
#include <windows.h>


void CrearM (int a[3][3]);
void Imprimir (int a[3][3]);


int main(void){

int Matriz[3][3];
CrearM(Matriz);
Imprimir(Matriz);



} 


void CrearM(int a[3][3]){
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j]=10;
        }       
    }
    
}
void Imprimir(int a[3][3]){
    
    for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        printf("%d   ", a[i][j]);
    }
    printf("\n");
    
}

}