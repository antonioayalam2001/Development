// *Puntero Doble
#include<stdio.h>
void func(char* ptr);   // prototipo

int main() {
    int x,y,*p1,*p2,**pd;
    x=5;
    y=10;

    printf(":%d\n ", x);
    printf(":%d\n ", y);

    p1=&x;
    p2=&y;

    printf("Con puntero");
    printf(":%d\n ", *p1);
    printf(":%d\n ", *p2);

    pd=&p1;
    printf(":%d\n ", *pd);
    printf(":%d\n ", *p1);
    printf(":%d\n ", **pd);

    *pd=&y;
    **pd=10+45;
    printf(":%d\n ", *p1);
    printf(":%d\n ", **pd);
    printf(":%d\n ", y);

 

   char a[5] = "AEIOU", *ptr = &a[0];
   func(a);              // Las tres
   func(ptr);           // llamadas son
   func(&a[0]);         // equivalentes


   char b[5]="TONYs",d;
    int i;
  for (i=0; i<5; i++) {
      d=b[i];
      printf("B[%d] = %c\n", i, d);
      
  }
}
    


void func(char* arr) {  // definición
  int i;
  for (i=0; i<5; i++) {
      printf("arr[%1i] =%5.0d =%2c\n", i, *arr, *arr);
     arr++;
  }
  return;}