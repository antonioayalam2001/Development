#!/bin/bash
echo Hola Estas apunto de ejecutar el programa:
cd ..
gcc PruebasAlgoritmo.c -lm -o PruebasAlgoritmo

./PruebasAlgoritmo 3 100 >numeros.txt
./PruebasAlgoritmo 3 1000 >>numeros.txt
./PruebasAlgoritmo 3 5000 >>numeros.txt
./PruebasAlgoritmo 3 10000
# ./PruebasAlgoritmo 3 50000
# ./PruebasAlgoritmo 3 100000
# ./PruebasAlgoritmo 3 200000
# ./PruebasAlgoritmo 3 400000
# ./PruebasAlgoritmo 3 600000
# ./PruebasAlgoritmo 3 800000
# ./PruebasAlgoritmo 3 1000000
# ./PruebasAlgoritmo 3 2000000
# ./PruebasAlgoritmo 3 3000000
# ./PruebasAlgoritmo 3 4000000
# ./PruebasAlgoritmo 3 5000000
# ./PruebasAlgoritmo 3 6000000
# ./PruebasAlgoritmo 3 7000000
# ./PruebasAlgoritmo 3 8000000
# ./PruebasAlgoritmo 3 9000000
# ./PruebasAlgoritmo 3 10000000


