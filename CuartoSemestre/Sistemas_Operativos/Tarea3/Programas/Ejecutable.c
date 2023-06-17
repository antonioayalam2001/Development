#include <windows.h>
#include <stdio.h>
int main(void)
{
 printf("Soy el hijo\n");

int *p,a,b;
a=10;
p=&a;

printf("Valor de a: %d \n",a);
printf("Valor de p: %d \n",p);
printf("Valor de *p: %d \n",*p);
*p=20;
printf("Valor de *p: %d \n",*p);
printf("Valor de a: %d \n",a);



} 
