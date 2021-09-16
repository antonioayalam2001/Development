#!/bin/bash
echo Hola Estas apunto de ejecutar el programa:
cd ..
gcc PruebasAlgoritmo.c -lm -o PruebasAlgoritmo

./PruebasAlgoritmo 1 100 >BurbujaT.txt
./PruebasAlgoritmo 1 1000 >>BurbujaT.txt
./PruebasAlgoritmo 1 5000 >>BurbujaT.txt
./PruebasAlgoritmo 1 10000 >>BurbujaT.txt
./PruebasAlgoritmo 1 50000 >>BurbujaT.txt
./PruebasAlgoritmo 1 100000 >>BurbujaT.txt 
./PruebasAlgoritmo 1 200000 >>BurbujaT.txt
./PruebasAlgoritmo 1 400000 >>BurbujaT.txt
./PruebasAlgoritmo 1 600000 >>BurbujaT.txt
./PruebasAlgoritmo 1 800000 >>BurbujaT.txt
./PruebasAlgoritmo 1 1000000 >>BurbujaT.txt
# ./PruebasAlgoritmo 1 2000000 >>BurbujaT.txt
# ./PruebasAlgoritmo 1 3000000 >>BurbujaT.txt
# ./PruebasAlgoritmo 1 4000000 >>BurbujaT.txt
# ./PruebasAlgoritmo 1 5000000 >>BurbujaT.txt
# ./PruebasAlgoritmo 1 6000000 >>BurbujaT.txt
# ./PruebasAlgoritmo 1 7000000 >>BurbujaT.txt
# ./PruebasAlgoritmo 1 8000000 >>BurbujaT.txt
# ./PruebasAlgoritmo 1 9000000 >>BurbujaT.txt
# ./PruebasAlgoritmo 1 10000000 >>BurbujaT.txt

