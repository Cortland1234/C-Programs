CC=gcc

CFLAGS+=-Wall -g

EXECUTABLE=Exercise7_1

all: $(OBJECTS) Exercise7_1.c
	$(CC) $(CFLAGS) $(OBJECTS) Exercise7_1.c -o $(EXECUTABLE)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *~
	rm -f *.o
	rm -f $(EXECUTABLE)
