#!/bin/bash
echo Lineal Sin Hilos
cd ..
gcc MainLin.c -lm -o MainLin -phtread
./MainLin 1000000 7 >Fibonacci.txt
./MainLin 2000000 7 >>Fibonacci.txt
./MainLin 3000000 7 >>Fibonacci.txt
./MainLin 4000000 7 >>Fibonacci.txt
./MainLin 5000000 7 >>Fibonacci.txt
./MainLin 6000000 7 >>Fibonacci.txt
./MainLin 7000000 7 >>Fibonacci.txt
./MainLin 8000000 7 >>Fibonacci.txt
./MainLin 9000000 7 >>Fibonacci.txt
./MainLin 10000000 7 >>Fibonacci.txt

