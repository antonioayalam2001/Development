#!/bin/bash
echo Estas apunto de ejecutar el programa: QuickSort
cd ..
gcc mainLin.c -lm -o mainLin

./mainLin 9 100 >QST.txt
./mainLin 9 1000 >>QST.txt
./mainLin 9 5000 >>QST.txt
./mainLin 9 10000 >>QST.txt
./mainLin 9 50000 >>QST.txt
./mainLin 9 100000 >>QST.txt 
./mainLin 9 125000 >>QST.txt 
./mainLin 9 175000 >>QST.txt 
./mainLin 9 200000 >>QST.txt
./mainLin 9 225000 >>QST.txt
./mainLin 9 275000 >>QST.txt
./mainLin 9 300000 >>QST.txt
./mainLin 9 325000 >>QST.txt
./mainLin 9 375000 >>QST.txt
./mainLin 9 400000 >>QST.txt
./mainLin 9 425000 >>QST.txt
./mainLin 9 500000 >>QST.txt
# ./mainLin 9 6000000 >>QST.txt
# ./mainLin 9 7000000 >>QST.txt
# ./mainLin 9 8000000 >>QST.txt
# ./mainLin 9 9000000 >>QST.txt
# ./mainLin 9 10000000 >>QST.txt


