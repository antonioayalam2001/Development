#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
	
char ruta[53] = {"/home/jomiantc/Escritorio/Programas/Punto_8/arc0.txt"};
char mode[4] = "";
char save[1];

int variable, i, j, k, pausa;

void modificar();
void comando();

int main(void){

	do{

		printf("A que archivo deseas cambiarle los permisos de usuario?\n");
		printf("1 - arc0.txt\n");
		printf("2 - arc1.txt\n");
		printf("3 - arc2.txt\n");
		printf("4 - arc3.txt\n");
		printf("5 - arc4.txt\n");
		printf("6 - arc5.txt\n");
		printf("7 - arc6.txt\n");
		printf("8 - arc7.txt\n");
		printf("9 - arc8.txt\n");
		printf("10 - arc9.txt\n\n");

		printf("0 Salir del programa\n\n");

		printf("Digite el numero del archivo: \t");

		scanf("%d", &i);

		system("clear");

		if(i == 0){

			i = -1;
		}

		else{

			modificar();
		}

		system("clear");

	}while(i != -1);

}

void modificar(){

		i--;

		sprintf(save,"%d",i);

		ruta[47] = save[0];

		mode[0] = '0';

	do{

		printf("Como quieres administrar los permisos del archivo?\n");
		printf("1 - solo lectura\n");
		printf("2 - solo escritura y lectura\n");
		printf("3 - solo lectura y ejecutable\n");
		printf("4 - sin ningun permiso\n");
		printf("5 - con todos los permisos\n\n");

		printf("0 Regresar al menu anterior\n\n");

		printf("Digite el numero del permiso: \t");

		scanf("%d", &j);

		system("clear");

		switch (j){

			case 0:

				j = -1;
				pausa = 0;

			break;

			case 1:

				mode[1] = '4';	mode[2] = '4';	mode[3] = '4';
				comando();

			break;

			case 2:

				mode[1] = '6';	mode[2] = '6';	mode[3] = '6';
				comando();

			break;

			case 3:

				mode[1] = '5';	mode[2] = '5';	mode[3] = '5';
				comando();

			break;

			case 4:

				mode[1] = '0';	mode[2] = '0';	mode[3] = '0';
				comando();

			break;

			case 5:

				mode[1] = '7';	mode[2] = '7';	mode[3] = '7';
				comando();

			break;

			default:

				printf("No has ingresado un numero valido\n");
				
		}

		system("clear");

		if(pausa == 10){

			printf("Modificasion exitosa \n");
			printf("Digite 0 para continuar: \t");

			scanf("%d", &i);

			system("clear");

		}

	}while(j != -1);
}

void comando(){

	k = strtol(mode, 0, 8);

	chmod(ruta, k);

	pausa = 10;

	j = -1;
}