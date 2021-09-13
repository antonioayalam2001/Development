#!/bin/bash
echo Hola Estas apunto de ejecutar el programa:

gcc PruebasAlgoritmo.c -lm -o PruebasAlgoritmo

./PruebasAlgoritmo 3 10 >numeros.txt
./PruebasAlgoritmo 3 15
./PruebasAlgoritmo 3 20
./PruebasAlgoritmo 3 30
./PruebasAlgoritmo 3 40
./PruebasAlgoritmo 3 50
./PruebasAlgoritmo 3 60 >> numeros.txt

