#include<stdio.h>
#include<math.h>


// >>>>>>>>>>>>>ALGORITMOS RECURSIVOS >>>>>>>>>>>>>>>>>>>>>>

int Busqueda (A[],i,val) {
    if (i<0)
        return -1;
    if (A[i]==val)
        return i;
    return Busqueda (A[],i-1,val);    
}

int coef (int n , int k ){
    if(k==0 || k==n)
        return 1;
    else if (k>0&&k<n)
        return coef (int n-1 , int k+1 )+coef (int n-1 , int k );
}

Palindromo (cadena){
    if (longitud(cadena)==1)
    {
        return TRUE
    }
    if (primer_caracter(cadena)!=ultimo_caracter(cadena))
    {
        return FALSE
    }
    cadena=remover_primer_ultimo_caracter(cadena);
    Palindromo(cadena);
}

SubAlgoritmo Volados (n,cadena)
    Si n!=0
        Volados(n-1,concatenar(cadena,'S'));
        Volados(n-1,concatenar(cadena,'A'));
    SiNo
        Mostrar cadena
    FinSi
FinSubAlgoritmo

DecABin(n){
    if(n>1)
    DecABiin(n/2);
    Mostrar(n%2);
}

int Producto(int a, int b){
    if(b==0)
        return 0;
    else
        return a+Prodcuto(a,b-1);
}
