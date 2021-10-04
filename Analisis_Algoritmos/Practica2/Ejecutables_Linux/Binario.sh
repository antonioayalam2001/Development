#!/bin/bash
echo Binario
cd ..
gcc MainLin.c -lm -o MainLin -pthread
./MainLin 1000000 3 0 >Binario.txt
./MainLin 2000000 3 0 >>Binario.txt
./MainLin 3000000 3 0 >>Binario.txt
./MainLin 4000000 3 0 >>Binario.txt
./MainLin 5000000 3 0 >>Binario.txt
./MainLin 6000000 3 0 >>Binario.txt
./MainLin 7000000 3 0 >>Binario.txt
./MainLin 8000000 3 0 >>Binario.txt
./MainLin 9000000 3 0 >>Binario.txt
./MainLin 10000000 3 0 >>Binario.txt


