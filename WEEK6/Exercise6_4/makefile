CC=gcc

CFLAGS+=-std=c11 -Wall -O2 -Warray-bounds

EXECUTABLE=Exercise6_4

OBJECTS=Location.o ItemList.o Item.o Game.o Player.o

all: $(OBJECTS) main.c
	$(CC) $(CFLAGS) $(OBJECTS) main.c -o $(EXECUTABLE)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *~
	rm -f *.o
	rm -f $(EXECUTABLE)
