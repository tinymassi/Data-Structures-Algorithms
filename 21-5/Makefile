CC = g++
CFLAGS = -Wall -g

all: p5

p5: main.o hashtable.o
	$(CC) $(CFLAGS) -o p5 main.o  hashtable.o 

main.o: main.cpp hashtable.h
	$(CC) $(CFLAGS) -c main.cpp

hashtable.o: hashtable.cpp hashtable.h
	$(CC) $(CFLAGS) -c hashtable.cpp

clean:
	rm -f *.o p5
