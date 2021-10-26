 #include<stdio.h>
int main(int argc, char const *argv[])
{
    int count;
    char string[12];
    printf("Ingresa la palabra que deseas obtener la cuenta de caracetres: ");
    gets(string);
    printf("%s",string);

    // El espacio tambien cuenta como un caracter, debemos agregar una restriccion para ese caso.
    for (char i = 'a'; i < 'z'; i++)
    {
        count=0;
        for (int j = 0; j <= 11; j++)
        {
            if (i == string[j])
            {
                count++;
            }       
        }
            if (count>0)
            {
                printf("La letra %c fue encontrada: %d  veces \n",i,count);
            }
        
    }
    

    return 0;
}
