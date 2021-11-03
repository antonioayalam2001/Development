#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *nombreArchivoFrecuencia;
char *nombreArchivoCodificacion;


int main (int argc, char* argv[]){

	if(argc!=3){

        printf("Ingresa el nombre del archivo %s\n",argv[0]);
        exit(0);    
    }else{

    	nombreArchivoFrecuencia = argv[1];
    	nombreArchivoCodificacion = argv[2];
    }

	FILE *frecuenciasTXT = NULL;

	frecuenciasTXT = fopen(nombreArchivoFrecuencia, "r");


	char *cadenaPrueba =malloc(sizeof(char)*100);
	char *cadenaValor = malloc(sizeof(char)*100);
    fgets(cadenaPrueba,100,frecuenciasTXT);
    fgets(cadenaPrueba,100,frecuenciasTXT);
    fgets(cadenaPrueba,100,frecuenciasTXT);
    printf("%s\n",cadenaPrueba);
    int valorbits = atoi(cadenaPrueba);
    printf("%d\n",valorbits);


}