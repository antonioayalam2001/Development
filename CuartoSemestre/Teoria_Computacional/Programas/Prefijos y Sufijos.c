//Titulo: Prefijos y sufijos
//Descripcion: Hacer un programa que reciba como entrada una cadena w y calcule todos los sufijos y prefijos (incluyendo épsilon).
//Fecha: 1 de marzo de 2021
//Version: 1.0
//Autores: Mora Ayala Jose Antonio, Torres Carrillo Josehf Miguel Angel y Tovar Jacuinde Rodrigo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){

	int a = 0 ,b = 1 , i = 0, j = 0;
	char arreglo[24];

	printf("Ingrese la palabra \n");

	scanf("%s", &arreglo);

	a = strlen(arreglo);

	system("cls");

	printf("Prefijos : { EPSILON, ");

	for (i = 0; i < a; ++i){

		if (b == i){

			printf(", ");
			i=0;
			b++;
		}

		printf("%c", arreglo[i]);

	}

	printf("}\n\n");	b = a-2;

	printf("Sufijos : { EPSILON, ");

	for (i = a-1; i >= 0; i--){

		if (b == i){

			printf(", ");
			b--;

			printf("%c", arreglo[i]);

			for (j = i+1; j < a; ++j){

				printf("%c", arreglo[j]);
			}
		}
		else{

			printf("%c", arreglo[i]);
		}
	}

	printf("}\n\n");

}
