#!/bin/bash
echo Hola Estas apunto de ejecutar el programa:
cd ..
gcc PruebasAlgoritmo.c -lm -o PruebasAlgoritmo

./PruebasAlgoritmo 1 100 >numeros.txt
./PruebasAlgoritmo 1 1000 >>numeros.txt
./PruebasAlgoritmo 1 5000 >>numeros.txt
./PruebasAlgoritmo 1 10000
# ./PruebasAlgoritmo 1 50000
# ./PruebasAlgoritmo 1 100000
# ./PruebasAlgoritmo 1 200000
# ./PruebasAlgoritmo 1 400000
# ./PruebasAlgoritmo 1 600000
# ./PruebasAlgoritmo 1 800000
# ./PruebasAlgoritmo 1 1000000
# ./PruebasAlgoritmo 1 2000000
# ./PruebasAlgoritmo 1 3000000
# ./PruebasAlgoritmo 1 4000000
# ./PruebasAlgoritmo 1 5000000
# ./PruebasAlgoritmo 1 6000000
# ./PruebasAlgoritmo 1 7000000
# ./PruebasAlgoritmo 1 8000000
# ./PruebasAlgoritmo 1 9000000
# ./PruebasAlgoritmo 1 10000000


