/* Manipulacion de archivos con c
@ Autor : Mora Ayala Jose aNtonio
@ Date : 10 / 31 / 21 
@
@
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Persona
{
    char * Persona;
    int edad;
};

typedef struct Persona Persona;

int escribeArchivo(Persona empleados[], int tam, const char *nombreArchivo );
int leerArchivo(Persona empleados[], int tam, const char *nombreArchivo );
int main(int argc, char const *argv[])
{
    Persona empleados[] = {{"Juan",25},
                        {"Samantha ,30"}};
    int tam = sizeof(empleados)/sizeof(Persona);
    Persona empleadosEntrada[tam];
    escribeArchivo(empleados,tam,"prueba2.txt");

    return 0;
}


int escribeArchivo(Persona empleados[], int tam, const char *nombreArchivo ){
    FILE *archivo;
    int i;
    archivo = fopen(nombreArchivo,"w");
    if (archivo == NULL)
    {
        return 0; 
    }

    for (i = 0; i < tam; i++)
    {
        fwrite(empleados[i],sizeof(Persona),1,archivo );
        // fprintf(archivo,"Empleado: %s , Salario %d",empleados->Persona,empleados->edad);
    }

    fflush(archivo);
    fclose(archivo);
    return 1;  
    
}



int leerArchivo(Persona empleados[], int tam, const char *nombreArchivo ){
    FILE *archivo;
    int i;
    archivo = fopen(nombreArchivo,"w");
    if (archivo == NULL)
    {
        return 0; 
    }

    for (i = 0; i < tam; i++)
    {
        fwrite(&empleados[i],sizeof(Persona),1,archivo );
    }
    fclose(archivo);
    return 1;
}