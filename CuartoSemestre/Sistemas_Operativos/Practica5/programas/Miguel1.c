#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void crear();

short int i = 0, j = 0, k = 0;
double matrizA3[3][3] = {

	{1, 3, 5},
	{1, 3, 2},
	{3, 2, 1},

};

double identidad3[3][3] = {

	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1},

};

double save3[3][3];

int main (void){

	crear();
}


void crear(){
    double aux=0,pivote=0,aux2=0,aux3=0;

	for (i = 0; i < 3; i++){

		for (j = 0; j < 3; j++){

			save3[i][j] = matrizA3[i][j];
		}
	}


	for (i = 0; i < 3; i++){
        aux2=save3[i][j];
		pivote = aux2;

		for (k = 0; k < 3; k++){

			save3[i][k] = save3[i][k]/pivote;
			identidad3[i][k] = identidad3[i][k]/pivote;
		}

		for (j = 0; j < 3; j++){
			
			if (i != j){

				aux3 = save3[j][i];
                aux=aux3;

				for ( k = 0; k < 3; k++){
					
					save3[j][k] = save3[j][k] - aux*save3[i][k];
					identidad3[j][k] = identidad3[j][k] - aux*identidad3[i][k];
				}
			}
		}

	} 

	for (i = 0; i < 3; i++){

		for (j = 0; j < 3; j++){

			printf("%.2f  ", save3[i][j]);
		}
		printf("\n");
	}

}