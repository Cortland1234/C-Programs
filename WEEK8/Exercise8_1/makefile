CC=gcc

CFLAGS=-Wall -g

PWD= $(shell pwd)

LIBDIR=-L $(PWD)

LIBS=-ltestlib

all: libtestlib.a main.c
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBDIR) main.c -o test $(LIBS) 

libtestlib.a: testlib.h testlib.c
	$(CC) -c testlib.c -o testlib.o

	$(AR) rc libtestlib.a testlib.o
