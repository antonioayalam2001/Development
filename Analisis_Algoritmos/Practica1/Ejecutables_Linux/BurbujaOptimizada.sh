#!/bin/bash
echo Estas apunto de ejecutar el programa: Burbuja BurbujaOptimizada
cd ..
gcc mainLin.c -lm -o mainLin
./mainLin
./mainLin 2 100 >BurbujaOT.txt
./mainLin 2 1000 >>BurbujaOT.txt
./mainLin 2 5000 >>BurbujaOT.txt
./mainLin 2 10000 >>BurbujaOT.txt
./mainLin 2 50000 >>BurbujaOT.txt
./mainLin 2 100000 >>BurbujaOT.txt 
./mainLin 2 125000 >>BurbujaOT.txt 
./mainLin 2 175000 >>BurbujaOT.txt 
./mainLin 2 200000 >>BurbujaOT.txt
./mainLin 2 225000 >>BurbujaOT.txt
./mainLin 2 275000 >>BurbujaOT.txt
./mainLin 2 300000 >>BurbujaOT.txt
./mainLin 2 325000 >>BurbujaOT.txt
./mainLin 2 375000 >>BurbujaOT.txt
./mainLin 2 400000 >>BurbujaOT.txt
./mainLin 2 425000 >>BurbujaOT.txt
./mainLin 2 500000 >>BurbujaOT.txt
# ./mainLin 2 3000000 >>BurbujaOT.txt
# ./mainLin 2 4000000 >>BurbujaOT.txt
# ./mainLin 2 5000000 >>BurbujaOT.txt
# ./mainLin 2 6000000 >>BurbujaOT.txt
# ./mainLin 2 7000000 >>BurbujaOT.txt
# ./mainLin 2 8000000 >>BurbujaOT.txt
# ./mainLin 2 9000000 >>BurbujaOT.txt
# ./mainLin 2 10000000 >>BurbujaOT.txt


