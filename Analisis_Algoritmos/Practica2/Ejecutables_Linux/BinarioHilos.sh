#!/bin/bash
echo BinarioHilos
cd ..
gcc MainLin.c -lm -o MainLin -pthread
./MainLin 1000000 4 >BinarioHilos.txt
./MainLin 2000000 4 >>BinarioHilos.txt
./MainLin 3000000 4 >>BinarioHilos.txt
./MainLin 4000000 4 >>BinarioHilos.txt
./MainLin 5000000 4 >>BinarioHilos.txt
./MainLin 6000000 4 >>BinarioHilos.txt
./MainLin 7000000 4 >>BinarioHilos.txt
./MainLin 8000000 4 >>BinarioHilos.txt
./MainLin 9000000 4 >>BinarioHilos.txt
./MainLin 10000000 4 >>BinarioHilos.txt


