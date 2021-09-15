#!/bin/bash
echo Hola Estas apunto de ejecutar el programa:
cd ..
gcc PruebasAlgoritmo.c -lm -o PruebasAlgoritmo

./PruebasAlgoritmo 6 100 >numeros.txt
./PruebasAlgoritmo 6 1000 >>numeros.txt
./PruebasAlgoritmo 6 5000 >>numeros.txt
./PruebasAlgoritmo 6 10000
# ./PruebasAlgoritmo 6 50000
# ./PruebasAlgoritmo 6 100000
# ./PruebasAlgoritmo 6 200000
# ./PruebasAlgoritmo 6 400000
# ./PruebasAlgoritmo 6 600000
# ./PruebasAlgoritmo 6 800000
# ./PruebasAlgoritmo 6 1000000
# ./PruebasAlgoritmo 6 2000000
# ./PruebasAlgoritmo 6 3000000
# ./PruebasAlgoritmo 6 4000000
# ./PruebasAlgoritmo 6 5000000
# ./PruebasAlgoritmo 6 6000000
# ./PruebasAlgoritmo 6 7000000
# ./PruebasAlgoritmo 6 8000000
# ./PruebasAlgoritmo 6 9000000
# ./PruebasAlgoritmo 6 10000000


