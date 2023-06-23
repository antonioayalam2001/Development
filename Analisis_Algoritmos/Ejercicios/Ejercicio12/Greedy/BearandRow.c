#define MAX 1000000
#include <stdio.h>
#include <string.h>


int main()
{
    int casos,
    // Variables de ciclos
    i,j;
    long long seg,y,tam,
    // Celda vacia 
    vacio,soldado;
    // Cadena de caracteres recibida 
    char a[MAX];
    scanf("%d", &casos);

    while(casos--){
        scanf("%s", a);
        // Longitud de la cadena
        tam= strlen(a);
        // Reiniciando las variables para las distintas partidas
        seg=vacio=y=soldado = 0;
        for(i=tam-1;i>=0;--i){
            if(a[i]=='0'){
                vacio++;
            }    
            else if(a[i]=='1' && vacio>0){
                y= vacio+y+1;
                seg+= y;
                vacio=0;
            }
            else if(a[i]=='1' && vacio==0){
                seg+=y;
            }
        }
        printf("%lld\n",seg);
    }

    return 0;
}  