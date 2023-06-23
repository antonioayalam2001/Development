#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Variables ciclos
int i = 0, j = 0, k = 0, n = 0;
	
//Variables algoritmo C1
int *A, m1 = 0, m2 = 0, m3 = 0;

//Variables algoritmo C2
int a = 0, b = 0, m = 0, residuo = 0, mcd = 0;

//Variables comprobacion de formula
int repeticiones = 10000, contador = 0, promedio = 0;

int fibonacci[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 
				   89, 144, 233, 377, 610, 987, 1597, 
				   2584, 4181, 6765, 10946, 17711, 28657, 
				   46368, 75025, 121393, 196418, 317811, 
				   514229, 832040};
// Variables Ciclo numero 3
int aux=0,r;


// void c1MejorPeorCaso();
// void c1CasoMedio();
// void c2MejorPeorCaso();
// void c2CasoMedio();
int SumaCuadratica3MayoresV2();

int main(void){

	//Inicializacion de la semilla
	srand (time(NULL));

	//for (k = 0; k < repeticiones; k++){

		//c1MejorPeorCaso();
		//c1CasoMedio();

		//c2CasoMedio();
		
	//}
		// c2CasoMedio();
		//c2MejorPeorCaso();

	
	SumaCuadratica3MayoresV2();
	promedio = promedio/repeticiones;

	//printf("Promedio en %d numeros: %d\n",n ,promedio);

	printf("Promedio : %d\n", promedio);
}


void c1MejorPeorCaso (){

	scanf("%d", &n);

	A = malloc(sizeof(int)*n);

	for (j = 0; j < n; j++){
		
		scanf("%d", &A[j]);
	}

	contador = 0;

	if (A[1] > A[2] && A[1] > A[3]){		

								

		m1 = A[1];				

		if (A[2] > A[3]){					

								

			m2 = A[2];			
			m3 = A[3];			
		}
		else{

								

			m2 = A[3];			
			m3 = A[2];					
		}
	}
	else if (A[2] > A[1] && A[2] > A[3]){

							

		m1 = A[2];				

		if (A[1] > A[3]){					

								

			m2 = A[1];			
			m3 = A[3];			
		}
		else{

								

			m2 = A[3];			
			m3 = A[1];			
		}
	}
	else{

							

		m1 = A[3];				

		if (A[1] > A[2]){	

													

			m2 = A[1];			
			m3 = A[2];			
		}
		else{

								

			m2 = A[2];			
			m3 = A[1];			
		}
	}

	i = 4;

	while( i <= n ){

		if (A[i] > m1){	

												

			m3 = m2;			
			m2 = m1;			
			m1 = A[i];			
		}
		else if (A[i] > m2){			

							

			m3 = m2;			
			m2 = A[i];			
		}
		else if (A[i] > m3){			

			contador+=3;				

			m3 = A[i];			
		}
		else{

			contador+=3;				
		}

		i++;
	}

	promedio+=contador;
}

void c1CasoMedio(){

	scanf("%d", &n);
	A = malloc(sizeof(int)*n); 
	contador = 0;

	for (j = 0; j < n; j++){
		
		A[j]= rand()%(32000);
	}

	if (A[1] > A[2] && A[1] > A[3]){			//-Operacion_CM
		m1 = A[1];							

		if (A[2] > A[3]){					
			m2 = A[2];			
			m3 = A[3];			
		}
		else{
			m2 = A[3];			
			m3 = A[2];					
		}
	}
	else if (A[2] > A[1] && A[2] > A[3]){		//-Operacion_CM
		m1 = A[2];								//-Operacion_CM

		if (A[1] > A[3]){						//-Operacion_CM

			m2 = A[1];							//-Operacion_CM
			m3 = A[3];							//-Operacion_CM
		}
		else{

			m2 = A[3];			
			m3 = A[1];			
		}
	}
	else{

							

		m1 = A[3];				

		if (A[1] > A[2]){	

													

			m2 = A[1];			
			m3 = A[2];			
		}
		else{

								

			m2 = A[2];			
			m3 = A[1];			
		}
	}
	i = 4;

	while( i <= n ){

		if (A[i] > m1){							//-Operacion_CM

			m3 = m2;							//-Operacion_CM
			m2 = m1;							//-Operacion_CM
			m1 = A[i];							//-Operacion_CM
		}
		else if (A[i] > m2){					//-Operacion_CM
			m3 = m2;							//-Operacion_CM
			m2 = A[i];							//-Operacion_CM
		}
		else if (A[i] > m3){					//-Operacion_CM
		m3 = A[i];								//-Operacion_CM
		}
		else{

			contador+=3;				
		}

		i++;
	}

	promedio+=contador;
}

void c2MejorPeorCaso(){
}

void c2CasoMedio(){

	//for (i = 1; i < 30; i++){

		contador = 0;

		//n = fibonacci[i];	//printf("%d",i );
		//m = fibonacci[i+1];	//printf("%d",i );

		n = 8;//rand()%(32000);	printf("n %d\n", n);
		m = 13;//rand()%(32000);	printf("m %d\n", m);
		
		if ( n < m ){
			
			a = m;
			b = n;
		}
		else{

			a = n;
			b = m;
		}

		residuo = 1;

		while( residuo > 0 ){

			residuo = a % b;		//Operacion Basica
			a = b;
			b = residuo;
		}

		mcd = a;

		promedio+=contador;

		printf("contador: %d\n", contador);
		//printf("mcd: %d\n", mcd);
		//printf("promedio: %d\n", promedio);
		
	//}
}

int SumaCuadratica3MayoresV2(){
	scanf("%d", &n);
	A = malloc(sizeof(int)*n); 
	contador = 0;

	for (j = 0; j < n; j++){
		
		A[j]= rand()%(32000);
	}

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < n-1-i ; j++)
        {
            if(A[j]>A[j+1]){
                aux=A[j];
                A[j]=A[j+1];
                A[j+1]=aux;
				contador +=4;
            }
        }        
    }
    r=A[n-1]+A[n-2]+A[n-3];
	contador+=1;
	printf("contador: %d\n", contador);

    return pow(r,2);
}

