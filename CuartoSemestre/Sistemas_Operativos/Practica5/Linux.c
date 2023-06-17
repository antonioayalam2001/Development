#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define tam 10

float determinant (float a[tam][tam],float k){
    float s=1, det=0, b[tam][tam];
    int i,j,m,n,c;
    if (k==1){
        return (a[0][0]);
    }
    else{
        det=0;
        for (c = 0; c < k; c++)
        {
            m=0;
            n=0;
            for (i = 0; i < k; i++)
            {
                for (j = 0; j < k; j++)
                {
                    b[i][j]=0;
                    if (i!=0 && j!= c)
                    {
                        b[m][n]=a[i][j];
                        if(n<(k-2))
                        n++;
                    }
                    else
                    {
                        n=0;
                        m++;
                    }
                    
                }
                
            }
            
        }
        det = det +s * (a[0][c]*determinant(b,k-1));
        s=-1*s;
        
    }
    return(det);
}

void transpose(float num[10][10],float fac[10][10],float r, FILE* archivo){
    int i,j;
    r=10;
    float b[10][10], inverse[10][10],d;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            b[i][j]=fac[j][i];
        }
    }
        d=determinant(num,r);
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            inverse[i][j]=b[i][j]/d;
        }
        
    }

    fprintf(archivo, "La inversa de la matriz es: \n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            fprintf(archivo,"\t%f",inverse[i][j]);
        }
            fprintf(archivo,"\n");
        
    }
    
}

void cofactor(float num[10][10],float f, FILE* archivo){
    float b[10][10],fac[10][10];
    int p,q,m,n,i,j;
    for (q = 0; q < f; q++)
    {
        for (p = 0; p < f; p++)
        {
            /* code */
        m=0;
        n=0;
        for (i = 0; i < f; i++)
        {
            for (j = 0; j < f; j++)
            {
                if (i!= q && j!=0)
                {
                    b[m][n]= num[i][j];
                    if (n<(f-2))
                        n++;
                    else{
                        n=0;
                        m++;
                    }
                    
                }
                
            }
            
        }
        fac[q][p] = pow(-1,q+p)* determinant(b,f-1);
        }
        
      
    }
    transpose(num,fac,f,archivo);

}

void sumMatriz(int matrices[][tam][tam],int result[][tam]){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            result[i][j] = matrices[0][i][j] + matrices[1][i][j];
        }
        
    }
    
}

void multMatriz(int matrices[][tam][tam],int result[][tam]){
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            int elemento = 0;
            for (int j = 0; j < 10; j++)
            {
                elemento+= (matrices[0][k][j] * matrices [1][j][i]);
            }
            result[k][i]=elemento;
            
        }
        
    }
    
}

void llenaMatriz (int arreglo[][10][10],int numMatrices){
    for (int i = 0; i < numMatrices; i++)
    {
        printf("Introduce los valores de la Matriz: %d \n",(i+1));
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < tam; k++)
            {
                scanf("%d", &arreglo[i][j][k]);
            }
            printf("\n");
        }
            printf("\n");        
    }
    
}

void imprimeMatriz (int arreglo[][10][10],int numMatrices){
    for (int i = 0; i < numMatrices; i++)
    {
        printf("Matriz %d:  \n",(i+1));
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < tam; k++)
            {
                printf("%d", arreglo[i][j][k]);
            }
            printf("\n");
        }
            printf("\n");        
    }
    
}

void imprimeMatrizuno (int arreglo[][10]){

        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < tam; k++)
            {
                printf("%d", arreglo[j][k]);
            }
            printf("\n");
        }
            printf("\n");        
    
}
void imprimeMatrizd (float arreglo[][10]){

        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < tam; k++)
            {
                printf("%d", arreglo[j][k]);
            }
            printf("\n");
        }
            printf("\n");        
    
}

int main(){

    pid_t pidHijo, pidNieto;
    int matrices1 [2][tam][tam];
    printf("Ingresa matrices a multiplicar");
    llenaMatriz(matrices1,2);

    int fds1[1],fds2[1],fds3[1],fds4[1];
    int buff[2][10][10];
    int buff3[2][10][10];
    int buff4[2][10][10];

    if (pipe(fds1 !=0)) exit(1);
    if (pipe(fds3 !=0)) exit(1);
    if (pipe(fds4 !=0)) exit(1);
    
    if(pidHijo=fork()==0){
        close(fds1[1]);
        read(fds1[0],buff,sizeof(buff));
        int multResul[tam][tam];
        multMatriz(buff,multResul);

        int matrices2[2][tam][10];
        int buff2[2][tam][10];
   
    if (pipe(fds2 !=0)) exit(1);


    printf("Ingresa matrices a Sumar");
    llenaMatriz(matrices2,2);
    if(pidNieto=fork()==0){
        close(fds2[1]);
        read(fds2[0],buff2,sizeof(buff2));
        int sumResul[tam][tam];
        sumMatriz(buff2,sumResul);

        close(fds4[0]);
        write(fds4[1],sumResul,sizeof(sumResul));


    }else{
        close(fds2[0]);
        write(fds2[1],matrices2,sizeof(matrices2));
        
        close(fds3[0]);
        write(fds3[1],multResul,sizeof(multResul));
        
        wait(0);
        

    }

        close(fds3[0]);
        write(fds3[1],multResul,sizeof(multResul));
}else{

        close(fds1[0]);
        write(fds1[1],matrices1,sizeof(matrices1));

        close(fds3[1]);
        read(fds3[0],buff3,sizeof(buff3));
        printf("Del hijo llego la siguiente matriz (multi): \n");
        imprimeMatrizuno(buff3);

        close(fds4[1]);
        read(fds4[0],buff4,sizeof(buff4));

        printf("Del nieto llego la siguiente matriz (suma): \n");
        imprimeMatrizuno(buff4);

        wait(0);

        float inversaUno [10][10];
        conversionMat(buff3,inversaUno);

        FILE* archivo = fopen("Salida1.txt","w");
        float d1= determinant(inversaUno,10);
        if (d1!=0)
        {
            cofactor(inversaUno,10,archivo);
        }else{
            fprintf(archivo, "La matriz no tiene inversa")
        }
        fclose(archivo);

        float inversados[10][10];
        conversionMat(buff4,inversados);

         FILE* archivo2 = fopen("Salida2.txt","w");
        float d2= determinant(inversaUno,10);
        if (d2!=0)
        {
            cofactor(inversados,10,archivo2);
        }else{
            fprintf(archivo2, "La matriz no tiene inversa")
        }
        fclose(archivo2);
        
}

return 0;
}


