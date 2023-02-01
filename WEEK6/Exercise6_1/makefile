

CFLAGS+=-Wall -g

EXECUTABLE=Exercise6_1

OBJECTS=Item.o

all: $(OBJECTS) main.c
	gcc $(CFLAGS) $(OBJECTS) main.c -o $(EXECUTABLE)

clean:
	rm -f *.o
	rm -f *~
	rm -f $(EXECUTABLE)

.c.o:
	$(CC) $(CFLAGS) -c $<
