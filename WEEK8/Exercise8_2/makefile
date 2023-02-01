C=gcc

CFLAGS=-Wall -g

PWD= $(shell pwd)

LIBS=-ltestlib

all: libtestlib.so main.c
	$(CC) $(CFLAGS) main.c -o test $(LIBS)

libtestlib.so: testlib.h testlib.c
	$(CC) -fPIC -c testlib.c -o testlib.o
	$(CC) -shared -o libtestlib.so testlib.o