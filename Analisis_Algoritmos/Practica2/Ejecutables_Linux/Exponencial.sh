#!/bin/bash
echo Exponencial
cd ..
gcc MainLin.c -lm -o MainLin -pthread
./MainLin 1000000 8 0 >Exponencial.txt
./MainLin 2000000 8 0 >>Exponencial.txt
./MainLin 3000000 8 0 >>Exponencial.txt
./MainLin 4000000 8 0 >>Exponencial.txt
./MainLin 5000000 8 0 >>Exponencial.txt
./MainLin 6000000 8 0 >>Exponencial.txt
./MainLin 7000000 8 0 >>Exponencial.txt
./MainLin 8000000 8 0 >>Exponencial.txt
./MainLin 9000000 8 0 >>Exponencial.txt
./MainLin 10000000 8 0 >>Exponencial.txt
