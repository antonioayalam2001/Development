#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char val[10];
unsigned char linea[4];
unsigned char acarreo;

void computo (unsigned char trama[]);

int main(void){

	unsigned char T[]={0x45, 0x00, 0x01, 0xe2, 0xd7, 0xdb, 0x40, 0x00, 0x80, 0x06, 0x00, 0x00, 0xc0, 0xa8, 0x01, 0x43, 0x94, 0xcc, 0x3a, 0xdd};
	unsigned char A[]={0x45, 0x00, 0x01, 0x9c, 0xd7, 0xde, 0x40, 0x00, 0x80, 0x06, 0x88, 0x9d, 0xc0, 0xa8, 0x01, 0x43, 0x94, 0xcc, 0x3a, 0xdd};

//Programa Primera Parte

	computo(T);

//Programa Segunda Parte

	computo(A);

	A[10] = 0x00;
	A[11] = 0x00;

	computo(A);

//Codigo de Pruebas
	/*

		45 = 69
		11 = 17
		56 = 86

		while (T[0]) {

	    	if (T[0] & 1) printf("1");
	    	else printf("0");

	    	T[0] <<= 1;
		}

		printf("\n");

		4 5 	0 0 	1
		0 1 	e 2 	3
		d 7 	d b 	5
		4 0 	0 0 	7
		8 0 	0 6 	9
		0 0 	0 0 	11
		c 0 	a 8 	13
		0 1 	4 3 	15
		9 4 	c c 	17
		3 a 	d d 	19

		unsigned char p1 = T[0], p2 = T[1];

		printf("%0.2x %0.2x\n", p1 , p2);

		unsigned char acarreo;
		unsigned int resultado = (p2<<8) | p1;

		printf("%0.8x \n", resultado);

	*/	
	/*
		//T[10]=0xac;
		//T[11]=0xac;

		bits = 8;

		printf("Ingrese el valor de entrada\n");
		scanf("%c", &entrada);

		for (bits; bits > 0; bits >>= 1){
			
			resultado[2] = resultado[2] + T[0]+;

		}


		for (int i = 0; i < 20; i+=2){
			
			resultado = resultado + T[i] + T[];

		}

		acarreo = resultado[2]%16;
		resultado[2] = resultado[2]/16;

		printf("Acarreo: %.3x, Resultado %.3x\n", acarreo, resultado[2]);

	*/	
}

void computo (unsigned char trama[]){

	//Para la suma de la primera linea

	acarreo = 0x00;

	val[0] = trama[1] - ((trama[1] / 0x10)*0x10);
	val[1] = trama[3] - ((trama[3] / 0x10)*0x10);
	val[2] = trama[5] - ((trama[5] / 0x10)*0x10);
	val[3] = trama[7] - ((trama[7] / 0x10)*0x10);
	val[4] = trama[9] - ((trama[9] / 0x10)*0x10);
	val[5] = trama[11] - ((trama[11] / 0x10)*0x10);
	val[6] = trama[13] - ((trama[13] / 0x10)*0x10);
	val[7] = trama[15] - ((trama[15] / 0x10)*0x10);
	val[8] = trama[17] - ((trama[17] / 0x10)*0x10);
	val[9] = trama[19] - ((trama[19] / 0x10)*0x10);

	linea[0] = val[0]+val[1]+val[2]+val[3]+val[4]+val[5]+val[6]+val[7]+val[8]+val[9];
	acarreo = (linea[0] / 0x10)*0x10;

	linea[0] = linea[0] - acarreo;

	acarreo = acarreo/0x10;

	//Para la suma de la segunda linea
	val[0] = (trama[1] / 0x10);	
	val[1] = (trama[3] / 0x10);	
	val[2] = (trama[5] / 0x10);	
	val[3] = (trama[7] / 0x10);	
	val[4] = (trama[9] / 0x10);	
	val[5] = (trama[11] / 0x10);	
	val[6] = (trama[13] / 0x10);	
	val[7] = (trama[15] / 0x10);	
	val[8] = (trama[17] / 0x10);	
	val[9] = (trama[19] / 0x10);	

	linea[1] = acarreo+val[0]+val[1]+val[2]+val[3]+val[4]+val[5]+val[6]+val[7]+val[8]+val[9];
	
	acarreo = (linea[1] / 0x10)*0x10;

	linea[1] = linea[1] - acarreo;

	acarreo = acarreo/0x10;

	//Suma para la tercera linea

	val[0] = trama[0] - ((trama[0] / 0x10)*0x10);	
	val[1] = trama[2] - ((trama[2] / 0x10)*0x10);	
	val[2] = trama[4] - ((trama[4] / 0x10)*0x10);	
	val[3] = trama[6] - ((trama[6] / 0x10)*0x10);	
	val[4] = trama[8] - ((trama[8] / 0x10)*0x10);	
	val[5] = trama[10] - ((trama[10] / 0x10)*0x10);
	val[6] = trama[12] - ((trama[12] / 0x10)*0x10);
	val[7] = trama[14] - ((trama[14] / 0x10)*0x10);
	val[8] = trama[16] - ((trama[16] / 0x10)*0x10);
	val[9] = trama[18] - ((trama[18] / 0x10)*0x10);

	linea[2] = acarreo+val[0]+val[1]+val[2]+val[3]+val[4]+val[5]+val[6]+val[7]+val[8]+val[9];

	acarreo = (linea[2] / 0x10)*0x10;

	linea[2] = linea[2] - acarreo;

	acarreo = acarreo/0x10;

	//Para la cuarta linea

	val[0] = (trama[0] / 0x10);		
	val[1] = (trama[2] / 0x10);		
	val[2] = (trama[4] / 0x10);		
	val[3] = (trama[6] / 0x10);		
	val[4] = (trama[8] / 0x10);		
	val[5] = (trama[10] / 0x10);		
	val[6] = (trama[12] / 0x10);		
	val[7] = (trama[14] / 0x10);		
	val[8] = (trama[16] / 0x10);		
	val[9] = (trama[18] / 0x10);		

	linea[3] = acarreo+val[0]+val[1]+val[2]+val[3]+val[4]+val[5]+val[6]+val[7]+val[8]+val[9];
	
	acarreo = (linea[3] / 0x10)*0x10;

	linea[3] = linea[3] - acarreo;

	acarreo = acarreo/0x10;

	linea[0] = linea[0] + acarreo;

	linea[0] = ~linea[0];
	linea[1] = ~linea[1];
	linea[2] = ~linea[2];
	linea[3] = ~linea[3];

	linea[0] = linea[0] - ((linea[0] / 0x10)*0x10);
	linea[1] = linea[1] - ((linea[1] / 0x10)*0x10);
	linea[2] = linea[2] - ((linea[2] / 0x10)*0x10);
	linea[3] = linea[3] - ((linea[3] / 0x10)*0x10);

	if (trama[3] == 0xe2){

		printf("El CHECKSUM ES 1: %0.1x%0.1x%0.1x%0.1x\n", linea[3], linea[2], linea[1], linea[0]);
	}

	if (linea[0] == 0x08 && linea[1] == 0x0e && linea[2] == 0x0f && linea[3] == 0x08 && trama[3] == 0x9c){

		printf("El CHECKSUM ES: %0.1x%0.1x%0.1x%0.1x\n", linea[3], linea[2], linea[1], linea[0]);
	}
	else if ( trama[3] == 0x9c ){

		printf("EL CHECKSUM ES INCORRECTO\n");
	}
}