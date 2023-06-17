#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void imp_cad(char cad[], char nc[], int act_s, int n, int l){

    if (act_s==l)
    {
        printf("%s\n",nc);
        return;
    }
    else{
        for (int i = 0; i < n; i++)
        {
            nc[act_s]=cad[i];
            imp_cad(cad,nc,act_s+1,n,l);
        }
        
    }
    
}


int main(){

    int n,k;
    printf("Ingresa el numero de elementos de tu alfabeto: \n");
    scanf("%i",&n);
    char cad[n];
    printf("Ingresa el alfabeto (este debe estar sin espacios y todo junto, ejemplo 'abcd'): \n");
    scanf("%s",&cad);
    printf("Ingresa la potencia del alfabeto: \n");
    scanf("%i",&k);
    system("cls");
    char esp[10]="";
    imp_cad(cad,esp,0,sizeof(cad),k);
    return 0;

}