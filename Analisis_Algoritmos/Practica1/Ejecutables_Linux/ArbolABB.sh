#!/bin/bash
echo Hola Estas apunto de ejecutar el programa:
cd ..
gcc PruebasAlgoritmo.c -lm -o PruebasAlgoritmo

./PruebasAlgoritmo 7 100 >numeros.txt
./PruebasAlgoritmo 7 1000 >>numeros.txt
./PruebasAlgoritmo 7 5000 >>numeros.txt
./PruebasAlgoritmo 7 10000
./PruebasAlgoritmo 7 50000
./PruebasAlgoritmo 7 100000
./PruebasAlgoritmo 7 200000
./PruebasAlgoritmo 7 400000
./PruebasAlgoritmo 7 600000
./PruebasAlgoritmo 7 800000
./PruebasAlgoritmo 7 1000000
./PruebasAlgoritmo 7 2000000
./PruebasAlgoritmo 7 3000000
./PruebasAlgoritmo 7 4000000
# ./PruebasAlgoritmo 7 5000000
# ./PruebasAlgoritmo 7 6000000
# ./PruebasAlgoritmo 7 7000000
# ./PruebasAlgoritmo 7 8000000
# ./PruebasAlgoritmo 7 9000000
# ./PruebasAlgoritmo 7 10000000


