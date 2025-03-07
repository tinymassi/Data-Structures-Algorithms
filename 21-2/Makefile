CC = g++
CFLAGS = -Wall -g

all: p2

p2: main.o intMinHeap.o
	$(CC) $(CFLAGS) -o p2 main.o  intMinHeap.o 

main.o: main.cpp intMinHeap.h
	$(CC) $(CFLAGS) -c main.cpp

intMinHeap.o: intMinHeap.cpp intMinHeap.h
	$(CC) $(CFLAGS) -c intMinHeap.cpp

clean:
	rm -f *.o p2
