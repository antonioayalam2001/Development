#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

struct stat statbuf;

char archivo[8] = {"arc0.txt"};
char save[1];
char times[25];

int i;

int main (void){

	for (i = 0; i < 10; ++i){

		sprintf(save,"%d",i);

		archivo[3] = save[0];
		
		stat(archivo, &statbuf);

		printf("Archivo: %s   ", archivo);

		printf("tamaño del archivo: %ld bytes   ", statbuf.st_size);

		strcpy(times, ctime(&statbuf.st_mtime));

		printf("ult.modificacion: %s", times);

	}

}