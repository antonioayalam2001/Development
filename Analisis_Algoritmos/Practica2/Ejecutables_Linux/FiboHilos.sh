#!/bin/bash
echo Lineal Sin Hilos
cd ..
gcc FibonacciHilos.c -lm -o FibonacciHilos -pthread
./FibonacciHilos 1000000 0 >FibonacciHilos.txt
./FibonacciHilos 1000000 5000 >>FibonacciHilos.txt
./FibonacciHilos 1000000 61396 >>FibonacciHilos.txt
./FibonacciHilos 1000000 152503 >>FibonacciHilos.txt
./FibonacciHilos 1000000 214826 >>FibonacciHilos.txt
./FibonacciHilos 1000000 322486 >>FibonacciHilos.txt
./FibonacciHilos 1000000 3128036 >>FibonacciHilos.txt
./FibonacciHilos 1000000 6337399 >>FibonacciHilos.txt
./FibonacciHilos 1000000 10393545 >>FibonacciHilos.txt
./FibonacciHilos 1000000 11889568 >>FibonacciHilos.txt
./FibonacciHilos 1000000 14700764 >>FibonacciHilos.txt
./FibonacciHilos 1000000 187645041 >>FibonacciHilos.txt
./FibonacciHilos 1000000 214744564 >>FibonacciHilos.txt
./FibonacciHilos 1000000 450057883 >>FibonacciHilos.txt
./FibonacciHilos 1000000 1295390003 >>FibonacciHilos.txt
./FibonacciHilos 1000000 1360839364 >>FibonacciHilos.txt
./FibonacciHilos 1000000 1493283650 >>FibonacciHilos.txt
./FibonacciHilos 1000000 1843349527 >>FibonacciHilos.txt
./FibonacciHilos 1000000 1980098116 >>FibonacciHilos.txt
./FibonacciHilos 1000000 2109248666 >>FibonacciHilos.txt
# ./FibonacciHilos 2000000  >>FibonacciHilos.txt
# ./FibonacciHilos 3000000  >>FibonacciHilos.txt
# ./FibonacciHilos 4000000  >>FibonacciHilos.txt
# ./FibonacciHilos 5000000  >>FibonacciHilos.txt
# ./FibonacciHilos 6000000  >>FibonacciHilos.txt
# ./FibonacciHilos 7000000  >>FibonacciHilos.txt
# ./FibonacciHilos 8000000  >>FibonacciHilos.txt
# ./FibonacciHilos 9000000  >>FibonacciHilos.txt
# ./FibonacciHilos 10000000  >>FibonacciHilos.txt


