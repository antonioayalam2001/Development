#!/bin/bash
echo ExponencialHilos
cd ..
gcc exponencial.c -lm -o exponencial -pthread
./exponencial 1000000 2 >ExpoH.txt
./exponencial 2000000  2 >>ExpoH.txt
./exponencial 3000000  2 >>ExpoH.txt
./exponencial 4000000  2 >>ExpoH.txt
./exponencial 5000000  2 >>ExpoH.txt
./exponencial 6000000  2 >>ExpoH.txt
./exponencial 7000000  2 >>ExpoH.txt
./exponencial 8000000  2 >>ExpoH.txt
./exponencial 9000000  2 >>ExpoH.txt
./exponencial 10000000  2 >>ExpoH.txt
