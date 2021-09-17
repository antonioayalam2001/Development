#!/bin/bash
echo Hola Estas apunto de ejecutar el programa:
cd ..
gcc PruebasAlgoritmo.c -lm -o PruebasAlgoritmo

./PruebasAlgoritmo 5 100 >SelectT.txt
./PruebasAlgoritmo 5 1000 >>SelectT.txt
./PruebasAlgoritmo 5 5000 >>SelectT.txt
./PruebasAlgoritmo 5 10000 >>SelectT.txt
./PruebasAlgoritmo 5 50000 >>SelectT.txt
./PruebasAlgoritmo 5 100000 >>SelectT.txt 
./PruebasAlgoritmo 5 125000 >>SelectT.txt 
./PruebasAlgoritmo 5 175000 >>SelectT.txt 
./PruebasAlgoritmo 5 200000 >>SelectT.txt
./PruebasAlgoritmo 5 225000 >>SelectT.txt
./PruebasAlgoritmo 5 275000 >>SelectT.txt
./PruebasAlgoritmo 5 300000 >>SelectT.txt
./PruebasAlgoritmo 5 325000 >>SelectT.txt
./PruebasAlgoritmo 5 375000 >>SelectT.txt
./PruebasAlgoritmo 5 400000 >>SelectT.txt
./PruebasAlgoritmo 5 425000 >>SelectT.txt
./PruebasAlgoritmo 5 500000 >>SelectT.txt
# ./PruebasAlgoritmo 5 6000000 >>SelectT.txt
# ./PruebasAlgoritmo 5 7000000 >>SelectT.txt
# ./PruebasAlgoritmo 5 8000000 >>SelectT.txt
# ./PruebasAlgoritmo 5 9000000 >>SelectT.txt
# ./PruebasAlgoritmo 5 10000000 >>SelectT.txt


