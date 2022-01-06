#!/bin/bash
echo Decodificador
cd ..
cd decodificador
gcc Decodificador.c  -o Decodificador
./Decodificador Frecuencias.txt codificacion.dat


