#!/bin/bash
echo Lineal Hilos
cd ..
gcc MainLin.c -lm -o MainLin -phtread
./MainLin 1000000 2 >LinealH.txt
./MainLin 2000000 2 >>LinealH.txt
./MainLin 3000000 2 >>LinealH.txt
./MainLin 4000000 2 >>LinealH.txt
./MainLin 5000000 2 >>LinealH.txt
./MainLin 6000000 2 >>LinealH.txt
./MainLin 7000000 2 >>LinealH.txt
./MainLin 8000000 2 >>LinealH.txt
./MainLin 9000000 2 >>LinealH.txt
./MainLin 10000000 2 >>LinealH.txt

