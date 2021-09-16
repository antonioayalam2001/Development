#!/bin/bash
echo Hola Estas apunto de ejecutar el programa:
cd ..
gcc PruebasAlgoritmo.c -lm -o PruebasAlgoritmo

./PruebasAlgoritmo 9 100 >QST.txt
./PruebasAlgoritmo 9 1000 >>QST.txt
./PruebasAlgoritmo 9 5000 >>QST.txt
./PruebasAlgoritmo 9 10000 >>QST.txt
# ./PruebasAlgoritmo 9 50000 >>QST.txt
# ./PruebasAlgoritmo 9 100000 >>QST.txt
# ./PruebasAlgoritmo 9 200000 >>QST.txt
# ./PruebasAlgoritmo 9 400000 >>QST.txt
# ./PruebasAlgoritmo 9 600000 >>QST.txt
# ./PruebasAlgoritmo 9 800000 >>QST.txt
# ./PruebasAlgoritmo 9 1000000 >>QST.txt
# ./PruebasAlgoritmo 9 2000000 >>QST.txt
# ./PruebasAlgoritmo 9 3000000 >>QST.txt
# ./PruebasAlgoritmo 9 4000000 >>QST.txt
# ./PruebasAlgoritmo 9 5000000 >>QST.txt
# ./PruebasAlgoritmo 9 6000000 >>QST.txt
# ./PruebasAlgoritmo 9 7000000 >>QST.txt
# ./PruebasAlgoritmo 9 8000000 >>QST.txt
# ./PruebasAlgoritmo 9 9000000 >>QST.txt
# ./PruebasAlgoritmo 9 10000000 >>QST.txt


