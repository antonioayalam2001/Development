#!/bin/bash
echo Hola Estas apunto de ejecutar el programa:
cd ..
gcc PruebasAlgoritmo.c -lm -o PruebasAlgoritmo

./PruebasAlgoritmo 6 100 >ShellT.txt
./PruebasAlgoritmo 6 1000 >>ShellT.txt
./PruebasAlgoritmo 6 5000 >>ShellT.txt
./PruebasAlgoritmo 6 10000 >>ShellT.txt
./PruebasAlgoritmo 6 50000 >>ShellT.txt
./PruebasAlgoritmo 6 100000 >>ShellT.txt 
./PruebasAlgoritmo 6 125000 >>ShellT.txt 
./PruebasAlgoritmo 6 175000 >>ShellT.txt 
./PruebasAlgoritmo 6 200000 >>ShellT.txt
./PruebasAlgoritmo 6 225000 >>ShellT.txt
./PruebasAlgoritmo 6 275000 >>ShellT.txt
./PruebasAlgoritmo 6 300000 >>ShellT.txt
./PruebasAlgoritmo 6 325000 >>ShellT.txt
./PruebasAlgoritmo 6 375000 >>ShellT.txt
./PruebasAlgoritmo 6 400000 >>ShellT.txt
./PruebasAlgoritmo 6 425000 >>ShellT.txt
./PruebasAlgoritmo 6 500000 >>ShellT.txt
# ./PruebasAlgoritmo 6 6000000 >>ShellT.txt
# ./PruebasAlgoritmo 6 7000000 >>ShellT.txt
# ./PruebasAlgoritmo 6 8000000 >>ShellT.txt
# ./PruebasAlgoritmo 6 9000000 >>ShellT.txt
# ./PruebasAlgoritmo 6 10000000 >>ShellT.txt


