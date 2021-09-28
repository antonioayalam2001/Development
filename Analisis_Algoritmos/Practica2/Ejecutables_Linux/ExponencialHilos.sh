#!/bin/bash
echo Lineal Sin Hilos
cd ..
gcc MainLin.c -lm -o MainLin -pthread
./MainLin 1000000 6 >ExpoH.txt
./MainLin 2000000 6 >>ExpoH.txt
./MainLin 3000000 6 >>ExpoH.txt
./MainLin 4000000 6 >>ExpoH.txt
./MainLin 5000000 6 >>ExpoH.txt
./MainLin 6000000 6 >>ExpoH.txt
./MainLin 7000000 6 >>ExpoH.txt
./MainLin 8000000 6 >>ExpoH.txt
./MainLin 9000000 6 >>ExpoH.txt
./MainLin 10000000 6 >>ExpoH.txt
