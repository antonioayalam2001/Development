//Titulo: Potencia de un alfabeto
//Descripcion: Hacer un programa que reciba como entrada un alfabeto y un entero k, y calcule la potencia k de ese alfabeto.
//Fecha: 1 de marzo de 2021
//Version: 1.0
//Autores: Mora Ayala Jose Antonio, Torres Carrillo Josehf Miguel Angel y Tovar Jacuinde Rodrigo

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void imp_cad(char cad[], char nc[], int act_s, int n, int l){

	int i = 0;

    if (act_s==l){

        printf("%s\n",nc);
        return;
    }

    else{

        for (i; i < n; i++){

            nc[act_s]=cad[i];
            imp_cad(cad,nc,act_s+1,n,l);
        }  
    }
}

int main(){

    int n = 0, k = 0;

    printf("Ingresa el numero de elementos de tu alfabeto: \t");
    scanf("%i", &n);

    char cad[n], esp[10]="";

    printf("\nIngresa el alfabeto (debe ser ingresado de la siguiente forma 'abcd', no dejes espacios o separes con comas): \t");
    scanf("%s", &cad);

    printf("\nIngresa la potencia del alfabeto: \t");
    scanf("%i", &k);

    system("cls");

    imp_cad(cad,esp,0,sizeof(cad),k);

    return 0;

}
