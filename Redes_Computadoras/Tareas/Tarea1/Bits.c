#include<stdio.h>

int main(){
	unsigned char i=1,contador=0,c;
	printf("Ingrese un caracter: \n");
	gets(&c);
	for(i=1;i<0x80;i=i<<1){	
		if((c&i)!=0)
		contador+=1;
	}
	printf("La cantidad de bits que tiene el caracter ingresado: %c es de: %d",c,contador);
	return 0;
}