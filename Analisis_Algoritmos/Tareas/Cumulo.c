#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Estrella
{
    float x;
    float y;
}Star;

void Busqueda(Star *s,int x);
int OrdenaCx(const void * , const void *);
double Distancia(Star s, Star p);
double minimaDistancia = 1e10;
int main(int argc, char const *argv[])
{
    int n;
    // n : Representa la cantidad de estrellas que estan en el mapa
    float x, y; //Coordenadas para las estrellas
    printf("Ingresa la cantidad de estrellas: \n");
    scanf("%d", &n);
    Star star[n];
    for (int i = 0; i < n; i++)
    {
        printf("Ingresa las coordenadas para cada estrella: \n");
        scanf("%f %f", &x, &y);
        star[i].x = x;
        star[i].y = y;
    }

    Busqueda(star, n);
    printf("Minima: %f\n",minimaDistancia);

    printf("%f\n", star[0].x);
    printf("%f\n", star[0].y);

    return 0;
}


void Busqueda(Star *s,int x){
    double d;
    int i, j, a, b;
    
    if (n<=1)
    {
        return; 
    }
    qsort(s,x,sizeof(Star),OrdenaCx);
    Busqueda(s, x / 2);
    Busqueda((s+ x / 2),(x+1)/2);
    for ( i = n/2; (i>0)&&(s[n/2].x - s[i].x)<minimaDistancia; i--);
    for ( j = n/2; (j<x-1)&&(s[j].x - s[j/2].x)<minimaDistancia; j++);
    for ( a = i; a <= j; a++)
    {
        for ( b = a+1; b <= j ; b++)
        {
            if ((d-Distancia(s[a],s[b]))<minimaDistancia)
            {
                minimaDistancia = d;
            }
            
        }
        
    }
    
    

}
int OrdenaCx(const void * , const void *){
    return ((*(struct Estrella*)a).x < (*(Star *)b).x) ? -1 : 1;
}
double Distancia(Star s, Star p){
    return (sqrt((s.x - p.x) * (s.x - p.x) + (s.y - p.y) * (s.y - p.y)));
}