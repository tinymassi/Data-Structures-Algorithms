CC = g++
CFLAGS = -Wall -g

all: p7

p7: main.o binarysearch.o
	$(CC) $(CFLAGS) -o p7 main.o binarysearch.o

main.o: main.cpp binarysearch.h
	$(CC) $(CFLAGS) -c main.cpp

binarysearch.o: binarysearch.cpp binarysearch.h
	$(CC) $(CFLAGS) -c binarysearch.cpp

clean:
	rm -f *.o p7