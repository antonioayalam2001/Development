#!/bin/bash
echo Lineal Sin Hilos
cd ..
gcc MainLin.c -lm -o MainLin -phtread
./MainLin 1000000 1 >Lineal.txt
./MainLin 2000000 1 >>Lineal.txt
./MainLin 3000000 1 >>Lineal.txt
./MainLin 4000000 1 >>Lineal.txt
./MainLin 5000000 1 >>Lineal.txt
./MainLin 6000000 1 >>Lineal.txt
./MainLin 7000000 1 >>Lineal.txt
./MainLin 8000000 1 >>Lineal.txt
./MainLin 9000000 1 >>Lineal.txt
./MainLin 10000000 1 >>Lineal.txt




