#!/bin/bash
echo Hola Estas apunto de ejecutar el programa:
cd ..
gcc mainLin.c -lm -o mainLin

./mainLin 6 100 >ShellT.txt
./mainLin 6 1000 >>ShellT.txt
./mainLin 6 5000 >>ShellT.txt
./mainLin 6 10000 >>ShellT.txt
./mainLin 6 50000 >>ShellT.txt
./mainLin 6 100000 >>ShellT.txt 
./mainLin 6 125000 >>ShellT.txt 
./mainLin 6 175000 >>ShellT.txt 
./mainLin 6 200000 >>ShellT.txt
./mainLin 6 225000 >>ShellT.txt
./mainLin 6 275000 >>ShellT.txt
./mainLin 6 300000 >>ShellT.txt
./mainLin 6 325000 >>ShellT.txt
./mainLin 6 375000 >>ShellT.txt
./mainLin 6 400000 >>ShellT.txt
./mainLin 6 425000 >>ShellT.txt
./mainLin 6 500000 >>ShellT.txt
# ./mainLin 6 6000000 >>ShellT.txt
# ./mainLin 6 7000000 >>ShellT.txt
# ./mainLin 6 8000000 >>ShellT.txt
# ./mainLin 6 9000000 >>ShellT.txt
# ./mainLin 6 10000000 >>ShellT.txt


