#!/bin/bash
echo Lineal Sin Hilos
cd ..
gcc FibonacciHilos.c -lm -o FibonacciHilos -phtread
./FibonacciHilos 1000000  >FibonacciHilos.txt
./FibonacciHilos 2000000  >>FibonacciHilos.txt
./FibonacciHilos 3000000  >>FibonacciHilos.txt
./FibonacciHilos 4000000  >>FibonacciHilos.txt
./FibonacciHilos 5000000  >>FibonacciHilos.txt
./FibonacciHilos 6000000  >>FibonacciHilos.txt
./FibonacciHilos 7000000  >>FibonacciHilos.txt
./FibonacciHilos 8000000  >>FibonacciHilos.txt
./FibonacciHilos 9000000  >>FibonacciHilos.txt
./FibonacciHilos 10000000  >>FibonacciHilos.txt


