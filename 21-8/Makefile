CC = g++
CFLAGS = -Wall -g

all: p8

p8: main.o pathfinder.o
	$(CC) $(CFLAGS) -o p8 main.o pathfinder.o

main.o: main.cpp pathfinder.h
	$(CC) $(CFLAGS) -c main.cpp

pathfinder.o: pathfinder.cpp pathfinder.h
	$(CC) $(CFLAGS) -c pathfinder.cpp

clean:
	rm -f *.o p8