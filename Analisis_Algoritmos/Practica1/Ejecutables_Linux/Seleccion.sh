#!/bin/bash
echo Hola Estas apunto de ejecutar el programa:
cd ..
gcc PruebasAlgoritmo.c -lm -o PruebasAlgoritmo

./PruebasAlgoritmo 5 100 >numeros.txt
./PruebasAlgoritmo 5 1000 >>numeros.txt
./PruebasAlgoritmo 5 5000 >>numeros.txt
./PruebasAlgoritmo 5 10000
# ./PruebasAlgoritmo 5 50000
# ./PruebasAlgoritmo 5 100000
# ./PruebasAlgoritmo 5 200000
# ./PruebasAlgoritmo 5 400000
# ./PruebasAlgoritmo 5 600000
# ./PruebasAlgoritmo 5 800000
# ./PruebasAlgoritmo 5 1000000
# ./PruebasAlgoritmo 5 2000000
# ./PruebasAlgoritmo 5 3000000
# ./PruebasAlgoritmo 5 4000000
# ./PruebasAlgoritmo 5 5000000
# ./PruebasAlgoritmo 5 6000000
# ./PruebasAlgoritmo 5 7000000
# ./PruebasAlgoritmo 5 8000000
# ./PruebasAlgoritmo 5 9000000
# ./PruebasAlgoritmo 5 10000000


