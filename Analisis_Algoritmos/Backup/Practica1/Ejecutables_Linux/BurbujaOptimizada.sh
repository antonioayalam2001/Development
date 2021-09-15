#!/bin/bash
echo Hola Estas apunto de ejecutar el programa:
cd ..
gcc PruebasAlgoritmo.c -lm -o PruebasAlgoritmo

./PruebasAlgoritmo 2 100 >numeros.txt
./PruebasAlgoritmo 2 1000 >>numeros.txt
./PruebasAlgoritmo 2 5000 >>numeros.txt
./PruebasAlgoritmo 2 10000
# ./PruebasAlgoritmo 2 50000
# ./PruebasAlgoritmo 2 100000
# ./PruebasAlgoritmo 2 200000
# ./PruebasAlgoritmo 2 400000
# ./PruebasAlgoritmo 2 600000
# ./PruebasAlgoritmo 2 800000
# ./PruebasAlgoritmo 2 1000000
# ./PruebasAlgoritmo 2 2000000
# ./PruebasAlgoritmo 2 3000000
# ./PruebasAlgoritmo 2 4000000
# ./PruebasAlgoritmo 2 5000000
# ./PruebasAlgoritmo 2 6000000
# ./PruebasAlgoritmo 2 7000000
# ./PruebasAlgoritmo 2 8000000
# ./PruebasAlgoritmo 2 9000000
# ./PruebasAlgoritmo 2 10000000


