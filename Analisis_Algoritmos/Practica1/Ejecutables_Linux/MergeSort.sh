#!/bin/bash
echo Hola Estas apunto de ejecutar el programa:
cd ..
gcc mainLin.c -lm -o mainLin

./mainLin 8 100 >MergeT.txt
./mainLin 8 1000 >>MergeT.txt
./mainLin 8 5000 >>MergeT.txt
./mainLin 8 10000 >>MergeT.txt
./mainLin 8 50000 >>MergeT.txt
./mainLin 8 100000 >>MergeT.txt 
./mainLin 8 125000 >>MergeT.txt 
./mainLin 8 175000 >>MergeT.txt 
./mainLin 8 200000 >>MergeT.txt
./mainLin 8 225000 >>MergeT.txt
./mainLin 8 275000 >>MergeT.txt
./mainLin 8 300000 >>MergeT.txt
./mainLin 8 325000 >>MergeT.txt
./mainLin 8 375000 >>MergeT.txt
./mainLin 8 400000 >>MergeT.txt
./mainLin 8 425000 >>MergeT.txt
./mainLin 8 500000 >>MergeT.txt
# ./mainLin 8 600000 >>MergeT.txt
# ./mainLin 8 800000 >>MergeT.txt
# ./mainLin 8 1000000 >>MergeT.txt
# ./mainLin 8 2000000 >>MergeT.txt
# ./mainLin 8 3000000 >>MergeT.txt               
# ./mainLin 8 4000000 >>MergeT.txt
# ./mainLin 8 5000000 >>MergeT.txt
# ./mainLin 8 6000000 >>MergeT.txt
# ./mainLin 8 7000000 >>MergeT.txt
# ./mainLin 8 8000000 >>MergeT.txt
# ./mainLin 8 9000000 >>MergeT.txt
# ./mainLin 8 10000000 >>MergeT.txt


