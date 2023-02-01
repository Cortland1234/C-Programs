CC=gcc

CFLAGS+=-Wall -g

EXECUTABLE=Exercise7_3

all: $(OBJECTS) Exercise7_3.c
	$(CC) $(CFLAGS) $(OBJECTS) Exercise7_3.c -o $(EXECUTABLE)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *~
	rm -f *.o
	rm -f $(EXECUTABLE)
