CC = g++
CFLAGS = -Wall -g

all: p3

p3: quicksort.o
	$(CC) $(CFLAGS) -o p3 quicksort.o

quicksort.o: quicksort.cpp
	$(CC) $(CFLAGS) -c quicksort.cpp

clean:
	rm -f *.o p3
