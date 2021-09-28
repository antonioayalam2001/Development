#!/bin/bash
echo Lineal Sin Hilos
cd ..
gcc MainLin.c -lm -o MainLin -phtread
./MainLin 1000000 5 >Exponencial.txt
./MainLin 2000000 5 >>Exponencial.txt
./MainLin 3000000 5 >>Exponencial.txt
./MainLin 4000000 5 >>Exponencial.txt
./MainLin 5000000 5 >>Exponencial.txt
./MainLin 6000000 5 >>Exponencial.txt
./MainLin 7000000 5 >>Exponencial.txt
./MainLin 8000000 5 >>Exponencial.txt
./MainLin 9000000 5 >>Exponencial.txt
./MainLin 10000000 5 >>Exponencial.txt
