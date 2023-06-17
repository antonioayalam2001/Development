#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char ruta[53] = {"/home/jomiantc/Escritorio/Programas/Punto_8/arc0.txt"};
char save[1];
char cadena[46] = {"Este es el archivo numero 0 de los txt creados"};

int variable, i;
mode_t mode = S_IRUSR | S_IWUSR;

int main (void){

	for (i = 0; i < 10; ++i){

		sprintf(save,"%d",i);

		ruta[47] = save[0];
		cadena[26] = save[0];

		variable = creat(ruta, mode);
		variable = open(ruta, O_WRONLY);

		write(variable, &cadena, sizeof(cadena));

		close(variable);
	}
}