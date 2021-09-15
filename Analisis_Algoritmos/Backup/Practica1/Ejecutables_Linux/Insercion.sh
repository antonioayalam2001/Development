#!/bin/bash
echo Hola Estas apunto de ejecutar el programa:
cd ..
gcc PruebasAlgoritmo.c -lm -o PruebasAlgoritmo

./PruebasAlgoritmo 4 100 >numeros.txt
./PruebasAlgoritmo 4 1000 >>numeros.txt
./PruebasAlgoritmo 4 5000 >>numeros.txt
./PruebasAlgoritmo 4 10000
# ./PruebasAlgoritmo 4 50000
# ./PruebasAlgoritmo 4 100000
# ./PruebasAlgoritmo 4 200000
# ./PruebasAlgoritmo 4 400000
# ./PruebasAlgoritmo 4 600000
# ./PruebasAlgoritmo 4 800000
# ./PruebasAlgoritmo 4 1000000
# ./PruebasAlgoritmo 4 2000000
# ./PruebasAlgoritmo 4 3000000
# ./PruebasAlgoritmo 4 4000000
# ./PruebasAlgoritmo 4 5000000
# ./PruebasAlgoritmo 4 6000000
# ./PruebasAlgoritmo 4 7000000
# ./PruebasAlgoritmo 4 8000000
# ./PruebasAlgoritmo 4 9000000
# ./PruebasAlgoritmo 4 10000000


