@echo off
gcc -o BinarySort BinarySort.c
gcc -o Generator Generator.c

SET /P size=Size of array: 
SET /P fileName=Out put file name: 

.\Generator.exe %size% %fileName%
.\BinarySort.exe %size% %fileName%

Sorted_%fileName%

@echo:

pause