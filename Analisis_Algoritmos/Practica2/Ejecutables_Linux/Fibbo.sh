#!/bin/bash
echo Fibonacci
cd ..
gcc MainLin.c -lm -o MainLin -pthread
./MainLin 1000000 5 0 >Fibonacci.txt
./MainLin 2000000 5 0 >>Fibonacci.txt
./MainLin 3000000 5 0 >>Fibonacci.txt
./MainLin 4000000 5 0 >>Fibonacci.txt
./MainLin 5000000 5 0 >>Fibonacci.txt
./MainLin 6000000 5 0 >>Fibonacci.txt
./MainLin 7000000 5 0 >>Fibonacci.txt
./MainLin 8000000 5 0 >>Fibonacci.txt
./MainLin 9000000 5 0 >>Fibonacci.txt
./MainLin 10000000 5 0 >>Fibonacci.txt

