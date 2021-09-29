#!/bin/bash
echo Arbol Hilos
cd ..
gcc MainLin.c -lm -o MainLin -pthread
./MainLin 1000000 7 >ArbolH.txt
./MainLin 2000000 7 >>ArbolH.txt
./MainLin 3000000 7 >>ArbolH.txt
./MainLin 4000000 7 >>ArbolH.txt
./MainLin 5000000 7 >>ArbolH.txt
./MainLin 6000000 7 >>ArbolH.txt
./MainLin 7000000 7 >>ArbolH.txt
./MainLin 8000000 7 >>ArbolH.txt
./MainLin 9000000 7 >>ArbolH.txt
./MainLin 10000000 7 >>ArbolH.txt
