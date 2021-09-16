#!/bin/bash
echo Hola Estas apunto de ejecutar el programa:
cd ..
gcc PruebasAlgoritmo.c -lm -o PruebasAlgoritmo

./PruebasAlgoritmo 8 100 >numeros.txt
./PruebasAlgoritmo 8 1000 >>numeros.txt
./PruebasAlgoritmo 8 5000 >>numeros.txt
./PruebasAlgoritmo 8 10000
# ./PruebasAlgoritmo 8 50000
# ./PruebasAlgoritmo 8 100000
# ./PruebasAlgoritmo 8 200000
# ./PruebasAlgoritmo 8 400000
# ./PruebasAlgoritmo 8 600000
# ./PruebasAlgoritmo 8 800000
# ./PruebasAlgoritmo 8 1000000
# ./PruebasAlgoritmo 8 2000000
# ./PruebasAlgoritmo 8 3000000
# ./PruebasAlgoritmo 8 4000000
# ./PruebasAlgoritmo 8 5000000
# ./PruebasAlgoritmo 8 6000000
# ./PruebasAlgoritmo 8 7000000
# ./PruebasAlgoritmo 8 8000000
# ./PruebasAlgoritmo 8 9000000
# ./PruebasAlgoritmo 8 10000000


