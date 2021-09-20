cd ..
gcc mainWin.c -lm -o mainWin

.\mainWin
.\mainWin 2 100 >BurbujaOptO.txt
.\mainWin 2 1000 >>BurbujaOptO.txt
.\mainWin 2 5000 >>BurbujaOptO.txt
.\mainWin 2 10000 >>BurbujaOptO.txt
.\mainWin 2 50000 >>BurbujaOptO.txt
.\mainWin 2 100000 >>BurbujaOptO.txt 
.\mainWin 2 200000 >>BurbujaOptO.txt
.\mainWin 2 400000 >>BurbujaOptO.txt
@REM .\mainWin 2 600000 >>BurbujaOptO.txt
@REM .\mainWin 2 800000 >>BurbujaOptO.txt
@REM .\mainWin 2 1000000 >>BurbujaOptO.txt
@REM .\mainWin 2 2000000 >>BurbujaOptO.txt
@REM .\mainWin 2 3000000 >>BurbujaOptO.txt
@REM .\mainWin 2 4000000 >>BurbujaOptO.txt
@REM .\mainWin 2 5000000 >>BurbujaOptO.txt
@REM .\mainWin 2 6000000 >>BurbujaOptO.txt
@REM .\mainWin 2 7000000 >>BurbujaOptO.txt
@REM .\mainWin 2 8000000 >>BurbujaOptO.txt
@REM .\mainWin 2 9000000 >>BurbujaOptO.txt
@REM .\mainWin 2 10000000 >>BurbujaOptO.txt

pause