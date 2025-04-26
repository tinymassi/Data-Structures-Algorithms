CC = g++
CFLAGS = -Wall -g

all: p6

p6: main.o maze.o disjoint.o
	$(CC) $(CFLAGS) -o p6 main.o maze.o disjoint.o

main.o: main.cpp maze.h
	$(CC) $(CFLAGS) -c main.cpp

maze.o: maze.cpp maze.h disjoint.h
	$(CC) $(CFLAGS) -c maze.cpp

disjoint.o: disjoint.cpp disjoint.h
	$(CC) $(CFLAGS) -c disjoint.cpp

clean:
	rm -f *.o p6