#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a,*b,**c,d;
    a=10;
    d=20;
    // 
    // B esta apuntando al valor de 20 en este momemnto *b->20
    b=&d;
    printf("El valor del *b es : %d\n",*b);
    printf("La direccion de memoria de a es : %d\n",&a);
    // 

    // 
    // El puntero doble esta apuntando a el valor que almacena b
    // **c->20
    c=&b;
    printf("El valor del **c es : %d\n",**c);
    printf("El valor del b es : %d\n",&b);
    // 
    
    // 
    // Vamos a modificar el valor de b por medio de c
    // *c->*b->10
    *c=&a;
    printf("El valor del *b siendo modificado por *c  es : %d\n",*b);
    //El valor de C ahora será **c->10 
    printf("El valor del **c es : %d\n",**c);
    // 

    // 
    // Imprimir unicamente *c->direccion de memoria de a
    printf("El valor del *c  es : %d\n",*c);
    // De igual manera imprime una direccion de memoria de b
    printf("El valor del c  es : %d\n",c);
    // 


    return 0;
}
