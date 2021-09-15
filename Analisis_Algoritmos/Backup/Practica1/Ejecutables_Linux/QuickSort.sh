#!/bin/bash
echo Hola Estas apunto de ejecutar el programa:
cd ..
gcc PruebasAlgoritmo.c -lm -o PruebasAlgoritmo

./PruebasAlgoritmo 9 100 >numeros.txt
./PruebasAlgoritmo 9 1000 >>numeros.txt
./PruebasAlgoritmo 9 5000 >>numeros.txt
./PruebasAlgoritmo 9 10000
# ./PruebasAlgoritmo 9 50000
# ./PruebasAlgoritmo 9 100000
# ./PruebasAlgoritmo 9 200000
# ./PruebasAlgoritmo 9 400000
# ./PruebasAlgoritmo 9 600000
# ./PruebasAlgoritmo 9 800000
# ./PruebasAlgoritmo 9 1000000
# ./PruebasAlgoritmo 9 2000000
# ./PruebasAlgoritmo 9 3000000
# ./PruebasAlgoritmo 9 4000000
# ./PruebasAlgoritmo 9 5000000
# ./PruebasAlgoritmo 9 6000000
# ./PruebasAlgoritmo 9 7000000
# ./PruebasAlgoritmo 9 8000000
# ./PruebasAlgoritmo 9 9000000
# ./PruebasAlgoritmo 9 10000000


