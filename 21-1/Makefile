CC = g++
CFLAGS = -Wall -g

all: p1

p1: main.o stack.o linkedlist.o
	$(CC) $(CFLAGS) -o p1 main.o stack.o linkedlist.o 

main.o: main.cpp stack.h
	$(CC) $(CFLAGS) -c main.cpp

stack.o: stack.cpp stack.h linkedlist.h
	$(CC) $(CFLAGS) -c stack.cpp

linkedlist.o: linkedlist.cpp linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.cpp

clean:
	rm -f *.o p1
