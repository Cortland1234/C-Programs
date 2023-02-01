#!/bin/bash

if [ "$1" = "clean" ] ; then
    rm -f *~
    rm -f *.o
    rm -f test_9_4
else

gcc -Wall -g -c my_sin.c -o my_sin.o
gcc -Wall -g -c my_cos.c -o my_cos.o
gcc -Wall -g -c my_tan.c -o my_tan.o
gcc -Wall -g my_sin.o my_cos.o my_tan.o main.c -o test_9_4 -lm

fi    
